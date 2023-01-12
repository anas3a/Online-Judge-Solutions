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

int a, b, cnt = 0;
;
int row[8];
bool check(int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        if (row[i] == r || abs(row[i] - r) == abs(i - c))
            return false;
    }
    return true;
}
void backtrack(int c)
{
    if (c == 8 && row[b] == a)
    {
        cout << setw(2) << ++cnt << "     ";
        for (int i = 0; i < 8; i++)
            cout << " " << row[i] + 1;
        cout << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        if (check(i, c))
            row[c] = i, backtrack(c + 1);
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
        cin >> a >> b;
        a--, b--;
        cnt = 0;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl
             << endl;
        backtrack(0);
        if (t)
            cout << endl;
    }
    return 0;
}
