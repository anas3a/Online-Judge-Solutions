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
    vll v(n);
    for (auto &i : v)
        cin >> i;
    map<ll, ll> m;
    set<ll> s;
    ll l = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        m[v[i]]++;
        s.insert(v[i]);
        ll mx = *s.rbegin(), mn = *s.begin();
        while (mx - mn > k)
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
                s.erase(v[l]);
            l++;
            mx = *s.rbegin(), mn = *s.begin();
        }
        ans += i - l + 1;
    }
    cout << ans << endl;
    return 0;
}
