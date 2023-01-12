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
        string s;
        cin >> s;
        ll c1 = 0, c2 = 0;
        stack<char> s1, s2;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == '(')
                s1.push(s[i]);
            if (s[i] == '[')
            s2.push(s[i]);
            if (s[i] == ')')
            {
                if (!s1.empty() && s1.top() == '(')
                {
                    c1++;
                    s1.pop();
                }
            }
            if (s[i] == ']')
            {
                if (!s2.empty() && s2.top() == '[')
                {
                    c2++;
                    s2.pop();
                }
            }
        }
        cout << c1 + c2 << endl;
    }
    return 0;
}
