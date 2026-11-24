// Escrevendo e anexando em arquivo.
#include <fstream>
#include <iostream>
#include <string>

int main() {
    const std::string caminho = "/tmp/aprendendo_cpp_exemplo.txt";

    {
        std::ofstream out(caminho);          // sobrescreve
        if (!out) {
            std::cerr << "não abriu " << caminho << "\n";
            return 1;
        }
        out << "nome,nota\n";
        out << "Ana,9.5\n";
        out << "Bia,8.0\n";
    }   // fecha aqui

    {
        std::ofstream out(caminho, std::ios::app);   // anexa
        out << "Caio,7.25\n";
    }

    std::cout << "arquivo escrito em " << caminho << "\n";
    return 0;
}
