#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz
{
	private:
		int _numeroLinhas;
		int _numeroColunas;
		double **val;

	public:
		Matriz(); // cria uma matriz vazia com números de linhas e colunas iguais a 0
		Matriz(int, int, const double &valor = 0); /*cria uma matriz com
												  			número de linhas e colunas iguais aos recebidos pelos argumentos e com todos
												  			os valores da matriz preenchidos com a variável valor.*/
		Matriz(const Matriz &);  //construtor de cópia
		~Matriz(); // destrutor
		void setCols();
		void setRows();
		int getRows() const;
		int getCols() const;
		void eye(int, int); // cria matriz identidade
		float det(); // calcula o determinante
		float trace(); // calcula o traco
		void zeros(); // cria matriz com tds elementos iguais a 0
		void ones();

		Matriz operator+(const Matriz&) const;
		Matriz operator*(const Matriz&) const;
		Matriz operator-(const Matriz&) const;
		Matriz operator+=(const Matriz&);
		Matriz operator=(const Matriz&);
		bool operator!=(const Matriz&) const;
		bool operator==(const Matriz&) const;
		friend istream& operator >> (istream&, Matriz&);
		friend ostream& operator << (ostream&, const Matriz&);
		Matriz& operator-=(const Matriz&);
		Matriz& operator*=(const Matriz&);
		Matriz operator~();
		Matriz& operator*=(double);
		double& operator()(int, int);
};

#endif
