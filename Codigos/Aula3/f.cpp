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
    for(int  & x : a) cin >> x;
    queue<int> fila;
    for(int i = 1; i <=n;i++) fila.push(i);

    while(fila.size() > 1){

        int id_crianca = fila.front();
        fila.pop();
        a[id_crianca - 1] -=m;
        if(a[id_crianca - 1] > 0) fila.push(id_crianca);
    }

    cout << fila.front() << endl;
    return 0;
}