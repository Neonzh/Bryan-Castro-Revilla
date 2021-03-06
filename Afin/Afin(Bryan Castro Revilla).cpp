#include <iostream>
#include<cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Afin
{
private:
    int c1;
    int c2;

public:
    string txt;
    string alf;
    Afin(int,int,string,string);
    string afin_cifrado();
    string afin_desifrado();
    int random(int);
    int MCD(int, int);
    int mod(int, int);
    int euclides_ex(int, int);
    string emisor_abc(string, string, int, int);
    string receptor_abc(string, string, int, int);

    



};

Afin::Afin(int _x, int _y, string _pal,string _alf)
{
    c1 = _x;
    c2 = _y;
    txt = _pal;
    alf = _alf;
}

int Afin::random(int c1) {

    while (MCD(c1, size(alf)) != 1) {
        srand(time(NULL));
        c1 = rand() % size(alf);
    }
    
    return c1;
}

int Afin::MCD(int a, int b) {
    int x, result, r, c;
    r = 1;
    c = 0;
    x = 0;
    while (r != 0) {
        x = a / b;
        r = a - x * (b);
        if (r == 0) {
            break;
        }
        if (b == 1) {

            break;
        }
        a = b;
        b = r;
        c = c + 1;
    }
    result = b;
    return result;
}

int Afin::mod(int a, int b) {
    if (a >= 0)
        return a - (a / b) * b;
    else
        return a - ((a / b) - 1) * b;
}

int Afin::euclides_ex(int a, int b) {
    int q, r, result, x, y, pos1, pos2;
    q = 0;
    r = 0;
    int olx1, oly1, oly2, olx2;
    olx1 = 0;
    oly1 = 1;
    oly2 = 0;
    olx2 = 1;
    pos1 = a;
    pos2 = b;
    while (b > 0) {
        q = a / b;
        r = a - q * (b);
        x = olx2 - q * olx1;
        y = oly2 - oly1 * q;
        a = b;
        b = r;
        olx2 = olx1;
        olx1 = x;
        oly2 = oly1;
        oly1 = y;
    }
    x = olx2;
    y = oly2;
    if (pos1 < pos2)
        x = olx2;
    else
        x = oly2;
    result = x;
    return result;
}

string Afin::emisor_abc(string pal, string alf, int code, int code2) {
    int operacion = 0;
    int tam = size(alf), piv;
    string pos;

    for (int i = 0; i < size(pal); i++) {
        for (int j = 0; j < tam; j++) {
            if (pal[i] == alf[j]) {
                piv = j;
                piv = (code * piv) + code2;
                if (piv >= tam) {
                    piv = mod(piv, tam);
                }
                pos = alf[piv];
                pal.replace(i, 1, pos);
                break;
            }
        }
    }
    return pal;
}

string Afin::receptor_abc(string pal, string alf, int code_inv, int  code2) {
    int operacion = 0;
    int tam = size(alf), piv, modu, modu2;
    string pos;
    modu = mod(code_inv, tam);

    for (int i = 0; i < size(pal); i++) {
        for (int j = 0; j < tam; j++) {
            if (pal[i] == alf[j]) {
                piv = j;
                piv = modu * (piv - code2);
                modu2 = mod(piv, tam);
                pos = alf[modu2];
                pal.replace(i, 1, pos);
                break;
            }
        }
    }
    return pal;
}

string Afin::afin_cifrado() {
    int tam_alf = size(alf);
    bool play = true;

    c1=random(c1);

    while (play) {
        cout << "continuo" << endl;
        cout << "tu clave 1 es: " << c1 << endl;
        if (c2 > tam_alf) {//dropea r
            cout << "se a??adira modulo: ";
            c2 = mod(c2, tam_alf);
            cout << c2 << endl;
        }
        cout << "tu clave 2 es: " << c2 << endl;
        txt = emisor_abc(txt, alf, c1, c2);
        play = false;
        break;
    }
    return txt;
}

string Afin::afin_desifrado() {
    int tam_alf = size(alf);
    int clave = 0;
    int q = 0;

    clave = euclides_ex(c1, tam_alf);
    txt = receptor_abc(txt, alf, clave, c2);
    return txt;
}





int main() {
    string alf = "abcdefghijklmnopqrstuvwxyz().:0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ,+-";
    string txt = "las leyes de la fisica son 3: LA PRIMERA es la ley de inercia para los cuerpos que estan en reposo o no tienen una velocidad constante,LA SEGUNDA es el movimiento ya que si un cuerpo tiene varias fuerzas ejerciondo sobre el , este tendra una fuerza resultante, LA tercera habla sobre la friccion.";
    int clave1=0 , clave2 = 0;

    cout << "ingrese el dato b(clave 2): ";
    cin >> clave2;

    Afin p1 = Afin(clave1, clave2,txt,alf);

    

    txt = p1.afin_cifrado();
    cout << "la oracion cifrada es:" << txt << endl;
    txt = p1.afin_desifrado();
    cout << "la oracion es:" << txt << endl;

}