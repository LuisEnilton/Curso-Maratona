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
    map<string,int> cnt;

    while(n--){
        string s; cin >> s;

        if(!cnt.count(s)){
            cout << "OK" << endl;
        }else{
            cout << s << cnt[s] << endl;
        }
        cnt[s]++;
    }



    return 0;
}