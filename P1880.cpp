#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> sinput(2 * n + 1);
int sum(int a, int b)
{
    return sinput[b] - sinput[a - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int n;
    cin >> n;
    sinput[0] = 0;
    vector<int> input(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
        input[n + i] = input[i];
        sinput[i] = input[i] + sinput[i - 1];

    } // 输入
    vector<vector<int>> dpmax(2 * n + 1, vector<int>(2 * n + 1));
    vector<vector<int>> dpmin(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 0; i <= 2 * n; i++)
    {
        dpmax[i][i] = 0;
        dpmin[i][i] = 0;
    }

    for (int length = 2; length <= n; length++)
    {
        // 外层循环
        for (int l = 1; l <= n; l++)
        {
            int r = l + length;
            dpmax[l][r] = 0;
            dpmin[l][r] = INT_MAX;

            for (int k = l; k <= r - 1; k++)
            {
                dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r]) + sum(l, r);
                dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] + dpmax[k + 1][r]) + sum(l, r);
            }
        }
    }

    cout << dpmin[1][n] << '\n'
         << dpmax[1][n];
    return 0;
}
