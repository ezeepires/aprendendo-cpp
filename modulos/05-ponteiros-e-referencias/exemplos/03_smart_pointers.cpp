// std::unique_ptr e std::shared_ptr.
#include <iostream>
#include <memory>
#include <string>

struct Jogador {
    std::string nome;
    Jogador(std::string n) : nome(std::move(n)) {
        std::cout << "criou " << nome << "\n";
    }
    ~Jogador() {
        std::cout << "destruiu " << nome << "\n";
    }
};

void usar_ponteiro_bruto(const Jogador* j) {   // observa, não é dono
    if (j) std::cout << "observando " << j->nome << "\n";
}

int main() {
    {
        auto unico = std::make_unique<Jogador>("Ana");
        usar_ponteiro_bruto(unico.get());

        // auto copia = unico;            // ❌ unique_ptr não copia
        auto transferido = std::move(unico);   // ✅ transfere a posse
        std::cout << "unico ficou nulo? " << (unico == nullptr) << "\n";
    }   // fim do escopo: transferido destrói o Jogador

    std::cout << "---\n";

    {
        auto a = std::make_shared<Jogador>("Bia");
        std::cout << "donos: " << a.use_count() << "\n";
        {
            auto b = a;
            std::cout << "donos agora: " << a.use_count() << "\n";
        }
        std::cout << "depois do bloco: " << a.use_count() << "\n";
    }
    return 0;
}
