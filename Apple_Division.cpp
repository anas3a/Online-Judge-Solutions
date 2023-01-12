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

int n;
vll v;
ll ans;
void f(int i, ll s1, ll s2)
{
    if (i == n)
    {
        ans = min(ans, abs(s1 - s2));
        return;
    }
    f(i + 1, s1 + v[i], s2);
    f(i + 1, s1, s2 + v[i]);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    ans = LLONG_MAX;
    f(0, 0, 0);
    cout << ans << endl;
    return 0;
}
