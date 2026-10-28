#include <iostream>
using namespace std;

int main(){
	int num;
	cin>>num;
	int a;
	int*  ans = new int[num];
	for(int i = 0;i<num;i++){
		cin>>a;
		if(a%4==0){
			ans[i]=0;
		}else if(a%4 ==1){
			ans[i]=1;
		}else if(a%4 ==2){
			if(a==2){
				ans[i]=2;
			}else{
				ans[i]=0;
			}
			
		}else if(a%4 ==3){
			if(a==3){
				ans[i]=3;
			}else{
				ans[i]=1;
			}
		}
			
	
	}for(int i = 0;i<num;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
