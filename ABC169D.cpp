#include<iostream>
#include<cmath>

using namespace std;
int main(){
	long long n;
	cin>>n;
	if(n==1){cout<<1;return 0;}
	//int times = 0;
	int sqn = sqrt(n);
	if(n<=7){n=7;}
	int* Prime = new int[sqn];
	int* tim = new int[sqn];
	
	Prime[0] =2;
	Prime [1] = 3;
	Prime[2] = 5;
	Prime[3] = 7;
	int proc =3;
	int trying = 9;
	bool isp= 0;
	//int effective_n = 3;
	//cout<<trying<<" "<<sqn<<endl;
	while(trying < sqn){
		isp = 1;
		
		for(int i =0;i<=proc;i++){
			if(trying%Prime[i]==0){
				isp = 0;
				break;
			}
			
		}
		if(isp){
			proc++;
			Prime[proc] = trying;
			//cout<<trying<<" ";
		}
		//cout<<trying<<" ";
		trying += 2;
		
	}//生成质数表
	isp = 1;
	for(int i =0;i<=proc;i++){
		if(n%Prime[i]==0){
			isp = 0;
			break;
		}
		
	}
	if(isp && n > Prime[proc]){
		proc++;
		Prime[proc] = n;
		//cout<<n<<" ";
	}
	//cout<<endl;
	for(int i = 0;i<=proc;i++){
		tim[i] = 0;
		while(n%Prime[i]==0){
			n /= Prime[i];
			tim[i]++;
			
			
		}
		//cout<<tim[i]<<endl;
	}//计算每项
	
	int num = 0;
	int temp = 0;
	int wo;
	double delta;
	for(int i =0 ;i<= proc;i++){
		temp = 0;
		wo = tim[i];
		if(wo==0){continue;}
		else if(wo==1 or wo==2){num++;}
		/* 4 =1+3 5 = 2 + 3 6 = 1+ 2+ 3 7 = 1+2+4 8 = 1+3+4
		
		*/
		else{
			delta = sqrt(1 + 8 * wo);
			delta = (delta-1)/2;
			temp = (int)delta;
			num += temp;
		}
	}
	cout<<num;
	
}
