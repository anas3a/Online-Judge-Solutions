#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    n *= 8;
    n++;
    n = (sqrt(n) - 1) / 2;
    cout << n << endl;
    return 0;
}