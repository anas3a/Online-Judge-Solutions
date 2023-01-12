#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using pii = pair <int, int>;
using pll = pair <long, long>;
using vpi = vector <pii >;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

string s = "aeiouAEIOU", a;

int f(int i)
{
    if (i == a.size())
    return 0;
    if (s.find(a[i]) != string::npos)
    return 1 + f(i + 1);
    return f(i + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, a);
    cout << f(0) << endl;
    return 0;
}
