// Exercício 02 — String para inteiro
//
// Converta textos como "42" e "-7" em int.
// Se o texto não for um número válido, lance std::invalid_argument
// com uma mensagem que contenha "inválido".
//
// Dica: std::stoi lança std::invalid_argument sozinho, mas aceita "42abc"
// (para no primeiro caractere inválido). Use o segundo parâmetro (posição)
// para garantir que a string inteira foi consumida.
#include <stdexcept>
#include <string>
#include "teste.hpp"

int para_inteiro(const std::string& texto) {
    // TODO
    return 0;
}

int main() {
    CHECK_IGUAL(42, para_inteiro("42"));
    CHECK_IGUAL(-7, para_inteiro("-7"));
    CHECK_IGUAL(0, para_inteiro("0"));
    CHECK_IGUAL(2026, para_inteiro("2026"));

    for (const std::string invalido : {"", "abc", "42abc", " "}) {
        bool lancou = false;
        try {
            para_inteiro(invalido);
        } catch (const std::invalid_argument&) {
            lancou = true;
        }
        CHECK(lancou);
    }
    return teste::resumo("ex02 · string para inteiro");
}
