#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
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

    int atual,n; cin >> atual >> n;

    vector<pair<int,int>> a(n); // (forca, y)
    for(auto & [forca,y] : a) cin >> forca >> y;

    sort(a.begin(),a.end());
    bool resposta = 1;
    for(auto [forca, bonus] : a){
        if(atual <= forca){
            resposta = false;
            break;
        }
        atual += bonus;
    }
    cout << (resposta ? "YES":"NO" ) << endl;
    return 0;
}