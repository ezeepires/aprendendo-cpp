# Soluções · Módulo 10

## ex01 · salvar linhas

```cpp
bool salvar_linhas(const std::string& caminho,
                   const std::vector<std::string>& linhas) {
    std::ofstream out(caminho);
    if (!out) return false;

    for (const auto& linha : linhas) {
        out << linha << '\n';
    }
    return static_cast<bool>(out);
}
```

## ex02 · ler linhas

```cpp
std::vector<std::string> ler_linhas(const std::string& caminho) {
    std::vector<std::string> linhas;
    std::ifstream in(caminho);
    if (!in) return linhas;

    std::string linha;
    while (std::getline(in, linha)) {
        linhas.push_back(linha);
    }
    return linhas;
}
```

## ex03 · contar palavras

```cpp
int contar_palavras(const std::string& caminho) {
    std::ifstream in(caminho);
    if (!in) return 0;

    int total = 0;
    std::string palavra;
    while (in >> palavra) {
        ++total;
    }
    return total;
}
```
