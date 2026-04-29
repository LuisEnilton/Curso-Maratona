#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;

        ll sum = ((1 + n) * n) / 2;

        // a gente subtrae as potencias de 2 que são menores ou igual a n

        for (ll val = 1; val <= n; val *= 2)
        {
            sum -= 2 * val;
        }
        cout << sum << endl;
    }
    return 0;
}