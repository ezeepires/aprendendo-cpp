# Soluções · Módulo 04

## ex01 · média

```cpp
double media(const std::vector<double>& valores) {
    if (valores.empty()) return 0.0;

    double soma = 0.0;
    for (double v : valores) soma += v;
    return soma / static_cast<double>(valores.size());
}
```

Com a STL: `return std::accumulate(valores.begin(), valores.end(), 0.0) / valores.size();`

## ex02 · maior

```cpp
int maior(const std::vector<int>& valores) {
    int maior_valor = valores.front();
    for (int v : valores) {
        if (v > maior_valor) maior_valor = v;
    }
    return maior_valor;
}
```

## ex03 · inverter

```cpp
std::string inverter(const std::string& texto) {
    std::string resultado;
    resultado.reserve(texto.size());
    for (auto it = texto.rbegin(); it != texto.rend(); ++it) {
        resultado.push_back(*it);
    }
    return resultado;
}
```

Ou direto:

```cpp
std::string inverter(std::string texto) {   // por valor: posso alterar
    std::reverse(texto.begin(), texto.end());
    return texto;
}
```

## ex04 · vogais

```cpp
int contar_vogais(const std::string& texto) {
    const std::string vogais = "aeiouAEIOU";
    int total = 0;
    for (char c : texto) {
        if (vogais.find(c) != std::string::npos) ++total;
    }
    return total;
}
```
