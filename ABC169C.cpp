#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	string a;
	string b;
	//double ans;
	long long da;
	double db;
	cin>>a>>b;
	da = stoll(a);
	db = stod(b);
	db = round(db*100);
	cout<<(long long)(da*db);
	
}
