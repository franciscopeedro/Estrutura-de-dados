#include <iostream>
using namespace std;

int main(){
    int n;
    cin>> n;
    int vet[n];
    for(int i=0;i<n;i++){
        cin >>vet[i]; 
    }
    for(int i=0;i<n;i++){
        if(vet[i]>vet[i+1]){
            cout << "precisa de ajuste";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(vet[i]<vet[i+1]){
            cout << "ok";
            return 0;
        }
    }
}