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

    int c, d, v;
    cin >> c >> d >> v;
    map<string, int> m;
    while (v--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        s1 += 'x';
        s2 += 'y';
        m[s1]++, m[s2]++;
    }
    int ans = 0;
    for (auto &i : m)
        ans = max(ans, i.ss);
    cout << ans << endl;
    return 0;
}