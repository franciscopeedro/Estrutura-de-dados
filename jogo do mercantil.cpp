            #include <iostream>
using namespace std;

int main(){
    int n,cseg=0,cpri=0;
    cin >> n;
    float valor[n];
    float chutes[n];
    char ch[n];
    for(int i=0;i<n;i++){
        cin >> valor[i];
    }
    for(int i=0;i<n;i++){
        cin >> chutes[i];
    }
    for(int i=0;i<n;i++){
        cin >> ch[i];
    }

    for(int i=0;i<n;i++){
        if(valor[i]==chutes[i]){
            cpri++;
        }
        else if(valor[i]>chutes[i] && ch[i] == 'm' ) {
            cpri++;
        }
        else if(valor[i]<chutes[i] && ch[i] == 'M' ){
            cpri++;
        }
        else{
            cseg++;
        }
    }
    if(cpri>cseg){cout <<"primeiro";}
    else if(cpri<cseg){cout <<"segundo";}
    else{cout << "empate";}

    return 0;
}
