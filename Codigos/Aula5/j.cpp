    #include <bits/stdc++.h>
    #define endl '\n'
    #define int long long
    #define ALL(x) x.begin(), x.end()
    #define dbg(x) cout << #x << " " << x << endl;
    #define vi vector<int>
    using namespace std;

    const int MAXN = 2e5 + 5;

    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto &x : a)
            cin >> x;

        // consigo fazer com que o minimo seja val blocos
        auto can = [&](int val)
        {
            vi aux = a;
            // achar a primeira posição em que a[i] < val
            int idx = -1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] < val)
                {
                    idx = i;
                    break;
                }
            }
            if (idx == -1)
                return true;

            int quanto = k;
            for (int i = idx; i >= 0 && quanto >= 0; i--, quanto--)
            {
                aux[i] += quanto;
            }
            for (auto x : aux)
            {
                if (x < val)
                    return false;
            }
            return true;
        };

        int l = 0, r = 1e10;
        int ans = 0;
        while (l <= r)
        {

            int m = (l + r) / 2;

            if (can(m))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << ans << endl;
        return 0;
    }