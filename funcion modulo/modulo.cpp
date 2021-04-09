#include <iostream>
using namespace std;

int division(int a, int b) {
	if (a >= 0)
		return a - (a / b) * b;//asignacion de el algoritmo de la division
	else
		return a - ((a / b) - 1) * b;//asignacion de el algoritmo de la division si es menor a 0
}
int main() {
  int a=-21,b=12;
  
  cout<<division(a,b);
}