# 11 · C++ moderno

> Objetivo: usar os recursos de C++11/14/17/20/23 que tornam o código mais seguro,
> expressivo e rápido — e reconhecer código antigo quando encontrar.

## 1. `auto` e dedução de tipos

```cpp
auto i = 42;                     // int
auto d = 3.14;                   // double
auto s = std::string{"oi"};      // std::string
auto v = std::vector<int>{1, 2}; // std::vector<int>

for (const auto& [chave, valor] : mapa) { ... }   // structured bindings
```

`auto` reduz ruído, mas não esconda o tipo quando ele importa para quem lê.

## 2. Inicialização uniforme

```cpp
int a{42};
std::vector<int> v{1, 2, 3};
Ponto p{1.0, 2.0};
auto x = int{7};
```

Chaves evitam conversões que perdem dados: `int x{3.9};` **não compila**
(com parênteses, `int x(3.9)` viraria 3 silenciosamente).

## 3. `nullptr`, `enum class`, `override`

```cpp
int* p = nullptr;

enum class Cor { Vermelho, Verde, Azul };
Cor c = Cor::Verde;              // não vira int sozinho

class B : public A {
    void f() const override;     // o compilador confere a assinatura
};
```

## 4. `std::optional`: talvez exista um valor

```cpp
#include <optional>

std::optional<int> para_inteiro(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return std::nullopt;
    }
}

if (auto valor = para_inteiro("42")) {
    std::cout << *valor;
}

para_inteiro("abc").value_or(-1);   // -1
```

Melhor que "devolver -1" quando -1 é um valor válido.

## 5. `std::variant`: um de vários tipos

```cpp
#include <variant>

std::variant<int, double, std::string> v = 42;
v = std::string("oi");

std::holds_alternative<int>(v);
std::get<std::string>(v);
std::get_if<double>(&v);            // ponteiro ou nullptr

std::visit([](const auto& valor) {  // visita com lambda genérica
    std::cout << valor << "\n";
}, v);
```

## 6. Move semantics

Copiar um `std::vector` grande custa. **Mover** apenas transfere o ponteiro interno:

```cpp
std::vector<int> a = {1, 2, 3};
std::vector<int> b = std::move(a);   // b fica com os dados; a fica válido, mas vazio
```

Regras:

- Use `std::move` quando **não vai mais precisar** do objeto.
- `std::move` não move nada: é um `static_cast` para `T&&`; quem move é o construtor/atribuição.
- Não use `std::move` em `return` (atrapalha a elisão de cópia).
- Tipos com destrutor customizado devem declarar move também (regra dos 5).

```cpp
class Buffer {
public:
    Buffer(Buffer&& outro) noexcept
        : dados_(std::move(outro.dados_)) {}

    Buffer& operator=(Buffer&& outro) noexcept {
        dados_ = std::move(outro.dados_);
        return *this;
    }
};
```

## 7. Ranges (C++20)

```cpp
#include <ranges>

auto pares = v | std::views::filter([](int x) { return x % 2 == 0; })
              | std::views::transform([](int x) { return x * x; });

for (int x : pares) std::cout << x << " ";
```

Pipelines preguiçosos: nada é copiado e o trabalho é feito conforme você itera.
Ainda não substitui `std::sort` e amigos, mas evita muitos laços com acumulador.

## 8. `constexpr`, `consteval`, `if constexpr`

```cpp
constexpr int quadrado(int x) { return x * x; }
static_assert(quadrado(5) == 25);

template <typename T>
std::string categoria() {
    if constexpr (std::is_integral_v<T>) return "inteiro";
    else return "outro";
}
```

## 9. Cheat sheet de versões

| Versão | Principais novidades |
|---|---|
| C++11 | `auto`, lambdas, `nullptr`, smart pointers, `range-for`, move |
| C++14 | lambdas genéricas, `make_unique`, `constexpr` relaxado |
| C++17 | `optional`, `variant`, `string_view`, `filesystem`, structured bindings, `if constexpr` |
| C++20 | concepts, ranges, `std::span`, `format`, `<=>`, módulos |
| C++23 | `expected`, `print`, `mdspan`, mais views |

## 10. Erros comuns

1. Usar `std::move` e depois ler o objeto movido (estado "válido, mas não especificado").
2. `const auto&` em um `std::optional` e chamar `->` sem checar.
3. `std::get<T>` em variant com tipo errado → exceção `bad_variant_access`.
4. Achar que `auto` sempre copia — `const auto&` evita cópia.
5. Usar recurso moderno só porque é moderno: legibilidade vem primeiro.

## Exercícios

`make test MODULO=11` · soluções em [`solucoes/modulo-11.md`](../../solucoes/modulo-11.md).

1. **ex01_optional** — conversão que pode falhar, sem exceção.
2. **ex02_variant** — descreva um valor de tipo variável.
3. **ex03_buffer** — implemente construtor e atribuição de movimento.
