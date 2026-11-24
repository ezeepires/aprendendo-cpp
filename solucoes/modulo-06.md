# Soluções · Módulo 06

## ex01 · ponto

```cpp
struct Ponto {
    double x = 0.0;
    double y = 0.0;

    double distancia_ate(const Ponto& outro) const {
        const double dx = x - outro.x;
        const double dy = y - outro.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void mover(double dx, double dy) {
        x += dx;
        y += dy;
    }
};
```

## ex02 · conta

```cpp
void depositar(double valor) {
    if (valor > 0.0) {
        saldo_ += valor;
    }
}

bool sacar(double valor) {
    if (valor <= 0.0 || valor > saldo_) {
        return false;
    }
    saldo_ -= valor;
    return true;
}
```

> A ordem das condições importa pouco aqui, mas note que `valor > saldo_` com
> `valor` negativo seria falso — por isso o teste de `valor <= 0` vem primeiro.

## ex03 · retângulo

```cpp
double area() const { return largura_ * altura_; }

double perimetro() const { return 2.0 * (largura_ + altura_); }

void escalar(double fator) {
    largura_ *= fator;
    altura_ *= fator;
}
```

## ex04 · formas

```cpp
// Circulo
double area() const override { return std::numbers::pi * raio_ * raio_; }
std::string nome() const override { return "círculo"; }

// Retangulo
double area() const override { return largura_ * altura_; }
std::string nome() const override { return "retângulo"; }

double total_area(const std::vector<std::unique_ptr<Forma>>& formas) {
    double total = 0.0;
    for (const auto& f : formas) {
        total += f->area();          // chamada virtual
    }
    return total;
}
```

> `const auto&` evita copiar o `unique_ptr` — que, aliás, nem poderia ser copiado.
