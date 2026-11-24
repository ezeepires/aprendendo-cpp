# Soluções · Módulo 05

## ex01 · incrementar

```cpp
void incrementar(int* p) {
    if (p != nullptr) {
        *p += 1;
    }
}
```

## ex02 · soma de array

```cpp
int soma(const int* valores, int quantidade) {
    if (valores == nullptr || quantidade <= 0) return 0;

    int total = 0;
    for (int i = 0; i < quantidade; ++i) {
        total += valores[i];       // == *(valores + i)
    }
    return total;
}
```

## ex03 · unique_ptr

```cpp
std::unique_ptr<int> criar(int valor) {
    return std::make_unique<int>(valor);
}
```

> `return nullptr;` também compila (unique_ptr tem construtor a partir de nullptr),
> mas devolveria um ponteiro vazio — o teste checa justamente isso.

## ex04 · trocar ponteiros

```cpp
void trocar_ponteiros(int*& a, int*& b) {
    int* temp = a;
    a = b;
    b = temp;
}
```

> Sem o `&` em `int*&`, você trocaria apenas as cópias locais dos ponteiros.
