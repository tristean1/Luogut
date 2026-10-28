#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	cin >> x >> y;
	int ans = 0;
	for(int a =x;a<=y;a++){
		for(int b = x;b<=y;b++){
			for(int c=x;c<=y;c++){
				for(int d =x;d<=y;d++){
					if(a*d==b*c){
						ans++;
					}
				}
			}
		}
	}
	cout << ans <<'\n';
}
