// Herança, métodos virtuais e polimorfismo.
#include <iostream>
#include <memory>
#include <numbers>
#include <string>
#include <vector>

class Forma {
public:
    virtual ~Forma() = default;
    virtual double area() const = 0;
    virtual std::string nome() const = 0;

    void descrever() const {
        std::cout << nome() << " com área " << area() << "\n";
    }
};

class Circulo : public Forma {
public:
    explicit Circulo(double raio) : raio_(raio) {}
    double area() const override { return std::numbers::pi * raio_ * raio_; }
    std::string nome() const override { return "círculo"; }
private:
    double raio_;
};

class Retangulo : public Forma {
public:
    Retangulo(double largura, double altura)
        : largura_(largura), altura_(altura) {}
    double area() const override { return largura_ * altura_; }
    std::string nome() const override { return "retângulo"; }
private:
    double largura_;
    double altura_;
};

int main() {
    std::vector<std::unique_ptr<Forma>> formas;
    formas.push_back(std::make_unique<Circulo>(1.0));
    formas.push_back(std::make_unique<Retangulo>(2.0, 3.0));
    formas.push_back(std::make_unique<Circulo>(0.5));

    double total = 0.0;
    for (const auto& forma : formas) {
        forma->descrever();      // chamada polimórfica
        total += forma->area();
    }
    std::cout << "área total: " << total << "\n";
    return 0;
}
