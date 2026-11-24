# Aprendendo C++

Meu estudo de C++ no Linux (Ubuntu), do zero, em arquivos simples.

Cada arquivo é um programa completo. Não tem build system, não tem framework,
não tem pasta escondida: é só abrir, ler, compilar e rodar.

## 1. Instalar o compilador

```bash
sudo apt update
sudo apt install build-essential
```

Confira com `g++ --version`.

## 2. Compilar e rodar

```bash
g++ -std=c++20 -Wall -Wextra aulas/01_primeiro_programa.cpp -o programa
./programa
```

- `-std=c++20` escolhe a versão da linguagem.
- `-Wall -Wextra` liga os avisos: se aparecer aviso, conserte.
- `-o programa` é o nome do executável gerado.

> Dica: use `-o /tmp/programa` enquanto testa, para não encher a pasta
> de executáveis.

## 3. Ordem de estudo

Leia a aula, compile, rode, mude valores e rode de novo.

| # | Aula | Assunto |
|---|------|---------|
| 01 | [aulas/01_primeiro_programa.cpp](aulas/01_primeiro_programa.cpp) | primeiro programa |
| 02 | [aulas/02_variaveis_e_tipos.cpp](aulas/02_variaveis_e_tipos.cpp) | variáveis, tipos, entrada |
| 03 | [aulas/03_condicionais.cpp](aulas/03_condicionais.cpp) | `if`, `switch` |
| 04 | [aulas/04_repeticoes.cpp](aulas/04_repeticoes.cpp) | `for`, `while` |
| 05 | [aulas/05_funcoes.cpp](aulas/05_funcoes.cpp) | funções e recursão |
| 06 | [aulas/06_vetores_e_strings.cpp](aulas/06_vetores_e_strings.cpp) | `vector`, `string` |
| 07 | [aulas/07_classes.cpp](aulas/07_classes.cpp) | struct e class |
| 08 | [aulas/08_arquivos.cpp](aulas/08_arquivos.cpp) | ler e escrever arquivo |

## 4. Exercícios

Depois de cada aula, resolva o exercício correspondente em `exercicios/`.
O enunciado está no topo do arquivo.

```bash
g++ -std=c++20 -Wall -Wextra exercicios/ex01.cpp -o /tmp/ex01
/tmp/ex01
```

Tente sozinho primeiro. Se travar, a resposta está em `solucoes/` — mas
copiar não ensina nada; compare com a sua versão.

Exercícios: `ex01` saudação · `ex02` calculadora · `ex03` conceito ·
`ex04` tabuada · `ex05` fatorial · `ex06` média de números ·
`ex07` conta bancária · `ex08` arquivo.

## 5. Progresso

| Aula | Li e rodei | Exercício | Resolvi |
|------|:----------:|-----------|:-------:|
| 01 primeiro programa | ⬜ | ex01 | ⬜ |
| 02 variáveis e tipos | ⬜ | ex02 | ⬜ |
| 03 condicionais | ⬜ | ex03 | ⬜ |
| 04 repetições | ⬜ | ex04 | ⬜ |
| 05 funções | ⬜ | ex05 | ⬜ |
| 06 vetores e strings | ⬜ | ex06 | ⬜ |
| 07 classes | ⬜ | ex07 | ⬜ |
| 08 arquivos | ⬜ | ex08 | ⬜ |

## Estrutura

```
aprendendo-cpp/
├── README.md      # este arquivo
├── aulas/         # 8 programas comentados
├── exercicios/    # 8 exercícios com enunciado
└── solucoes/      # as respostas
```

## Licença

MIT. Use, copie e estude.
