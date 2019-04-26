#include "Matriz.h"
#include <iostream>
using namespace std;


Matriz::Matriz(int numeroLinhas, int numeroColunas, const double &valor){
	_numeroColunas = numeroColunas;
	_numeroLinhas = numeroLinhas;
	val = new double*[numeroLinhas];
	for (int i=0; i<numeroLinhas; i++){
		val[i] = new double[numeroColunas];
		for (int j = 0; j<numeroColunas; j++){
			val[i][j] = valor;
		}
	}
}

Matriz::Matriz()
{
	_numeroColunas = 0;
	_numeroLinhas = 0;
	val = NULL;
}

Matriz::~Matriz()  // destrutor
{
	for (int i = 0; i<_numeroLinhas; i++){
		delete[] val[i];
	}
	delete[] val;
}

Matriz::Matriz(const Matriz &m){    //construtor de copia
    _numeroColunas = m._numeroColunas;
    _numeroLinhas = m._numeroLinhas;
    if (m.val){
    	val = new double*[_numeroLinhas];
    	for (int i = 0; i<_numeroLinhas; i++){
    		val[i] = new double[_numeroColunas];
		}
		for (int i = 0; i<_numeroLinhas; i++){
			for(int j = 0; j<_numeroColunas; j++){
				val[i][j] = m.val[i][j];
			}
		}
	}
}

void Matriz::setCols(){
	cin >> _numeroColunas;
}

void Matriz::setRows(){
	cin >> _numeroLinhas;
}

int Matriz::getCols() const {
	return _numeroLinhas;
}

int Matriz::getRows() const {
	return _numeroColunas;
}

void Matriz::eye(int Linha, int Coluna){  //cria matriz identidade
	for (int i = 0; i < _numeroLinhas; i++){
		for (int j = 0; j < _numeroColunas; j++){
			if (i == j){
				val[i][j] = 1;
			}else{
				val[i][j] = 0;
			}
		}
	}
}

void Matriz::zeros(){
  for(int i=0; i<_numeroLinhas; i++){
    for(int j=0; j<_numeroColunas; j++)
      val[i][j] = 0;
    }
}

Matriz Matriz::operator+(const Matriz& a) const{
	if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "operacao invalida. matrizes de dimencoes diferentes." << endl;
	}
	else {
		Matriz resp(a._numeroLinhas, a._numeroColunas);
		
	}
}
