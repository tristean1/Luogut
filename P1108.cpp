#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> price(n+1);
	for(int i = 1; i<=n;i++){
		cin >> price[i];
	}//1-based方便算
	//由于需要计数，只能使用dp
	vector<int> f(n+1); //状态1：以p【i结尾的最长
	vector<long long> g(n+1);//状态2 以p结尾的方案数
	
	for(int i = 1; i<=n;i++){
		f[i] = 1; 
		g[i] =1;
		for(int j =1; j <i;j++){
			if(price[j] > price[i]){
				if(f[j]+1 > f[i]){
					f[i] = f[j] +1; //手动max
					g[i] = g[j]; //拓展原来的链，继承原来的方案数
					
				}else if(f[j]+1==f[i]){	//发现一条新的可行方案，继承并吸收之前的方案数
					g[i] += g[j];
				}
			}
		}
		for(int j = 1; j<i;j++){
			if(price[i]==price[j] && f[i]==f[j]){g[j]=0;}
		}
	}
	int f_max = 0;
	long long ways  = 0;
	for(int i =1;i <=n;i++){
		
		if(f[i] > f_max){
			f_max = f[i];
		}
		cout<<g[i]<<" ";
	
	}
	cout<<endl;
	for(int i =1;i<=n;i++){
		if(f_max == f[i]){
			ways += g[i];
		}
	}
	
	cout<<f_max<<" "<<ways;
}
