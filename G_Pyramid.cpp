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

int n, z;
void print(int i, int j, int cn1, int cn2)
{
    if (i > n || j > z)
        return;
    if (cn2 < (z - (i * 2 - 1)) / 2)
    {
        cout << " ";
        cn2++;
    }
    else if (cn1 < (i * 2 - 1))
    {
        cout << "*";
        cn1++;
    }
    if (j == z)
    {
        cout << endl;
        i++;
        j = 0;
        cn1 = 0;
        cn2 = 0;
    }
    print(i, j + 1, cn1, cn2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    z = n * 2 - 1;
    print(1, 1, 0, 0);
    return 0;
}
