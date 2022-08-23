#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

int main(){
    Aluno a;
    Aluno b;
    cin>> a.nome >> a.matricula >> a.disciplina >> a.nota;
    cin>> b.nome >> b.matricula >> b.disciplina >> b.nota;

    if(a.nota>b.nota){
        cout << a.nome << " , "<< fixed << setprecision(1)<< a.nota;
    }else if(a.nota<b.nota) {
        cout << b.nome << " , "<< fixed << setprecision(1) << b.nota;
    }else{
        cout << a.nome << " e " << b.nome << " , "<< fixed << setprecision(1) << a.nota;
    }
   
}