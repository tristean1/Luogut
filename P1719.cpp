#include<bits/stdc++.h>
using namespace std;

int main(){
	bool debug  = 0;
	int n;
	cin>>n;
	short input[120][120];
	short s_input[121][121];
	for(int i = 0;i < n;i++){
		for(int j = 0; j < n;j++){
			cin>>input[i][j];
		}
	}
	s_input[0][0]=0;
	for(int i = 1;i <= n;i++){
		s_input[0][i] = 0;
		s_input[i][0] =0;
	}
	s_input[1][1]=input[0][0];
	for(int i = 0;i < n;i++){
		s_input[1][i+1] = input[0][i] + s_input[1][i];
		s_input[i+1][1] = input[i][0] + s_input[i][1];
	}

	for(int x = 1;x <= n;x++){
		for(int y = 1;y<=n;y++){
			s_input[x+1][y+1] = s_input[x][y+1] + s_input[x+1][y] - s_input[x][y] + input[x][y];
		}
	}
//	cout<<endl;
	if(debug){
		for(int x = 0;x < n+1;x++){
			for(int y = 0;y<n+1;y++){
				cout<<s_input[x][y]<<" ";
			}
			cout<<endl;
		}
	}
	int mx = INT_MIN;
	int val;
	for(int x = 1;x <= n;x++){
		for(int y = 1;y<=n;y++){
			for(int kx = 0;kx < x;kx++){
				for(int ky = 0;ky <y;ky++){
					val = s_input[x][y] - s_input[x][ky] - s_input[kx][y] + s_input[kx][ky];
					if(val >  mx){
						mx = val;
					}
				}
			}
		}
	}
	cout<<mx;
	
}
