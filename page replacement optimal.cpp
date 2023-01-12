// Page replacement - Optimal

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    set<int> s;
    int fault_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.count(v[i]) == 0)
        {
            fault_cnt++;
            if (s.size() == capacity)
            {
                int ind = INT_MIN, val;
                for (auto &j : s)
                {
                    bool flag = false;
                    for (int k = i + 1; k < n; k++)
                    {
                        if (v[k] == j)
                        {
                            flag = true;
                            if (k > ind)
                            {
                                ind = k;
                                val = j;
                            }
                        }
                    }
                    if (!flag)
                    {
                        val = j;
                        break;
                    }
                }
                s.erase(val);
            }
            s.insert(v[i]);
        }
    }
    cout << fault_cnt << endl;
    return 0;
}