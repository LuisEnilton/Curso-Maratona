#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi a (n);

    for(auto & x : a) cin >> x;

    vi sp(n + 1);
    for(int i = 1; i <=n;i++) sp[i] = sp[i - 1] + a[i - 1];

    int mini_s = sp[0]; // menor soma de prefixo que apareceu até agora
    int ans = -12314121321321;
    for(int i = 1; i <= n;i++){

        int resposta = sp[i] - mini_s;
        ans = max(ans,resposta);
        mini_s = min(mini_s,sp[i]);
    }

    cout << ans << endl;
    return 0;
}