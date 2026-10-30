#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int num = 1 << n;
	priority_queue<pair<int,int>> seq;
	for(int i = 0;i<num;i++){
		int in;
		cin >> in;
		pair<int,int> s;
		s.first = in;
		s.second = i+1;
		seq.push(s);
		
	}
	seq.pop();
	cout << seq.top().second <<'\n';
	
}
