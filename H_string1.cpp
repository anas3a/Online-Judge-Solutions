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

    int n, cnt = 0;
    string s;
    cin >> n >> s;
    vi v;
    int i = 0, j = 0;
    while (i < n)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[j] != s[i])
                break;
        }
        v.pb(j - i);
        i = j;
    }
    j = 0;
    ll m = sz(v);
    for (int i = 0; i < m; i++)
    {
        j = max(i, j);
        while (j < m)
        {
            if (v[j] != 1)
                break;
            j++;
        }
        if (j < m)
            v[j]--;
        else
            i++;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
