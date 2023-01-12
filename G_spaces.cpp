#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using pii = pair <int, int>;
using pll = pair <long, long>;
using vpi = vector <pii >;
using vpl = vector <pll >;

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

    int k = 7, cnt = 0;
    for (int i = 1; i <= 100000000; i++)
    {
        ll a = i;
        while (a != 0)
        {
            if (a % 10 == k)
            {
                cnt++;
                break;
            }
            a /= 10;
        }
        if (i == 100)
        cout << i << " " << cnt << endl;
        if (i == 1000)
        cout << i << " " << cnt << endl;
        if (i == 10000)
        cout << i << " " << cnt << endl;
        if (i == 100000)
        cout << i << " " << cnt << endl;
        if (i == 1000000)
        cout << i << " " << cnt << endl;
        if (i == 10000000)
        cout << i << " " << cnt << endl;
        if (i == 100000000)
        cout << i << " " << cnt << endl;
    }
    return 0;
}
