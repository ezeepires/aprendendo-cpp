# 01 · Fundamentos

> Objetivo: compilar e executar seu primeiro programa, entender tipos, variáveis,
> constantes e o básico de entrada e saída.

## 1. Como um programa C++ nasce

C++ é uma linguagem **compilada**: o código-fonte (`.cpp`) passa pelo compilador e
vira um executável que a máquina roda direto.

```
hello.cpp  --[ g++ ]-->  hello (executável)  --[ ./hello ]-->  saída
```

```bash
g++ hello.cpp -o hello
./hello
```

Na prática, sempre compile com avisos ligados:

```bash
g++ -std=c++20 -Wall -Wextra -g hello.cpp -o hello
```

## 2. Anatomia de um programa

```cpp
#include <iostream>   // biblioteca de entrada/saída

int main() {                       // ponto de entrada do programa
    std::cout << "Olá, mundo!\n";  // escreve no terminal
    return 0;                      // 0 = sucesso
}
```

- `#include <...>` traz uma biblioteca da biblioteca padrão.
- `main` é obrigatória e é por onde o programa começa.
- `std::cout` é o "console output". `std::` indica que `cout` pertence ao
  namespace `std` (standard).
- `\n` quebra a linha. `std::endl` também quebra, mas **força a descarga do buffer**;
  para texto normal, `\n` é mais rápido e idiomático.

## 3. Tipos fundamentais

| Tipo | Uso | Exemplo |
|---|---|---|
| `int` | inteiros (normalmente 32 bits) | `int idade = 20;` |
| `long long` | inteiros grandes (64 bits) | `long long populacao = 8'000'000'000LL;` |
| `double` | ponto flutuante (precisão dupla) | `double pi = 3.14159;` |
| `float` | ponto flutuante (precisão simples) | `float nota = 9.5f;` |
| `bool` | `true` / `false` | `bool aprovado = true;` |
| `char` | um caractere | `char letra = 'A';` |
| `std::string` | texto | `std::string nome = "Ana";` |

C++ é **fortemente tipado** e **estaticamente tipado**: o tipo é definido na
compilação e não muda. Converta explicitamente quando precisar:

```cpp
double media = 7.5;
int inteira = static_cast<int>(media);   // 7, truncado
```

## 4. Variáveis, `auto` e `const`

```cpp
int contador = 0;
contador = contador + 1;        // pode mudar
contador += 1;                  // forma curta
++contador;                     // idem

auto nome = std::string{"Ana"}; // o compilador deduz o tipo
const int LIMITE = 10;          // não pode ser alterado
constexpr int TAMANHO = 5;      // constante conhecida em tempo de compilação
```

Prefira `const` sempre que o valor não deve mudar: o compilador passa a te ajudar.

## 5. Entrada e saída

```cpp
#include <iostream>
#include <string>

int main() {
    std::string nome;
    int idade = 0;

    std::cout << "Seu nome: ";
    std::getline(std::cin, nome);      // lê a linha inteira (aceita espaços)
    std::cout << "Sua idade: ";
    std::cin >> idade;                 // lê uma palavra/número

    std::cout << "Olá, " << nome << "! Você tem " << idade << " anos.\n";
}
```

> **Pegadinha clássica:** `std::cin >>` deixa o `\n` no buffer. Se depois você usar
> `std::getline`, ela lê uma linha vazia. Solução: `std::cin.ignore();` antes do `getline`.

## 6. Operadores

```cpp
int a = 7, b = 2;

a + b   // 9    soma
a - b   // 5    subtração
a * b   // 14   multiplicação
a / b   // 3    divisão INTEIRA (truncada!)
a % b   // 1    resto da divisão
7.0 / 2 // 3.5  divisão real (pelo menos um double)
```

Comparações (`==`, `!=`, `<`, `>`, `<=`, `>=`) devolvem `bool`. Cuidado: `=` atribui,
`==` compara. Esse é o erro de digitação mais comum da linguagem.

## 7. Números e formatação

```cpp
#include <iomanip>
#include <iostream>

std::cout << std::fixed << std::setprecision(2) << 3.14159 << "\n";  // 3.14
```

## 8. Compilando este módulo

```bash
cd ../..                    # volta para a raiz do repositório
make exemplos MODULO=01
./build/01-fundamentos/exemplos/01_ola.exe
./build/01-fundamentos/exemplos/02_io.exe
./build/01-fundamentos/exemplos/03_tipos.exe
```

## 9. Erros comuns de iniciante

1. Esquecer o `;` no fim da linha.
2. Usar `=` no `if` (`if (x = 5)`).
3. Esquecer `#include <string>` antes de usar `std::string`.
4. Dividir inteiros esperando decimal (`5 / 2` é `2`).
5. Escrever `end1` em vez de `endl` (o número 1 no lugar da letra l).
6. Compilar sem `-Wall`: o compilador avisa, mas você não vê.

## Exercícios

Resolva os arquivos em `exercicios/` e rode `make test MODULO=01`.
As respostas estão em [`solucoes/modulo-01.md`](../../solucoes/modulo-01.md).

1. **ex01_ola** — monte uma saudação.
2. **ex02_temperatura** — converta Celsius para Fahrenheit.
3. **ex03_par_impar** — descubra se um número é par.
4. **ex04_circulo** — calcule a área de um círculo.
