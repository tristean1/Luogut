#include<iostream>
using namespace std;



int main(){
	string steps;
	bool k1 = true;
	bool k2,k3 = false;
	bool exchange;
	while(cin>>steps){
		
		k1 =1;
		k2 = 0;
		k3 = 0;
		
		for(int i = 0;i<steps.length();i++){
			exchange = false;
			if(steps[i]=='A'){
				exchange = k2;//1 2
				k2 = k1;
				k1 = exchange;
			}
			else if(steps[i]=='B'){
				exchange = k3;// 2 3
				k3 = k2;
				k2 = exchange;
			}
			else if(steps[i]=='C'){
				exchange = k3;//1 3
				k3 = k1;
				k1 = exchange;
			}
			//cout<<k1<<k2<<k3<<endl;
		}
		if(k1){cout<<"1";}
		else if(k3){cout<<"3";}
		else if(k2){cout<<"2";}
		
		
	}
	return 0 ;
}
