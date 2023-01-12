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

int mx = 1e5 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a[mx];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    while (m--)
    {
        ll x;
        cin >> x;
        bool flag = false;

        ll left = 0, right = n - 1;
        while (left <= right)
        {
            ll mid = (left + right) / 2;
            if (a[mid] == x)
            {
                flag = true;
                break;
            }
            else if (a[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (flag)
            cout << "found" << endl;
        else
            cout << "not found" << endl;
    }
    return 0;
}





4 2 2 3 1 2 9 3 8 9

int i = 6, j = 9;

ll sum = 0;
for (; i <= j; i++)
    sum += a[i];




1 22 323 1 31 = 10^5
10 ^ 5


10^5 * 10^5 = 10;




10^5 + 10^5 = 2 * 10^5 = 2 lac


1 lac  = 

