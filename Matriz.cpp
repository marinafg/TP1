#include "Matriz.h"
#include <iostream>
using namespace std;


Matriz::Matriz(int linhas, int colunas, const double &valor){
	_numeroColunas = colunas;
	_numeroLinhas = linhas;
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
//	_numeroColunas = new int;
//	_numeroLinhas = new int;
}

void Matriz::setCols(){
	cin >> _numeroColunas;	
}

void Matriz::setRows(){
	cin >> _numeroLinhas;
}
