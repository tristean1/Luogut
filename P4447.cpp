#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> men(n);
	for(int i = 0;i<n;i++){
		cin >> men[i];
	}
	sort(men.begin(),men.end());
	vector<bool> new_group(n+1,0);
	new_group[0] = 1;
	
	for(int i = 0;i<n-1;i++){
		if(men[i+1]==men[i]+1){
			continue;
		}else if(men[i+1]==men[i]){
			// 2 2 3 3 
		}else{
			new_group[i+1] = 1;
		}
	}
	new_group[n] = 1;
	int min_g = n;
	int now_g = n;
	for(int i = 0;i<=n;i++){
		if(new_group[i]){
			min_g = min(min_g,now_g);
			now_g=1;
		}else{
			now_g++;
		}
	}
	cout<<min_g;
}
