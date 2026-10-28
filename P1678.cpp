#include<bits/stdc++.h>
using namespace std;



int main(){
	int m,n;
	cin >>m>>n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> school(m);
	vector<int> student(n);
	for(int i = 0;i < m;i++){
		cin>>school[i]; 
	}
	for(int j =0 ;j < n;j++){
		cin>>student[j];
	}//输入
	sort(school.begin(),school.end());
	long long sum = 0;
	//int min_unsat = 100000000;
//	int chazhi;
	int lo = 1;
	int hi = m;
	int ans;
	int mid;
	for(int i =0;i < n;i++){//对于每位学生
		lo = 0;
		hi = m-1;
		ans = 0;
//	cout<<"循环for"<<endl;
		while(lo<=hi)
		{
			mid = (lo+hi)/2;
//			cout<<lo<<" "<<mid<<" "<<hi<<endl;
		if(student[i] >= school[mid]){//大于
				ans = mid;
				lo = mid + 1;
				
			}else{//小于
				hi = mid -1;
			}
	//	cout<<lo<<" "<<mid<<" "<<hi<<endl;
		}
		if(ans==m-1){
			sum += abs(student[i]-school[ans]);
		}
		else{sum += min(abs(student[i]-school[ans]),abs(student[i]-school[ans+1]));}
//	cout<<ans<<" "<<sum<<endl;
	}
	cout<<sum;
}
