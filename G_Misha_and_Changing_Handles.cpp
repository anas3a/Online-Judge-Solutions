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

    ll n;
    cin >> n;
    map<string, string> m1, m2;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (!m2.count(s1))
        {
            m1[s1] = s2;
            m2[s2] = s1;
        }
        else
        {
            string sx = m2[s1];
            m2[s2] = sx;
            m1[sx] = s2;
        }
    }
    cout << sz(m1) << endl;
    for (auto &i : m1)
        cout << i.ff << " " << i.ss << endl;
    return 0;
}