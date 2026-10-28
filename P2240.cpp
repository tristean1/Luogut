#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	vector<int> price(n);//价
	vector<int> heavy(n);//重量
	for(int i  =0 ;i < n;i++){
		cin>>heavy[i];
		cin>>price[i];
	}
	double p_max = 0; 
	int p_max_index = 0;
	int can_b = t;
	double gain = 0;
	double now = 0;
	while(1){
		p_max_index = 0;
		p_max = 0;
		
		for(int i = 0;i < n;i++){
			now = (double)price[i] / (double)heavy[i];
			if(p_max < now){
				p_max = now;
				p_max_index = i;//找单位价值最高的
			}
		}
		//cout<<p_max<<" "<<endl;
		if(p_max == 0){
			break;
		}
		
		if(can_b > heavy[p_max_index]){
			//空间足够
			gain +=price[p_max_index];
			can_b -= heavy[p_max_index];
			price[p_max_index] = 0; //拿了必拿完
			
			continue;
		}else{
			//不够
			gain += p_max * can_b;
			break;
		}
		//cout<<"循环 "<<can_b<<" "<<gain<<" "<<p_max<<endl;
		
	}
	cout<<fixed<<setprecision(2)<<gain;
}
