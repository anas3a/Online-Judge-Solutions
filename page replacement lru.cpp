// Page replacement - LRU

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
    map<int, int> mp;
    int fault_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // if value isnt in ram
        if (s.count(v[i]) == 0)
        {
            fault_cnt++;
            // if ram is full
            if (s.size() == capacity)
            {
                int ind = INT_MAX, val;
                // traversing ram
                for (auto &j : s)
                {
                    if (mp[j] < ind)
                    {
                        ind = mp[j];
                        val = j;
                    }
                }
                // delete from ram
                s.erase(val);
            }
            s.insert(v[i]);
        }
        mp[v[i]] = i;
    }
    cout << fault_cnt << endl;
    return 0;
}
