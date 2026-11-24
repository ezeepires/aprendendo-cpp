# Soluções · Módulo 03

## ex01 · dobrar

```cpp
void dobrar(int& valor) {
    valor *= 2;
}
```

## ex02 · fatorial

```cpp
long long fatorial(int n) {
    if (n < 0) return 0;        // fora do domínio
    if (n <= 1) return 1;       // caso base
    return n * fatorial(n - 1);
}
```

## ex03 · potência

```cpp
int potencia(int base, int expoente) {
    if (expoente < 0) return 0;
    int resultado = 1;
    for (int i = 0; i < expoente; ++i) {
        resultado *= base;
    }
    return resultado;
}
```

> A definição do exercício já tem `= 2` no cabeçalho. Não repita o valor padrão
> na definição se ele já estiver na declaração do header.

## ex04 · trocar

```cpp
void trocar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Versão sem variável temporária (funciona até com `a` e `b` sendo o mesmo objeto):

```cpp
void trocar(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
```

> Na prática use `std::swap(a, b)` — é otimizado e cobre todos os casos.
