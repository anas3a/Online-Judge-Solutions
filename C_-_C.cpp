#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        map<ll, ll> m;
        for (auto &i : v)
            cin >> i, m[i]++;
        ll sum = 0;
        priority_queue<ll> pq;
        for (auto &i : m)
            pq.push(i.ss);
        ll ans = 0;
        while (!pq.empty())
        {
            int u = pq.top();
            pq.pop();
            if (pq.empty())
            {
                ans++;
                u--;
                if (u)
                    pq.push(u);
            }
            else
            {
                int v = pq.top();
                pq.pop();
                if (u >= 1 && v >= 1)
                {
                    ans++;
                    u--;
                    v--;
                    if (u)
                        pq.push(u);
                    if (v)
                        pq.push(v);
                }
                else if (u >= 1)
                {
                    ans++;
                    u--;
                    if (u)
                        pq.push(u);
                }
            }
        }
        cout << ans << nl;
    }
    return 0;
}