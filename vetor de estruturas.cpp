#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Aluno{
    int matricula;
    string nome;
    double media;
};

int main(){
    int n;
    cin >> n;
    Aluno a[n];
    for(int i=0 ; i<n ;i++){
        cin >> a[i].matricula;
        cin.ignore();
        getline(cin, a[i].nome);
        cin >>a[i].media;
    }

    int m;
    cin >> m;
    for(int i=0;i,i<n;i++){
        if(a[i].matricula == m){
            cout << a[i].nome << endl;
            cout <<fixed<<setprecision(1)<< a[i].media;
            return 0;
        }
    }
    cout << "NAO ENCONTRADA"; 
}