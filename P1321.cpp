#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin >> input;
    vector<bool> boys(input.length()+1,false);
    vector<bool> girls(input.length()+1,false);
    for(int i = 0; i < input.length();i++){
        char x = input[i];
        if(x=='b'){
            boys[i] = true;
        }else if(x=='o' and i >= 1){
            boys[i-1] = true;
        }else if(x == 'y' and i >= 2){
            boys[i-2] = true;
        }else if(x == 'g'){
            girls[i] = 1;
        }else if(x == 'i' and i >= 1){
            girls[i-1] = 1;
        }else if(x == 'r' and i >= 2){
            girls[i-2] = 1;
        }else if(x == 'l' and i >= 3){
            girls[i-3] = 1;
        }
    }
    int ans_boy =0;
    int ans_girl = 0;
    for(int i = 0; i <input.length() -2;i++){
        ans_boy += boys[i];
    }
    for(int i = 0;i < input.length() - 3;i++){
        ans_girl += girls[i];
    }
    cout<<ans_boy<<'\n'<<ans_girl;
    return 0;
}