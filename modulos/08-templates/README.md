# 08 · Templates

> Objetivo: escrever código uma vez e usar com vários tipos, sem perder desempenho
> nem segurança de tipos.

## 1. O problema

Sem templates, você duplicaria funções:

```cpp
int     maior(int a, int b)       { return a > b ? a : b; }
double  maior(double a, double b) { return a > b ? a : b; }
std::string maior(const std::string& a, const std::string& b) { ... }
```

Com template:

```cpp
template <typename T>
T maior(T a, T b) {
    return a > b ? a : b;
}

maior(3, 7);                       // T = int
maior(2.5, 1.5);                   // T = double
maior(std::string("a"), std::string("b"));   // T = std::string
```

O compilador **gera uma função diferente para cada tipo** usado (instanciação).
Não há custo em tempo de execução — o código é tão rápido quanto escrito à mão.

## 2. Dedução e parâmetros

```cpp
template <typename T, typename U>
auto somar(T a, U b) {        // tipos podem ser diferentes
    return a + b;             // o tipo de retorno é deduzido
}
```

Você também pode ser explícito: `maior<double>(2, 3.5)`.

Cuidado: `maior(3, 7.5)` **não compila**, porque `T` não pode ser `int` e `double`
ao mesmo tempo. Use dois parâmetros de tipo ou converta antes.

## 3. Classes template

```cpp
template <typename T>
class Pilha {
public:
    void push(const T& valor) { dados_.push_back(valor); }

    T pop() {
        T valor = dados_.back();
        dados_.pop_back();
        return valor;
    }

    bool vazia() const { return dados_.empty(); }
    std::size_t tamanho() const { return dados_.size(); }

private:
    std::vector<T> dados_;
};

Pilha<int> p;
p.push(10);
Pilha<std::string> nomes;
```

## 4. Onde definir templates

O compilador precisa ver a **definição** no momento de instanciar. Por isso
templates costumam ficar inteiros no header (`.hpp`), não separados em `.cpp`.

## 5. Conceitos (C++20)

Conceitos documentam e restringem o que `T` precisa saber fazer:

```cpp
#include <concepts>

template <typename T>
concept Numerico = std::integral<T> || std::floating_point<T>;

template <Numerico T>
T dobro(T x) { return x * 2; }

dobro(3);      // ok
dobro(1.5);    // ok
// dobro("oi");  // erro de compilação com mensagem clara
```

Antes dos conceitos existia **SFINAE** com `std::enable_if` — funciona, mas é bem
menos legível. Comece pelos conceitos.

## 6. Quando **não** usar

- Se só existe um tipo concreto, template é complexidade sem retorno.
- Templates aumentam o tempo de compilação e o tamanho do binário.
- Erros de template são longos: leia a **primeira** linha do erro, não a última.

## 7. Erros comuns

1. Pôr a definição do template no `.cpp` e só a declaração no header → erro de link.
2. Passar tipos incompatíveis e receber um erro gigante.
3. Usar `>` `>` sem espaço pré-C++11: `vector<vector<int>>` (hoje é ok).
4. Esquecer que `T` é copiado: em parâmetros grandes use `const T&`.
5. Fazer template "por fazer" — sem uso concreto, é só ruído.

## Exercícios

`make test MODULO=08` · soluções em [`solucoes/modulo-08.md`](../../solucoes/modulo-08.md).

1. **ex01_maior** — função genérica.
2. **ex02_soma** — soma de vetor genérico.
3. **ex03_par** — classe `Par<T>` com `maior()` e `trocar()`.
