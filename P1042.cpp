#include<iostream>
using namespace std;

void proc(string input){
	int hua = 0;
	int dui = 0;
	//bool out = 0;
	for(int i = 0;i<input.length();i++){
		if(input[i] =='E'){break;}
		else if(input[i]=='W'){
			hua++;
		}else if(input[i] == 'L'){
			dui++;
		}
		if((hua>=11 or dui >= 11) && (hua - dui >=2 or dui - hua >=2)){
			cout<<hua<<':'<<dui<<endl;
			hua  =0;
			dui = 0;
		}
	}
	cout<<hua<<':'<<dui<<endl<<endl;
	hua = 0;
	dui = 0;
	for(int i = 0;i<input.length();i++){
		if(input[i] =='E'){break;}
		
		else if(input[i]=='W'){
			hua++;
		}else if(input[i] == 'L'){
			dui++;
		}
		if((hua>=21 or dui >= 21) && (hua - dui >=2 or dui - hua >=2)){
			cout<<hua<<':'<<dui<<endl;
			hua  =0;
			dui = 0;
		}
	}
	cout<<hua<<':'<<dui<<endl;
	//return out;
}

int main(){
	string input;
	string temp;
	bool cont = 1;
	while(cont){
		cin>>temp;
		input += temp;
		for(int i = 0;i<temp.length();i++){
			if(temp[i] == 'E'){
				cont = 0;
				break;
			}
		}
	}
	proc(input);
	
}
