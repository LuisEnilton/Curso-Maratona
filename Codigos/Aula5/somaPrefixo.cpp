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
    int n,q; cin >> n >> q;
    vector<ll> a(n);
    for(auto & x : a) cin >> x;

    vector<ll> soma_pref(n + 1,0);
    // soma_pref[0] guarda o prefixo vazio
    for(int i = 1; i <=n;i++){
        soma_pref[i] = soma_pref[i - 1] + a[i - 1];
    }
    while(q--){

        int l,r; cin >> l >> r;

        ll resposta = soma_pref[r] - soma_pref[l -1];
        cout << resposta << endl;
    }   

    return 0;
}