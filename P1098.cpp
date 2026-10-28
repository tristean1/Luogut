#include <bits/stdc++.h>
using namespace std;
bool isame(char a, char b)
{
    return ('a' <= a && a <= 'z' && 'a' <= b && b <= 'z') || ('0' <= a && a <= '9' && '0' <= b && b <= '9');
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string input;
    string ans;
    cin >> input;
    string add;
    for (unsigned long int i = 0; i < input.length(); i++)
    {
        if (i != 0 && i != input.length() - 1 && input[i] == '-' && isame(input[i - 1], input[i + 1]) && input[i + 1] > input[i - 1])
        {   
            add = "";
            // 是合法的-，进行填充
            if (p1 != 3)
            {
                if ('a' <= input[i - 1] && input[i - 1] <= 'z')
                {
                    // 字母填充模式
                    if (p1 == 1)
                    {
                        for (char j = input[i - 1] + 1; j < input[i + 1]; j++)
                        {
                            add += j;
                        }
                    }
                    else
                    { // 小写
                        for (char j = input[i - 1] + 1; j < input[i + 1]; j++)
                        {
                            add += (j + 'A' - 'a');
                        } // 大写
                    }
                }
                else
                {
                    // 数字填充模式
                    for (char j = input[i - 1] + 1; j < input[i + 1]; j++)
                    {
                        add += j;
                    }
                }
            }
            else
            {
                for (char j = input[i - 1] + 1; j < input[i + 1]; j++)
                {
                    add += '*'; // 计数填充模式
                }
            }
            if (p2 != 1)
            {
                string _add = "";
                for (unsigned long int t = 0; t < add.length(); t++)
                {
                    for (int j = 0; j < p2; j++)
                    {
                        _add += add[t];
                    } // 倍增填充
                }
                add = _add;
            }
            if (p3 == 2)
            {
                string _add = "";
                for (int j = add.length() - 1; j >= 0; j--)
                {
                    _add += add[j];
                }
                add = _add;
            }
            //cerr<<"-"<<add<<'-'<<"\n";
            ans += add;
            continue;
        }
        ans += input[i];
    }
    cout << ans;
}