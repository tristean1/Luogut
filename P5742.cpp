#include <iostream>
using namespace std;

struct student{
	int number;
	int ga;
	int gb;
	bool isex(){
		return (ga+gb)>140 && (ga*7+gb*3)>=80;
	}
	student(int _number,int _ga,int _gb){
		number = _number;
		ga = _ga;
		gb = _gb;
		
	}
};
int main(){
	int n;
	int number,ga,gb;
	cin>>n;
	int* ans = new int[n];
	for(int i =0;i<n;i++){
		cin>>number>>ga>>gb;
		if(student(number,ga,gb).isex()){
				cout<<"Excellent"<<endl;
		}else{
			cout<<"Not excellent"<<endl;
		}
	}
	
}
