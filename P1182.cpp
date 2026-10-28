#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<int> input;

bool check(long long x){
	//数列能否在m次分割内使最大值的最小值为mid
	int working = 0;
	int sep_times = 0;
	int sum = 0;
	while(working<n){//进行分割
		if(input[working] > x){
			return false;
		}else if(input[working]==x){
			//必然在此分割一次
			sep_times++;
			working++;
			continue;
		}else{
			sum = input[working];
			//检查下一个
			//A:在这里写循环，再改working循环找到最大的分割使sum<x
			//B:进入下个大循环 
			while(1){
				working++;
				if(working==n){
					//已经到底，只能分割
					sep_times++;
					return sep_times <= m;
				}
				sum += input[working];
				if(sum>x){
					//只能单分割，退回到之前
					sep_times++;
					break;
				}else if(sum==x){
					//立刻完成分割
					++sep_times;
					++working;
					break;
				}else{
					continue;//继续尝试
				}
				
			}
			
			continue;//不用再加working
		}
		if(sep_times>m){return false;}
		working++;
		if(working==n){
			//已经到底，只能分割
			sep_times++;
			return sep_times <= m;
		}
	}
	return true;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	input.resize(n);
	long long hi = 0;
	for(int i = 0; i <n;i++){
		cin>>input[i];
		hi += input[i];
	}//输入
	//二分查找最小的最大值
	long long lo = 1;//正整数
	//hi = s index 取总和；
	long long ans = 1;
	long long mid;
	for(int i = lo;i<=hi;i++){
	//	cout<<check(i)<<" ";
	}
	//cout<<endl;
	while(lo<=hi){
		mid = (lo + hi)/2;
		//cout<<mid<<" ";
		if(check(mid)){
			ans = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	cout<<ans;

}
