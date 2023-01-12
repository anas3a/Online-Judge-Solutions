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

    ll n, p, sum = 0;
    cin >> n >> p;
    vll v(n);
    for (auto &i : v)
        cin >> i, sum += i;
    ll in, cnt = LLONG_MAX, z = 0, y = 0;
    z = p / sum;
    y = z * sum;
    for (int i = 0; i < n; i++)
    {
        ll s = y, cx = 0, j = i;
        while (s < p)
        {
            s += v[j];
            j++;
            cx++;
            if (j == n)
                j = 0;
        }
        if (cx < cnt)
            cnt = cx, in = i + 1;
    }
    cout << in << " " << cnt + (z * n) << endl;
    return 0;
}
