#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k; cin >> n >> k;

    vector<int> a(n);
    for(int &  x : a) cin >> x; // O(n)

    int val = a[k - 1];
    int ans = 0;
    for(int x : a){ // O(N) = O(2N)

        if(x >= val && x > 0) ans++;

    }

    cout << ans << endl;
    return 0;
}