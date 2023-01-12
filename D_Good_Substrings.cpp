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

    string s, t;
    int k;
    cin >> s >> t >> k;

    ll base1 = 233, base2 = 241;
    ll md1 = 1008897979, md2 = 1008902467;
    int n = sz(s);
    vll hash1(n, 0), hash2(n, 0);
    vll p1(n, 0), p2(n, 0);
    p1[0] = p2[0] = 1;
    for (int i = 1; i < n; i++)
    {
        p1[i] = (p1[i - 1] * base1) % md1;
        p2[i] = (p2[i - 1] * base2) % md2;
    }
    for (int i = 0; i < sz(s); i++)
    {
        if (i)
            hash1[i] = hash1[i - 1], hash2[i] = hash2[i - 1];
        hash1[i] = (hash1[i] + (p1[i] * s[i])) % md1;
        hash2[i] = (hash2[i] + (p2[i] * s[i])) % md2;
    }
    ll sum = 0;
    set<pll> st;
    for (auto &i : t)
        i = i == '0' ? '1' : '0';
    for (int i = 0, l = 0; i < sz(s); i++)
    {
        sum += t[s[i] - 'a'] - '0';
        while (sum > k)
        {
            sum -= t[s[l++] - 'a'] - '0';
        }
        for (int j = l; j <= i; j++)
        {
            ll cur_hash1 = hash1[i], cur_hash2 = hash2[i];
            if (j)
            {
                cur_hash1 = (hash1[i] - hash1[j - 1] + md1) % md1;
                cur_hash2 = (hash2[i] - hash2[j - 1] + md2) % md2;
            }
            cur_hash1 = (cur_hash1 * p1[n - j - 1]) % md1;
            cur_hash2 = (cur_hash2 * p2[n - j - 1]) % md2;
            st.insert({cur_hash1, cur_hash2});
        }
    }
    cout << sz(st) << nl;
    return 0;
}