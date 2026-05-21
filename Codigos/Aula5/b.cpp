#include <bits/stdc++.h>
#define endl '\n'
#define int long long
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
    int n,m; cin >> n >> m;
    vector<int> k(n);
    for(auto& x : k) cin >> x;

    auto can = [&](int t){
        // dbg(t);
        int tot = 0;
        for(auto x : k){
            int qtd = t/x;
            tot += qtd;
            if(tot >= m) return true;
        }
        // dbg(tot);
        return false;
    };

    int l = 0, r = 1e18;
    int ans;
    while(l <= r){

        int t = (l + r)/2;
        // se eu consigo com esse valor tento com menos
        if(can(t)){
            ans = t;
            r = t - 1;
        }else{
            l = t + 1;
        }

    }
    cout << ans << endl;
    return 0;
}