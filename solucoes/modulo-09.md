# Soluções · Módulo 09

## ex01 · dividir

```cpp
int dividir(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("divisão por zero");
    }
    return a / b;
}
```

## ex02 · string para inteiro

```cpp
int para_inteiro(const std::string& texto) {
    std::size_t pos = 0;
    int valor = 0;

    try {
        valor = std::stoi(texto, &pos);
    } catch (const std::exception&) {
        throw std::invalid_argument("valor inválido: '" + texto + "'");
    }

    if (pos != texto.size()) {
        throw std::invalid_argument("valor inválido: '" + texto + "'");
    }
    return valor;
}
```

> `std::stoi("42abc")` devolve 42 e para em `pos == 2`. Verificar `pos` é o que
> distingue conversão total de parcial.

## ex03 · RAII

```cpp
ContadorRecurso() {
    ++ativos_;
    ++criados_;
}

~ContadorRecurso() {
    --ativos_;
}
```
