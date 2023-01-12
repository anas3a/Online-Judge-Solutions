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

    ll a, b;
    cin >> a >> b;
    string s, t;
    cin >> s >> t;
    map<char, int> m, x;
    for (auto &i : t)
        m[i]++;
    ll l = 0, ans = 0;
    for (int i = 0; i < a; i++)
    {
        x[s[i]]++;
        while (m[s[i]] < x[s[i]])
            x[s[l++]]--;
        ans += i - l + 1;
    }
    cout << ans << endl;
    return 0;
}
