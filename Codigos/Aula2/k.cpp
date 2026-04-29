#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    // 1s -> 10^8
    // O(sqrt(N))

    vector<ll> divisores;
    divisores.push_back(1);
    if(n > 1) divisores.push_back(n);

    for(ll i =  2; i * i <=n;i++){
        if(n % i == 0){
            divisores.push_back(i);
            if(i != n/i) divisores.push_back(n/i);
        }
    }
    sort(divisores.begin(),divisores.end());
    // se for impar
    if(divisores.size() & 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;

    }
    return 0;
}