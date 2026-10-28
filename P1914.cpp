#include<iostream>
using namespace std;

int main(){
	int n;
	string input;
	cin>>n>>input;
	n = n%26;
	for(int i = 0;i<input.length();i++){
		input[i] += n;
		if(input[i] > 'z'){
			input[i] -= 26;
		}
	}
	cout<<input;
}
