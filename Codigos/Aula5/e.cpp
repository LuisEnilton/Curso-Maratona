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
    int n; cin >> n;
    vi a(n);
    for(auto & x : a) cin >> x;
    vi ps(n + 1);
    for(int i = 1; i <=n;i++) ps[i] = ps[i - 1] + a[i - 1];
    // for(auto x : ps){
    //     cout << x << " ";
    // }
    // cout << endl;
    int q; cin >> q;
    while(q--){
        int numero; cin >> numero;

        int ans = lower_bound(ALL(ps),numero) - ps.begin();
        cout << ans << endl;
    }

    return 0;
}