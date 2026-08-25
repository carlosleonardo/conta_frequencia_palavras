#include <iostream>

#include "Programa.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#if defined(_WIN32)
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    std::cout << "Contar frequência de palavras" << std::endl;
    Programa programa;
    return programa.executar();
}
