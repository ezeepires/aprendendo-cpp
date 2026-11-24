# 09 · Exceções e RAII

> Objetivo: separar o caminho feliz do tratamento de erro e garantir que recursos
> sejam liberados sempre — inclusive quando algo dá errado.

## 1. `throw`, `try`, `catch`

```cpp
#include <stdexcept>

int dividir(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("divisão por zero");
    }
    return a / b;
}

int main() {
    try {
        std::cout << dividir(10, 0) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "erro: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "erro genérico: " << e.what() << "\n";
    }
}
```

Pontos importantes:

- Capture **por referência `const&`** — não copia e preserva o tipo real.
- Ordene os `catch` do mais específico para o mais genérico (`std::exception` por último).
- `catch (...)` captura qualquer coisa: use só na borda do programa.

## 2. Hierarquia padrão

```
std::exception
├── std::logic_error
│   ├── std::invalid_argument
│   ├── std::domain_error
│   ├── std::length_error
│   └── std::out_of_range
└── std::runtime_error
    ├── std::range_error
    ├── std::overflow_error
    └── std::underflow_error
```

`logic_error` = erro de programação (o chamador deveria ter evitado).
`runtime_error` = condição externa (arquivo, rede, entrada do usuário).

## 3. Exceções personalizadas

```cpp
class ErroSaldo final : public std::runtime_error {
public:
    explicit ErroSaldo(double faltando)
        : std::runtime_error("saldo insuficiente"), faltando_(faltando) {}

    double faltando() const { return faltando_; }

private:
    double faltando_;
};
```

`final` impede que alguém herde dela — bom para tipos de erro.

## 4. RAII: Resource Acquisition Is Initialization

A ideia mais importante de C++: **um recurso pertence a um objeto**, e o objeto
libera o recurso no destrutor. Como destrutores rodam ao sair do escopo — inclusive
durante uma exceção (*stack unwinding*) — nada vaza.

```cpp
class Arquivo {
public:
    explicit Arquivo(const std::string& nome) : f_(std::fopen(nome.c_str(), "r")) {
        if (!f_) throw std::runtime_error("não abriu " + nome);
    }
    ~Arquivo() { if (f_) std::fclose(f_); }   // sempre executado

    Arquivo(const Arquivo&) = delete;             // sem cópia
    Arquivo& operator=(const Arquivo&) = delete;

private:
    std::FILE* f_;
};

void ler() {
    Arquivo a("dados.txt");
    // se algo lançar exceção aqui, ~Arquivo() ainda fecha o arquivo
}
```

É isso que `std::vector`, `std::string`, `std::unique_ptr` e `std::ofstream` já fazem
por você. Você usa RAII o tempo todo sem perceber.

## 5. Quando lançar e quando devolver erro

| Situação | Escolha |
|---|---|
| Erro excepcional, impossível de continuar | exceção |
| Erro esperado e comum (busca sem resultado, parse) | `std::optional` / `bool` / código de erro |
| Erro que precisa de contexto rico | `std::expected<T, E>` (C++23) ou tipo próprio |

Exceções têm custo quando lançadas (mas ~zero no caminho feliz em implementações
modernas). Não use exceção para controle de fluxo normal.

## 6. `noexcept`

```cpp
void limpar() noexcept;   // promete não lançar
```

Se lançar, o programa chama `std::terminate`. Marque como `noexcept` destrutores,
movimentos e funções simples que realmente não falham — isso permite otimizações
(ex.: `std::vector` prefere mover a copiar durante o crescimento).

## 7. Erros comuns

1. Capturar por valor: `catch (std::exception e)` — *slicing*, perde o tipo derivado.
2. `catch (...)` engolindo tudo silenciosamente.
3. Lançar ponteiro (`throw new ...`) — quem libera?
4. Lançar exceção em destrutor (durante unwinding → `std::terminate`).
5. Usar exceção para "não achei" em um loop quente: isso é fluxo normal.
6. Esquecer de liberar recursos manualmente nos caminhos de erro — use RAII.

## Exercícios

`make test MODULO=09` · soluções em [`solucoes/modulo-09.md`](../../solucoes/modulo-09.md).

1. **ex01_dividir** — lance `std::invalid_argument` para divisor zero.
2. **ex02_para_inteiro** — converta string em `int` lançando em texto inválido.
3. **ex03_recurso** — implemente um contador RAII (aula de destrutor).
