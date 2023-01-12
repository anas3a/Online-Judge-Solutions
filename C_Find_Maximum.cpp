#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

    ll n;
    cin >> n;
    vll v(n), vx(n, 0);
    for (auto &i : v)
        cin >> i;
    string s;
    cin >> s;
    ll sum = 0, sx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            sum += v[i];
            vx[i] = sx - v[i];
        }
        else
            sx += v[i];
    }
    sort(rall(vx));
    if (vx[0] > 0)
        sum += vx[0];
    cout << sum << endl;
    return 0;
}
