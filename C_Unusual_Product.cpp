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

    int n;
    cin >> n;
    vvi v(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    ll cx = 0, cy = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            cx += v[k][i] * v[i][k];
        }
        cy += cx % 2;
        cx = 0;
    }
    cy %= 2;
    string s;
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (a <= 2)
        {
            int b;
            cin >> b;
            cy++;
        }
        else
            cout << cy % 2;
    }
    cout << endl;
    return 0;
}
