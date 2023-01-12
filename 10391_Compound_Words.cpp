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

    set<string> v;
    string s;
    while (cin >> s)
        v.insert(s);
    for (auto &s : v)
    {
        for (int i = 1; i < s.size(); i++)
        {
            string prefix = s.substr(0, i);
            string suffix = s.substr(i, s.size() - i);
            if (v.count(prefix) && v.count(suffix))
            {
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}
