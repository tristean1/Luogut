#include<bits/stdc++.h>
using namespace std;

int main(){
	queue<int> q;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	for(int i = 0; i < t;i++){
		string s; cin >> s;
		if(s == "2"){
			if(!q.empty()){
				q.pop();
			}else{
				cout << "ERR_CANNOT_POP" << '\n';
			}
		}else if(s == "1"){
			int in; cin >> in;
			q.push(in);
		}else if(s == "3"){
			if(!q.empty()){
				cout << q.front()<< '\n';
			}else{
				cout << "ERR_CANNOT_QUERY" << '\n';
			}
		}else if(s == "4"){
			cout << q.size() << '\n';
		}
	}
}
