# 10 · Arquivos e streams

> Objetivo: ler e escrever arquivos com `std::ifstream`/`std::ofstream`, entender
> o estado dos streams e navegar em diretórios com `std::filesystem`.

## 1. A família de streams

```
std::istream ── std::ifstream   (ler arquivo)
             └─ std::istringstream (ler string)
std::ostream ── std::ofstream   (escrever arquivo)
             └─ std::ostringstream (montar string)

std::cin / std::cout / std::cerr
```

Todos derivam de `std::ios`, então funcionam com `<<`, `>>` e `std::getline`.

## 2. Escrever

```cpp
#include <fstream>
#include <string>

std::ofstream out("saida.txt");          // sobrescreve (trunca)
if (!out) {
    throw std::runtime_error("não consegui abrir para escrita");
}

out << "linha 1\n";
out << 42 << " " << 3.14 << "\n";
out.close();                              // opcional: o destrutor fecha
```

Modos: `std::ios::app` (anexar), `std::ios::binary`, `std::ios::trunc` (padrão).

```cpp
std::ofstream log("log.txt", std::ios::app);
```

## 3. Ler

```cpp
#include <fstream>
#include <iostream>
#include <string>

std::ifstream in("entrada.txt");
if (!in) {
    std::cout << "arquivo não existe\n";
    return 1;
}

// Palavra por palavra
std::string palavra;
while (in >> palavra) { ... }

// Linha por linha
std::string linha;
while (std::getline(in, linha)) {
    std::cout << linha << "\n";
}
```

`while (in >> x)` para quando a leitura falha (fim do arquivo ou dado inválido).
Sempre cheque `if (!arquivo)` depois de abrir.

## 4. Estado do stream

```cpp
in.is_open();     // abriu?
in.good();        // tudo ok
in.eof();         // chegou ao fim
in.fail();        // operação falhou (formato inválido)
in.clear();       // limpa as flags (útil depois de fail/eof)
in.seekg(0);      // volta ao início (leitura)
```

> **Pegadinha:** depois de `eof()` ou `fail()`, o stream fica "travado". Chame
> `clear()` antes de tentar ler de novo.

## 5. `std::filesystem` (C++17)

```cpp
#include <filesystem>
namespace fs = std::filesystem;

fs::path p = "dados/entrada.txt";
fs::exists(p);
fs::is_regular_file(p);
fs::file_size(p);
fs::create_directories("saida/2026");
fs::remove(p);                       // ou remove_all para diretório

for (const auto& entrada : fs::directory_iterator(".")) {
    std::cout << entrada.path() << "\n";
}

// Montar caminhos sem brigar com barras
fs::path arquivo = fs::path("dados") / "entrada.txt";
```

No Ubuntu com `g++` 9+ o filesystem já vem pronto. Em versões antigas era
necessário linkar `-lstdc++fs`.

## 6. Lendo CSV simples

```cpp
std::string linha;
while (std::getline(in, linha)) {
    std::istringstream ss(linha);
    std::string campo;
    std::vector<std::string> campos;
    while (std::getline(ss, campo, ',')) {
        campos.push_back(campo);
    }
    // usa campos[0], campos[1], ...
}
```

## 7. Erros comuns

1. Não checar se o arquivo abriu e usar dados vazios silenciosamente.
2. Misturar `>>` e `getline` sem `ignore()` (igual ao `cin`).
3. Esquecer `std::ios::app` e apagar o arquivo sem querer ao abrir de novo.
4. Ler caminho relativo sem saber qual é o diretório atual.
5. Comparar `getline` com `!= ""` em vez de usar o retorno no `while`.

## Exercícios

`make test MODULO=10` · soluções em [`solucoes/modulo-10.md`](../../solucoes/modulo-10.md).

1. **ex01_salvar** — grave um vetor de linhas em arquivo.
2. **ex02_ler** — leia o arquivo de volta.
3. **ex03_contar_palavras** — conte palavras de um arquivo.
