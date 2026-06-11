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

    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &x : a)
        cin >> x;

    int l = 0;
    // calcula pra cada r, qual o l mais a esquerda que satisfaz a condição
    unordered_map<int, int> freq; // frequencia de cada valor
    int cnt = 0,ans = 0;                  // qtd de valores distintos
    for (int r = 0; r < n; r++)
    {
        freq[a[r]]++;
        if(freq[a[r]] == 1){
            cnt++;
        }

        while(l < r && cnt > k){
            freq[a[l]]--;
            if(freq[a[l]] == 0) cnt--;
            l++;
        }

        // o l mais a esquerda que satisfaz
        // quantidade de subarrays terminando em r
        int qtd = (r -l + 1);
        ans += qtd;
    }
    cout << ans << endl;
    return 0;
}