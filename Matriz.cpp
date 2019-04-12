#include "Matriz.h"
#include <iostream>
using namespace std;


Matriz::Matriz(int linhas, int colunas, const double &valor){
	_colunas = colunas;
	_linhas = linhas;
}

Matriz::Matriz()
{
}

Matriz::~Matriz()
{
}

Matriz::Matriz(const Matriz &m){
}

void Matriz::set_colunas(){
	cin >> _colunas;	
}

void Matriz::set_linhas(){
	cin >> _linhas;
}
