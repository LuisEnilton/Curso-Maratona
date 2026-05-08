//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 200010
#define print_arr(a) for(auto x : a) cout << x << " ";  \
                            cout << endl; 
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;

void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    sort(a.begin(),a.end()); // lembrem de ordenar!!!
    while(q--){

        int tipo,x; cin >> tipo >> x;
        int qtd = 0;
        if(tipo == 1){
            qtd = a.end() - lower_bound(a.begin(),a.end(),x);
        }
        
        if(tipo == 2){
            qtd = a.end() - upper_bound(a.begin(),a.end(),x);
        }

        if(tipo == 3){
            qtd = upper_bound(a.begin(),a.end(),x) - a.begin();
        }
        
        if(tipo == 4){
            qtd = lower_bound(a.begin(),a.end(),x) - a.begin();
        }

        if(tipo == 5){
            qtd = upper_bound(a.begin(),a.end(),x) - lower_bound(a.begin(),a.end(),x);
        }
        cout << qtd << endl;

    }
    
}


signed main()
{
    optimize;
    int t = 1; 
    // cin >> t;
    while(t--){

        solve();

    }

    return 0;
}