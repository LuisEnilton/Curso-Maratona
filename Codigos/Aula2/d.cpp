#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool busca_binaria(int x , vector<int> & a){

    int esquerda = 0, direita = a.size() - 1;

    while(esquerda <= direita){
        int meio = (esquerda + direita)/2;

        if(a[meio] == x) return true;
        else if(a[meio] < x){
            esquerda = meio + 1;
            
        }else{
            direita = meio - 1;
        }
    }

    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q; cin >> n >>q;

    vector<int> a(n);

    for(int & x : a) cin >> x;

    sort(a.begin(),a.end());
    // for(auto x : a){
    //     cout << x << " ";
    // }
    // cout << endl;
    while(q--){
        int x; cin >> x;
        // cout << x << endl;
        bool ans = busca_binaria(x,a);

        cout << (ans ? "YES":"NO") << endl;
    }


    return 0;
}