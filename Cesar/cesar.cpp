#include <iostream>
#include <string>
using namespace std;

class Cesar
{
  private:
  int clave;

  public:
  string pal;
  Cesar(int,string);
  string cifrar();
  string decifrar();
  int mod(int,int);

};

Cesar::Cesar(int _x, string _pal)
{
    clave=_x;
    pal=_pal;
}

int Cesar::mod(int a,int b){
  if (a >= 0)
        return a - (a / b) * b;
    else
        return a - ((a / b) - 1) * b;
}

string Cesar::cifrar() {
  string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .:[]{}(),;_-";
    int piv = 0,tam1=size(pal),tam2= size(alf);
    string pos;

    for (int i = 0; i < tam1; i++) {
        for(int j=0;j<tam2;j++){
          if(pal[i] == alf[j]){
            piv=j;
            break;
          }
        }
        if (piv + clave > tam2) {
            piv = mod(piv + clave, tam2);
            pos = alf[piv];
            pal.replace(i, 1, pos);
        }
        else {
            pos = alf[piv + clave];
            pal.replace(i, 1, pos);
        }
    }
    return pal;
}

string Cesar::decifrar(){
  string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .:[]{}(),;_-";
    int piv = 0,tam1=size(pal),tam2= size(alf);
    string pos;
    for (int i = 0; i < size(pal); i++) {
        for(int j=0;j<tam2;j++){
          if(pal[i] == alf[j]){
            piv=j;
            break;
          }
        }
        if (piv - clave < 0) {
            piv = mod(piv - clave, size(alf));
            pos = alf[piv];
            pal.replace(i, 1, pos);
        }
        else {
            pos = alf[piv - clave];
            pal.replace(i, 1, pos);
        }
    }

    return pal;
}

int main() {
  string pal = "El poder de un Arconte esta directamente ligado a su nivel de control sobre su nacion. Como resultado, Venti (Barbatos), que viaja como bardo y se niega a controlar directamente a la gente de Mondstadt es extremadamente debil para los estandares de Arconte, mientras que Zarina es extremadamente poderosa.";
  int clave ;

  cout<<"ecriba una clave:";
  cin>>clave;
  cout << endl;

  Cesar p1= Cesar(clave,pal);
  pal=p1.cifrar();
  cout << "la oracion cifrada es:" << pal << endl;
  pal=p1.decifrar();
  cout << "la oracion es:" << pal << endl;

  
}