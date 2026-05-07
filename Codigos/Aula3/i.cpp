#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
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

    int n; cin >> n;
    vector<ll> a(n);
    for(auto & x : a) cin >> x;

    sort(a.begin(),a.end());

    ll mediana = a[n/2];
    // = {1,2,3,4}
    // = {1,2,2,3,4}

    if(n % 2 == 0){
        mediana = (a[n/2 - 1] + a[n/2])/2;
    }

    ll ans = 0;
    for(ll & x : a){
        ans += abs(x - mediana);
    }
    cout << ans << endl;
    return 0;
}