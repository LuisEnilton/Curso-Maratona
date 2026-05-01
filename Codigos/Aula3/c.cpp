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

    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 1; i <=n;i++){
        int x; cin >> x;
        a[i - 1] = {x,i};  // (valor,indice original)
    }
    sort(a.begin(),a.end());

    for(auto [valor, indice] : a){
        cout << indice << " ";
    }
    cout << endl;

    return 0;
}