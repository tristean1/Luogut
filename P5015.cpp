#include<iostream>
using namespace std;

int main(){
	string input;int num =0;
	while(cin>>input){
		num += input.length();
	}
	
	cout<<num;
}
