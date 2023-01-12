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
    vll v(n);
    for (auto &i : v)
        cin >> i;
    int mx = 0, ind = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int cnt = 1;
        while (j < n - 1 && v[j + 1] - v[j] == 1)
        {
            j++;
            cnt++;
        }
        if (cnt > mx)
        {
            mx = cnt;
            ind = i;
        }
        i = j;
    }
    dg(mx);
    dg(ind);
    return 0;
}