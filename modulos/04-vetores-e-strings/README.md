# 04 · Vetores e strings

> Objetivo: guardar muitos valores e manipular texto com `std::vector`,
> `std::string` e o `for` de intervalo.

## 1. `std::vector`: o array que cresce

```cpp
#include <vector>

std::vector<int> notas;                 // vazio
std::vector<int> idades = {20, 31, 45}; // com valores
std::vector<double> pesos(5, 1.0);      // 5 elementos, todos 1.0
```

Operações essenciais:

```cpp
notas.push_back(10);        // adiciona no fim
notas.size();               // quantos elementos (size_t, sem sinal)
notas[0];                   // acesso (sem checagem de limites)
notas.at(0);                // acesso com checagem (lança exceção se não existir)
notas.front(); notas.back();
notas.pop_back();           // remove o último
notas.clear();              // apaga tudo
notas.empty();              // true se size() == 0
```

> **Atenção:** `size()` devolve `std::size_t`, que é **sem sinal**. Comparar
> `int i < v.size()` gera aviso com `-Wall -Wextra`. Use `std::size_t` ou o
> `for` de intervalo.

### Percorrer

```cpp
for (std::size_t i = 0; i < notas.size(); ++i) {
    std::cout << notas[i] << "\n";
}

for (int nota : notas) {              // por valor (cópia)
    std::cout << nota << "\n";
}

for (int& nota : notas) {             // por referência: pode alterar
    nota += 1;
}

for (const auto& nota : notas) {      // leitura sem cópia (o mais comum)
    std::cout << nota << "\n";
}
```

`v.size()` devolve `size_t`, então o laço com índice mais seguro é:

```cpp
for (std::size_t i = 0; i < v.size(); ++i)
```

## 2. `std::string`

Texto é uma sequência de `char` com várias facilidades:

```cpp
#include <string>

std::string nome = "Ana";
nome.size();              // 3
nome.empty();             // false
nome[0];                  // 'A'
nome += " Silva";         // concatena
nome.substr(0, 3);        // "Ana"
nome.find("Silva");       // posição, ou std::string::npos
nome.replace(0, 3, "Joana");
std::stoi("42");          // string → int
std::to_string(42);       // int → string
```

`std::getline(std::cin, nome)` lê até a quebra de linha (aceita espaços).

### Comparação e busca

```cpp
if (nome == "Ana") ...
if (nome.find("Si") != std::string::npos) ...
```

`npos` é o "não encontrado". Nunca compare com `-1`.

## 3. Arrays de C (por que evitar)

```cpp
int v[5] = {1, 2, 3, 4, 5};   // tamanho fixo, não sabe o próprio tamanho
```

Funcionam, mas não carregam o tamanho, não crescem e decaem para ponteiro ao
serem passados para funções. Em C++ moderno prefira `std::vector` e
`std::array` (tamanho fixo, com `.size()`).

## 4. Algoritmos prontos (prévia do módulo 07)

```cpp
#include <algorithm>
#include <numeric>

std::sort(v.begin(), v.end());                  // ordena crescente
std::reverse(v.begin(), v.end());               // inverte
int soma = std::accumulate(v.begin(), v.end(), 0);
auto it = std::find(v.begin(), v.end(), 42);    // procura
```

## 5. Matrizes

```cpp
std::vector<std::vector<int>> matriz(3, std::vector<int>(4, 0));
matriz[1][2] = 7;
```

Ou achatada: `std::vector<int> m(linhas * colunas);` com `m[l * colunas + c]`.

## 6. Erros comuns

1. `v[v.size()]` — o último índice válido é `size() - 1`.
2. Guardar `v.data()` ou referência a elemento e depois dar `push_back`
   (o vetor pode realocar e invalidar tudo).
3. Loop `for (int i = 0; i <= v.size(); ++i)`.
4. Esquecer `#include <string>` / `<vector>`.
5. Usar `std::string` com aspas simples: `'texto'` é `char` (e nem compila).

## Exercícios

`make test MODULO=04` · soluções em [`solucoes/modulo-04.md`](../../solucoes/modulo-04.md).

1. **ex01_media** — média de um vetor de `double`.
2. **ex02_maior** — maior elemento (sem usar `std::max_element`, para treinar o laço).
3. **ex03_inverter** — inverta uma string.
4. **ex04_vogais** — conte vogais (maiúsculas e minúsculas).
