#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct aluno {
   int matricula;
   char nome[50];
   float media;
};

aluno le_aluno()
{
    aluno a;
    cin >> a.matricula;
    cin.ignore(); // lê e descarta o caractere '\n' do buffer 
    cin.get(a.nome, 50);
    cin >> a.media;
    return a;
}

/* 
Recebe vetor de alunos e novo aluno, e insere o novo aluno no final do vetor.
- v: vetor de alunos
- n: tamanho do vetor de alunos (passado por referência)
- novo: novo aluno a ser inserido no final do vetor.

Pseudocódigo:
   altere o tamanho do vetor v para conter *n+1 elementos, pondo endereço em v
   se não conseguir alocar (v == 0) imprima msg de erro e retorne 0
   coloque o aluno 'novo' na última posição do vetor (posição *n)
   aumente em 1 o tamanho do vetor (incrementar *n)
   retorne v
*/
aluno* insere_aluno(aluno *v, int *n, aluno novo)
{
   if(v==0){
      v= new aluno[*n+1];
      v[0]=novo;
   }
   else{
      aluno *w= new aluno[*n+1];
      for(int i =0;i<*n;i++){
         w[i] = v[i];
      }
      delete[] v;
      v=w;
      v[*n] = novo;
   }
   *n=*n+1;
   return v;
}
aluno* remove_aluno(aluno *v, int *n, int matricula){
    for(int i=0;i<*n;i++){
      if(v[i].matricula == matricula){ 
        v[i]=v[*n-1];
        aluno *w= new aluno[*n-1];
        for(int i =0;i<*n-1;i++){
         w[i] = v[i];
        
      }
      delete[] v;
      v=w;
      *n=*n-1;
      return v;
    }
   }
}

int main()
{
   int num_oper = 0, i, n = 0;
   cin >> num_oper;
   aluno *v = 0;

   for (i = 0; i < num_oper; i++) {
      cin.ignore(); // lê e descarta o caractere '\n' do buffer 
      char oper;
      cin >> oper;
      if (oper == 'i') {
         aluno a = le_aluno();
         v = insere_aluno(v, &n, a);
      } else {
         int mat;
         cin >> mat;
         v = remove_aluno(v, &n, mat);
      }
   }

   for (i = 0; i < n; i++) {
      cout << v[i].matricula << "\n" << v[i].nome << "\n" << std::fixed << setprecision(1) << v[i].media << "\n";
   }
   
   delete[] v;
   
   return 0;
}