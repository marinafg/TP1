#include "Matriz.h"
#include <iostream>
using namespace std;


Matriz::Matriz(int numeroLinhas, int numeroColunas, const double &valor){
	_numeroColunas = numeroColunas;
	_numeroLinhas = numeroLinhas;
	_valor = valor;
}

Matriz::Matriz()
{
	_numeroColunas = 0;
	_numeroLinhas = 0;
}

Matriz::~Matriz()
{
}

Matriz::Matriz(const Matriz &m){ //construtor de copia
    _numeroColunas = m._numeroColunas;
    _numeroLinhas = m._numeroLinhas;
}

void Matriz::setCols(){
	cin >> _numeroColunas;
}

void Matriz::setRows(){
	cin >> _numeroLinhas;
}

void Matriz::eye(int Linha, int Coluna){
	for (Linha=0; Linha < _numeroLinhas; Linha++){
		for (Coluna=0; Coluna < _numeroColunas; Coluna++){
			if (Linha == Coluna){
				int _valor = 1;
			}else{
				int _valor = 0;
			}
		}
	}
}
