#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	bool* face = new bool[n];
	string* name = new string[n];
	
	for(int i = 0;i<n;i++){
		cin>>face[i]>>name[i];
		
	}
	string ans;
	int target = 0;
	bool _f;
	int dist;
	for(int i = 0;i<m;i++){
		cin>>_f>>dist;
		if(!_f == face[i]){
			//逆时针
			target += dist;
			if(target > n -1){
				target -= n;
			}
		}else{
			target -= dist;
			if(target<0){
				target += n;
			}
		}
		cout<<name[target]<<endl;
	}
	cout<<name[target];
}
