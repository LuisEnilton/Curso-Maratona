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

    int n;
    cin >> n;
    vii a(n);
    for (auto &x : a)
        cin >> x.first >> x.second;

    // ordena pela duração de forma crescente
    sort(ALL(a));
    int ans = 0, t = 0;
    for (auto [dur, prazo] : a)
    {
        t += dur;
        ans += (prazo - t);
    }
    cout << ans << endl;

    return 0;
}