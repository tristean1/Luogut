#include<bits/stdc++.h>
using namespace std;

int doable(const vector<int> &woods,int l,int n) {
	int total = 0;
	if(l==0){return -1;}
	for(int i = 0;i < n;i++){
		total += woods[i] / l;
	}
	return total;//在给定 l（长度）下最多切出 total块
}

int main(){
	int n,k;
	
	
	int l_min,l_max;
	int min_index;
	int mi = 100000005;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	vector<int> woods(n);
	long long sum = 0;
	for(int i = 0;i < n; i++){
		cin >> woods[i];
		sum += woods[i];
		if(woods[i]<mi){
			mi = woods[i];
			min_index = i;
		}
	}//输入
	cout.flush();
	if(n==1){cout<<sum/k<<endl;return 0;}
	if(sum < (long long)k) {cout<<0<<endl;return 0;}//1cm切不出来当且仅当最大块<1cm
	l_min = 0;
	l_max = woods[min_index] ;
	int trying = (l_min + l_max) /2 ;
	int success;
	while(1){
		success = doable(woods,trying,n);
		if(doable(woods,trying+1,n)<k && success >= k){break;}//唯一退出条件
		//else if(doable(woods,trying,n)<k && success >= k){break;}
		if(success >= k){
			if(l_max - l_min > 3){
			l_max = trying+1;
			trying = (l_min + l_max) /2 ;
			}else{
				
				trying++;
			}
			//if(l_max - l_min==2){trying++;}
			
		}else{
			if(l_max-l_min>3){
				l_min = trying-1;
				trying = (l_min + l_max) /2 ;
			}else{
				
				trying--;
				
			}
			//if(l_max - l_min==2){trying--;}
		}
		
		//cout<<l_min<<" "<<l_max<<" "<<trying<<" "<<success<<endl;
		if(l_min + 1== l_max){break;}
	}
	cout<<trying<<endl;
	
	
}
