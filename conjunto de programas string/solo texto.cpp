1.

#include <iostream>
#include <string>
using namespace std;

int mod(int a, int b) {
  if (a >= 0)
    return a - (a / b) * b;
  else
    return a - ((a / b) - 1) * b;
}

string rot_cif(string txt,int clave){
  string alm;
  string alfa="abcdefghijklmnopqrstuwxyz";
  int j=0,comp;
  for(int i=0;i<size(txt);i++){
      while(txt[i]!=alfa[j]){
        j++;
      }
      comp=j+clave;
      if(comp>size(alfa)){
        comp=mod(comp,size(alfa));
        txt[i]=alfa[comp];
      }
      else{
        txt[i]=alfa[comp];
      }
      j=0;
  }
  return txt;
}

string rot_des(string txt,int clave){
  string alm;
  string alfa="abcdefghijklmnopqrstuwxyz";
  int j=0,comp;
  for(int i=0;i<size(txt);i++){
      while(txt[i]!=alfa[j]){
        j++;
      }
      comp=j-clave;
      if(comp>size(alfa)){
        comp=mod(comp,size(alfa));
        txt[i]=alfa[comp];
      }
      else{
        txt[i]=alfa[comp];
      }
      j=0;
  }
  return txt;
}

int main() {
  int rot=13;
  string txt,abc;
  txt="casademiamigo";

  txt=rot_cif(txt,rot);
  cout<<txt<<endl;
   txt=rot_des(txt,rot);
  cout<<txt;
 
}


2. 

int main() {
  string a,b,c;
  a="Pedro ";
  b="Quispe";
  c=a+b;

  cout<<"nombre y apellido: "<<c;
 
}

3. 

#include <iostream>
#include <string>
using namespace std;

void ahorcado(string txt,string invi){
  string letra,cuerpo="O!!////";
  int tam=0,pos=0,jugada=1,posl,cont=0,ava;
  while(tam<size(txt)){
    invi.insert(tam,"x");
    tam++;
  }
  
  cout<<"la palabra oculta: "<<invi<<endl;

  while(jugada==1){
      cout<<"elija una posicion: ";
        cin>>posl;
      cout<<"elija una letra: ";
        cin>>letra;
        if(txt.find(letra,posl)<size(txt)){
          cout<<"si"<<endl;
          pos=txt.find(letra,posl);
          invi.replace(pos,1,letra);
          cout<<"la palabra oculta: "<<invi<<endl;
        }
        else{
          cout<<"no"<<endl;
          cout<<cuerpo[cont]<<endl;
          cont++;
          if(cont>size(cuerpo)){
            jugada=0;
          }
        }
  }
  
}

int main() {

  string  texto,invicible;

  texto="esternocleidomastoideo";

  ahorcado(texto,invicible);

}

4. 

#include <iostream>
#include <string>
using namespace std;

string txt(string t){
  int mitad;
  cout<<size(t)<<endl;
  mitad=size(t)/2;
  for(int i=0;i<mitad;i++){
    t.replace(i,1,"*");
  }
  return t;
}

int main() {
  string  texto;
  texto="esternocleidomastoideo";

  cout<<txt(texto);
  
}

5.

#include <cstring>
#include <iostream>

using namespace std;

string cambio(string texto){
  int tam=size(texto);
  for(int i=0;i<tam;i++){
      if(texto[i]== ',' or texto[i]== ';' or texto[i]== '.' or texto[i]== ':' or texto[i]== '[' or texto[i]== ']' or texto[i]== '(' or texto[i]== ')' or texto[i]== '{' or texto[i]== '}' or texto[i]== '/' or texto[i]== '-' or texto[i]== '_'){
        texto.replace(i,1," ");
      }
    }
  return texto;
}


int main()
{
  string texto;
  texto="caminar(despues de almuerzo),dormir,[noche]";
  int longi=texto.length();
  char *ptr2 = new char[ longi + 1 ];
  texto=cambio(texto);
  cout<<"separacion: "<<texto<<endl;
  texto.copy(ptr2,longi,0);
  cout << "\nel char es: " << ptr2 << endl;

  cout << "El toque es:" << endl;
  char *token = strtok(ptr2," ");
  while (token)
    {
        cout << token << endl;
        token = strtok(0," ");
    }
    

}

6.

#include <cstring>
#include <iostream>

using namespace std;

int main()
{
  string texto="hola que ashe";
  string::const_iterator itera1= texto.end();
  
  while(itera1 !=texto.begin()){
    cout<<*itera1;
    itera1--;
  }
}

7.

//no funciona
#include <iostream>
using namespace std;

void ordena(string a)
{
    for(int i=0;i<size(a);i++)
    {
        for (int j=i;j<size(a);j++)
        {

            if (a[i] > a[j])
            {
                int aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
        }
    }
}

int main() {
  string a="94132";
    
    ordena(a);
    cout << "Lista ordenada:" << endl;
    for(int i=0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}



