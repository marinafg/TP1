#include <iostream>
#include "Matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

    Matriz A(3,4,2);
    cout << A << endl; // teste de um construtor parametrico
    Matriz B(3,4,3);   // teste de um construtor parametrico
    Matriz C;          // teste de um construtor padrao
    C = A + B;         // teste de sobrecarga de operador +
    cout << C << endl;
    C -= A;						// teste de sobrecarga de operador -=
    cout << C << endl;

    float auxiliar = A.trace();   // teste da funcao trace, que calcula o traço da matriz
    cout << auxiliar << endl;

    Matriz D;			// teste de construtor padrao
    cout << D << endl; // nao vai imprimir nada porque a matriz e 0 por 0

    Matriz E(3,3);  // teste de construtor parametrico
    E.eye(3,3); // teste de funcao eye, faz com que a matriz vire uma matriz identidade
    cout << endl;

    Matriz F;
    F.eye(3,4);	// teste de matriz identidade invalida
    cout << endl;

    Matriz G(2,2,2);	// teste de construtor parametrico
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
    P.ones();  // teste da funcao ones, que faz os valores da matriz serem todos iguais a 1
    cout << P << endl;

    P *= 2;  // teste de sobrecarga do operador *=
    cout << P << endl;
    P *= E;  // teste de sobrecarga do operador *=
    cout << P << endl;

    Matriz Q(3,3);
    cin >> Q;
    cout << Q << endl;
    Q = ~Q;   // teste de sobrecarga do operador ~, transposta da matriz
    cout << Q << endl;

    A(2,1) = 10;  // teste de sobrecarga do operador (), troca o elemento [2][1] da matriz A por 10
    cout << A << endl;

    cin >> A;   // teste de sobrecarga do operador >>
    cout << A << endl;  // teste de sobrecarga do operador <<

    Matriz R = Q;	// teste de sobrecarga de operador =
    cout << R << endl;

    int numLinhas = A.getRows();	// teste da funcao getRows
    int numColunas = A.getCols();	// teste da funcao getCols
    cout << "numero de linhas: " << numLinhas << " " << "e numero de colunas: " << numColunas << endl;

    Matriz S(2,2);
    cin >> S;
    cout << S << endl;
    float deter = S.det();
    cout << deter << endl;

    return 0;
}
