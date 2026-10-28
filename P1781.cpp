#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	string max = "0";
	string input;
	int index = 0;
	for(int i = 0;i < t;i++){
		cin>>input;
		if(input.length() > max.length()){
			index = i;
			max = input;
		}else if(input.length() == max.length()){
			for(int j = 0; j< input.length();j++){
				if(input[j]>max[j]){
					index = i;
					max = input;
				}else if(input[j]<max[j]){
					break;
				}else{
					continue;
				}
			}
		}
		//cout<<max<<endl;
	}
	cout<<index+1<<'\n'<<max<<endl;
}
