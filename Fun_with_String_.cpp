#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tst;
    cin >> tst;
    cin.ignore();
    int m = 1;
    while (tst--)
    {
        string s;
        getline(cin, s);
        int cnt[5];
        for (int i = 0; i < 5; i++) cnt[i] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'i' || s[i] == 'I') cnt[0]++;
            else if (s[i] == 'u' || s[i] == 'U') cnt[1]++;
            else if (s[i] == 'c' || s[i] == 'C') cnt[2]++;
            else if (s[i] == 's' || s[i] == 'S') cnt[3]++;
            else if (s[i] == 'e' || s[i] == 'E') cnt[4]++;
        }
        cnt[0] = cnt[0] / 2;
        cnt[2] = cnt[2] / 2;
        sort(cnt, cnt + 5);
        cout << "Case " << m++ << ": " << cnt[0] << endl;
    }
    return 0;
}
