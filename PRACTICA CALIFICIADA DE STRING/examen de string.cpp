1.
#include <iostream>
#include <string.h>
using namespace std;

void separador(string txt,int cadena){
  string div;

  for(int i=0;i<size(txt);i++){
  div=txt.substr(i,4);
  cout << div<<endl;
  i=i+4;
    while(size(div)!=4){
      txt.insert(i,"X");
    }
  }
}

int main() {
  string txt ;
  int cadena;
  cout << "Escriba caracteres: ";
  getline(cin, txt);
  cout << "ingrese bloques:";
  cin>> cadena;
  cout<<endl;
  cout << txt<<endl;

  separador(txt,cadena);
  
}


2.
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string num = "5486312";
    int a = stoi(num);
    cout << a ;
    return 0;
} 

3. 
#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int inte;
  string txt;

  cout<<"ingrese valores al entero: ";
  cin>> inte;

  txt = std::to_string(inte);
  cout <<"la convergencia seria: "<< txt << endl;
}

