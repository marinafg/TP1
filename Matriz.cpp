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
        for (int i=0; i<_numeroLinhas; i++){
            for (int j = 0; j<_numeroColunas; j++){
                resp.val[i][j] = val[i][j] + a.val[i][j];
            }
        }
        return resp;
	}
}

Matriz Matriz::operator*(const Matriz& a) const{
    if (_numeroColunas != a._numeroLinhas){
       cout << "operacao invalida. numero de linhas invalido" << endl;
    }
    else {
        Matriz resp(_numeroLinhas, a._numeroColunas);
        double aux;
        for (int i=0; i<_numeroLinhas; i++){
            for (int j=0; j<a._numeroColunas; j++){
                aux = 0;
                for (int k=0; k<_numeroLinhas; k++){
                    aux += val[i][k]*a.val[k][j];
                }
                resp.val[i][j] = aux;
            }
        }
        return resp;
    }
}

Matriz Matriz::operator-(const Matriz &a) const {
	if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "operacao invalida. matrizes de dimencoes diferentes." << endl;
	}
	else {
		Matriz resp(a._numeroLinhas, a._numeroColunas);
		for (int i = 0; i<_numeroLinhas; i++){
			for (int j = 0; j<_numeroColunas; j++){
				resp.val[i][j] = val[i][j] - a.val[i][j];
			}
		}
		return resp;
	}
}

Matriz Matriz::operator+=(const Matriz& a) {
    if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "operacao invalida. matrizes de dimencoes diferentes." << endl;
	}
	else {
        for (int i=0; i<_numeroLinhas; i++){
            for (int j = 0; j<_numeroColunas; j++){
                val[i][j] = val[i][j] + a.val[i][j];
            }
        }
        return *this;
	}
}

Matriz Matriz::operator=(const Matriz& a){
    if(this == &a){
        return *this;
    }else{
        if(val != NULL){
          for(int i = 0; i<_numeroLinhas; i++) // libera as linhas
            delete[] val[i];
          delete[] val;
        }
        _numeroLinhas = a._numeroLinhas;
        _numeroColunas = a._numeroColunas;

        val = new double*[_numeroLinhas]; //aloca o numero de linhas da matriz
        for(int i=0; i<_numeroLinhas; i++){ //aloca o numero de colunas para cada linha
            val[i] = new double[_numeroColunas];
            for(int j=0; j<_numeroColunas; j++)
                val[i][j] = a.val[i][j];
        }
        return *this;
    }
}

bool Matriz::operator!=(const Matriz& a) const{
    if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "operacao invalida. matrizes de dimencoes diferentes." << endl;
	}
	else {
        int cont = 0;
        for (int i=0; i<_numeroLinhas; i++){
            for (int j = 0; j<_numeroColunas; j++){
                if (val[i][j] == a.val[i][j]){
                    cont++;
                }
            }
        }
        if (cont > 0) return false;
        else return true;
	}
}

bool Matriz::operator==(const Matriz& a) const{
    if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "operacao invalida. matrizes de dimencoes diferentes." << endl;
	}
	else {
        int cont = 0;
        for (int i=0; i<_numeroLinhas; i++){
            for (int j = 0; j<_numeroColunas; j++){
                if (val[i][j] != a.val[i][j]){
                    cont++;
                }
            }
        }
        if (cont > 0) return false;
        else return true;
	}
}

/*istream& operator >> (istream& tcha, Matriz& a){
	cout << "linhas: ";
	tcha >> a._numeroLinhas;
	cout << "colunas: ";
	tcha >> a._numeroColunas;
	cout << "valores: " << endl;
	if (a.val != NULL){
		for (int i = 0;  < a._numeroLinhas){
			
		}
	}
} */

void Matriz::printMatriz() const{
	for(int i=0; i<_numeroLinhas; i++){
		for(int j=0; j<_numeroColunas; j++){
			cout << val[i][j];
		}
		cout << endl;
	}

}
