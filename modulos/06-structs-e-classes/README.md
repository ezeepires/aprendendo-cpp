# 06 · Structs e classes

> Objetivo: criar seus próprios tipos, juntar dados e comportamento, proteger
> invariantes e usar herança e polimorfismo com moderação.

## 1. `struct`: dados agrupados

```cpp
struct Ponto {
    double x = 0.0;
    double y = 0.0;
};

Ponto p{3.0, 4.0};       // inicialização agregada
std::cout << p.x;
```

Em C++, `struct` e `class` são quase iguais: a única diferença é que em `struct`
membros são **públicos** por padrão, em `class` são **privados**.

Convenção: `struct` para pacotes de dados simples; `class` quando há invariantes
a proteger.

## 2. Métodos e `this`

```cpp
struct Retangulo {
    double largura = 0.0;
    double altura = 0.0;

    double area() const {        // const: não altera o objeto
        return largura * altura;
    }

    void escalar(double fator) {  // não é const: altera
        largura *= fator;
        altura *= fator;
    }
};
```

Dentro de um método, `this` é um ponteiro para o próprio objeto.

## 3. Construtores

```cpp
class Conta {
public:
    Conta(std::string titular, double saldo_inicial)
        : titular_(std::move(titular)), saldo_(saldo_inicial) {   // lista de inicialização
        if (saldo_inicial < 0) {
            throw std::invalid_argument("saldo inicial negativo");
        }
    }

    double saldo() const { return saldo_; }

    void depositar(double valor) {
        if (valor <= 0) return;
        saldo_ += valor;
    }

private:
    std::string titular_;
    double saldo_ = 0.0;
};
```

A lista de inicialização (`: membro(valor)`) inicializa direto, sem atribuir depois.
Para membros `const` e referências ela é **obrigatória**.

## 4. Encapsulamento

```cpp
class Temperatura {
public:
    explicit Temperatura(double celsius) : celsius_(celsius) {}

    double celsius() const { return celsius_; }
    double fahrenheit() const { return celsius_ * 9.0 / 5.0 + 32.0; }

    void aquecer(double graus) {
        if (graus < 0) return;         // protege a invariante
        celsius_ += graus;
    }

private:
    double celsius_;                   // ninguém de fora altera direto
};
```

O `explicit` impede conversões implícitas acidentais: `Temperatura t = 30;` não compila.

## 5. `const` nos métodos

- `double area() const` → promete não alterar o objeto; pode ser chamado em objetos `const`.
- Marque como `const` todo método que só lê. É grátis e documenta a intenção.

## 6. Herança e polimorfismo

```cpp
class Forma {
public:
    virtual ~Forma() = default;              // sempre virtual em classe base!
    virtual double area() const = 0;         // pura: Forma é abstrata
    virtual std::string nome() const = 0;
};

class Circulo : public Forma {
public:
    explicit Circulo(double r) : raio_(r) {}
    double area() const override { return std::numbers::pi * raio_ * raio_; }
    std::string nome() const override { return "círculo"; }
private:
    double raio_;
};

class Retangulo : public Forma {
public:
    Retangulo(double l, double a) : largura_(l), altura_(a) {}
    double area() const override { return largura_ * altura_; }
    std::string nome() const override { return "retângulo"; }
private:
    double largura_, altura_;
};
```

Uso polimórfico:

```cpp
std::vector<std::unique_ptr<Forma>> formas;
formas.push_back(std::make_unique<Circulo>(1.0));
formas.push_back(std::make_unique<Retangulo>(2.0, 3.0));

for (const auto& f : formas) {
    std::cout << f->nome() << ": " << f->area() << "\n";
}
```

Três palavras-chave:

| Palavra | Significado |
|---|---|
| `virtual` | a chamada é resolvida em tempo de execução |
| `= 0` | método puro: a classe não pode ser instanciada |
| `override` | confere se você realmente está sobrescrevendo (use sempre!) |

## 7. Regra dos 3/5/0

Se sua classe gerencia um recurso (ponteiro, arquivo, descritor), você provavelmente
precisa definir: destrutor, construtor de cópia, atribuição de cópia (regra dos 3) e,
com move semantics, também as versões `&&` (regra dos 5).

**Regra dos 0:** se não gerencia recurso diretamente, não escreva nenhum desses —
deixe o compilador gerar. É o que você deve buscar na maior parte do tempo.

## 8. Erros comuns

1. Destrutor da classe base não `virtual` → `delete` em `Base*` não chama o derivado (vazamento).
2. Esquecer `override` e escrever a assinatura errada → cria um método novo silenciosamente.
3. Retornar referência a membro local (`const std::string&` para variável da função).
4. Construtor que aceita 1 argumento sem `explicit` → conversões implícitas bizarras.
5. Herdar só para reaproveitar código — **composição** costuma ser melhor.
6. Escrever getters/setters para tudo e quebrar o encapsulamento na prática.

## Exercícios

`make test MODULO=06` · soluções em [`solucoes/modulo-06.md`](../../solucoes/modulo-06.md).

1. **ex01_ponto** — métodos `distancia_ate` e `mover`.
2. **ex02_conta** — depósito, saque com saldo e invariantes.
3. **ex03_retangulo** — `area`, `perimetro` e métodos `const`.
4. **ex04_formas** — herança com `virtual`/`override` e soma de áreas.
