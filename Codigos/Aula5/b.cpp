#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ALL(x) x.begin(),x.end()
#define dbg(x) cout << #x << " " << x << endl;
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
    ll n,m; cin >> n >> m;
  
    vector<ll> k(n);
    for(auto & x : k) cin >> x;

    auto can = [&](ll t){
        // dbg(t);
        ll tot_produtos = 0;

        for(auto x : k){

            ll qtd_prod = t/x;
            tot_produtos += qtd_prod;
            if(tot_produtos >= m) return true;
        }
        // dbg(tot_produtos);
        return false;
    };

    ll l = 0, r = 1e18 + 5;
    ll ans = 0;
    while(l <= r){

        ll t = (l + r)/2;
        if(can(t)){
            ans = t;
            r = t- 1;
        }else{
            l = t + 1;
        }

    }
    // O(NLogn)
    cout << ans << endl;
    return 0;
}