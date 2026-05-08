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
    vector<int> a(n);
    for(auto & x : a ) cin >> x;

    multiset<int> ingressos;
    for(auto x : a) ingressos.insert(x);
    // m clientes
    while(m--){
        int valor; cin >> valor;

        auto iterador = ingressos.upper_bound(valor);

        if(iterador == ingressos.begin()){
            cout << -1 << endl;
            continue;
        }
        iterador--; // volto pro primeiro cara <=
        cout << *iterador << endl;
        // ingressos.erase(*iterador);
        ingressos.erase(iterador);
    }


    return 0;
}