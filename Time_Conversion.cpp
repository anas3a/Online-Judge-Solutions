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

    string s;
    cin >> s;
    if (s[8] != 'P')
    {
        if (s[0] == '1' && s[1] == '2')
            s[0] = '0', s[1] = '0';
    }
    else
    {
        int x = (s[0] - '0');
        x *= 10;
        x += (s[1] - '0');
        x += 12;
        s[1] = (x % 10) + '0';
        x /= 10;
        s[0] = (x % 10) + '0';
    }
    string ans;
    for (int i = 0; i < 8; i++)
        ans += s[i];
    if (s[0] == '2' && s[1] == '4')
        ans[0] = '1', ans[1] = '2';
    cout << endl;
    return 0;
}