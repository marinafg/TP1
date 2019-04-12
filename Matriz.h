#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz
{
	private:
		int _linhas;
		int _colunas;
		
	public:
		Matriz(); // cria uma matriz vazia com n�meros de linhas e colunas iguais a 0
		Matriz(int = 0, int = 0, const double &valor = 0); /*cria uma matriz com 
												  			n�mero de linhas e colunas iguais aos recebidos pelos argumentos e com todos
												  			os valores da matriz preenchidos com a vari�vel valor.*/
		Matriz(const Matriz &m);  //construtor de c�pia
		~Matriz(); // destrutor 
		void set_colunas();
		void set_linhas();
		
	protected:
};

#endif
