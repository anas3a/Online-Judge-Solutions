// Page replacement - FIFO

// 13 4
// 7 0 1 2 0 3 0 4 2 3 0 3 2


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, capacity;
    // input page file & capacity
    cin >> n >> capacity;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // s is ram
    set<int> s;
    // q is queue fifo
    queue<int> q;
    int fault_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // if value doesnt exist in ram
        if (s.count(v[i]) == 0)
        {
            // page fault increasing
            fault_cnt++;
            if (s.size() == capacity)
            {
                // ram is full
                int first = q.front();
                q.pop();
                s.erase(first);
            }
            s.insert(v[i]);
        }
        // value insert in queue
        q.push(v[i]);    
    }
    // Hit
    cout << n - fault_cnt << endl;
    // Miss
    cout << fault_cnt << endl;
    return 0;
}

// FIFO
// First in First out
// 1 + 1 + 1 + 1 + 0 + 1 + 0 + 1 + 0+ 0 + 1 + 0 + 0
// 4
// 7 0 1 2 0 3 0 4 2 3 0 3 2
// 2 3 4 0

// LRU
// 1 + 1 + 1 + 1 + 0 + 1 + 0 + 1 + 0 + 0 + 0 + 0 + 0
// 7 0 1 2 0 3 0 4 2 3 0 3 2
// 0 2 3 4  

// Optimal 
// 1 + 1 + 1 + 1 + 0 + 1 + 0 + 1 + 0 + 0 + 0 + 0
// 7 0 1 2 0 3 0 4 2 3 0 3 2 
// 3 0 2 4 

// 4 5 6 2 9