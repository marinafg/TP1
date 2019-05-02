#include <iostream>
#include "Matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz A(3,4,2);
	Matriz B(3,4,3);
	Matriz C;
	C = A + B;
	C.printMatriz();
	return 0;
}
