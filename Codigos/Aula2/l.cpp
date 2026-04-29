#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool eh_primo(long long n){
    if(n == 1) return false;

    for(long long i = 2; i * i <= n;i++){
        if((n % i) == 0) return false;
    }
    return true;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q; cin >> q;

    while(q--){
        long long n; cin >> n;
        cout << (eh_primo(n) ? "YES":"NO" ) << endl;
    }

    /*
    Operador ternário
    
    Sintaxe
    (Condiçao ? "YES":"NO")

    if(Condiçao){
        "YES"
    }else{
        "NO"
    }

    */


    return 0;
}