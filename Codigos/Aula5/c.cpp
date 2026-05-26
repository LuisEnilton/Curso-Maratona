#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;

    vi ps(n + 1), ps_ord(n + 1);

    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    sort(ALL(a));
    for (int i = 1; i <= n; i++)
        ps_ord[i] = ps_ord[i - 1] + a[i - 1];

    int q;
    cin >> q;
    while (q--)
    {
        int tipo;
        cin >> tipo;
        int l, r, ans;
        cin >> l >> r;
        if (tipo == 1)
        {
            ans = ps[r] - ps[l - 1];
        }

        if (tipo == 2)
        {
            ans = ps_ord[r] - ps_ord[l - 1];
        }
        cout << ans << endl;
    }
    return 0;
}