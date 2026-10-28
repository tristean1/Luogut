#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> tab(n, vector<int>(n));
    int now = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = now;
            now++;
        }
    }
    int mid_i, mid_j;
    int scale;
    int direct;
    vector<vector<int>> vice_tab;
    for (int temp = 0; temp < m; temp++)
    {
        vice_tab = tab;
        cin >> mid_i >> mid_j >> scale >> direct;
        mid_i--;
        mid_j--;
        if (direct == 1)
        {
            // 逆时针转90
            for (int i = mid_i - scale; i <= mid_i + scale; i++)
            {
                for (int j = mid_j - scale; j <= mid_j + scale; j++)
                {
                    
                   //  tab[i][j] = vice_tab[mid_i + (mid_j - j)][mid_j + ( mid_i - i)];
                  // tab[i][j] = vice_tab[mid_j + ( mid_i - i)][mid_i + (mid_j - j)];
                  //tab[i][j] = vice_tab[mid_i + (mid_j - j)][mid_j - (mid_i - i)];
                  tab[i][j] = vice_tab[mid_i - (mid_j - j)][mid_j + (mid_i - i)];
                }
            }
        }
        else
        {
            // 顺时针转90
            for (int i = mid_i - scale; i <= mid_i + scale; i++)
            {
                for (int j = mid_j - scale; j <= mid_j + scale; j++)
                {
                   
                   // tab[i][j] = vice_tab[mid_i - (mid_j -j)][mid_j - (mid_i -i)];
                   //tab[i][j] = vice_tab[mid_j - (mid_i -i)][mid_i - (mid_j -j)];
                  // tab[i][j] = vice_tab[mid_i - (mid_j - j)][mid_j + (mid_i - i)];
                  tab[i][j] = vice_tab[mid_i + (mid_j - j)][mid_j - (mid_i - i)];
                }
            }
        }
#ifdef LOCAL
        cerr << '\n';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cerr << tab[i][j] << " ";
            }
            cerr << '\n';
        }
        cerr<< '\n';
#endif
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << '\n';
    }
}