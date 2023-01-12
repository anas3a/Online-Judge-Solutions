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

    ll n, t;
    cin >> n >> t;
    string s1, s2, s3(n, 'u');
    cin >> s1 >> s2;
    ll x = n - t, cnt = 0;
    vector<bool> v(n, false);
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (cnt == x)
            break;
        if (s1[i] == s2[i])
        {
            s3[i] = s1[i];
            cnt++;
            v[i] = true;
        }
    }
    ll z = x - cnt;
    if (z > 0)
    {
        int j = cnt;
        for (int i = 0; i < n && j < x; i++)
        {
            if (!v[i])
            {
                s3[i] = s1[i];
                v[i] = true;
                j++;
            }
        }
        if (j < x)
            f = false;
        j = cnt;
        for (int i = 0; i < n && j < x; i++)
        {
            if (!v[i])
            {
                s3[i] = s2[i];
                v[i] = true;
                j++;
            }
        }
        if (j < x)
            f = false;
    }
    if (!f)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
            {
                vector<bool> vx(26, 0);
                vx[s1[i] - 'a'] = 1;
                vx[s2[i] - 'a'] = 1;
                for (int j = 0; j < 26; j++)
                {
                    if (vx[j] == 0)
                    {
                        s3[i] = char('a' + j);
                        break;
                    }
                }
            }
        }
        cout << s3 << endl;
    }
    return 0;
}
