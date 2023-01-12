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

int n;
vll v;

void f(int i)
{
    if (i == n)
    return;
    f(i + 1);
    if (i % 2 == 0)
    cout << v[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for(auto &i : v)
    cin >> i;
    f(0);
    cout << endl;
    return 0;
}
