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

    string s, t;
    cin >> s >> t;
    ll cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        if (s[i] == '#')
            cnt++;
        if (t[i] == '#')
            cnt++;
    }
    if (cnt >= 3)
        cout << "Yes" << endl;
    else
    {
        if (s[0] == t[1] || s[1] == t[0])
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}