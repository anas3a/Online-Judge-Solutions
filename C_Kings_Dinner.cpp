#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    int n, cs = 0;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        vvi v(k + 1);
        bool fx = true;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            while (x--)
            {
                int a;
                cin >> a;
                if (i == a)
                    fx = false;
                v[i].pb(a);
            }
        }
        set<int> s1, s2;
        s1.insert(1);
        for (int i = 2; i <= k; i++)
        {
            bool f = true;
            for (auto &j : v[i])
            {
                if (s1.count(j))
                {
                    f = false;
                    s2.insert(i);
                    break;
                }
            }
            if (f)
                s1.insert(i);
        }
        for (auto &i : s2)
        {
            for (auto &j : v[i])
            {
                if (s2.count(j))
                {
                    fx = false;
                    break;
                }
            }
            if (!fx)
                break;
        }
        for (auto &i : s1)
        {
            for (auto &j : v[i])
            {
                if (s1.count(j))
                {
                    fx = false;
                    break;
                }
            }
            if (!fx)
                break;
        }
        cout << "Case " << ++cs << ": ";
        if (!fx)
            cout << "0 0 0" << endl;
        else
            cout << 1 << " " << min(sz(s1), sz(s2)) << " " << max(sz(s1), sz(s2)) << endl;
    }
    return 0;
}
