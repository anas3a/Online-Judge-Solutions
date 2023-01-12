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

    int nx;
    cin >> nx;
    vi original(nx);
    for (auto &i : original)
        cin >> i;
    int n;
    cin >> n;
    vector<int> v_low, v_high, ans;
    for (auto &i : original)
    {
        if (i < n)
            v_low.pb(i);
        else
            v_high.pb(i);
    }
    sort(rall(v_low));
    sort(all(v_high));
    int i = 0, j = 0;
    while (i < v_low.size() && j < v_high.size())
    {
        if (abs(v_low[i] - n) < abs(v_high[j] - n))
            ans.pb(v_low[i++]);
        else
            ans.pb(v_high[j++]);
    }
    while (i < v_low.size())
        ans.pb(v_low[i++]);
    while (j < v_high.size())
        ans.pb(v_high[j++]);

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}