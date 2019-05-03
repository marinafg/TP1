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
    cout << "Digite o numero de colunas: " << endl;
	cin >> _numeroColunas;
	cout << _numeroColunas << endl;
}

void Matriz::setRows(){
    cout << "Digite o numero de linhas: " << endl;
	cin >> _numeroLinhas;
	cout << _numeroLinhas << endl;
}

int Matriz::getCols() const {
    cout << _numeroColunas << endl;
	return _numeroColunas;
}

int Matriz::getRows() const {
    cout << _numeroLinhas << endl;
	return _numeroLinhas;
}

void Matriz::eye(int Linha, int Coluna){  //cria matriz identidade
    if (Linha != Coluna){
        cout << "Matriz invalida. Numero de linhas e diferente do numero de colunas." << endl;
    } else {
        _numeroColunas = Coluna;
        _numeroLinhas = Linha;
        for (int i = 0; i <_numeroLinhas; i++){
            for (int j = 0; j <_numeroColunas; j++){
                if (i == j){
                    val[i][j] = 1;
                }else{
                    val[i][j] = 0;
                }
                cout << val[i][j];
            }
            cout << endl;
        }
    }
}

void Matriz::zeros(){
  for(int i=0; i<_numeroLinhas; i++){
    for(int j=0; j<_numeroColunas; j++)
      val[i][j] = 0;
    }
}

void Matriz::ones(){
	for(int i=0; i<_numeroLinhas; i++){
    for(int j=0; j<_numeroColunas; j++)
      val[i][j] = 1;
    }
}

Matriz Matriz::operator+(const Matriz& a) const{
	if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "Operacao invalida. Matrizes de dimencoes diferentes." << endl;
		return a;
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
       cout << "Operacao invalida. Numero de linhas invalido" << endl;
       return a;
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
		cout << "Operacao invalida. Matrizes de dimencoes diferentes." << endl;
        return a;
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
		cout << "Operacao invalida. Matrizes de dimencoes diferentes." << endl;
		return a;
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
		cout << "Operacao invalida. Matrizes de dimencoes diferentes." << endl;
		return false;
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
        if (cont > 0) {            
			cout << "false" << endl;
            return false;
        } else {
            cout << "true" << endl;
            return true;
        }
	}
}

bool Matriz::operator==(const Matriz& a) const{
    if (_numeroLinhas != a._numeroLinhas || _numeroColunas != a._numeroColunas){
		cout << "Operacao invalida. Matrizes de dimencoes diferentes." << endl;
		return false;
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
        if (cont > 0) {            
			cout << "false" << endl;
            return false;
        } else {
            cout << "true" << endl;
            return true;
        }
	}
}

istream& operator >> (istream& op, Matriz& a){
	cout << "Digite os valores da matriz: " << endl;
	if (a.val != NULL){
		for (int i = 0;  i< a._numeroLinhas; i++){
			delete [] a.val[i];
		}
		delete [] a.val;
	}
	a.val = new double*[a._numeroLinhas];
	for(int j = 0; j<a._numeroLinhas; j++){
		a.val[j] = new double[a._numeroColunas];
		for (int k = 0; k<a._numeroColunas; k++){
			op >> a.val[j][k];
		}
	}
	return op;
}

ostream& operator << (ostream& op, const Matriz& a){
	for (int i = 0; i < a._numeroLinhas; i++){
		for (int j = 0; j < a._numeroColunas; j++){
			cout << a.val[i][j] << ' ';
		}
		cout << endl;
	}
	return op;
}

Matriz& Matriz::operator*=(const Matriz& a){
    if (a._numeroLinhas != a._numeroColunas){
    	cout << "Operacao invalida. Matrizes de dimencoes diferentes." << endl;
	}
	
	else if(a._numeroColunas == a._numeroLinhas){
    Matriz aux(a._numeroLinhas, a._numeroColunas);

    for(int i=0; i<a._numeroLinhas; i++){
      for(int j=0; j<a._numeroColunas; j++)
          aux.val[i][j] = val[i][j];
    }

    for(int i=0; i<a._numeroLinhas; i++) // libera as linhas
        delete[] val[i];
    delete[] val;

    double s = 0;
    val = new double*[a._numeroLinhas];
    for(int i=0; i<a._numeroLinhas; i++){
        val[i] = new double[a._numeroColunas];
        for(int j=0; j< a._numeroColunas; j++){
            val[i][j] = 0;
            for(int k=0; k<_numeroColunas; k++)
                val[i][j] += (aux.val[i][k] * a.val[k][j]);
        }
    }
    _numeroColunas = a._numeroColunas;
    return *this;
}
}

Matriz Matriz::operator~(){
	Matriz aux(_numeroLinhas, _numeroColunas);

    for(int i=0; i<aux._numeroLinhas; i++){
      for(int j=0; j<aux._numeroColunas; j++)
          aux.val[i][j] = val[j][i];
    }
	
	return aux;
}

Matriz& Matriz::operator*=(double xis){
    for(int i=0; i<_numeroLinhas; i++){
      for(int j=0; j<_numeroColunas; j++)
          val[i][j] *= xis;
    }
	
	return *this;
}

double& Matriz::operator()(int l, int c) {
  if(l-1 >= _numeroLinhas || c-1 >= _numeroColunas){
    static Matriz aux(_numeroLinhas, _numeroColunas);
    cout << "Operacao invalida. Dimensao nao pode ser alterada." << endl;
    return aux.val[0][0]; 

  }else{
    return val[l-1][c-1];}
}
