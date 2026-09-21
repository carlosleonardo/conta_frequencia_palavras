//
// Created by carlo on 25/08/2026.
//

#include "Programa.h"

#include <format>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

void Programa::extrairPalavras(const std::string &frase) {
    const boost::tokenizer<> tokenizer(frase);
    const std::set<char> simbolos = {
        ' ', '.', ',', ';', ':', '!', '?', '-', '_', '(', ')', '[', ']', '{', '}', '"', '\''
    };

    for (auto &palavra: tokenizer) {
        // Se a palavra não estiver vazia e não for um símbolo, adiciona à lista de palavras
        if (!palavra.empty() && !std::ranges::any_of(palavra, [&](const char c) { return simbolos.contains(c); })) {
            m_palavras.push_back(palavra);
        }
    }
}

void Programa::exibirTabelaFrequencias() const {
    std::cout << "Frequência das palavras:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << std::format("{:<20} {:>10}\n", "Palavra", "Frequência");
    for (const auto &[palavra, count]: m_frequencia) {
        std::cout << std::format("{:<20} {:>10}\n", palavra, count);
    }
}

void Programa::contaFrequenciaPalavras() {
    for (auto &palavra: m_palavras) {
        m_frequencia[palavra]++;
    }
}

bool Programa::extrairEntradaUsuario(std::string &frase) {
    std::cout << "Informe uma frase (Fim-de-arquivo termina): ";
    m_palavras.clear();
    m_frequencia.clear();

    std::getline(std::cin, frase);
    return true;
}

bool Programa::extrairEntradaArquivo(std::string texto) {
    std::cout << "Informe o nome do arquivo: ";

    m_frequencia.clear();
    m_palavras.clear();

    std::string nomeArquivo;
    std::cin >> nomeArquivo;
    if (std::cin.fail()) {
        tratarErroEntrada();
        std::cout << "Entrada inválida. Por favor, digite um nome de arquivo válido." << std::endl;
        return false;
    }

    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return false;
    }
    while (std::getline(arquivo, texto)) {
        extrairPalavras(texto);
    }
    return true;
}

void Programa::tratarErroEntrada() const {
    std::cin.clear(); // Limpa o estado de falha
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
}

int Programa::executar() {
    std::string frase;
    do {
        std::cout << "--- MENU ---" << std::endl;
        std::cout << "1. Extrair Palavras" << std::endl;
        std::cout << "2. Ler de arquivo" << std::endl;
        std::cout << "3. Sair" << std::endl;
        int opcao{};
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        if (std::cin.fail()) {
            tratarErroEntrada();
            std::cout << "Entrada inválida. Por favor, digite um número válido." << std::endl;
            continue;
        }
        // Limpa o buffer de entrada para evitar problemas com entradas subsequentes
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (opcao) {
            case 1:
                if (extrairEntradaUsuario(frase)) break;
                continue; // Volta para o menu
            case 2: {
                if (extrairEntradaArquivo(frase)) break;
                continue; // Volta para o menu
            }
            case 3:
                std::cout << "Saindo do programa." << std::endl;
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
        extrairPalavras(frase);

        contaFrequenciaPalavras();

        exibirTabelaFrequencias();
    } while (true);

    return 0;
}
