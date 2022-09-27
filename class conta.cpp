#include <iostream>
using namespace std;

class Conta{
    private:
    float saldo;

    public:
    Conta(float saldo){
        if(saldo>=0){
            this->saldo = saldo;
        }else{
            this->saldo = 0;
            cout << "Valor do saldo tem q ser maior q zero" << endl;
        }

    }

    void Credito(float saldo){
        this->saldo = this->saldo + saldo; 
    }

    void Debito(float valor){
        if(this->saldo < valor){
            cout << "Sem saldo disponivel" << endl;
        }else{
            this->saldo = this->saldo - valor;
        }
    }

    float getSaldo(){
        cout <<"O saldo da sua conta eh: " <<this->saldo<<"  reais"<<endl;
    }

};

int main(){
    Conta *a = new Conta(10);
    a->Debito(11);
}