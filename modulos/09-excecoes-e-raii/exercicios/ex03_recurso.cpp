// Exercício 03 — RAII na prática
//
// Complete a classe ContadorRecurso:
//   construtor  → incrementa ativos_ e o total criado
//   destrutor   → decrementa ativos_
//
// O objetivo é provar que o destrutor roda em todos os caminhos,
// inclusive quando uma exceção é lançada.
#include <stdexcept>
#include "teste.hpp"

class ContadorRecurso {
public:
    ContadorRecurso() {
        // TODO: ++ativos_ e ++criados
    }

    ~ContadorRecurso() {
        // TODO: --ativos_
    }

    ContadorRecurso(const ContadorRecurso&) = delete;
    ContadorRecurso& operator=(const ContadorRecurso&) = delete;

    static int ativos() { return ativos_; }
    static int criados() { return criados_; }

private:
    static inline int ativos_ = 0;
    static inline int criados_ = 0;
};

int main() {
    CHECK_IGUAL(0, ContadorRecurso::ativos());

    {
        ContadorRecurso a;
        ContadorRecurso b;
        CHECK_IGUAL(2, ContadorRecurso::ativos());
    }
    CHECK_IGUAL(0, ContadorRecurso::ativos());
    CHECK_IGUAL(2, ContadorRecurso::criados());

    try {
        ContadorRecurso c;
        CHECK_IGUAL(1, ContadorRecurso::ativos());
        throw std::runtime_error("falha");
    } catch (const std::exception&) {
        // esperado
    }
    CHECK_IGUAL(0, ContadorRecurso::ativos());
    return teste::resumo("ex03 · RAII");
}
