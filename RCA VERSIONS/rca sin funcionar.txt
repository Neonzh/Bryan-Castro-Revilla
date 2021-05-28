#include <NTL/ZZ.h>
#include <iostream>
#include<cstring>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <gmpxx.h>
#include <NTL/vector.h>
#include <vector>
#include <random>

using namespace std;
using namespace NTL;


ZZ random(ZZ num) {
    ZZ n;
	n=to_ZZ("1000001");
    num=RandomBnd(n);
    return num;
}

ZZ modulo(ZZ a,ZZ b)
{
	if (a >= 0)
        return a - (a / b) * b;
    else
        return a - ((a / b) - 1) * b;
}

int  modulo_int(int a, int b)
{
	int q,r=1;
  if(b!=0){
    q = a / b;
	  r = a - (q * (b));
  }
	if (r < 0)
	{
		q = q + 1;
		r = b + r;
	}
  return r;
}

ZZ MCD( ZZ a,ZZ b){
  ZZ x,result,r,c;
  r=to_ZZ("1");
  c=to_ZZ("0");
  x=to_ZZ("0");
  while ( r != to_ZZ("0")) {
        x = a / b;
        r = a - x*(b);
        if (r == to_ZZ("0")) {
            break;
        }
        if(b==to_ZZ("1")){

          break;
        }
        a = b;
        b = r;
        c=c+to_ZZ("1");
    }
    result=b;
    return result;
}

ZZ euclides_ex(ZZ a,ZZ b){
  ZZ q,r,result,x,y,pos1,pos2;
  q=to_ZZ("0");
  r=to_ZZ("0");
  ZZ olx1,oly1,oly2,olx2;
  olx1=to_ZZ("0");
  oly1=to_ZZ("1");
  oly2=to_ZZ("0");
  olx2=to_ZZ("1");
  pos1=a;
  pos2=b;
  while (b>to_ZZ("0")){
    q=a/ b;
    r=a-q*(b);
    x=olx2-q*olx1;
    y=oly2-oly1*q;
    a=b;
    b=r;
    olx2=olx1;
    olx1=x;
    oly2=oly1;
    oly1=y;
     }
  x=olx2;
  y=oly2;
  if(pos1<pos2)
    x=olx2;
  else
    x=oly2;
  result=x;
  return result;
}

string string_com(ZZ n)//convierte variables a string
 {
	stringstream buffer;
	buffer << n;
	return buffer.str();
}

int int_com(ZZ n)
 {
	string temp = string_com(n);
	int num = stoi(temp);
	return num;
}



ZZ inversa(ZZ entero, ZZ modulonum)
 {
	if (MCD(entero, modulonum) != to_ZZ("1")) {
		cout << "Este numero no tiene inversa" << endl;
		return to_ZZ("0");
	}

	ZZ modulo_cero , variable, cociente;
	ZZ variable0, variable1;
	variable0 = to_ZZ("0"); variable1 = to_ZZ("1");modulo_cero = modulonum;
	while (entero > to_ZZ("1")) {
		cociente = entero / modulonum;
		variable = modulonum;
		modulonum = modulo(entero, modulonum);
		entero = variable;
		variable = variable0;
		variable0 = variable1 - cociente * variable0;
		variable1 = variable;
	}
	if (variable1 < to_ZZ("0"))
		variable1 += modulo_cero;
	return variable1;
}

ZZ potenciar(ZZ a, ZZ n) {
    if (n == 0)
        return to_ZZ("1");
    ZZ x ;
    x = potenciar(a, n/2);
    if (modulo(n,to_ZZ("2"))== 0)
        return x*x;
    return x*x*a;
}

ZZ d_binario(ZZ  numero){
   ZZ exp,digito,cont,binario;
   ZZ n,n10;
   cont=to_ZZ("1");exp=to_ZZ("0");digito=to_ZZ("1");n=to_ZZ("2");n10=to_ZZ("10");binario=to_ZZ("0");
   while(numero/to_ZZ("2")!=to_ZZ("0"))
   {
           digito=modulo(numero,n);
           binario = binario + digito * potenciar(n10,exp);
           exp++;
           numero=numero/to_ZZ("2");
           cont=cont+to_ZZ("1");
   }
   binario = binario + numero * potenciar(n10,exp);
   cout << "binario: " << binario << endl;
   return cont;
   //11101

}

ZZ exponenciacion(ZZ g,ZZ ah,ZZ n){

    ZZ a,b,comp,r1,r2;
    a=g;
    b=to_ZZ("1");
    comp=to_ZZ("0");
    r1=to_ZZ("1");
    r2=to_ZZ("2");
    if(ah>comp){
        while(ah>comp){
            if(ah==modulo(r1,r2)){
                b=modulo(b*a,n);
            }
            a=modulo(potenciar(a,r2),n);
            ah=ah/r2;
        }
    }
    return b;
}

//ZZ exponenciacion( ZZ m, ZZ mod,  ZZ a)

ZZ  mulmod(ZZ  a, ZZ  b, ZZ m){
   ZZ  x ,y ;
   x=to_ZZ("0");
   y = modulo(a,m);
   while (b > 0) {
      if (modulo(b,to_ZZ("2")) == 1) {
         x = modulo((x + y) , m);
      }
      y = modulo((y * 2) , m);
      b /= 2;
   }
   return x % m;
}

