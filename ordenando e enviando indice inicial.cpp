#include <iostream>
using namespace std;

void ordena(int vet[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vet[i] > vet[j]){
                int aux;
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

}

void compara(int vet[], int vetaux[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vet[i] == vetaux[j]){
                cout << i << " ";
            }
        }
    }
}

void faztudoporra(int vet[],int vetaux[], int n){
    ordena(vet,n);
    compara(vet,vetaux,n);

}

int main(){
    int n;
    cin >> n;
    int vet[n];
    for(int i=0;i<n;i++){
        cin >> vet[i];
    }

    int vetaux[n];
    for(int i=0;i<n;i++){
        vetaux[i] = vet[i];
    }

    faztudoporra(vet,vetaux,n);
}