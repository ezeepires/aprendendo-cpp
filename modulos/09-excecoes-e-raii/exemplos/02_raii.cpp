// RAII: o destrutor libera o recurso, mesmo com exceção.
#include <iostream>
#include <stdexcept>
#include <string>

class Marcador {
public:
    explicit Marcador(std::string nome) : nome_(std::move(nome)) {
        std::cout << "  + entrou: " << nome_ << "\n";
    }
    ~Marcador() {
        std::cout << "  - saiu: " << nome_ << "\n";
    }
    Marcador(const Marcador&) = delete;
    Marcador& operator=(const Marcador&) = delete;

private:
    std::string nome_;
};

void funcao_que_falha() {
    Marcador m("recurso interno");
    std::cout << "  trabalhando...\n";
    throw std::runtime_error("falha no meio do trabalho");
    // ~Marcador() roda mesmo assim (stack unwinding)
}

int main() {
    Marcador externo("recurso externo");
    try {
        funcao_que_falha();
    } catch (const std::exception& e) {
        std::cout << "capturei: " << e.what() << "\n";
    }
    std::cout << "fim do main (o destrutor do externo roda agora)\n";
    return 0;
}
