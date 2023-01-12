#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    vi sa(26, 0), sb(26, 0), ta(26, 0), tb(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            sa[s[i] - 'A']++;
        else
            sb[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] >= 'A' && t[i] <= 'Z')
            ta[t[i] - 'A']++;
        else
            tb[t[i] - 'a']++;
    }
    ll c1 = 0, c2 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (sa[i])
        {
            ll x = min(sa[i], ta[i]);
            c1 += x;
            sa[i] -= x, ta[i] -= x;
        }
        if (sb[i])
        {
            ll x = min(sb[i], tb[i]);
            c1 += x;
            sb[i] -= x, tb[i] -= x;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (sa[i])
        {
            ll x = min(sa[i], tb[i]);
            c2 += x;
        }
        if (sb[i])
        {
            ll x = min(sb[i], ta[i]);
            c2 += x;
        }
    }
    cout << c1 << " " << c2 << endl;
    return 0;
}
