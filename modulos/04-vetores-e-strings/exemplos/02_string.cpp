// std::string: operações comuns.
#include <iostream>
#include <string>

int main() {
    std::string nome = "  Ana Maria  ";

    std::cout << "bruto: [" << nome << "]\n";
    std::cout << "tamanho: " << nome.size() << "\n";

    // Remover espaços das pontas (manual, para entender)
    std::size_t inicio = nome.find_first_not_of(' ');
    std::size_t fim = nome.find_last_not_of(' ');
    std::string limpo = nome.substr(inicio, fim - inicio + 1);
    std::cout << "limpo: [" << limpo << "]\n";

    std::cout << "primeira letra: " << limpo[0] << "\n";
    std::cout << "iniciais: " << limpo[0] << limpo[limpo.find(' ') + 1] << "\n";

    std::string saudacao = "Olá, " + limpo + "!";
    std::cout << saudacao << "\n";

    if (limpo.find("Maria") != std::string::npos) {
        std::cout << "achei 'Maria' na posição " << limpo.find("Maria") << "\n";
    }

    int numero = std::stoi("2026");
    std::cout << "ano + 1 = " << numero + 1 << "\n";
    std::cout << "texto: " << std::to_string(numero) << "\n";

    return 0;
}
