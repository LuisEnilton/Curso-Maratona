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
    int n, s;
    cin >> n >> s;
    vi a(n);
    for (auto &x : a)
        cin >> x;

    int sum = 0;
    map<int, int> freq; // quantas vezes essa soma apareceu na soma de prefixos
    freq[0]++; // prefixo vazio é uma opção
    int ans = 0;
    for (auto x : a)
    {
        sum += x;
        ans += freq[sum - s]; // l em que ps[r] - ps[l - 1] = K.
        freq[sum]++;
    }
    cout << ans << endl;

    return 0;
}