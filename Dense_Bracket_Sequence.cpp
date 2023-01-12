#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using vvl = vector <vll >;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
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

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cnt = 0;
        ll cntx = 0;
        for (int i = 0, j = sz(s) - 1; i < j;)
        {
            if (s[i] == '(' && s[j] == ')')
            {
                i++, j--;
                cntx += 2;
            }
            else if (s[i] == ')')
            {
                i++, cnt++;
            }
            else if (s[j] == '(')
            {
                j--, cnt++;
            }
        }
        cnt += n - cnt - cntx;
        cout << cnt << endl;
    }
    return 0;
}