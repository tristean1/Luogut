#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string input;
    cin >> input;
    
    int ans = 0;
    for(int i = 0; i < n-1;i++){
        if(input[i] == 'V' and input[i+1] == 'K'){
            ans++;
            i++;
            
            //continue;
        }
        
    }   
    for(int i = 0; i <n;i++){
        if(i == n-2 and input[i] == 'V' and input[i+1] != 'K'){ans++;break;}
        else if(i < n-2 and input[i] == 'V' and input[i+1] != 'K' and input[i+2] != 'K' and input[i+1] != 'V'){
            ans++;break;
        }
        else if(i==1 and input[i] == 'K' and input[0] != 'V'){ans++;break;}
        else if(i > 1 and input[i] == 'K' and input[i-1] != 'V' and input[i-2] != 'K' and input[i-1] != 'V'){
            ans++;
            break;
        }
    }
    cout<<ans;
}