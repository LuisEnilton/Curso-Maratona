#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    int maxi = 0;
    // ler o array
    for(int i = 0 ; i < n;i++) cin >> a[i],maxi = max(maxi,a[i]);

    vector<int> cnt(maxi + 1);
    int ans = 1;
    // acha a frequencia de cada valor
    for(int x : a){
        cnt[x]++;
        ans = max(ans,cnt[x]);
    }
    // achar a maior frequencia
    cout << ans << endl;
    return 0;
}