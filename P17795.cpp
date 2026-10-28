#include<bits/stdc++.h>
using namespace std;

int n;
int k;
vector<int> cminus;
vector<int> cplus;

bool check(long long c){
	bool init = 1;
	long long cc = c;
	int used = 0;
	for(int i = 0;i<n;i++){
		if(init){
			
			c -= cminus[i];
			if(c < 0){
				init = 0;
				if(cc < cminus[i]) return 0; //用全新电池也过不了
				else {
					used++;
					c = cc;
					c -= cminus[i];
					
				}
			}else{
				c += cplus[i];
				if(c >= cc) c = cc;
			}
			
		}else{
			if(c >= cminus[i]){
				//电够用
			}else{
				c = cc;//换新电池
				used++;
				if(c < cminus[i]) return 0;
			}
			c-=cminus[i];
		}
	}
	return used <= k;
}


int main(){
	cin >> n >>k;
	cminus.resize(n);
	cplus.resize(n);
	
	for(int i =0;i<n;i++) cin >> cminus[i] >> cplus[i];
	//for(int i = 0;i < 100;i++) cout << check(i)<<" ";
	long long lo = 0;
	long long hi =  LLONG_MAX;
	while(lo <= hi){
		long long mid = (lo + hi) /2;
		if(check(mid)){
			hi = mid -1;
		}else{
			lo = mid + 1;
		}
	}
	cout <<lo<<'\n';
	
}
