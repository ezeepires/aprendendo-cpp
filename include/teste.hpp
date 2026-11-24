// Framework mínimo de testes usado nos exercícios.
// Não é uma biblioteca séria: existe só para você saber, na hora,
// se a sua implementação está correta.
#pragma once

#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

namespace teste {

struct Falha {
    std::string descricao;
};

inline std::vector<Falha>& falhas() {
    static std::vector<Falha> lista;
    return lista;
}

inline int& total() {
    static int contador = 0;
    return contador;
}

template <typename T>
std::string texto(const T& valor) {
    std::ostringstream os;
    os << valor;
    return os.str();
}

inline void registrar(bool passou, const std::string& descricao) {
    ++total();
    if (!passou) {
        falhas().push_back({descricao});
    }
}

// Retorna 0 se tudo passou, 1 caso contrário (útil para o Makefile).
inline int resumo(const std::string& nome) {
    if (falhas().empty()) {
        std::printf("\033[32m✅ %s\033[0m — %d/%d verificações passaram\n",
                    nome.c_str(), total(), total());
        return 0;
    }

    std::printf("\033[31m❌ %s\033[0m — %zu de %d verificações falharam\n",
                nome.c_str(), falhas().size(), total());
    for (const auto& f : falhas()) {
        std::printf("     → %s\n", f.descricao.c_str());
    }
    return 1;
}

}  // namespace teste

// Verifica uma condição simples.
#define CHECK(condicao)                                                     \
    teste::registrar(static_cast<bool>(condicao),                          \
                     std::string(__FILE__) + ":" +                         \
                                     std::to_string(__LINE__) +             \
                                     " → condição falsa: " #condicao)

// Compara dois valores e mostra os dois quando diferente.
#define CHECK_IGUAL(esperado, obtido)                                       \
    teste::registrar((esperado) == (obtido),                               \
                     std::string(__FILE__) + ":" +                         \
                         std::to_string(__LINE__) + " → esperado " +       \
                         teste::texto(esperado) + ", obtido " +            \
                         teste::texto(obtido))

// Compara números de ponto flutuante com tolerância.
#define CHECK_PROXIMO(esperado, obtido, tolerancia)                         \
    teste::registrar(((esperado) - (obtido) < (tolerancia)) &&              \
                         ((obtido) - (esperado) < (tolerancia)),           \
                     std::string(__FILE__) + ":" +                         \
                         std::to_string(__LINE__) + " → esperado ~" +      \
                         teste::texto(esperado) + ", obtido " +            \
                         teste::texto(obtido))
