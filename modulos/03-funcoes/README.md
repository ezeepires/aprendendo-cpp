# 03 · Funções

> Objetivo: dividir o programa em partes pequenas e reutilizáveis, entender
> passagem por valor e por referência, valores padrão, sobrecarga e recursão.

## 1. Definindo e chamando

```cpp
#include <iostream>

int soma(int a, int b) {      // tipo de retorno, nome, parâmetros
    return a + b;
}

void imprimir_linha() {       // void = não devolve nada
    std::cout << "-----\n";
}

int main() {
    imprimir_linha();
    std::cout << soma(2, 3) << "\n";   // 5
    imprimir_linha();
}
```

Uma função deve fazer **uma coisa** e ter um nome que diga qual é essa coisa.

## 2. Por valor x por referência

```cpp
void por_valor(int x) { x = 99; }          // mexe numa CÓPIA

void por_referencia(int& x) { x = 99; }    // mexe no original

void somente_leitura(const std::string& s) { /* não copia e não altera */ }
```

Regra prática:

| Situação | Use |
|---|---|
| Tipos pequenos (`int`, `double`, `char`) | por valor |
| Tipos grandes (`std::string`, `std::vector`) que você só lê | `const&` |
| Precisa alterar o argumento | `&` |
| Precisa devolver vários valores | `&` de saída, `std::tuple` ou `struct` |

```cpp
void dividir(int a, int b, int& quociente, int& resto) {
    quociente = a / b;
    resto = a % b;
}
```

## 3. Parâmetros com valor padrão

```cpp
double potencia(double base, int expoente = 2) {
    double resultado = 1.0;
    for (int i = 0; i < expoente; ++i) resultado *= base;
    return resultado;
}

potencia(3.0);      // 9   (usa o padrão 2)
potencia(2.0, 10);  // 1024
```

Valores padrão ficam **no fim** da lista de parâmetros.

## 4. Sobrecarga (overload)

Várias funções com o mesmo nome e assinaturas diferentes:

```cpp
int soma(int a, int b)             { return a + b; }
double soma(double a, double b)    { return a + b; }
int soma(int a, int b, int c)      { return a + b + c; }
```

O compilador escolhe pela quantidade/tipo dos argumentos. **Não** faça sobrecarga
mudando só o tipo de retorno.

## 5. Recursão

Uma função que chama a si mesma. Precisa sempre de um **caso base**.

```cpp
long long fatorial(int n) {
    if (n <= 1) return 1;          // caso base
    return n * fatorial(n - 1);    // caso recursivo
}
```

Todo problema recursivo pode ser escrito com laço — mas alguns são naturalmente
recursivos (árvores, divisão e conquista).

## 6. Separando declaração e definição

Em projetos maiores, cada `.cpp` tem seu `.hpp`:

```cpp
// matematica.hpp
#pragma once
int soma(int a, int b);
```

```cpp
// matematica.cpp
#include "matematica.hpp"
int soma(int a, int b) { return a + b; }
```

```bash
g++ main.cpp matematica.cpp -o programa
```

## 7. `inline` e `constexpr`

- `inline`: permite definir a função no header sem erro de múltiplas definições.
- `constexpr`: a função pode ser avaliada em tempo de compilação.

```cpp
constexpr int quadrado(int x) { return x * x; }
int vetor[quadrado(3)];   // tamanho 9, calculado na compilação
```

## 8. Erros comuns

1. Esquecer o `return` em função que não é `void` (comportamento indefinido).
2. Passar `const&` e tentar alterar dentro da função.
3. Recursão sem caso base → *stack overflow*.
4. Achar que passar um `std::vector` por valor é barato — ele é **copiado**.
5. Nomear parâmetro igual à variável global (shadowing) e se confundir.

## Exercícios

`make test MODULO=03` · soluções em [`solucoes/modulo-03.md`](../../solucoes/modulo-03.md).

1. **ex01_dobrar** — altere um valor através de referência.
2. **ex02_fatorial** — implemente recursivamente.
3. **ex03_potencia** — com expoente padrão 2.
4. **ex04_trocar** — troque dois valores usando referências.
