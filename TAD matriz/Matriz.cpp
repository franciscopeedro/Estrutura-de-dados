// Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"

// Aloca espaco para matriz n por m
Matriz::Matriz(int n, int m) {
	lin = n;
	col = m;
	matriz = new int *[lin];
	for(int i =0;i <col;i++){
		matriz[i] = new int [col];
	}
}   

// Destrutor: Libera a memoria da matriz
Matriz::~Matriz() {
	for(int i =0;i<lin;i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}     

// Retorna o valor do elemento [i][j]
int Matriz::valor(int i, int j) {
	return matriz[i][j];
} 

// Atribui valor ao elemento [i][j]
void Matriz::atribui(int valor, int i, int j) {
	matriz[i][j]= valor;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	return lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	return col;
}

// Imprime matriz --- Ja esta codificado 
void Matriz::imprime(int largura) {
	for (int linha = 0; linha < lin; linha++) {
		for (int coluna = 0; coluna < col; coluna++) {
			std::cout << std::setw(largura) << matriz[linha][coluna];
		}
		std::cout << std::endl;
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz *B) {
	for(int i=0;i<lin;i++){
		for(int j=0;j<col;j++){
			std:: cout << matriz[i][j] + B->matriz[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Multiplica matrizes
/* NAO CONSEGUIR FAZER :/
Matriz *Matriz::multiplica(Matriz *B) {
	if( lin != B->col){
		std::cout << "Numero de linhas diferente do de colunas ";
	}else{
		Matriz aux (lin,);
		for(int  i = 0; i < lin; i++){
			for (int j = 0; j < col; j++){
				B->matriz[i][j];
			}
		}
	}
}	
*/
