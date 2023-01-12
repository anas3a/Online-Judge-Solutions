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
        ll n;
        cin >> n;
        vll v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v[x]++;
        }
        multiset<ll> mt;
        for (int i = 0; i <= n; i++)
        {
            if (v[i] > 1)
            {
                for (int j = 1; j < v[i]; j++)
                    mt.insert(i);
            }
        }
        ll flag = true;
        ll cnt1 = 0, sum1 = 0;
        for (int i = 0; i <= n; i++)
        {
            if (sum1 < i || !flag)
                cout << -1 << " ", flag = false;
            else
            {
                cout << v[i] + cnt1 << " ";
            }
            if (!v[i])
            {
                auto ind = mt.lower_bound(i);
                if (ind != mt.begin())
                    ind--;
                cnt1 += i - (*ind);
                if (ind != mt.begin())
                    mt.erase(ind);
            }
            sum1 += v[i];
        }
        cout << endl;
    }
    return 0;
}