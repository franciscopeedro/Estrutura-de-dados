#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "matrizlista.h"


using namespace std;

/* comandos:

criar matriz: cria n n (cria matriz com n linhas e n colunas)
ler arquivo: arquivo n (numero da matriz a ser preenchida) A.txt (nome do arquivo e extenção) Ex: arquivo 0 A.txt
inserir valor na matriz: insere n (numero da matriz) n (linha) n (coluna) n (valor) Ex: insere 0 1 1 99
checar valor da matriz: valor n (numero da matriz) n (linha) n (coluna) Ex: valor 0 1 1
somar matrizes: soma n (numero da primeira matris) n (numero da segunda matris) Ex: soma 0 1
multiplicar matrizes: multiplica n (numero da primeira matris) n (numero da segunda matris) Ex: multiplica 0 1

obs: para preencher matriz através do arquivo é necessário que a matriz já tenha sido criada
Ex:
g++ main.cpp matrizfuncoes.cpp -o main
./main
cria 4 4
arquivo 0 A.txt */

int main()
{
	vector<SparseMatriz*> matrizes; 
	
	while(true) {
		string cmd;
		getline(cin, cmd);

		std::stringstream ss{ cmd };
		vector<string> tokens;
		string buffer;

		while(ss >> buffer) {
			tokens.push_back(buffer);
		}

		if(tokens[0] == "libera" || tokens[0] == "exit") {
			for(int i = 0; i < matrizes.size(); ++i) {
				delete matrizes[i];
				matrizes[i] = nullptr;
			}
			matrizes.clear();
			break;
		}
		// cria matriz.
		else if(tokens[0] == "cria") {
            int l = std::stoi(tokens[1]);
            int c = std::stoi(tokens[2]);
            SparseMatriz *m = new SparseMatriz(l, c);
            matrizes.push_back(m);
			
            }
            // imprime matriz
		else if(tokens[0] == "imprime") {
			int k = std::stoi(tokens[1]);
			matrizes[k]->print();
		}
		// insere valor na matriz
		else if(tokens[0] == "insere") {
            int k= std::stoi(tokens[1]);
			int i = std::stoi(tokens[2]);
            int j = std::stoi(tokens[3]);
            double v = std::stoi(tokens[4]);
            matrizes[k]->insert(i, j, v);
		}
        // ler arquivo
		else if(tokens[0] == "arquivo") {
			int k = std::stoi(tokens[1]);
            std::string arquivo = tokens[2];
			cout<<"Lendo arquivo "<<arquivo<<endl;
			SparseMatriz *c;
			c=c->lerMatrizDeArquivo(arquivo);
			matrizes[k]->lerMatrizDeArquivo(arquivo);
			if (matrizes[k] != nullptr) 
				delete matrizes[k];

			c=c->lerMatrizDeArquivo(arquivo);
			matrizes[k]=c;
		}

		// soma matrizes
		else if(tokens[0] == "soma") {
            int p = std::stoi(tokens[1]);
            int q = std::stoi(tokens[2]);
			SparseMatriz *C = matrizes[p]->soma(matrizes[p], matrizes[q]);
			if(C == nullptr) 
                cout << "nao foi possivel somar" << endl;
            else {
                C->print();
                delete C;
            }
		 }
        // multiplica matrizes
		else if(tokens[0] == "multiplica") {
            int p = std::stoi(tokens[1]);
            int q = std::stoi(tokens[2]);
			SparseMatriz *C = multiplica(matrizes[p], matrizes[q]);
			if(C == nullptr) 
                cout << "nao foi possivel multiplicar" << endl;
            else {
                C->print();
                delete C;
            }
        }
        // verifica valor na matriz
		else if(tokens[0] == "valor") {
			int k = std::stoi(tokens[1]);
            int i = std::stoi(tokens[2]);
            int j = std::stoi(tokens[3]);
			double v = matrizes[k]->getValue(i,j);
            cout << "valor: " << v << endl;

		}
		
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}