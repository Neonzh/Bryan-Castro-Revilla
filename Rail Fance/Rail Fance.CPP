# include <iostream>
# include <string>
# include <stdlib.h>
using namespace std;

string cifrado_vallas(int v, string text) {
	int elm_ola, cant_olas, tam, real_tam,z,cont;
	string txt_alm,z1;
	elm_ola = (v * 2) - 2;// 6 elementos en las olas
	tam = text.size();// 21 tamaño
	cant_olas = tam / elm_ola; //4
	real_tam = cant_olas * elm_ola;// 24
	z = real_tam - tam;//3
	cont = 0;
	z1 = "z";

	while (cont <= z) {
		text = text + z1;
		cont += cont;
	}
	return text;
		
	
}

int main() {
	int v=4;//4
	string text="enelmundohaypocagente";


	cout << cifrado_vallas(v, text);
}