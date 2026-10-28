#include<bits/stdc++.h>
using namespace std;

struct man{
	int time;
	int number;
	
	bool operator<(man another){
		if(time == another.time){
			return number < another.number;
		}
		return time < another.time;
	}
};

int main(){
	int n;
	cin >> n;
	vector<man> input(n);
	for(int i = 0;i < n;i++){
		cin >> input[i].time;
		input[i].number = i;
		
	}
	sort(input.begin(),input.end());
	vector<int> waiting_time(n);
	waiting_time[0] = 0;//第一个人不等待
	for(int i = 0; i < n;i++){
		cout<<input[i].number+1<<" ";
		
	}
	for(int i = 1; i < n;i++){
//		cout<<input[i].number<<" ";
		waiting_time[i] = waiting_time[i-1] + input[i-1].time;
	}
	long long sum_wat = 0;
	for(int i = 1; i < n;i++){
		sum_wat += waiting_time[i];
	}
	cout<<endl;
	cout<<fixed<<setprecision(2)<<(double)sum_wat/(double)n;
	
	
}
