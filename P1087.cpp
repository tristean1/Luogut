#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> num1;
void callFBI(int left,int length){
	int num = num1[left+length] - num1[left];
	if(num == 0){
		cout << 'B';
	}else if(num == length){
		cout << 'I';
	}else{
		cout << 'F';
	}
}
void dfs(int left,int length){
//	cout << left <<" "<< length<<'\n';
	if(length==0) return;
	dfs(left,length>>1);
	dfs(left+length/2,length>>1);
	callFBI(left,length);
}
int main(){
//	string s;
	int n;
	cin >> n >> s;
	num1.resize((1 << n)+1);
	num1[0] = 0;
	for(int i = 1;i <= 1<<n;i++){
		num1[i] = num1[i-1] + (s[i-1]=='1');
	}
//	s = "a" + s;
	dfs(0,1 << n);
	return 0;
}

