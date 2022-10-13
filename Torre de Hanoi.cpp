#include <iostream>

using namespace std;


void hanoi(int n,char a, char b, char c){
    if(n>=1){
        hanoi(n-1,a,c,b);
        cout << a << "->" << c << endl;
        hanoi(n-1,b,a,c);
    }
}

int main()
{
   int qte;
   cin >> qte;
   hanoi(qte, 'A', 'B', 'C');
   return 0;
}
