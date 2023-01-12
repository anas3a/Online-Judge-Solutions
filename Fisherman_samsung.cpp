#include <iostream>
using namespace std;

int cnt[4], pos[4];
bool slot[100];
int ans = INT_MAX;
int n;
void solve(int a, int b, int c, int cur, int dist)
{
    if (dist > ans)
        return;
    if (cnt[cur] == 0)
    {
        if (cur == a)
            cur = b;
        else if (cur == b)
            cur = c;
        else
        {
            ans = min(ans, dist);
            return;
        }
    }
    int left = INT_MAX;
    for (int i = pos[cur]; i >= 1; i--)
    {
        if (!slot[i])
        {
            left = i;
            break;
        }
    }
    int right = INT_MAX;
    for (int i = pos[cur]; i <= n; i++)
    {
        if (!slot[i])
        {
            right = i;
            break;
        }
    }
    int left_sum = abs(pos[cur] - left) + 1;
    int right_sum = abs(right - pos[cur]) + 1;
    if (left_sum <= right_sum)
    {
        slot[left] = true;
        cnt[cur]--;
        solve(a, b, c, cur, dist + left_sum);
        slot[left] = false;
        cnt[cur]++;
    }
    if (right_sum <= left_sum)
    {
        slot[right] = true;
        cnt[cur]--;
        solve(a, b, c, cur, dist + right_sum);
        slot[right] = false;
        cnt[cur]++;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 3; i++)
            cin >> pos[i] >> cnt[i];
        for (int i = 0; i < 100; i++)
            slot[i] = false;
        ans = INT_MAX;
        solve(0, 1, 2, 0, 0);
        solve(0, 2, 1, 0, 0);
        solve(1, 0, 2, 1, 0);
        solve(1, 2, 0, 1, 0);
        solve(2, 1, 0, 2, 0);
        solve(2, 0, 1, 2, 0);
        cout << ans << endl;
    }
}