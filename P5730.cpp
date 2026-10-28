#include <iostream>
using namespace std;

int main(){
	string a1[10] = {"XXX","..X","XXX","XXX","X.X","XXX","XXX","XXX","XXX","XXX"};
	string a2[10] = {"X.X","..X","..X","..X","X.X","X..","X..","..X","X.X","X.X"};
	string a3[10] = {"X.X","..X","XXX","XXX","XXX","XXX","XXX","..X","XXX","XXX"};
	string a4[10] = {"X.X","..X","X..","..X","..X","..X","X.X","..X","X.X","..X"};
	string a5[10] = {"XXX","..X","XXX","XXX","..X","XXX","XXX","..X","XXX","XXX"};
	
	int n ;
	cin>>n;
	
	string inpt;
	cin>>inpt;
	
	cout<<a1[inpt[0] - '0'];
	for(int i = 1;i<n;i++){
		cout<<"."<<a1[inpt[i] - '0'];
	}
	cout<<endl;
	cout<<a2[inpt[0] - '0'];
	for(int i = 1;i<n;i++){
		cout<<"."<<a2[inpt[i] - '0'];
	}
	cout<<endl;
	cout<<a3[inpt[0] - '0'];
	for(int i = 1;i<n;i++){
		cout<<"."<<a3[inpt[i] - '0'];
	}
	cout<<endl;
	cout<<a4[inpt[0] - '0'];
	for(int i = 1;i<n;i++){
		cout<<"."<<a4[inpt[i] - '0'];
	}
	cout<<endl;
	cout<<a5[inpt[0] - '0'];
	for(int i = 1;i<n;i++){
		cout<<"."<<a5[inpt[i] - '0'];
	}
	cout<<endl;
	
}
	
