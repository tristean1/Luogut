#include<iostream>
#include<string>
using namespace std;
string repeat(int num,string input){
	string ans;
	for(int i = 0;i < num;i++){
		ans += input;
	}
	//cout<<input<<" to "<<ans<<endl;
	return ans;
}
int main(){
	int t;
	cin>>t;
	string input;
	string ans;
	size_t p;

	int rep = 0;
	
	string copy;
	for(int i = 0;i<t;i++){
		ans = "";
		cin>>input;
		rep = 0;

		
		//if(input==""){cout<<ans<<endl;break;}
		//cout<<"find"<<input<<endl;
		//p = input.find_first_of("123456789");
		bool mode = false; // 0字符读取 1次数读取
		while(1){
			
			if(!mode){
				p = input.find_first_of("1234567890");
				if(p==string::npos){copy = input;input = "";}
				else{
					copy = input.substr(0,p);
					input = input.substr(p);
				
				}
				mode=!mode;
			}else{//次数读取
				p = input.find_first_not_of("1234567890");
				if(p==string::npos){
					rep = stoi(input);
					ans += repeat(rep,copy);
					cout<<ans<<endl;
					break;
				}
				else{
					rep = stoi(input.substr(0,p));
					input = input.substr(p);
					ans += repeat(rep,copy);
				}
				
				mode=!mode;
			}
			
		}
			
	
			
			
			

			//input = input.substr(p+num);
			//cout<<input<<endl;
		
	}
}
