#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    const int MAX_TIME = 10000;
    int m, n;
    cin >> m >> n; // m机器数 n工件数
    vector<int> order(n * m);
    vector<int> phase(n, 0);                                     // 第n个工件进行到phase【i】步
    vector<vector<int>> select_which_machine(n, vector<int>(m)); // 第i个工件的第j个工序用s__m[i][j]机器
    vector<vector<int>> times(n, vector<int>(m));                // 第i个工件的第j个工序的加工时间
    for (int i = 0; i < m * n; i++)
    {
        cin >> order[i]; // 第n个工件也是1-based！
        order[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> select_which_machine[i][j]; // 机器号是1-based！，转为0-based
            select_which_machine[i][j]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> times[i][j];
        }
    }
    vector<vector<bool>> consumed_time(m, vector<bool>(MAX_TIME, 0)); // 第i台机器的j时间是否空闲 0=空闲 1=忙碌
    vector<int> last_step_at(n, 0);                                   // 第i个工件的上次加工时间
    for (int tmp = 0; tmp < m * n; tmp++)
    {
        // 主循环，依次分配每个工序到机器
        int giving_this_thing = order[tmp];

        int need_time = times[giving_this_thing][phase[giving_this_thing]];
        int which_machine = select_which_machine[giving_this_thing][phase[giving_this_thing]];
        // 向该机器中插入任务
        int start = -1;
        for (int s = last_step_at[giving_this_thing]; s + need_time <= MAX_TIME; s++)
        { // 只找起点
            bool ok = true;
            for (int t = 0; t < need_time; t++)
                if (consumed_time[which_machine][s + t])
                {
                    ok = false;
                    break;
                }
            if (ok)
            {
                start = s;
                break;
            }
        }
        for (int t = start; t < start + need_time; t++) {// 只写
            consumed_time[which_machine][t] = 1;
            
        }
        last_step_at[giving_this_thing] = start + need_time ;
        phase[giving_this_thing]++; // 处理后阶段数+1
    }
    // 任务分配完，统计最大时间
    int max_time = 0;
    int ct;
    for (int i = 0; i < m; i++)
    {
        ct = 0;
        for (int j = 0; j < MAX_TIME; j++)
        {
            if (consumed_time[i][j])
            {
                ct = j;
            }
        }
        max_time = max(max_time, ct);
    }
    cout << max_time+1 << '\n';
    return 0;
}