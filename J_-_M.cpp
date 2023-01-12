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

    ll n, m;
    cin >> n >> m;
    vll v(n);
    ll sum = 0;
    for (auto &i : v)
        cin >> i, sum += 2 * i;
    sort(rall(v));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m >= 2 * (n - i))
        {
            sum -= (2 * v[i]);
            ans += v[i] * (2 * (n - i));
            ans += sum;
            m -= 2 * (n - i);
            dg(sum);
        }
        else
        {
            ans += 2 * v[i];
            m--;
            for (int j = i + 1; j < n; j++)
            {
                if (!m)
                    break;
                ans += v[i];
                ans += v[j];
                m--;
                if (!m)
                    break;
                ans += v[i];
                ans += v[j];
                m--;
            }
            break;
        }
    }
    cout << ans << nl;
    return 0;
}