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
    string x = "Samsung";
    bool flag = true;
    int j = 0;
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == x[j])
            j++;
        if (j == sz(x))
            break;
    }
    if (j == sz(x))
    cout << "SRBD" << endl;
    else 
    cout << "GHOST" << endl;
    return 0;
}