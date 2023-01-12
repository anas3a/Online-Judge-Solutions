// Deadlock avoidance - Banker's algorithm

// 5 3

// 3 3 2

// 7 5 3                  
// 3 2 2                
// 9 0 2                
// 2 2 2                
// 4 3 3

// 0 1 0                 
// 2 0 0                 
// 3 0 2                 
// 2 1 1                 
// 0 0 2


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> max(n, vector<int>(m)), alloc(n, vector<int>(m)), need(n, vector<int>(m));
    vector<int> work(m);

    for (auto &i : work)
        cin >> i;
    for (auto &i : max)
        for (auto &j : i)
            cin >> j;
    for (auto &i : alloc)
        for (auto &j : i)
            cin >> j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    vector<bool> finish(n, false);
    vector<int> ans;

    while (ans.size() < n)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                int j; 
                for (j = 0; j < m; j++)
                    if (work[j] < need[i][j])
                        break;
                if (j == m)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    ans.push_back(i);
                    finish[i] = true;
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
    }

    if (ans.size() < n)
        cout << "Unsafe State!" << endl;
    else
    {
        cout << "Safe sequence: ";
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}