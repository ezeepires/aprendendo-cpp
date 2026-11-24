# Aprendendo C++ 🚀

Repositório público do meu aprendizado de **C++ no Linux (Ubuntu)**, do zero ao C++ moderno.

A ideia é simples: eu aprendo, escrevo o que entendi, resolvo os exercícios e deixo tudo aqui.
Se você também está aprendendo, sinta-se em casa — pode usar, abrir issues e sugerir melhorias.

> **Compromisso público:** aprender C++ de verdade, um módulo por vez, com código que compila e testes que passam. 🎯

---

## Como começar

```bash
git clone https://github.com/ezeepires/aprendendo-cpp.git
cd aprendendo-cpp
make test        # roda todos os exercícios (no começo, quase tudo falha: é o esperado)
```

### Pré-requisitos (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential git
```

O `build-essential` instala o `g++`, o `make` e as bibliotecas padrão.

Para conferir:

```bash
g++ --version
make --version
```

---

## Como este repositório funciona

Cada módulo tem três partes:

| Pasta | O que tem |
|---|---|
| `README.md` do módulo | A aula: explicação, exemplos comentados e pegadinhas |
| `exemplos/` | Programas completos que compilam e rodam |
| `exercicios/` | Exercícios com **testes automáticos** já prontos |

Os exercícios vêm com um `TODO` e um teste que falha até você implementar a resposta certa.
Assim você sabe na hora se acertou — sem depender de ninguém para corrigir.

```bash
make exemplos             # compila todos os exemplos
make exercicios           # compila todos os exercícios
make test                 # compila e roda os testes
make test MODULO=03       # roda só o módulo 3
make ci                   # compila tudo (exemplos, exercícios e projeto final)
./build/01-fundamentos/exercicios/ex01_ola.exe   # roda um exercício específico
```

As respostas ficam em [`solucoes/`](solucoes/). Tente antes de olhar! 😉

---

## Roadmap

Marque conforme for concluindo.

### Fase 1 — Base da linguagem

- [ ] [01 · Fundamentos](modulos/01-fundamentos/README.md) — compilar, variáveis, tipos, entrada/saída
- [ ] [02 · Controle de fluxo](modulos/02-controle-de-fluxo/README.md) — `if`, `switch`, `for`, `while`
- [ ] [03 · Funções](modulos/03-funcoes/README.md) — parâmetros, referências, sobrecarga, recursão
- [ ] [04 · Vetores e strings](modulos/04-vetores-e-strings/README.md) — `std::vector`, `std::string`, `range-for`

### Fase 2 — Memória e abstração

- [ ] [05 · Ponteiros e referências](modulos/05-ponteiros-e-referencias/README.md) — stack, heap, `new`/`delete`, smart pointers
- [ ] [06 · Structs e classes](modulos/06-structs-e-classes/README.md) — construtores, encapsulamento, herança, polimorfismo
- [ ] [07 · STL](modulos/07-stl/README.md) — containers, iterators, algoritmos, lambdas

### Fase 3 — C++ de verdade

- [ ] [08 · Templates](modulos/08-templates/README.md) — funções e classes genéricas, conceitos
- [ ] [09 · Exceções e RAII](modulos/09-excecoes-e-raii/README.md) — tratamento de erros e gestão de recursos
- [ ] [10 · Arquivos e streams](modulos/10-arquivos-e-streams/README.md) — ler e escrever arquivos, `std::filesystem`
- [ ] [11 · C++ moderno](modulos/11-cpp-moderno/README.md) — `auto`, move semantics, `optional`, `variant`, ranges

### Fase 4 — Consolidar

- [ ] [Projeto final](projeto-final/README.md) — uma aplicação completa de linha de comando

---

## Meu progresso

| Módulo | Aula lida | Exercícios feitos | Revisado |
|:------:|:---------:|:-----------------:|:--------:|
| 01 · Fundamentos | ⬜ | 0/4 | ⬜ |
| 02 · Controle de fluxo | ⬜ | 0/4 | ⬜ |
| 03 · Funções | ⬜ | 0/4 | ⬜ |
| 04 · Vetores e strings | ⬜ | 0/4 | ⬜ |
| 05 · Ponteiros e referências | ⬜ | 0/4 | ⬜ |
| 06 · Structs e classes | ⬜ | 0/4 | ⬜ |
| 07 · STL | ⬜ | 0/4 | ⬜ |
| 08 · Templates | ⬜ | 0/3 | ⬜ |
| 09 · Exceções e RAII | ⬜ | 0/3 | ⬜ |
| 10 · Arquivos e streams | ⬜ | 0/3 | ⬜ |
| 11 · C++ moderno | ⬜ | 0/3 | ⬜ |

---

## Estrutura do projeto

```
aprendendo-cpp/
├── README.md              # este arquivo
├── Makefile               # compila e roda tudo
├── include/teste.hpp      # pequeno framework de testes dos exercícios
├── modulos/
│   └── 01-fundamentos/
│       ├── README.md      # a aula
│       ├── exemplos/      # código pronto para ler e rodar
│       └── exercicios/    # exercícios com testes
├── solucoes/              # respostas comentadas
└── projeto-final/         # projeto integrador
```

## Convenções que uso aqui

- **Padrão:** C++20 (`-std=c++20`).
- **Avisos ligados:** `-Wall -Wextra` — se o compilador reclama, eu conserto.
- **Nada de `using namespace std;`** no código dos módulos, para aprender de onde vem cada coisa.
- **`std::` explícito** sempre que possível.
- Um arquivo = um programa com `main()`, compilado separadamente.
- Comentários em português, código em inglês (padrão do mercado).

## Comandos úteis do dia a dia

```bash
g++ -std=c++20 -Wall -Wextra -g arquivo.cpp -o programa   # compilar
./programa                                                 # executar
gdb ./programa                                             # depurar
make limpar                                                # apagar a pasta build/
```

## Licença

MIT — use, copie, estude. Veja [LICENSE](LICENSE).
