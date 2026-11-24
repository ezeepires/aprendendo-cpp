# 07 · STL — biblioteca padrão

> Objetivo: parar de escrever laços manuais. A STL tem container, iterador e
> algoritmo prontos, testados e rápidos.

## 1. Os três pilares

```
Container  →  guarda os dados        (vector, map, set, ...)
Iterator   →  aponta para um elemento (begin(), end(), ...)
Algorithm  →  faz o trabalho          (sort, find, count, accumulate, ...)
```

```cpp
std::vector<int> v = {5, 3, 9};

std::sort(v.begin(), v.end());              // algoritmo + iteradores
auto it = std::find(v.begin(), v.end(), 9);
```

O intervalo é sempre **meio aberto**: `[begin, end)` — `end` aponta *depois* do último.
Por isso `v.end() - v.begin() == v.size()`.

## 2. Containers essenciais

| Container | Quando usar | Acesso | Inserir no meio |
|---|---|---|---|
| `std::vector` | padrão para quase tudo | O(1) por índice | O(n) |
| `std::array<T,N>` | tamanho fixo conhecido | O(1) | não |
| `std::deque` | inserir/remover nas duas pontas | O(1) | O(n) |
| `std::list` | muitas inserções no meio | O(n) | O(1) |
| `std::map<K,V>` | chave → valor ordenado | O(log n) | O(log n) |
| `std::unordered_map` | chave → valor, ordem irrelevante | O(1) médio | O(1) |
| `std::set<T>` | valores únicos, ordenados | O(log n) | O(log n) |
| `std::unordered_set` | valores únicos, sem ordem | O(1) médio | O(1) |
| `std::stack` / `std::queue` | LIFO / FIFO | top/front | — |

Regra: **comece com `vector`**. Só troque se tiver motivo (perfil de desempenho,
necessidade de busca por chave, unicidade...).

```cpp
std::map<std::string, int> idade;
idade["Ana"] = 30;              // cria se não existir
idade["Bia"] = 25;

for (const auto& [nome, anos] : idade) {   // structured bindings (C++17)
    std::cout << nome << ": " << anos << "\n";
}

if (idade.contains("Ana")) { ... }          // C++20
```

## 3. Algoritmos que você vai usar sempre

```cpp
#include <algorithm>
#include <numeric>

std::sort(v.begin(), v.end());
std::sort(v.begin(), v.end(), std::greater<>{});   // decrescente
std::reverse(v.begin(), v.end());
std::find(v.begin(), v.end(), 42);                 // iterador ou end()
std::count(v.begin(), v.end(), 7);
std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
std::any_of / all_of / none_of
std::min_element / max_element
std::accumulate(v.begin(), v.end(), 0);
std::transform(...)                                // mapear
std::copy_if(...)                                  // filtrar
std::remove_if + erase                            // remover (erase-remove idiom)
std::unique + erase                               // remover duplicados consecutivos
```

Remover elementos de verdade:

```cpp
v.erase(std::remove_if(v.begin(), v.end(),
                       [](int x) { return x < 0; }),
        v.end());
```

`std::remove_if` só move os elementos; o `erase` é que reduz o tamanho.

## 4. Lambdas

Uma função anônima, útil para passar comportamento:

```cpp
auto dobro = [](int x) { return x * 2; };

int limite = 10;
auto pequeno = [limite](int x) { return x < limite; };  // captura por valor
auto mutavel = [&contador](int x) { contador += x; };   // captura por referência
```

Formas de captura: `[]` nada, `[=]` tudo por valor, `[&]` tudo por referência,
`[a, &b]` misto. Prefira capturar explicitamente — fica mais claro e evita
referência pendurada.

## 5. Escolhendo o container

```
Preciso de sequência e acesso por índice?      → vector
Preciso de tamanho fixo?                        → array
Preciso buscar por chave?                       → unordered_map (ou map se ordenado)
Preciso de elementos únicos?                    → unordered_set / set
Preciso de fila ou pilha?                       → queue / stack
Preciso de prioridade?                          → priority_queue
```

## 6. Erros comuns

1. Guardar iterador e depois inserir/remover no container → iterador invalidado.
2. `std::sort` em `std::list` (não tem iterador aleatório) — use `.sort()` do próprio list.
3. Esquecer `#include <algorithm>` / `<numeric>`.
4. Usar `[]` em `map` só para consultar — isso **cria** a chave. Use `.find()` ou `.contains()`.
5. `remove_if` sem `erase` — o container mantém o tamanho antigo.

## Exercícios

`make test MODULO=07` · soluções em [`solucoes/modulo-07.md`](../../solucoes/modulo-07.md).

1. **ex01_pares** — filtre pares (use `copy_if` ou `remove_if`).
2. **ex02_palavras** — conte ocorrências com `std::map`.
3. **ex03_decrescente** — ordene de forma decrescente.
4. **ex04_mediana** — calcule a mediana (cuidado com vetor par).
