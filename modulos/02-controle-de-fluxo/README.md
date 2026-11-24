# 02 · Controle de fluxo

> Objetivo: fazer o programa tomar decisões (`if`, `switch`) e repetir trabalho
> (`for`, `while`, `do-while`).

## 1. `if`, `else if`, `else`

```cpp
int nota = 75;

if (nota >= 90) {
    std::cout << "A\n";
} else if (nota >= 80) {
    std::cout << "B\n";
} else if (nota >= 70) {
    std::cout << "C\n";
} else {
    std::cout << "Reprovado\n";
}
```

A ordem importa: o primeiro `if` verdadeiro "ganha" e o resto é ignorado.
Repare que não precisamos testar `nota < 90` no segundo ramo — já sabemos que é falso.

### Operadores lógicos

```cpp
if (idade >= 18 && tem_documento) { ... }   // AND
if (chovendo || nevando) { ... }            // OR
if (!logado) { ... }                        // NOT
```

Cuidado com a diferença entre `&`/`&&` e `|`/`||`: as versões duplas fazem
**curto-circuito** (param de avaliar quando já sabem a resposta). Use sempre as duplas
em condições.

## 2. `switch`

Bom quando você compara **o mesmo valor inteiro ou caractere** com várias opções.

```cpp
char operacao = '+';

switch (operacao) {
    case '+':
        std::cout << "soma\n";
        break;                     // sem break, "cai" no próximo case
    case '-':
        std::cout << "subtração\n";
        break;
    default:
        std::cout << "desconhecida\n";
        break;
}
```

Esquecer o `break` é o bug clássico do `switch`. Em C++17+ você pode declarar a
variável dentro do switch: `switch (int x = f(); x)`.

## 3. `for` clássico

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << i << " ";     // 0 1 2 3 4
}
```

Três partes: inicialização; condição (enquanto verdadeira); incremento.
Escopo: `i` só existe dentro do laço.

## 4. `while` e `do-while`

```cpp
int n = 5;
while (n > 0) {        // testa ANTES de entrar
    std::cout << n << " ";
    --n;
}

int tentativas = 0;
do {                   // executa pelo menos uma vez
    ++tentativas;
} while (tentativas < 3);
```

Use `while` quando **não sabe** quantas repetições serão; `for` quando sabe.

## 5. `break` e `continue`

```cpp
for (int i = 0; i < 10; ++i) {
    if (i == 5) break;      // sai do laço inteiro
    if (i % 2 == 0) continue;  // pula para o próximo i
    std::cout << i << " ";  // 1 3
}
```

## 6. Laços aninhados e padrões

```cpp
// Triângulo de asteriscos
for (int linha = 1; linha <= 4; ++linha) {
    for (int coluna = 1; coluna <= linha; ++coluna) {
        std::cout << '*';
    }
    std::cout << '\n';
}
```

## 7. Erros comuns

1. `while (n > 0)` sem alterar `n` dentro → laço infinito.
2. `for (int i = 0; i <= v.size(); ++i)` → acessa uma posição além do fim
   (deve ser `<`, não `<=`).
3. Esquecer `break` no `switch`.
4. Usar `=` em vez de `==` na condição.
5. Comparar `double` com `==` — sempre use tolerância.

## Exercícios

Rode `make test MODULO=02`. Soluções em [`solucoes/modulo-02.md`](../../solucoes/modulo-02.md).

1. **ex01_nota** — converta nota numérica em conceito A–F.
2. **ex02_soma_pares** — some os pares de 1 até `n`.
3. **ex03_digitos** — conte os dígitos de um número.
4. **ex04_primo** — descubra se um número é primo.
