#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string rev(string a){
	reverse(a.begin(),a.end());
	size_t p = a.find_first_not_of("0");
	if(p==string::npos){return "0";}
	else{
		return a.substr(p);
	}
	
	
	
	
//	cout<<a<<" to "<<ans;
	//return a;
}

int main(){
	string input;
	cin>>input;
	char imp = 'N';
	//cout<<reverse(1234500000)<<" "<<reverse(984038594);
	string a,b;
	for(char i : input){
		//cout<<a<<" "<<b<<endl;
		if('0' <= i and i <= '9'){
			a+=i;
			//cout<<a<<endl;
		}else{
			if(i == '.' or i == '/'){
				imp = i;
				b = a;
				a = "";
			}else if(i=='%'){
				cout<<rev(a)<<'%'<<endl;
				return 0;
				//break;
			}
			
		}
	}
	if(imp!='N'){
		if(imp=='.'){
			size_t p = a.find_first_not_of("0");
			if(p == string::npos){a = "0";}
			else{a = a.substr(p);}
		}
	
			cout<<rev(b)<<imp<<rev(a)<<endl;
		
	}else{
		cout<<rev(a);
	}
	
	
}
