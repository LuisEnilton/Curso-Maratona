#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m,a; cin >> n >> m >> a;

    long long qtd_h = (n + a - 1) / a;
    long long qtd_v = (m + a - 1) / a;
    long long ans = qtd_h * qtd_v;
    cout << ans << endl;
    return 0;
}