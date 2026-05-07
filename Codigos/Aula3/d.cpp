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
    vector<pair<string,string>> a(n);

    for(auto &[nome1,nome2] : a){
        cin >> nome1 >> nome2;
    }
    sort(a.begin(),a.end());

    auto last = unique(a.begin(),a.end());
    // daqui pra frente ta duplicado
    a.erase(last,a.end());
    cout << a.size() << endl;
    return 0;
}