ZZ  modulo_miller(ZZ base, ZZ e, ZZ m) {
   ZZ x ,y ;
   x=to_ZZ("1");
   y = base;
   while (e > 0) {
      if (modulo(e , to_ZZ(2))== 1)
         x = modulo((x * y) , m);
         y = modulo((y * y) , m);
         e = e / 2;
   }
   return modulo(x , m);
}

bool Miller(ZZ p, ZZ iteration) {
   if (p < 2) {
      return false;
   }
   if (p != 2 && modulo(p , to_ZZ("2"))==0) {
      return false;
   }
   ZZ s ;
   s = p - 1;
   while (modulo(s , to_ZZ("2")) == 0) {
      s /= 2;
   }
   for (int i = 0; i < iteration; i++) {
      ZZ a , temp ,mod ,num;
      a = modulo(random(num) , (p - to_ZZ("1")) +to_ZZ("1") );
      temp = s;
      mod = modulo_miller(a, temp, p);
      while (temp != p - 1 && mod != 1 && mod != p - 1) {
         mod = mulmod(mod, mod, p);
         temp *= 2;
      }
      if (mod != p - 1 && modulo(temp , to_ZZ("2")) == 0) {
         return false;
      }
   }
   return true;
}

bool primalidad(ZZ num){
   ZZ iteration;
   iteration = to_ZZ("10");
   if (Miller(num, iteration)){
      return true;
   }
   else{
      return false;
   }
}

void emisor_abc(char pal[], char alf[], ZZ pos[], ZZ* t) {

    int j,tam;
    ZZ cont,cont2,k,m,mod,operacion;
	cont = 0, cont2 = 26;m = 0, mod = 1; operacion = 0; tam = strlen(alf);

	for (int i = 0; i < strlen(pal); i++) {
		j = 0;
		k = 0;
		while (j < strlen(pal)) {
			if (pal[i] == alf[j] && j < strlen(alf)) {
				pos[j] = i;//solamente se toma las posciones de las letras, no las mismas letras
				j = tam;
				*t = j;
			}
			j++;
		}
	}
}

void keys_generator(ZZ* e, ZZ* n, ZZ* pasos, ZZ pos[], ZZ* x) {
	char alf[] = "abcdefghijklmnopqrstuvwxyz().0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ,+-";
	ZZ euler,y,e2,pi,pi2,repos,clave,q_eu,result,rep;
	euler = 0; pi = 0; pi2 = 0; repos = 0; clave = 0; q_eu = 0; result = 1;


    ZZ p,q;
    //p11 y q33
    p = to_ZZ("11"); q = to_ZZ("33");

	if (*pasos == 1) {
		*n = p * (q);
		cout << "el producto de p y q es:" << *n << endl;
		euler = (p - 1) * (q - 1);
		cout << "el fi de euler es :" << euler << endl;
		pi = euler;// 3759525384
		cout << "se generan las claves........." << endl;
		//*e = 323;
		//323
		repos = *e;
		while (pi2 != 1) {
			*e=random(repos);
			if(primalidad(*e)==1){
                pi2 = euler;
                e2 = *e;
                euler=MCD(*e, euler);
                if (pi2 == 1) {
                    *e = e2;
                    euler = pi;
                    break;
                }
			}
			else {
                pi2=0;
			}
		}
		cout << "clave publica: Ce=<N,e> Ce=<" << *n << "," << *e << ">" << endl;
		*x=euclides_ex(euler,*e);
		if(*x<0){
            *x=*x*-1;
            *x=inversa(*x,euler);
		}
		*e = e2;
		cout << "clave privada: Ce=<N,d> Cd=<" << *n << "," << *x << ">" << endl;
		cout << "enviando clave publica......" << endl;
	}
	if (*pasos == 2) {
		cout << "llego un mensaje cifrado" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "resivio los valores:" << pos[i] << endl;
		}
		cout << "decifrando......" << endl;
		cout << "x:" << *x << endl;
		cout << "n:" << *n << endl;
		for (int i = 0; i < 2; i++) {
			result=exponenciacion(pos[i],*x,*n);
			pos[i] = result;
			cout << "los valores decifrados son:" << pos[i] << endl;
		}
	}
}

void emisor(ZZ* e, ZZ* n, ZZ pos[]) {
	char alf[] = "abcdefghijklmnopqrstuvwxyz().0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ,+-";
	char pal[1000] = "HI";
	ZZ tam,result;
    tam; result = 1;
	cout << "resivio clave publica: Ce=<N,e> Ce=<" << *n << "," << *e << ">, sifre su mensaje" << endl;
	emisor_abc(alf, pal, pos, &tam);

	for (int i = 0; i < tam; i++) {
		cout << "las posiciones son:" << pos[i] << endl;
	}


	cout << "cifrando..." << endl;
	for (int i = 0; i < tam; i++) {
		result=exponenciacion(pos[i],*e,*n);
		pos[i] = result;
		cout << "los valores cifrados son:" << pos[i] << endl;
	}
	cout << "enviando valores cifrados......" << endl;


}




int main()
{
   ZZ e,n,x,c;
   ZZ *pos;
   ZZ pasos;
   pasos=1;

   pos = new ZZ [100];
   keys_generator(&e, &n, &pasos, pos, &x);
   emisor(&e, &n, pos);
   pasos = 2;
   keys_generator(&e, &n, &pasos, pos, &x);

}