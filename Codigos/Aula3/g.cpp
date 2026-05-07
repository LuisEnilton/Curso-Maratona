#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


void print_arr(vector<int> & a){

    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> a(m);
    for(int & x : a) cin >> x;
    sort(a.begin(),a.end());
    int ans = INT32_MAX;
    for(int i = 0 ; i + n <= m;i++){
        int diferenca = a[i + n - 1] - a[i];
        ans = min(ans,diferenca);
    }
    cout << ans << endl;

    return 0;
}