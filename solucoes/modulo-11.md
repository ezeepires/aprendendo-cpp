# Soluções · Módulo 11

## ex01 · optional

```cpp
std::optional<int> para_inteiro(const std::string& texto) {
    std::size_t pos = 0;

    try {
        const int valor = std::stoi(texto, &pos);
        if (pos != texto.size()) {
            return std::nullopt;
        }
        return valor;
    } catch (const std::exception&) {
        return std::nullopt;
    }
}
```

## ex02 · variant

```cpp
std::string descrever(const std::variant<int, double, std::string>& valor) {
    if (std::holds_alternative<int>(valor)) {
        return "int: " + std::to_string(std::get<int>(valor));
    }
    if (std::holds_alternative<double>(valor)) {
        std::ostringstream os;
        os << std::get<double>(valor);        // 3.5 vira "3.5"
        return "double: " + os.str();
    }
    return "texto: " + std::get<std::string>(valor);
}
```

> Cuidado: `std::to_string(3.5)` devolve `"3.500000"`. Para o formato esperado,
> use `std::ostringstream` (ou `std::format` em C++20).

Versão com `std::visit` e `if constexpr`:

```cpp
std::string descrever(const std::variant<int, double, std::string>& valor) {
    return std::visit([](const auto& v) -> std::string {
        using T = std::decay_t<decltype(v)>;
        if constexpr (std::is_same_v<T, int>) {
            return "int: " + std::to_string(v);
        } else if constexpr (std::is_same_v<T, std::string>) {
            return "texto: " + v;
        } else {
            std::ostringstream os;
            os << v;
            return "double: " + os.str();
        }
    }, valor);
}
```

## ex03 · move semantics

```cpp
Buffer(Buffer&& outro) noexcept : dados_(std::move(outro.dados_)) {
    ++movimentos_;
}

Buffer& operator=(Buffer&& outro) noexcept {
    dados_ = std::move(outro.dados_);
    ++movimentos_;
    return *this;
}
```

> Note a lista de inicialização: `dados_(std::move(outro.dados_))` move
> diretamente na construção. No `operator=`, `dados_` já existe, então a
> atribuição de movimento do `vector` cuida do resto.
