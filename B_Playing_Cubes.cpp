#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

    ll n, m, x = 0, y = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0, z = 1;
    cin >> n >> m;
    ll a = n, b = m;
    while (n != 0 || m != 0)
    {
        if (z)
        {
            if (x == 0)
            {
                x = 1;
                n--;
            }
            else if (x == 1 && n != 0)
            {
                n--;
                c1++;
            }
            else if (x == 2 && m != 0)
            {
                m--;
                c1++;
            }
            else
            {
                if (m)
                {
                    m--;
                    d1++;
                    x = 2;
                }
                else
                {
                    n--;
                    d1++;
                    x = 1;
                }
            }
            z = !z;
        }
        else
        {
            if (x == 1 && m != 0)
            {
                m--;
                d1++;
                x = 2;
            }
            else if (x == 2 && n != 0)
            {
                n--;
                d1++;
                x = 1;
            }
            else
            {
                if (m)
                {
                    m--;
                    c1++;
                    x = 2;
                }
                else
                {
                    n--;
                    c1++;
                    x = 1;
                }
            }
            z = !z;
        }
    }
    x = 0;
    z = 1;
    while (a != 0 || b != 0)
    {
        if (z)
        {
            if (x == 0)
            {
                x = 2;
                b--;
            }
            else if (x == 1 && a != 0)
            {
                a--;
                c2++;
            }
            else if (x == 2 && b != 0)
            {
                b--;
                c2++;
            }
            else
            {
                if (b)
                {
                    b--;
                    d2++;
                    x = 2;
                }
                else
                {
                    a--;
                    d2++;
                    x = 1;
                }
            }
            z = !z;
        }
        else
        {
            if (x == 1 && b != 0)
            {
                b--;
                d2++;
                x = 2;
            }
            else if (x == 2 && a != 0)
            {
                a--;
                d2++;
                x = 1;
            }
            else
            {
                if (b)
                {
                    b--;
                    c2++;
                    x = 2;
                }
                else
                {
                    a--;
                    c2++;
                    x = 1;
                }
            }
            z = !z;
        }
    }
    if (c1 >= c2)
        cout << c1 << " " << d1 << endl;
    else
        cout << c2 << " " << d2 << endl;
    return 0;
}
