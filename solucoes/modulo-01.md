# Soluções · Módulo 01

## ex01 · saudação

```cpp
std::string saudacao(const std::string& nome) {
    if (nome.empty()) {
        return "Olá, pessoa desconhecida!";
    }
    return "Olá, " + nome + "!";
}
```

## ex02 · temperatura

```cpp
double para_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double para_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
```

> Repare no `9.0 / 5.0`: se fosse `9 / 5`, a divisão seria inteira e o resultado errado.

## ex03 · par ou ímpar

```cpp
bool eh_par(int numero) {
    return numero % 2 == 0;
}
```

> `-4 % 2` é `0` em C++, então negativos funcionam. Mas `-3 % 2` é `-1`, não `1`:
> por isso compare com `0`, nunca com `1`.

## ex04 · círculo

```cpp
double area_circulo(double raio) {
    return std::numbers::pi * raio * raio;
}

double circunferencia(double raio) {
    return 2.0 * std::numbers::pi * raio;
}
```
