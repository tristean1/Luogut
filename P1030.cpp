#include<bits/stdc++.h>
using namespace std;

string mid;//中序
string last;//后序
int length = 4;
void solve(int ml,int mr,int ll,int lr){
	//ml,mr为子树的中序区间
	//ll,lr为子树的后序区间
	if(ml > mr){
		//cout << last[lr];
		return;
	}
	char father = last[lr];
	cout << father;
	int loc = -1;
	for(int i = ml;i <= mr;i++){
		if(mid[i] == father){
			loc = i;
			break;
		}
	}
	solve(ml,loc-1,ll,ll + (loc-1-ml));
	//右边
//	int right_length = length - loc; 
	solve(loc+1,mr,lr-1 - (mr - loc -1),lr-1);
	
	
}
int main(){
	cin >> mid >> last;
	length = mid.length();
	solve(0,length-1,0,length-1);
}

