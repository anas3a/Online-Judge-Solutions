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
        string x1, x2;
        ll p1, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        for (int i = 0; sz(x1) < 10; i++)
        {
            if (p1 == 0)
                break;
            x1 += '0';
            p1--;
        }
        for (int i = 0; sz(x2) < 10; i++)
        {
            if (p2 == 0)
                break;
            x2 += '0';
            p2--;
        }
        if (p1 == p2)
        {
            ll xx1 = stoll(x1);
            ll xx2 = stoll(x2);
            if (xx1 < xx2)
                cout << "<" << endl;
            else if (xx1 > xx2)
                cout << ">" << endl;
            else
                cout << "=" << endl;
        }
        else if (p1 < p2)
            cout << "<" << endl;
        else
            cout << ">" << endl;
    }
    return 0;
}