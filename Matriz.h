#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz
{
	private:
		int _numeroLinhas;
		int _numeroColunas;
		
	public:
		Matriz(); // cria uma matriz vazia com números de linhas e colunas iguais a 0
		Matriz(int = 0, int = 0, const double &valor = 0); /*cria uma matriz com 
												  			número de linhas e colunas iguais aos recebidos pelos argumentos e com todos
												  			os valores da matriz preenchidos com a variável valor.*/
		Matriz(const Matriz &m);  //construtor de cópia
		~Matriz(); // destrutor 
		void setCols();
		void setRows();
		int getRows();
		int getCols();
		
	protected:
};

#endif
