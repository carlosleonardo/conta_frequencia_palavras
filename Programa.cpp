//
// Created by carlo on 25/08/2026.
//

#include "Programa.h"

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
    for (const auto &[palavra, count]: m_frequencia) {
        std::cout << palavra << ": " << count << std::endl;
    }
}

void Programa::contaFrequenciaPalavras() {
    for (auto &palavra: m_palavras) {
        m_frequencia[palavra]++;
    }
}

int Programa::executar() {
    std::cout << "Informe uma frase (Fim-de-arquivo)";

    std::string frase;
    std::getline(std::cin, frase);

    extrairPalavras(frase);

    // Conta quantas vezes aparece cada palavra
    contaFrequenciaPalavras();

    exibirTabelaFrequencias();
    return 0;
}
