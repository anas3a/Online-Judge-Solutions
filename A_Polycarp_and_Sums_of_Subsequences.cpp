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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n = 7;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    if (v[i] + v[j] + v[k] == v[n - 1])
                    {
                        cout << v[i] << " " << v[j] << " " << v[k] << endl;
                        i = n;
                        j = n;
                        k = n;
                    }
                }
            }
        }
    }
    return 0;
}