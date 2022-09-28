#include <iostream>
#include <cstring>
using namespace std;

struct Aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

int main(){
    Aluno a;
    cin>> a.nome >> a.matricula >> a.disciplina >> a.nota;

    if(a.nota>=7.00){
        cout << a.nome << " aprovado(a) em "<< a.disciplina;
    }else{
        cout << a.nome << " reprovado(a) em "<< a.disciplina;
    }   
}
