#include <iostream>
#include "matrizlista.h"
#include <fstream>

using namespace std;

struct Node
{
    Node *direita;
    Node *abaixo;
    int linha;
    int coluna;
    double valor;
};

SparseMatriz::SparseMatriz(int m, int n){
    // Iniciando o nó cabeca
    head = new Node;
    head->valor = 9999;
    head->linha = -1;
    head->coluna = -1;
    head->direita = head;
    head->abaixo = head;

    createHead(m, n);
}

SparseMatriz::~SparseMatriz(){
    // Apagando a matriz
    Node *atual;
    
    lin = head->abaixo;
    col = head->direita;

    while(lin != head){
        atual = lin->direita;

        while(atual->linha != -1){
            Node* prev = atual;
            atual = atual->direita;
            delete prev;
            lin->direita = atual;
        }

        lin = lin->abaixo;
    }

    lin = head->abaixo;

    while(lin != head || col != head){  
        if(lin != head){
            Node* prev = lin;
            lin = lin->abaixo;
            delete prev;
        }

        if(col != head){
            Node* prev = col;
            col = col->direita;
            delete prev;
        }
    }
    delete head;

std::cout << "Matriz apagada" << std::endl;
}

void SparseMatriz::createHead(int m, int n){
    // Guardando o tamanho da matriz
    mlinha = m;
    mcoluna = n;
    
    col = head;

    Node* novo;

    // Crindo os nós cabeças para coluna
    for(int i = 1; i <= mcoluna; i++){
        novo = new Node;

        col->direita = novo;                
        novo->valor = 9999;
        novo->linha = i; // Guardar o indice da coluna
        novo->coluna = -1;
        novo->abaixo = novo; // Circularidade
        col = col->direita;
    }
    // ajustar a circularidade
    col->direita = head;

    // Crindo os nós cabeças para linha
    lin = head;
    for(int i = 1; i <= mlinha; i++){
        novo = new Node;
        lin->abaixo = novo;                
        novo->valor = 9999;
        novo->linha = -1; 
        novo->direita = novo;
        lin = lin->abaixo;
    }
    lin->abaixo = head;
}
    //função para inserir valor na matriz
void SparseMatriz::insert(int i, int j, double value){
    // Verificar se os indices de linha e coluna 
    // passados como parametro são válidos
    if (i < 1 || i > mlinha || j < 1 || j > mcoluna)
        return;
  
    /* Buscar: Verificar se ja existe um elemeto na posição */
    Node* prev = nullptr;
    Node* atual;

    lin = col = head;

    // Mover o ponteiro pelo no da coluna até a posição desejada 
    for(int ind = 1; ind <= j; ind++)
        col = col->direita;

    // Mover o ponteiro pelo no da linha até a posição desejada 
    for(int ind = 1; ind <= i; ind++)
        lin = lin->abaixo;

    atual = lin;

    //Meu atual recebe o primeiro elemento da linha
    prev = atual;
    atual = atual->direita;

    //Mover o ponteiro pelo no da linha até a posição desejada 
    while(atual->coluna < j && atual->linha != -1){
        prev = atual;
        atual = atual->direita;
    }
    
    /* Atribuir valor: Se o no existir*/
    if (atual != lin && atual->coluna == j && atual->linha == i){
        if(value == 0){
            if(prev == lin) 
                lin->direita = atual->direita;
            else{
                prev->direita = atual->direita; 
                col->abaixo = atual->abaixo;            
            }
            delete atual;
        }else atual->valor = value;
    }else{
        Node* novo = new Node;
        novo->linha = i;
        novo->coluna = j;
        novo->valor = value;
        
        novo->direita = atual;
        if(prev == lin)
            lin->direita = novo;
        else
            prev->direita = novo;
    }
}

double SparseMatriz::getValue(int i, int j){
    // Verificar se os indices de linha e coluna 
    // passados como parametro são válidos
    if (i < 1 || i > mlinha || j < 1 || j > mcoluna)
        return 0;
    
    lin = head->abaixo;

    for(int ind = 1; ind < i; ind++)
        lin = lin->abaixo;
    
    Node *atual = lin->direita;

    while(atual->linha != -1){
        
        if(atual->coluna == j && atual->linha == i)
            return atual->valor;
        else 
            atual = atual->direita;
    }
    return 0;
}

int SparseMatriz::getColuna(){
    return mcoluna;
}

int SparseMatriz::getLinha(){
    return mlinha;
}   
    //função para printar matriz
void SparseMatriz::print(){
    Node* linha = head->abaixo;
    Node*atual = nullptr;

    for(int i = 1; i <= mlinha; i++){
        atual = linha->direita;
        
        for(int j = 1; j <= mcoluna; j++){
        
            if(atual->linha == i && atual->coluna == j){
                 std::cout << atual->valor << " ";
                 atual = atual->direita;
            }else
                 std::cout << "0" << " ";
             
            if(linha->direita->linha == -1 || linha->direita->linha == i)
                linha = linha->abaixo; 
        
       }
        std::cout << std::endl;
    }
}
    //função para somar matrizes
SparseMatriz *SparseMatriz::soma(SparseMatriz *A, SparseMatriz *B){
    
    if(A->mlinha == B->mlinha && A->mcoluna == B->mcoluna){
		// Cria uma nova matriz para retornar
		SparseMatriz *C = new SparseMatriz(A->mlinha, A->mcoluna);

		for(int i = 1; i <= A->mlinha; i++){
			for(int j = 1; j <= A->mcoluna; j++){               
                C->insert(i,j, (A->getValue(i,j) + B->getValue(i,j)));    
			}
		}
		return C;
	}

    return nullptr;
}
    //função para multiplicar matrizes.
SparseMatriz *multiplica(SparseMatriz *A, SparseMatriz *B){ 
	if(A->getColuna() != B->getLinha())
		return nullptr;
	
	SparseMatriz* C = new SparseMatriz(A->getLinha(), B->getColuna());

	for(int i = 1; i <= A->getLinha(); i++){
		for(int j = 1; j <= B->getColuna(); j++){
			for(int k = 1; k <= A->getColuna(); k++){
                C->insert(i,j, (C->getValue(i,j)+(A->getValue(i,k) * B->getValue(k,j))));  
            }
		}
	}
	return C;
}  
    //lê matriz do arquivo.
 SparseMatriz *SparseMatriz::lerMatrizDeArquivo(std::string nomeDoArquivo){
    std::ifstream txtFile;
    int lin, col;
    double value;

    //Abrindo o arquivo
    txtFile.open(nomeDoArquivo);

    //Le o tamanho da matriz no arquivo
    txtFile >> lin >> col;
    //c->createHead(lin, col);
    SparseMatriz* c  = new SparseMatriz(lin, col);

    int i, j ;
    for (int cont = 1; cont <= lin; cont++){
        for (int cont2 = 1; cont2 <= col; cont2++){
            txtFile >> i >> j >> value;
            c->insert(i, j, value); 
        }
    }
    
    return c;
 }