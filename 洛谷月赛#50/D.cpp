#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<vector<long long>> mat(n,vector<long long>(m));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> mat[i][j];
		}
	}
	char type;cin >> type;
	if(type == 'A'){
		cout << n <<" "<<m<<'\n';
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cout << mat[i][j] << " ";
			}
			cout << '\n';
		}
	}else if(type >= 'B'){
		
		for(int i = 0;i<n-1;i++){
			for(int j = 0;j<m-1;j++){
				mat[i][j] = mat[i][j] * mat[i+1][j+1]-mat[i+1][j]*mat[i][j+1];
			}
		}
		if(type == 'B'){
			cout << n-1 <<" "<<m-1<<'\n';
			for(int i = 0;i<n-1;i++){
				for(int j = 0;j<m-1;j++){
					cout << mat[i][j]<<" ";
				}
					cout << '\n';
			}
		}
	}
	if(type >= 'C'){
		for(int i = 0;i<n-2;i++){
			for(int j = 0;j<m-2;j++){
				mat[i][j] = mat[i][j] * mat[i+1][j+1]-mat[i+1][j]*mat[i][j+1];
			}
		}
		if(type=='C'){
			cout << n-2 <<" "<<m-2<<'\n';
			for(int i = 0;i<n-2;i++){
				for(int j = 0;j<m-2;j++){
					cout << mat[i][j] << " ";
				}
					cout << '\n';
			}
		}
	}
	if(type=='D'){
		for(int i = 0;i<n-3;i++){
			for(int j = 0;j<m-3;j++){
				mat[i][j] = mat[i][j] * mat[i+1][j+1]-mat[i+1][j]*mat[i][j+1];
			}
		}
		if(type=='D'){
			cout << n-3 <<" "<<m-3<<'\n';
			for(int i = 0;i<n-3;i++){
				for(int j = 0;j<m-3;j++){
					cout << mat[i][j] <<" ";
				}
					cout << '\n';
			}
		}
	}
	return 0;
	
}
