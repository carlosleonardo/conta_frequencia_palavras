//
// Created by carlo on 25/08/2026.
//

#ifndef CONTA_FREQUENCIA_PALAVRAS_PROGRAMA_H
#define CONTA_FREQUENCIA_PALAVRAS_PROGRAMA_H
#include <map>
#include <vector>
#include <string>

class Programa {
public:
    void extrairPalavras(const std::string &frase);

    void exibirTabelaFrequencias() const;

    void contaFrequenciaPalavras();

    bool extrairEntradaUsuario(std::string &frase);

    bool extrairEntradaArquivo(std::string texto);

    void tratarErroEntrada() const;

    int executar();

private:
    std::vector<std::string> m_palavras;
    std::map<std::string, int> m_frequencia;
};


#endif //CONTA_FREQUENCIA_PALAVRAS_PROGRAMA_H
