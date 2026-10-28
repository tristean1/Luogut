#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> win_loss_table = {{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};



int main(){
    int n,la,lb;
    cin >>n >> la >> lb;
    vector<int> wa(la);
    vector<int> wb(lb);
    for(int i = 0;i<la;i++){cin >> wa[i];}
    for(int i = 0;i<lb;i++){cin >> wb[i];}
    int win_a = 0;
    int win_b = 0;
   // for(int i =0;i<lb;i++){cout<<wb[i];}
    for(int i = 0; i < n;i++){
        //主循环 i= 第i轮比赛;
        //#ifdef Local
        //cout<<wa[i%la]<<" "<<wb[i%lb]<<" ";
        //#endif
        int result = win_loss_table[wa[i%la]][wb[i%lb]];
        //cout<<result<<'\n';
        if(result == 0){continue;}
        else if(result == -1) {win_b++;}
        else if(result == 1){win_a++;}
    }
    cout<<win_a<<' '<<win_b<<'\n';
    return 0;
}