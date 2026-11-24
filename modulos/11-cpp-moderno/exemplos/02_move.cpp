// Move semantics: cópia x movimento.
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Buffer {
public:
    explicit Buffer(std::size_t n) : dados_(n, 0) {
        std::cout << "construtor(" << n << ")\n";
    }

    Buffer(const Buffer& outro) : dados_(outro.dados_) {
        std::cout << "cópia\n";
    }

    Buffer(Buffer&& outro) noexcept : dados_(std::move(outro.dados_)) {
        std::cout << "movimento\n";
    }

    Buffer& operator=(const Buffer& outro) {
        std::cout << "atribuição de cópia\n";
        dados_ = outro.dados_;
        return *this;
    }

    Buffer& operator=(Buffer&& outro) noexcept {
        std::cout << "atribuição de movimento\n";
        dados_ = std::move(outro.dados_);
        return *this;
    }

    std::size_t tamanho() const { return dados_.size(); }

private:
    std::vector<int> dados_;
};

int main() {
    Buffer a(1'000'000);
    std::cout << "--- copiando ---\n";
    Buffer b = a;
    std::cout << "--- movendo ---\n";
    Buffer c = std::move(a);

    std::cout << "tamanhos: " << b.tamanho() << " " << c.tamanho()
              << " " << a.tamanho() << "\n";

    // std::move em string: sem cópia
    std::string texto = "um texto razoavelmente grande";
    std::string outro = std::move(texto);
    std::cout << "outro: " << outro << "\n";
    return 0;
}
