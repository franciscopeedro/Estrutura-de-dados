#include <iostream>
using namespace std;

int main(){
    int matriz[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> matriz[i][j];
        }
    }
    
    int cont=0;
    if((matriz[0][0]+matriz[0][1]+matriz[0][2])==(matriz[1][0]+matriz[1][1]+matriz[1][2])){cont++;}
    if((matriz[2][0]+matriz[2][1]+matriz[2][2])==(matriz[0][0]+matriz[1][1]+matriz[2][2])){cont++;}
    if((matriz[0][2]+matriz[1][1]+matriz[2][0])==(matriz[0][0]+matriz[0][1]+matriz[0][2])){cont++;}
    if((matriz[0][1]+matriz[1][1]+matriz[2][1])==(matriz[0][2]+matriz[1][2]+matriz[2][2])){cont++;}
    if(cont==4){
        cout << "sim"<<endl;
    }else{cout <<"nao"<<endl;}
    return 0;
}