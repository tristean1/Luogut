#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	string input;
	cin>>input;
	int operate;
	string ans;
	for(int i = 0;i<t;i++){
		cin>>operate;
		if(operate==1){
			string append;
			cin>>append;
			ans= input + append;
			input = ans;
			cout<<ans<<endl;
		}else if(operate ==2){
			int a,b;
			cin>>a>>b;
			ans = input.substr(a,b);
			input = ans;
			cout<<ans<<endl;
		}else if(operate ==3){
			int a;
			string insert;
			cin>>a>>insert;
			ans = input.substr(0,a) + insert + input.substr(a);
			input = ans;
			cout<<ans<<endl;
		}else if(operate ==4){
			string search;
			cin>>search;
			size_t p = input.find(search);
			if(p == string::npos){ans = "-1";}else{
				ans =to_string(p);
			}
			cout<<ans<<endl;
		}
		
		
	}
	
}

