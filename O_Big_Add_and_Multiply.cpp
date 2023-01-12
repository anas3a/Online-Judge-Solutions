#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    string s1, s2;
    cin >> s1;
    s2 = "9999";
    string sum;
    reverse(s1.begin(), s1.end());
    ll carry = 0;
    for (int i = 0; i < max(s1.size(), s2.size()); i++)
    {
        ll x = 0, y = 0;
        if (i < s1.size())
            x = s1[i] - '0';
        if (i < s2.size())
            y = s2[i] - '0';
        ll z = x + y + carry;
        carry = z / 10;
        sum += to_string(z % 10);
    }
    if (carry != 0)
        sum += to_string(carry);
    reverse(sum.begin(), sum.end());
    cout << sum << endl;
    string mul, sx;
    carry = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        ll z = (9 * (s1[i] - '0')) + carry;
        sx += to_string(z % 10);
        carry = z / 10;
    }
    if (carry)
        sx += to_string(carry);
    string a1 = sx + "000", a2 = "0" + sx + "00", a3 = "00" + sx + "0", a4 = "000" + sx;
    carry = 0;
    for (int i = 0; i < a4.size(); i++)
    {
        ll z = a1[i] + a2[i] + a3[i] + a4[i] + carry - (4 * '0');
        mul += to_string(z % 10);
        carry = z / 10;
    }
    if (carry)
    mul += to_string(carry);
    reverse(mul.begin(), mul.end());
    cout << mul << endl;
    return 0;
}
