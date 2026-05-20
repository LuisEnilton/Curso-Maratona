#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define int long long

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin>>n>>m; 

    vector<pii> a (n);
    for(int i = 0; i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end(),[&](pii & x, pii & y){
        if(x.first == y.first){
            if(x.first & 1){
               return x.second > y.second;
            }else{
               return x.second < y.second;
            }
        }
        return x.first < y.first;
    });

    for(auto [val,id] : a){
        cout << id + 1 << " ";
    }
    cout << endl;


    return 0;
}