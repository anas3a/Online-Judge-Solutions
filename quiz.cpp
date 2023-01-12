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

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string a, b;
        cin >> a >> b;
        int cnt = 0;
        int n = sz(a);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                cnt++;
        }
        int ans = min(cnt, k);
        int cntx = n - cnt;
        if (k > cnt)
            cntx -= k - cnt;
        ans += cntx;
        cout << ans << endl;
    }
    return 0;
}