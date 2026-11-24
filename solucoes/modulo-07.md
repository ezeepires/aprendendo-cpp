# Soluções · Módulo 07

## ex01 · pares

```cpp
std::vector<int> pares(const std::vector<int>& valores) {
    std::vector<int> resultado;
    resultado.reserve(valores.size());

    std::copy_if(valores.begin(), valores.end(), std::back_inserter(resultado),
                 [](int x) { return x % 2 == 0; });
    return resultado;
}
```

## ex02 · contar palavras

```cpp
std::map<std::string, int> contar_palavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::istringstream ss(texto);
    std::string palavra;
    while (ss >> palavra) {
        ++contagem[palavra];
    }
    return contagem;
}
```

## ex03 · decrescente

```cpp
std::vector<int> ordenar_decrescente(std::vector<int> valores) {
    std::sort(valores.begin(), valores.end(), std::greater<>{});
    return valores;
}
```

## ex04 · mediana

```cpp
double mediana(std::vector<int> valores) {
    if (valores.empty()) return 0.0;

    std::sort(valores.begin(), valores.end());
    const std::size_t meio = valores.size() / 2;

    if (valores.size() % 2 == 0) {
        return (valores[meio - 1] + valores[meio]) / 2.0;
    }
    return static_cast<double>(valores[meio]);
}
```

> `(a + b) / 2` com dois `int` faria divisão inteira. O `2.0` (ou um
> `static_cast<double>` antes) força o resultado real.
