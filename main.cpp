#include <iostream>
#include "Matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Matriz A(3,4,2);
	cout << A << endl; // teste de um construtor parametrico
	Matriz B(3,4,3);   // teste de um construtor parametrico
	Matriz C;          // teste de um construtor padrao
	C = A + B;         // teste da sobrecarga de operador +
	cout << C << endl;

	Matriz D;
	D.getCols(); // pus um cout na funcao pra imprimir as
	D.getRows(); // paradinhas
	cout << D << endl; // nao vai imprimir nada porque a matriz e 0 por 0

    Matriz E(3,3);
	E.eye(3,3); // so roda essa funcao sem crachar o programa se voce criar uma matriz de tamanho definido NAO SEI PQ
    cout << endl;

	Matriz F;  // teste de matriz identidade invalida
	F.eye(3,4);
	cout << endl;

	Matriz G(2,2,2);
	cout << G << endl;
	G.zeros();  // teste da funcao zeros
	cout << G << endl;

	//Matriz H(const Matriz &A);  TESTE QUE DEU ERRADO TO PENSANDO EM COMO FAZER AINDA
	//H.printMatriz();

	cin >> A;
	cout << A << endl;


	return 0;
}
