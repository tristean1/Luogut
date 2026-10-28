#include<bits/stdc++.h>
using namespace std;

struct student{
	int a;
	int b;
	int c;
	int total;
	int number;
	
	void gen(int i ){
		total = a + b + c;
		number = ++i;
	}
	
	bool operator<(const student& other) const {
		if(total > other.total){return 1;}
		else if(total == other.total ){
			if(a> other.a){
				return 1;
			}else if(a == other.a){
				return number < other.number;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	bool operator>(const student& other) const{
		return other < *this;
	}
};

int main(){
	int n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	vector<student> score(n); 
	for(int i = 0;i < n;i++){
		cin>>score[i].a;
		cin>>score[i].b;
		cin>>score[i].c;
		score[i].gen(i);
		
	}
	std::sort(score.begin(),score.end());
	for(int i = 0;i < 5;i++){
		cout<<score[i].number<<" "<<score[i].total<<endl;
	}
	
}
