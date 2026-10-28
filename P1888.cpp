#include <iostream>

#include<cmath>
using namespace std;
int gcd(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);
	
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	int a,b,c;
	int up,down;
	cin>>a>>b>>c;
	int A,B,C;
	if(a<b and a<c){
		A = a;
		B = b;
		C = c;
	}else if(b <a and b<c){
		A = b;
		B = a;
		C = c;
	}else if(c<a and c<b){
		A = c;
		B = b;
		C = a;
	}
	up = B*B + C*C - A*A;
	down = 2 * B * C;
	int g;
	do{
		g = gcd(up,down);
		up = up/g;
		down = down/g;
	}while(g!=1);
	cout<<sqrt(down*down-up*up)<<"/"<<down<<endl;
	return 0;
	
}
