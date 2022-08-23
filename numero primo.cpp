#include <iostream>
using namespace std;

int primo(int n){
    int cont=0;

    for(int i=1;i<=n;i++){
        if(n%i==0){
        cont++;
        }
    }
    if(cont==2){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int a,b;
    cin >> a>>b;
    if(a>b){
        for(int i=b;i<=a;i++){
            if(primo(i)==1){
            cout << i << endl;
            }
        }
    }
    if(b>a){
        for(int i=a;i<=b;i++){
            if(primo(i)==1){
            cout << i<< endl;
            }
        }
    }   
    else if(a==b){
        if(primo(a)==1){
            cout << a <<endl;
        }
    }

}