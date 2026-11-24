# Soluções · Módulo 02

## ex01 · conceito

```cpp
std::string classificar(int nota) {
    if (nota < 0 || nota > 100) return "?";
    if (nota >= 90) return "A";
    if (nota >= 80) return "B";
    if (nota >= 70) return "C";
    if (nota >= 60) return "D";
    return "F";
}
```

## ex02 · soma dos pares

```cpp
long long soma_pares(int n) {
    long long soma = 0;
    for (int i = 2; i <= n; i += 2) {
        soma += i;
    }
    return soma;
}
```

Alternativa matemática (sem laço): `n / 2 * (n / 2 + 1)` para `n >= 0`.

## ex03 · dígitos

```cpp
int contar_digitos(long long numero) {
    if (numero < 0) numero = -numero;
    if (numero == 0) return 1;

    int digitos = 0;
    while (numero > 0) {
        numero /= 10;
        ++digitos;
    }
    return digitos;
}
```

> O caso `0` precisa de tratamento especial: o `while` nunca entraria.

## ex04 · primo

```cpp
bool eh_primo(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
```

> `i * i <= n` evita `std::sqrt` e testa só até a raiz. Se `n` fosse `int` muito
> grande, `i * i` poderia estourar — por isso usei `long long`.
