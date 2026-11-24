// Exercício 03 — Move semantics
//
// Complete o construtor de movimento e a atribuição de movimento de Buffer.
// Regras:
//   - o construtor de movimento deve TRANSFERIR os dados (std::move),
//     nunca copiar;
//   - deve ser noexcept;
//   - incrementar movimentos_ no construtor de movimento e na atribuição.
//
// O teste confere que mover não gera cópias.
#include <utility>
#include <vector>
#include "teste.hpp"

class Buffer {
public:
    explicit Buffer(std::size_t n) : dados_(n, 0) {}

    Buffer(const Buffer& outro) : dados_(outro.dados_) { ++copias_; }

    Buffer& operator=(const Buffer& outro) {
        dados_ = outro.dados_;
        ++copias_;
        return *this;
    }

    Buffer(Buffer&& outro) noexcept {
        // TODO: transfira os dados de outro
    }

    Buffer& operator=(Buffer&& outro) noexcept {
        // TODO: transfira os dados de outro
        return *this;
    }

    std::size_t tamanho() const { return dados_.size(); }

    static int copias() { return copias_; }
    static int movimentos() { return movimentos_; }
    static void zerar_contadores() { copias_ = 0; movimentos_ = 0; }

private:
    std::vector<int> dados_;
    static inline int copias_ = 0;
    static inline int movimentos_ = 0;
};

int main() {
    Buffer::zerar_contadores();

    Buffer a(10);
    Buffer b = std::move(a);          // construtor de movimento
    CHECK_IGUAL(std::size_t(10), b.tamanho());
    CHECK_IGUAL(1, Buffer::movimentos());
    CHECK_IGUAL(0, Buffer::copias());

    Buffer c(3);
    c = std::move(b);                 // atribuição de movimento
    CHECK_IGUAL(std::size_t(10), c.tamanho());
    CHECK_IGUAL(2, Buffer::movimentos());
    CHECK_IGUAL(0, Buffer::copias());
    return teste::resumo("ex03 · move semantics");
}
