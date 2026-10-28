#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> maap(12,vector<char>(12,'*'));
char zhuan(char x){
    if(x =='w')return 'd';
    else if(x == 'd') return 's';
    else if(x=='s') return 'a';
    else if(x == 'a') return 'w';
    else return '0';
}

struct Location{
    int x;
    int y;
    char direct;
    bool operator==(const Location& another) const {
        return x==another.x and y == another.y;
    }
    bool operator!=(const Location& another) const {
        return !(*this == another);
    }
    Location(int _x,int _y,char _direct) : x(_x),y(_y),direct(_direct){}
    Location(){};
};
Location move(Location &p){
    int ax,ay;
    int x = p.x;int y = p.y;
    if(p.direct == 'w'){ax = x; ay = y-1;}
    else if(p.direct == 's'){ax = x;ay = y+1;}
    else if(p.direct == 'a'){ax = x-1;ay = y;}
    else if(p.direct == 'd'){ax = x+1;ay = y;}
    if(maap[ay][ax]=='*'){
        p.direct = zhuan(p.direct);
        ax = x; ay= y;
    }
    Location ans(ax,ay,p.direct);
    return ans;
}

int main(){
    
    Location far,cow;
    for(int i = 1; i<=10;i++){
        string input;
        cin >> input;
        for(int j = 0;j<10;j++){
            maap[i][j+1] = input[j];
            if(input[j]=='F'){
                far.x = j+1;
                far.y = i;

            }else if(input[j] == 'C'){
                cow.x = j+1;
                cow.y = i;
            }
        }
    }
    far.direct = 'w';
    cow.direct = 'w'; 
      
    const int LIMIT = (10*10*4) * (10*10*4);   // 160000：联合状态总数
for (int t = 0; t <= LIMIT; t++) {
    if (cow == far) { cout << t << '\n'; return 0; }
    cow = move(cow);
    far = move(far);
}
cout << 0 << '\n';
    
}