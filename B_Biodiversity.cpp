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
    map<string, ll> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    ll cnt = 0, mx = -1;
    string ans;
    for (auto &i : m)
    {
        cnt += i.ss;
        if (i.ss > mx)
        {
            mx = max(mx, i.ss);
            ans = i.ff;
        }
    }
    cnt -= mx;
    if (mx > cnt)
        cout << ans << endl;
    else
        cout << "NONE" << endl;
    return 0;
}
