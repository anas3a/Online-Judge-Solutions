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

    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0, pos = -1;
        string s;
        cin >> n >> s;
        vi v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
            {
                if (i + 1 < n)
                {
                    if (s[i + 1] == 'D')
                        s[i + 1] = 'B';
                    else
                        s[i + 1] = 'D';
                }
                int j = i;
                while (j > pos)
                {
                    v.pb(j + 1);
                    j--;
                    x++;
                }
                pos = i;
            }
        }
        if (x < n)
            cout << "N" << endl;
        else
        {
            cout << "Y" << endl;
            for (auto &i : v)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
