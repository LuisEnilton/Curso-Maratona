#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
#define int ll
int d(int x){

    // como iterar nos digitos de um numero

    // x % 10 - retorna o ultimo digito de um numero
    // x/ 10 apaga o ultimo digito de um numero
    int sum = 0;
    while(x > 0){
        int dig = x % 10;
        sum += dig;
        x/=10;
    }

    return sum;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){

        int x; cin >> x;
        int ans = 0;

        for(int y = x; y <= x + 100;y++){
            // y - d(y) = x
            if(y - d(y) == x) ans++; // 100 * log(x) * t
        }
        cout << ans << endl;
    }

    return 0;
}