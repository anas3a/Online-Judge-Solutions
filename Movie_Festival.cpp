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

    int n;
    cin >> n;
    vpl v(n);
    for (auto &i : v)
        cin >> i.ss >> i.ff;
    sort(all(v));
    ll cnt = 0, etime = 0;
    for (auto &i : v)
    {
        if (i.ss >= etime)
        {
            cnt++;
            etime = i.ff;
        }
    }
    cout << cnt << endl;
    return 0;
}
