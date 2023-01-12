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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vll v(n + 1, 0);

    deque<int> q;
    ll ans;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        q.push_back(x);
    }
    ll a, b;
    while (true)
    {
        ll a = q.front();
        q.pop_front();
        ll b = q.front();
        q.pop_front();
        if (a < b)
            swap(a, b);
        v[a]++;
        q.push_front(a);
        q.push_back(b);
        if (v[a] >= k || a == n)
        {
            ans = a;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}