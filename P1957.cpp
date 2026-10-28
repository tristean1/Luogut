#include<iostream>
#include<string>
using namespace std;

string _add(string a,string b){
	return to_string(stoi(a) + stoi(b));
}
string _add1(string a,string b){
	return to_string(stoi(a) * stoi(b));
}
string _add2(string a,string b){
	return to_string(stoi(a) - stoi(b));
}

int main(){
	int n;
	cin>>n;
	string a,b;
	string input;
	string output = "";
	char w;
	
	for(int i = 0;i<n;i++){
		cin>>input;
		if(input[0] == 'a' or input[0] == 'b' or input[0] == 'c'){
			w = input[0];
			cin>>input;
			
		}
			a = input;
			cin>>b;
			if(w == 'a'){
				output += a +'+'+b+ '='+_add(a,b);
			}else if(w == 'b'){
				output += a +'*'+b+'='+_add1(a,b);
				
			}else if(w == 'c'){
				output += a +'-'+b+'='+_add2(a,b);
			}
			cout<<output<<endl<<output.length()<<endl;
			output = "";
		
		
	}
}
