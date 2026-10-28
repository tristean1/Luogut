#include<iostream>
using namespace std;

int main(){
	int alphabet[26] = {0};
	string input;
	for(int i = 0;i<4;i++){
		getline(cin,input);
		for(char a : input){
			if('A' <= a and a<='Z'){
				alphabet[a - 'A']++;
			}
		}
	}
	int max = 0;
	for(int i : alphabet){
		if(i > max){
			max = i;
		}
	}
	for(int i = max;i >0;i--){
		for(int j = 0;j<26;j++){
			if(alphabet[j]>=i){
				cout<<"*";
			}else{
				cout<<" ";
			}
			if(j!=25){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
}
