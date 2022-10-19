#ifndef MATRIZ
#define MATRIZ

struct Node;

class SparseMatriz{
    private:
        Node *head;
        Node *lin;
        Node *col;
        int mlinha, mcoluna;

    public:
        /*Inicializa uma matriz esparsa vazia com 
        capacidade para m linhas e n colunas.*/
        SparseMatriz(int m, int n);

        /*Destrutor que libera toda a memoria que foi alocada 
        dinamicamente para esta estrutura de dados.*/
        ~SparseMatriz();
        
        /*Inicializa os no cabeça das linha e das colunas*/
        void createHead(int m, int n);
        
        /*Insere um valor na célula (i, j) da matriz, 
        onde i é a linha e j é a coluna.*/
        void insert(int i, int j, double value); 
        
        /*Devolve o valor na célula (i, j) da matriz, 
        onde i é a linha e j é a coluna.*/
        double getValue(int i, int j);
        
        /* Quantidade de Colunas*/
        int getColuna();
        
        /*Quantida de Linhas*/
        int getLinha();
        
        /*Esse método imprime a matriz */
        void print();

        /*Soma duas matrizes(A,B) e o resultando sai numa terceira matriz(C) q logo depois é excluida*/
        SparseMatriz *soma(SparseMatriz *A, SparseMatriz *B);

        SparseMatriz *lerMatrizDeArquivo (std::string nomeDoArquivo);
               
};
        /*Multiplica duas matrizes(A,B) e o resultando sai numa terceira matriz(C) que logo depois é excluida*/
        SparseMatriz *multiplica(SparseMatriz *A, SparseMatriz *B);


#endif
