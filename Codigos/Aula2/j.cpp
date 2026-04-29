#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){

        int n; cin >> n;
        vector<int> a(n);

        for(auto & x : a) {
            cin >> x; 
        }

        sort(a.begin(),a.end(),[&](int & c, int & b){
            return (c % 2) < (b % 2);
        });
        
        for(auto x : a){
            cout << x << " "; 
        }
        cout << endl;
    }


    return 0;
}