// Agenda de contatos — esqueleto do projeto final.
//
// Já funciona em memória (adicionar, listar, buscar, remover).
// TODO: separar em contato.hpp/agenda.hpp, persistir em CSV e tratar
// entradas inválidas com mais cuidado.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

struct Contato {
    std::string nome;
    std::string telefone;
    std::string email;

    bool valido() const {
        return !nome.empty() && !telefone.empty() && !email.empty();
    }
};

std::string minusculo(std::string texto) {
    std::transform(texto.begin(), texto.end(), texto.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return texto;
}

class Agenda {
public:
    bool adicionar(const Contato& contato) {
        if (!contato.valido() || email_existe(contato.email)) {
            return false;
        }
        contatos_.push_back(contato);
        return true;
    }

    std::vector<Contato> listar() const {
        std::vector<Contato> copia = contatos_;
        std::sort(copia.begin(), copia.end(),
                  [](const Contato& a, const Contato& b) { return a.nome < b.nome; });
        return copia;
    }

    std::vector<Contato> buscar(const std::string& termo) const {
        std::vector<Contato> achados;
        const std::string alvo = minusculo(termo);
        for (const auto& c : contatos_) {
            if (minusculo(c.nome).find(alvo) != std::string::npos) {
                achados.push_back(c);
            }
        }
        return achados;
    }

    bool remover(const std::string& email) {
        const auto it = std::find_if(contatos_.begin(), contatos_.end(),
                                     [&](const Contato& c) { return c.email == email; });
        if (it == contatos_.end()) return false;
        contatos_.erase(it);
        return true;
    }

    bool email_existe(const std::string& email) const {
        return std::any_of(contatos_.begin(), contatos_.end(),
                           [&](const Contato& c) { return c.email == email; });
    }

    std::size_t tamanho() const { return contatos_.size(); }

    // TODO: implemente carregar() e salvar() usando std::ifstream/ofstream,
    // no formato nome,telefone,email.
    bool carregar(const std::string& caminho) {
        (void)caminho;
        return false;
    }

    bool salvar(const std::string& caminho) const {
        (void)caminho;
        return false;
    }

private:
    std::vector<Contato> contatos_;
};

void mostrar(const std::vector<Contato>& contatos) {
    if (contatos.empty()) {
        std::cout << "(nenhum contato)\n";
        return;
    }
    int i = 1;
    for (const auto& c : contatos) {
        std::cout << i++ << ". " << c.nome << " | " << c.telefone
                  << " | " << c.email << "\n";
    }
}

int main() {
    Agenda agenda;
    const std::string arquivo = "dados/contatos.csv";

    if (!agenda.carregar(arquivo)) {
        std::cout << "(começando com agenda vazia)\n";
    }

    bool executando = true;
    while (executando) {
        std::cout << "\n1) Adicionar  2) Listar  3) Buscar  4) Remover  "
                     "5) Salvar  0) Sair\n> ";

        int opcao = -1;
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(10'000, '\n');
            std::cout << "Opção inválida.\n";
            continue;
        }
        std::cin.ignore(10'000, '\n');

        switch (opcao) {
            case 1: {
                Contato c;
                std::cout << "Nome: ";
                std::getline(std::cin, c.nome);
                std::cout << "Telefone: ";
                std::getline(std::cin, c.telefone);
                std::cout << "Email: ";
                std::getline(std::cin, c.email);

                if (agenda.adicionar(c)) {
                    std::cout << "✔ Contato adicionado (" << agenda.tamanho()
                              << " no total).\n";
                } else {
                    std::cout << "✘ Não foi possível adicionar "
                                 "(dados inválidos ou email repetido).\n";
                }
                break;
            }
            case 2:
                mostrar(agenda.listar());
                break;
            case 3: {
                std::string termo;
                std::cout << "Buscar por nome: ";
                std::getline(std::cin, termo);
                mostrar(agenda.buscar(termo));
                break;
            }
            case 4: {
                std::string email;
                std::cout << "Email do contato a remover: ";
                std::getline(std::cin, email);
                std::cout << (agenda.remover(email) ? "✔ Removido.\n"
                                                    : "✘ Não encontrado.\n");
                break;
            }
            case 5:
                std::cout << (agenda.salvar(arquivo) ? "✔ Salvo.\n"
                                                     : "✘ Falha ao salvar (TODO).\n");
                break;
            case 0:
                executando = false;
                std::cout << "Até logo!\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    }
    return 0;
}
