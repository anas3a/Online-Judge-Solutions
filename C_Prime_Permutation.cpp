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

    string s;
    cin >> s;
    ll n = sz(s);
    vi prime;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.pb(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vll v(26, 0);
    ll mx = 0;
    char c;
    for (auto &i : s)
    {
        v[i - 'a']++;
        if (v[i - 'a'] > mx)
        {
            mx = v[i - 'a'];
            c = i;
        }
    }
    string ans(n, 'Z');
    for (auto &i : prime)
    {
        if (i > n / 2)
            break;
        for (int j = i; j <= n; j += i)
        {
            if (ans[j - 1] == 'Z')
            {
                ans[j - 1] = c;
                mx--;
            }
        }
    }
    if (mx < 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        v[c - 'a'] = mx;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == 'Z')
            {
                int j = 0;
                while (!v[j])
                    j++;
                ans[i] = char('a' + j);
                v[j]--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}