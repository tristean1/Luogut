#include<bits/stdc++.h>
using namespace std;
//zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
//a both another first second third
int getNum(string in){
    if(in == "zero"){
        return 0;
    }else if(in == "one" || in == "a" || in == "another"){
        return 1;
    }else if(in == "two" || in == "second" || in == "both"){
        return 2;
    }else if(in == "three" || in == "third"){
        return 3;
    }else if(in == "four"){
        return 4;
    }else if(in == "five"){
        return 5;
    }else if(in == "six"){
        return 6;
    }else if(in == "seven"){
        return 7;
    }else if(in == "eight"){return 8;}
    else if(in == "nine")return 9; else if(in == "ten"){return 10;}else if (in == "eleven")return 11;else if(in =="twelve")return 12;
    else if(in == "thirteen" )return 13; else if(in == "forteen")return 14;else if(in == "fifteen")return 15; else if(in =="sixteen") return 16;
    else if(in =="seventeen")return 17; else if(in == "eighteen")return 18; else if(in == "nighteen") return 19; else if(in == "twenty") return 20;
    else {
        return 0;
    }
}
int main(){
    string a,b,c,d,e,f;
    cin >>a>>b>>c>>d>>e>>f;
    vector<int> number(6,0);
    //int exist = 0;
    number[0] = getNum(a);
    number[1] = getNum(b);
    number[2] = getNum(c);
    number[3] = getNum(d);
    number[4] = getNum(e);
    number[5] = getNum(f);
    for(int i = 0; i< 6;i++){
        number[i] = (number[i] * number[i]) % 100;
        //cout << number[i] <<" ";
    }
    //cout<<"\n";
    std::sort(number.begin(),number.end());
    long long ans = 0;
    for(int k : number){
        //cout<<k<<" ";
        ans *=100;
        ans += k;
    }
    cout<<ans;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    const map<string,int> NUM = {          // ← 一张表，Ctrl+F 就能对题面核一遍
        {"zero",0},
        {"one",1},{"a",1},{"another",1},{"first",1},
        {"two",2},{"both",2},{"second",2},
        {"three",3},{"third",3},
        {"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},
        {"ten",10},{"eleven",11},{"twelve",12},{"thirteen",13},{"fourteen",14},
        {"fifteen",15},{"sixteen",16},{"seventeen",17},{"eighteen",18},
        {"nineteen",19},{"twenty",20}
    };

    vector<int> v;
    string w;
    while (cin >> w) {
        while (!w.empty() && !isalpha((unsigned char)w.back())) w.pop_back(); // 防御句号
        auto it = NUM.find(w);
        if (it == NUM.end()) continue;                        // 不是数字词 → 不产生块
        v.push_back(it->second * it->second % 100);
    }

    sort(v.begin(), v.end());
    long long ans = 0;
    for (int x : v) ans = ans * 100 + x;                      // 前导 0 自动消失
    cout << ans << '\n';
}