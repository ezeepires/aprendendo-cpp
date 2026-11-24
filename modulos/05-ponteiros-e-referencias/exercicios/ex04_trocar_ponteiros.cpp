// Exercício 04 — Trocar ponteiros
//
// Faça `a` apontar para onde `b` apontava e vice-versa.
// O parâmetro é `int*&`: referência para ponteiro. Sem o `&`, a troca
// aconteceria só em cópias locais.
#include "teste.hpp"

void trocar_ponteiros(int*& a, int*& b) {
    // TODO
}

int main() {
    int x = 1, y = 2;
    int* px = &x;
    int* py = &y;

    trocar_ponteiros(px, py);
    CHECK(px == &y);
    CHECK(py == &x);
    CHECK_IGUAL(2, *px);

    int z = 3;
    int* pz = &z;
    trocar_ponteiros(px, pz);   // agora px aponta para z
    CHECK(px == &z);
    CHECK(pz == &y);
    return teste::resumo("ex04 · trocar ponteiros");
}
