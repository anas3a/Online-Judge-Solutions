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

vector<string> ans;
int n;
void fun(string s)
{
    ll sum = 0;
    for (auto &i : s)
        sum += i - '0';
    if (sum == n)
    {
        ans.pb(s);
        return;
    }
    for (int j = s.back() - '0' + 1; j <= 9; j++)
    {
        fun(s + to_string(j));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= 9; i++)
            fun(to_string(i));
        ll ansx = LLONG_MAX;
        for (auto &i : ans)
        {
            ll tmp = stoll(i);
            ansx = min(ansx, tmp);
        }
        cout << ansx << endl;
    }
    return 0;
}