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

int n;
string s, ans = "Just a legend";
ll base1 = 233, base2 = 241;
ll md1 = 1008897979, md2 = 1008902467;
vll hash1, hash2, p1, p2;

bool f(ll m)
{
    if (!m)
        return false;

    pll prefhash, suffhash = {0, 0};
    prefhash.ff = hash1[m - 1], prefhash.ss = hash2[m - 1];
    for (int i = n - 1, j = 0; i >= n - m; i--, j++)
    {
        suffhash.ff = ((suffhash.ff * base1) + s[i]) % md1;
        suffhash.ss = ((suffhash.ss * base2) + s[i]) % md2;
    }
    dg(m);
    dg(prefhash.ff);
    dg(suffhash.ff);
    prefhash.ff = (prefhash.ff * p1[n - m]) % md1;
    prefhash.ss = (prefhash.ss * p2[n - m]) % md2;
    if (prefhash != suffhash)
        return false;
    for (int i = 0; i < n - m - 1; i++)
    {
        pll cur_hash;
        cur_hash.ff = (hash1[i + m] - hash1[i] + md1) % md1;
        cur_hash.ss = (hash2[i + m] - hash2[i] + md2) % md2;
        cur_hash.ff = (cur_hash.ff * p1[n - (i + m) - 1]) % md1;
        cur_hash.ss = (cur_hash.ss * p2[n - (i + m) - 1]) % md2;
        if (prefhash == cur_hash)
        {
            ans.clear();
            for (int j = 0; j < m; j++)
                ans += s[j];
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = sz(s);
    hash1.resize(n, 0), hash2.resize(n, 0), p1.resize(n, 1), p2.resize(n, 1);
    for (int i = 1; i < n; i++)
    {
        p1[i] = p1[i - 1] * base1 % md1;
        p2[i] = p2[i - 1] * base2 % md2;
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            hash1[i] = hash1[i - 1], hash2[i] = hash2[i - 1];
        hash1[i] = (hash1[i] + (p1[i] * s[i])) % md1;
        hash2[i] = (hash2[i] + (p2[i] * s[i])) % md2;
    }

    ll l = 0, r = n - 1;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (f(m))
            l = m;
        else
            r = m;
    }
    cout << ans << endl;
    return 0;
}