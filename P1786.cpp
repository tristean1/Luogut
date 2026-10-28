#include <bits/stdc++.h>
using namespace std;
string mode;
struct pop
{
    string name;
    string former_position;
    int bg;
    int level;

    int pos; // 输入中出现的位置
    const bool operator<(pop &another)
    {
       
        if (mode == "ab")
        { // 排序顺序
            
            if (bg > another.bg)
            {
                return true;
            }
            else if (bg == another.bg)
            {
                return pos < another.pos;
            }
            else
            {
                return false;
            }
        }
        else
        { // 显示顺序
            #ifdef LOCAL
             cerr<<'\n';
        cerr<<"比较任务 "<<name<<" "<<former_position<<" "<<bg<<" "<<level<<" "<<pos<<'\n';
        cerr<<"比较任务 "<<another.name<<" "<<another.former_position<<" "<<another.bg<<" "<<another.level<<" "<<another.pos<<'\n';
        cerr<<'\n';
        #endif
            if (level > another.level)
            {
                return true;
            }
            else if (level == another.level)
            {
                return pos < another.pos;
            }
            else
            {
                return false;
            }
        }
    }
};
int main()
{
    int popuarity;
    cin >> popuarity;
    vector<pop> pops(popuarity);
    for (int i = 0; i < popuarity; i++)
    {
        cin >> pops[i].name >> pops[i].former_position >> pops[i].bg >> pops[i].level;
        pops[i].pos = i;
    }
    mode = "ab";
    sort(pops.begin() + 3, pops.end());
    #ifdef LOCAL
     for (int i = 0; i < popuarity; i++)
    {
        cout << pops[i].name << " " << pops[i].former_position << " " << pops[i].level << '\n';
    }
    #endif
    mode = "ld";
    for (int i = 0; i < 3; i++)
    {
        // cout<<pops[i].name <<" "<< pops[i].former_position <<" "<<pops[i].level<<'\n';
    } // 前三个不改动，原样返回
    for (int i = 3; i < min(5, popuarity); i++)
    {
        // cout<<pops[i].name << " Hufa " <<pops[i].level <<'\n';
        pops[i].former_position = "HuFa";
    }
    if(popuarity>=3) sort(pops.begin() + 3, pops.begin() + min(5, popuarity));
    for (int i = 5; i < min(9, popuarity); i++)
    {
        // cout<<pops[i].name << " Zhanglao " <<pops[i].level <<'\n';
        pops[i].former_position = "ZhangLao";
    }
     if(popuarity>=5)sort(pops.begin() + 5, pops.begin() + min(9, popuarity));
    // sort(pops.begin()+)
    for (int i = 9; i < min(16, popuarity); i++)
    {
        // cout<<pops[i].name << " Tangzhu " <<pops[i].level <<'\n';
        pops[i].former_position = "TangZhu";
    }
     if(popuarity>=9)sort(pops.begin() + 9, pops.begin() + min(16, popuarity));
    for (int i = 16; i < min(41, popuarity); i++)
    {
        // cout<<pops[i].name << " Jingying " <<pops[i].level <<'\n';
        pops[i].former_position = "JingYing";
    }
     if(popuarity>=16)sort(pops.begin() + 16, pops.begin() + min(41, popuarity));
    for (int i = 41; i < popuarity; i++)
    {
        // cout<<pops[i].name << " Bangzhong " <<pops[i].level <<'\n';
        pops[i].former_position = "BangZhong";
    }
     if(popuarity>=41)sort(pops.begin() + 41, pops.end());
    for (int i = 0; i < popuarity; i++)
    {
        cout << pops[i].name << " " << pops[i].former_position << " " << pops[i].level << '\n';
    }
}