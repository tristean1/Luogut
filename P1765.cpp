#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    int total = 0;
    for(char x : input){
        if(x=='a' || x=='d' || x=='g' || x=='j' || x=='m' || x=='p' || x=='t' || x=='w'){
            total += 1;
        }
        else if(x=='b' || x=='e' || x=='h' || x=='k' || x=='n' || x=='q' || x=='u' || x=='x'){
            total += 2;
        }
        else if(x=='c' || x=='f' || x=='i' || x=='l' || x=='o' || x=='r' || x=='v' || x=='y'){
            total += 3;
        }
        else if(x=='s'){
            total += 4;
        }
        else if(x=='z'){
            total += 4;
        }else if(x == ' '){
            total += 1;
        }else{
            total++;
        }
        
    }
    cout << total;
    return 0;
}