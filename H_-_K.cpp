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

    // vi v(15, 0);
    // vvi ans;
    // int ind = 14;
    // while (true)
    // {
    //     v[ind]++;
    //     ans.pb(v);
    //     if (v[ind] == 9 && ind == 0)
    //         break;
    //     if (v[ind] == 9)
    //     {
    //         ind--;
    //     }
    // }
    // ll k;
    // cin >> k;
    // for (int i = 0; i < k; i++)
    // {
    //     for (auto &j : ans[i])
    //     {
    //         if (j)
    //             cout << j;
    //     }
    //     cout << nl;
    // }

    int n;
    cin >> n;
    set<pair<double, int>> st;
    for (ll i = 1000; i < n; i++)
    {
        ll j = i;
        ll sum = 0;
        while (j)
        {
            sum += j % 10;
            j /= 10;
        }
        double x = i / double(sum);
        st.insert({x, i});
    }
    for (auto &i : st)
    {
        if (i.ss % 10 == 9)
            cout << i.first << " " << i.second << endl;
    }
    return 0;
}