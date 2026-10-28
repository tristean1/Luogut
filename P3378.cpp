#include<bits/stdc++.h>
using namespace std;
vector<int> pq;
int sz = 0; //元素存在 1，sz;
int pq_top(){
	return pq[1];
}
void pq_pop(){
	pq[1] = pq[sz--];
	int i = 1;
	while(1){
		//和儿子比较
		int l = i * 2;
		int r = i * 2 +1;
		int mn =i;
		if(l<=sz && pq[l] < pq[mn]){
			mn = l;
		}
		if(r <= sz && pq[r] < pq[mn]){
			mn = r;
		}
		if(mn==i){
			break;
		}
		swap(pq[i],pq[mn]);
		i = mn;
	}
}
void pq_add(int x){
	pq[++sz] =x;
	int i = sz;
	while(i > 1 && pq[i] < pq[i/2]){
		swap(pq[i],pq[i/2]);
		i /= 2;
	}
}

int main(){
	int n;
	cin >> n;
	pq.resize(n);
	int type;
	int x;
	for(int i = 0; i < n;i++){
		cin>>type;
		if(type == 1){
			cin>>x;
			pq_add(x);
		}else if(type ==2){
			cout<<pq_top()<<endl;
		}else if(type == 3){
			pq_pop();
		}
	}
}
