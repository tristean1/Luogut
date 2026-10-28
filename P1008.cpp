#include<iostream>
using namespace std;

bool ist(int a){
	//cout<<a;
	int b = a*2;
	int c = a*3;
	if(c>999){return false;}
	int t=0;
	for(int i =1;i<10;i++){
		t=0;
		if(a%10==i  ){
			t++;
		}
		if(a/100%10==i){t++;}
		if(a/10 %10==i){t++;}
		if(b%10==i ){
			t++;
		}
		if(b/10 %10==i ){t++;}
		if( b/100%10==i){t++;}
		if(c%10==i  ){
			t++;
		}
		if(c/10 %10==i){t++;}
		if(c/100%10==i){t++;}
		if(t>1){return false;}
	}
	t=0;
	int i =0;
	if(a%10==i  ){
		t++;
	}
	if(a/100%10==i){t++;}
	if(a/10 %10==i){t++;}
	if(b%10==i ){
		t++;
	}
	if(b/10 %10==i ){t++;}
	if( b/100%10==i){t++;}
	if(c%10==i  ){
		t++;
	}
	if(c/10 %10==i){t++;}
	if(c/100%10==i){t++;}
	if(t>0){return false;}
	return true;
}
int main(){
	int a;
	
	for(int i =1;i<10;i++){
		for(int j =1;j<10;j++){
			for(int k =1;k<10;k++){
				a = i * 100 + j* 10 +k;
				
				if(ist(a)){
					cout<<a<<" "<<a*2<<" "<<a*3<<endl;
				}
			}
		}
	}
}
