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
#define dg(x) cout << #x << " = " << x << endl

bool comp(char &a, char &b)
{
    if (a == b)
        return false;
    return a < b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n = 10, sum = 0;
        vll v(n);
        string ans;
        for (auto &i : v)
            cin >> i, sum += i;
        priority_queue<pll> p;
        for (int i = 0; i < n; i++)
        {
            p.push({v[i], i});
        }
        pll x = {0, 10};
        while (!p.empty())
        {
            pll u = p.top();
            p.pop();
            if (u.ff > 0)
                ans += char('0' + u.ss);
            u.ff--;
            if (x.ff > 0)
                p.push(x);
            x = u;
        }
        reverse(all(ans));
        if (ans[0] == '0' && sz(ans) > 1)
            swap(ans[0], ans[1]);
        bool flag = true;
        for (int i = 0; i < sz(ans) - 1; i++)
        {
            if (ans[i] == ans[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}