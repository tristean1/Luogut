#include <iostream>
using namespace std;

int main(){
	float a,b;
	cin>>a>>b;
	double bmi = a/(b*b);
	if(bmi<18.5){
		cout<<"Underweight"<<endl;
		
	}else if(bmi>=18.5 and bmi<24){
		cout<<"Normal"<<endl;
	}else{
		cout<<bmi<<endl<<"Overweight";
	}
}
