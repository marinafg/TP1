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
	E.eye(3,3); // so roda essa funcao sem crachar o programa se voce criar uma matriz de tamanho definido
    cout << endl;

	Matriz F;  // teste de matriz identidade invalida
	F.eye(3,4);
	cout << endl;

	Matriz G(2,2,2);
	cout << G << endl;
	G.zeros();  // teste da funcao zeros
	cout << G << endl;

	Matriz H(A);
	cout << H << endl;

    Matriz I(2,2,1);
    Matriz J(2,2,3);
    Matriz K;
    K = I*J;  // teste da sobrecarga de operador *
    cout << K << endl;

    Matriz M;
    M = I-J;  // teste da sobrecarga de operador -
    cout << M << endl;

    Matriz N;
    N += I;  // teste da sobrecarga de operador +=
    cout << N << endl;

    M += J;  // teste da sobrecarga de operador +=
    cout << M << endl;

    Matriz O;
    O = M; // teste de sobrecarda de operador =
    cout << O << endl;

    I != J;  // teste de sobrecarga de operador !=

    M == O;  // teste de sobrecarga de operador ==
    cout << endl;

    Matriz P(3,3,0);
    cout << P << endl;
    P.ones();  // teste da funcao ones
    cout << P << endl;

    P *= 2;  // teste de sobrecarga do operador *=
    cout << P << endl;
    P *= E;  // teste de sobrecarga do operador *=
    cout << P << endl;

    Matriz Q(3,3);
    cin >> Q;
    cout << Q << endl;
    Q = ~Q;   // teste de sobrecarga do operador ~
    cout << Q << endl;

    A(2,1) = 10;  // teste de sobrecarga do operador ()
    cout << A << endl;

    cin >> A;   // teste de sobrecarga do operador >>
	cout << A << endl;  // teste de sobrecarga do operador <<

	return 0;
}
