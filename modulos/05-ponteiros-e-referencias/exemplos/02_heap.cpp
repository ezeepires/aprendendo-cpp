// Heap com new/delete — e por que evitar.
#include <iostream>

int main() {
    // Um inteiro no heap
    int* p = new int(7);
    std::cout << "*p = " << *p << "\n";
    *p = 8;
    std::cout << "agora *p = " << *p << "\n";
    delete p;                      // liberar!
    p = nullptr;                   // evitar ponteiro solto

    // Array dinâmico
    int n = 5;
    int* v = new int[n];
    for (int i = 0; i < n; ++i) {
        v[i] = i * i;
    }
    std::cout << "vetor: ";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    delete[] v;                    // delete[] para arrays
    v = nullptr;

    // A mesma coisa, sem gerenciar memória na mão:
    std::cout << "(comparar com std::vector no módulo 04)\n";
    return 0;
}
