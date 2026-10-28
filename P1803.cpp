#include<bits/stdc++.h>
using namespace std;
struct req{
	int start;
	int end;
	bool operator<(const req &another){
		return end < another.end;//右端点升序
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<req> reqs(n);
	//int max_time = 0;
	for(int i = 0;i < n;i++){
		cin>>reqs[i].start;
		cin>>reqs[i].end;
		//cout<<reqs[i].start<<" "<<reqs[i].end<<endl;
	}
	sort(reqs.begin(),reqs.end());
	int can_attend = 0;
	//bool c = true;
	//vector<int> time(max_time+1,0);
	int use = 0;
	for(int i = 0;i<n;i++){
		if(reqs[i].start >= use){
			can_attend++;
			use = reqs[i].end;
			//cout<<reqs[i].start<<" "<<reqs[i].end<<" "<<use<<endl;
		}
	}
	cout<<can_attend;
}
