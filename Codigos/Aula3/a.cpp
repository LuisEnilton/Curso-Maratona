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
    vector<int> a(n);
    for(int & x : a) cin >> x;
    sort(a.begin(),a.end());
    for(auto x : a) cout << x <<  " ";
    cout << endl;
    return 0;
}