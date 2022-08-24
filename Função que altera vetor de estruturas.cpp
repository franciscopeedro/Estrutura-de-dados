#include <iostream> // std::cout, std::cin, std::fixed
#include <iomanip> // std::setprecision
using namespace std;

struct aluno {
   float nota[3];
   float media;
};

void calcula_media(aluno *a){
    a->media = (a->nota[0] + a->nota[1] + a->nota[2])/3;
}

void calcula_media_turma(aluno a[], int n){
   for(int i=0;i<n;i++){
      calcula_media(a);
      a++;
   }
}

int main(){
   int n, i, j;
   
   cin >> n;
   aluno turma[n];
   
   for (j = 0; j < n; j++)
      for (i = 0; i < 3; i++)
         cin >> turma[j].nota[i];
   
   // Chame a função 'calcula_media_turma' passando o vetor de alunos 'turma'.
   calcula_media_turma(turma, n);
   
   for (j = 0; j < n; j++) {
      cout << fixed;
      cout << setprecision(1) << turma[j].media << " ";
   }
   
   return 0;
}