 #include <iostream>
 #include <iomanip>

using namespace std;

float fatorial(int n){
	int f=1;
    for (int i=1; i<=n; i++) {
		f*=i;
	}	
	return f;
}
float euler(int n){
	float eu;
	for(int i=1;i<=n;i++){
		eu+=1/fatorial(i);
	}
	return eu+1;	
}

int main() {

	float n;
	cin >> n;
	cout << fixed <<setprecision(6) << euler(n) << endl;

	return 0;
} 
