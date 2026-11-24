# Projeto final · Agenda de contatos (CLI)

> Junte tudo o que aprendeu em um programa de verdade: classes, `std::vector`,
> STL, tratamento de erros, arquivos e C++ moderno.

## O que o programa faz

Uma agenda de contatos que roda no terminal e **persiste os dados em CSV**.

```
$ ./agenda
=== Agenda de contatos ===
1) Adicionar  2) Listar  3) Buscar  4) Remover  5) Salvar  0) Sair
> 1
Nome: Ana Silva
Telefone: 11 99999-0000
Email: ana@exemplo.com
✔ Contato adicionado (1 no total).

> 2
1. Ana Silva | 11 99999-0000 | ana@exemplo.com
```

## Requisitos

1. **Adicionar** contato com nome, telefone e email.
   - Nome e telefone não podem ser vazios.
   - Não permitir dois contatos com o mesmo email.
2. **Listar** todos os contatos em ordem alfabética.
3. **Buscar** por parte do nome (case-insensitive).
4. **Remover** por email, pedindo confirmação.
5. **Salvar** e **carregar** automaticamente de `dados/contatos.csv`.
   - Formato: `nome,telefone,email` por linha.
   - Nome com vírgula deve ser tratado (ou rejeitado com mensagem clara).
6. **Estatísticas** no menu: total de contatos e contatos por domínio de email.
7. Tratar entrada inválida sem quebrar: `"abc"` no menu não pode entrar em loop infinito.

## Estrutura sugerida

```
projeto-final/
├── Makefile
├── README.md
├── dados/
│   └── contatos.csv          # criado/atualizado pelo programa
└── src/
    ├── contato.hpp           # struct Contato + validação
    ├── contato.cpp
    ├── agenda.hpp            # class Agenda: vector<Contato> + operações
    ├── agenda.cpp
    └── main.cpp              # menu e loop principal
```

Separar em `.hpp`/`.cpp` não é burocracia: é o que permite testar a `Agenda`
sem passar pelo menu.

## Etapas (faça em ordem, commit a cada uma)

- [ ] **1. Modelo** — `struct Contato` com nome, telefone, email e um método
      `bool valido() const`.
- [ ] **2. Agenda em memória** — `adicionar`, `listar`, `buscar`, `remover`.
- [ ] **3. Menu** — loop com `switch`, leitura robusta (limpar `cin` quando falhar).
- [ ] **4. Persistência** — salvar CSV ao sair e carregar ao iniciar.
- [ ] **5. Polimento** — ordenar com `std::sort`, buscar com `std::search` ou
      `std::string::find`, mensagens claras.
- [ ] **6. Testes manuais** — um roteiro com entradas e saídas esperadas.

## Roteiro de teste manual

```
1) adicionar "Ana" / "1111" / "ana@a.com"     → ok
2) adicionar "Ana" / "2222" / "ana@a.com"     → rejeitado (email duplicado)
3) adicionar ""    / "3333" / "x@x.com"       → rejeitado (nome vazio)
4) listar                                     → mostra Ana
5) buscar "an"                                → encontra Ana
6) remover "ana@a.com" (confirmar)            → remove
7) sair e abrir de novo                       → lista vazia (persistiu)
8) digitar "abc" no menu                      → mensagem de erro, não trava
```

## Critérios de "pronto"

- Compila com `-Wall -Wextra` **sem avisos**.
- Nenhum `new`/`delete` manual no código.
- Nenhum `using namespace std;`.
- Funções com responsabilidade única (menu não faz I/O de arquivo).
- `dados/contatos.csv` sobrevive a fechar e abrir o programa.
- Nenhum caminho de erro derruba o programa.

## Compilar e rodar

```bash
cd projeto-final
make
./agenda
```

O `src/main.cpp` já vem com um esqueleto funcional (menu + lista em memória,
sem persistência). Complete os `TODO`.
