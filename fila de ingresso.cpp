#include <iostream>
#include <string>
using namespace std;

void printa(int *v,int n){
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void remove(int *v, int &n,int value){{
    for(int i=0;i<n;i++){
        if(v[i]==value){
            for(int j=i;j<n-1;j++){
                v[j]=v[j+1];
            }
            n--;
        }
    }
}

}

int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    int q;
    cin >> q;
    int b[q];
    for(int i=0;i<q;i++){
        cin >> b[i];
    }

   for(int i=0;i<q;i++){
        remove(v,n,b[i]);
    }
    printa(v,n);
}