#include<iostream>
# include<iomanip>
using namespace std;

int main(){
	int num;
	cin>>num;
	double shang = 0;
	double xia = 0;
	double a,b;
	for(int i =0;i<num;i++){
		cin>>a>>b;
		shang += a*b;
		xia += b;
	}
	cout.precision();
	cout<<fixed<<setprecision(2) <<shang/xia;
	
	return 0;
}
