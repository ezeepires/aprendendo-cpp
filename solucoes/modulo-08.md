# Soluções · Módulo 08

## ex01 · maior genérico

```cpp
template <typename T>
T maior(T a, T b) {
    return a > b ? a : b;
}
```

## ex02 · soma genérica

```cpp
template <typename T>
T soma(const std::vector<T>& valores) {
    T total{};
    for (const auto& valor : valores) {
        total += valor;
    }
    return total;
}
```

> `T total{}` inicializa com zero/vazio do tipo, sem depender de `T` ter construtor
> com `0`.

## ex03 · Par<T>

```cpp
T maior() const { return primeiro_ > segundo_ ? primeiro_ : segundo_; }

T soma() const { return primeiro_ + segundo_; }

void trocar() {
    T temp = primeiro_;
    primeiro_ = segundo_;
    segundo_ = temp;
}
```
