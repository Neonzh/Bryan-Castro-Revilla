# include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string cifrado(string a) {

    int tam, fil, col, piv, piv2, conteo, cont;
    string pal,pal1;
    tam = a.size();
    conteo = 0;
    fil = 5;
    col = 3;
    piv = 0;
    piv2 = 0;
    cont = 0;
    // y+l2
    for (int j = 0; j <= tam; j++) {

        if (j == piv2 and piv < col) {
            pal = a[j];
            pal1 += pal;
            piv2 = piv2 + fil;
            piv = piv + 1;
        }
        if (j == tam-1) {
            conteo = conteo + 1;
            piv2 = cont + 1;
            piv = 0;
            j = cont;
            cont = cont + 1;
            if (conteo == fil) {
                j = tam-1;
            }
        }
    }
    return pal1;

}

string decifrado(string b) {
    int tam, fil, col, piv, piv2, conteo, cont;
    string pal, pal1;
    tam = b.size();
    conteo = 0;
    fil = 5;
    col = 3;
    piv = 0;
    piv2 = 0;
    cont = 0;

    for (int j = 0; j <= tam; j++) {

        if (j == piv2 and piv < fil) {
            pal = b[j];
            pal1 += pal;
            piv2 = piv2 + col;
            piv = piv + 1;
        }
        if (j == tam-1) {
            conteo = conteo + 1;
            piv2 = cont + 1;
            piv = 0;
            j = cont;
            cont = cont + 1;
            if (conteo == col) {
                j = tam-1;
            }
        }
    }
    return pal1;

}
int main() {

    string a;
    a = "hola como estas"; // h e c


    a= cifrado(a);
    decifrado(a);

    //cout << cifrado(a)<<endl;
    //cout << decifrado(a);
    
}