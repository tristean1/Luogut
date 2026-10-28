#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> target;
	int input;
	target.push_back(0);//1-based
	while(cin >> input){
		target.push_back(input);
	}
	int n = target.size();
	reverse(target.begin()+1,target.end());
	//算最长减子序列
	//vector<int> g(n+1);
	
//	cout<<endl;
//	vector<int> tails;
	int total = 0;
	
	vector<int> tails;
	for(int i = 1;i < n;i++){
		
		int y = target[i];
		//if(y==-1){continue;}
		auto it = upper_bound(tails.begin(),tails.end(),y);
		if(it == tails.end()){
			tails.push_back(y);
			target[i] = -1; //标记已被拦截
		}//没有比y更大的元素
		else{
			*it = y;
		}
	}
	total = tails.size();
	cout<<tails.size()<<'\n';
	int turns = 1;
	while(total < n-1){
		vector<int> tails;
		for(int i = 1;i < n;i++){
			
			int y = target[i];
			if(y==-1){continue;}
			auto it = upper_bound(tails.begin(),tails.end(),y);
			if(it == tails.end()){
				tails.push_back(y);
				target[i] = -1; //标记已被拦截
			}//没有比y更大的元素
			else{
				*it = y;
			}
		}
		total += tails.size();
		turns++;
		cout<<"大循环"<<total<<" "<<n<<'\n';
	}
	cout<<turns<<'\n';
}
