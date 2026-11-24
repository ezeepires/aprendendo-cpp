// Endereços, desreferência e nullptr.
#include <iostream>

void incrementar(int* p) {
    if (p != nullptr) {
        *p += 1;
    }
}

int main() {
    int x = 42;
    int* p = &x;

    std::cout << "valor de x:  " << x << "\n";
    std::cout << "endereço:    " << p << "\n";
    std::cout << "via *p:      " << *p << "\n";

    *p = 100;
    std::cout << "depois de *p = 100, x = " << x << "\n";

    incrementar(&x);
    std::cout << "depois de incrementar, x = " << x << "\n";

    int* nulo = nullptr;
    incrementar(nulo);            // não faz nada, sem crash
    std::cout << "nullptr tratado com segurança\n";

    std::cout << "tamanho de um ponteiro: " << sizeof(p) << " bytes\n";
    return 0;
}
