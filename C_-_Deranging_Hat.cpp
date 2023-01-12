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
    vpi ans;
    for (int i = 0; i < sz(s); i++)
    {
        for (int j = i + 1; j < sz(s); j++)
        {
            if (s[i] > s[j])
            {
                swap(s[i], s[j]);
                ans.pb({j + 1, i + 1});
            }
        }
    }
    reverse(all(ans));
    for (auto &i : ans)
        cout << i.ff << " " << i.ss << endl;
    return 0;
}