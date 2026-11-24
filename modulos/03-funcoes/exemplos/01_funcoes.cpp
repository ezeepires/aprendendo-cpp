// Funções: valor, referência e retorno.
#include <iostream>
#include <string>

int ao_quadrado(int x) {
    return x * x;
}

void dobrar(int& valor) {
    valor *= 2;
}

// Devolve dois resultados por referência.
void dividir(int a, int b, int& quociente, int& resto) {
    quociente = a / b;
    resto = a % b;
}

// Recebe texto grande sem copiar.
std::size_t tamanho(const std::string& texto) {
    return texto.size();
}

int main() {
    std::cout << "5 ao quadrado = " << ao_quadrado(5) << "\n";

    int numero = 10;
    dobrar(numero);
    std::cout << "10 dobrado = " << numero << "\n";

    int q = 0, r = 0;
    dividir(17, 5, q, r);
    std::cout << "17 / 5 = " << q << " resto " << r << "\n";

    std::cout << "tamanho = " << tamanho("programar") << "\n";
    return 0;
}
