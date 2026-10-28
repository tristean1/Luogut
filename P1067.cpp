#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> input(n+1);
    for(int i = n;i >=0;i--){cin >> input[i];}
    for(int i = n;i>=0;i--){
        //递减顺序
        if(input[i] == 0){continue;}//只包含系数不为0的项
        if(i == n && n!= 0){
            //刚开始
           if(input[i] > 0){
                cout<<"";
            }else{
                cout<<"-";
            }
            if(!(input[i]==1 or input[i] == -1)){
                cout<<abs(input[i]);
            }
            
            cout<<"x";
            
            if(i>1){
                cout<<"^"<<i;
            }
        }
        else if(i < n && i > 0){//不是最高次的项
            if(input[i] > 0){
                cout<<"+";
            }else{
                cout<<"-";
            }
            if(!(input[i]==1 or input[i] == -1)){
                cout<<abs(input[i]);
            }
            cout<<"x";
            if(i>1){
                cout<<"^"<<i;
            }
        }else{
            //是最后一项
            if(n!=0){
            if(input[i]>0){cout<<"+";}
            else{cout<<"-";}
            }
            cout<<abs(input[i]);
        }
        
    }
    cout<<'\n';
    return 0;
}