# 05 · Ponteiros e referências

> Objetivo: entender onde os dados vivem na memória, como acessá-los por endereço
> e como **não** vazar memória usando smart pointers.

## 1. O modelo de memória

```
┌──────────────┐  alta velocidade, tamanho fixo, liberada sozinha
│    Stack     │  variáveis locais, parâmetros
├──────────────┤
│     Heap     │  memória dinâmica: new / malloc, você controla
└──────────────┘
```

```cpp
int x = 42;      // na stack
int* p = &x;     // p guarda o ENDEREÇO de x
*p = 43;         // desreferência: acesso o valor guardado em x
```

- `&x` → "endereço de x"
- `*p` → "valor no endereço p"

## 2. Ponteiros

```cpp
int* p = nullptr;   // ponteiro que não aponta para nada (use nullptr, não NULL ou 0)
if (p != nullptr) { /* seguro */ }

int a = 1, b = 2;
p = &a;
std::cout << *p;    // 1
p = &b;
std::cout << *p;    // 2
```

Ponteiro para `const` x `const` ponteiro:

```cpp
const int* p1 = &a;   // não posso alterar *p1, posso mudar p1
int* const p2 = &a;   // posso alterar *p2, não posso mudar p2
const int* const p3 = &a;  // nada muda
```

## 3. Ponteiros e arrays

```cpp
int v[3] = {10, 20, 30};
int* p = v;          // decai para &v[0]

p[0]      // 10
*(p + 1)  // 20  (aritmética de ponteiros)
```

Por isso `std::vector` é melhor: sabe o tamanho e não decai.

## 4. Heap: `new` e `delete`

```cpp
int* p = new int(42);       // aloca 1 int no heap
delete p;                   // libera

int* v = new int[10];       // aloca array
delete[] v;                 // libera array (delete[] !)
```

Regras de ouro:

1. Todo `new` precisa de exatamente um `delete`; todo `new[]`, um `delete[]`.
2. Nunca use depois de `delete` (*use-after-free*).
3. Nunca dê `delete` duas vezes (*double free*).
4. Prefira **não usar `new` diretamente** (veja smart pointers).

## 5. Referências

Uma referência é um **apelido** para uma variável existente:

```cpp
int a = 10;
int& r = a;      // r é outro nome para a
r = 20;
std::cout << a;  // 20
```

Diferenças para ponteiro:

| | Referência | Ponteiro |
|---|---|---|
| Pode ser nula | ❌ | ✅ |
| Pode ser "re-apontada" | ❌ | ✅ |
| Precisa de `*` para acessar | ❌ | ✅ |
| Sintaxe mais limpa | ✅ | ❌ |

Use referência quando o argumento **deve existir**; ponteiro quando "pode não haver".

## 6. Smart pointers (C++11+)

O problema: exceções e `return` antecipado fazem você esquecer o `delete`.

```cpp
#include <memory>

// Dono único: libera sozinho ao sair do escopo
auto p = std::make_unique<int>(42);
std::cout << *p << "\n";

auto vetor = std::make_unique<int[]>(10);   // array
vetor[0] = 7;

// Dono compartilhado: conta referências
auto a = std::make_shared<std::string>("oi");
auto b = a;                  // agora use_count() == 2
// último a sair libera a memória

auto unico = std::make_unique<int>(5);
std::shared_ptr<int> compartilhado = std::move(unico);  // transfere a posse
```

Regra prática moderna: **`std::make_unique` / `std::make_shared` e pronto**.
`new`/`delete` só em código legado ou implementando containers.

## 7. Como escolher

```
Preciso de "nenhum valor"?          → std::optional<T>
Observo sem ser dono?               → T& ou const T&
Preciso de um dono único?           → std::unique_ptr<T>
Preciso de vários donos?            → std::shared_ptr<T>
Só preciso de um array dinâmico?    → std::vector<T>
```

## 8. Erros comuns

1. Esquecer `*` ao usar ponteiro (`p = 5` em vez de `*p = 5`).
2. `delete` em memória da stack (`int x; delete &x;` 💥).
3. Usar `delete` em vez de `delete[]`.
4. Retornar referência/ponteiro para variável local (dangling).
5. Vazar memória: `new` sem `delete` em cada caminho de saída.
6. Comparar ponteiro com `0` em vez de `nullptr`.

## Exercícios

`make test MODULO=05` · soluções em [`solucoes/modulo-05.md`](../../solucoes/modulo-05.md).

1. **ex01_incrementar** — altere um `int` via ponteiro (com checagem de `nullptr`).
2. **ex02_soma_array** — some um array de C recebido como ponteiro.
3. **ex03_criar** — devolva um `std::unique_ptr<int>`.
4. **ex04_trocar_ponteiros** — troque para onde dois ponteiros apontam.
