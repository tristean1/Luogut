#include <iostream>

using namespace std;
long long* a;
//int max_a;
int _max(long long* a,int l,int r){
	int ans = a[l-1];
	for(int i = l ;i<=r;i++){
		if(a[i]>ans){
			ans = a[i];
		}
	}
	return ans;
}



long long M(int l,int r){
	//cout<<(l+r)/2<<endl;
	int ans;
	if(abs(r-l)<=5){
		return _max(a,l,r);
	}else{
		ans =  M(l,(l+r)/2) % max(7ll,M(1+((l+r)/2),r)) + a[((l+r)/2)-1]-1;
		return ans;
	}
}
int main(){
	int n;
	cin>>n;
	a = new long long[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		
	}
	cout<<M(1,n)<<endl;
	//cout<<_max(a,0,3);
	return 0;
	
}
