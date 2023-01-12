#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a;
        string b;
        cin >> a >> b;
        int x = 0;
        for (auto &i : b)
            x += i - '0';
        if (x == a)
            cout << "Karim" << endl;
        else
            cout << "Rahim" << endl;
    }
    return 0;
}