#include <iostream>
#include <vector>
using namespace std;

void printa(vector<int> &v,int tamanho,int faca){
    cout << "[ ";
    for(int i=0;i<tamanho;i++){
        if(faca == i){
            cout << v[i] << "> ";
        }else{
        cout << v[i] << " ";
        }
    }
    cout << "]" << endl;
}

void remove(vector<int> &v, int &t, int indice){
    for(int i=0;i<t;i++){
        if(i==indice){
            for(int j=i;j<t-1;j++){
                v[j]=v[j+1];
            }
        }
    }
    t--;
}

int main(){
    int t, assassino, faca;
    cin >> t >> assassino;
    vector<int> pessoas(t);
    for(int i=1;i<=t;i++){
        pessoas[i-1]=i;
    }
    int morre = 0;
    faca = assassino-1;
    
    printa(pessoas,t,faca);

    while(t>1){
        if(assassino == t){ // caso o assassino seja o ultimo
            faca=0;
            morre = 0;
            remove(pessoas,t,morre);
            printa(pessoas,t,faca);
            assassino=1;

        }else if(assassino == t-1){  // caso o assassino seja o penultimo
            faca=0;
            morre=t-1;
            remove(pessoas,t,morre);           
            printa(pessoas,t,faca);
            assassino=1;
        }else{
            faca=faca+1;
            morre=assassino;
            remove(pessoas,t,morre);
            printa(pessoas,t,faca);
            assassino=assassino+1;
        }
    
    }
    
}