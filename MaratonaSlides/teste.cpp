#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;


    while(t--){

        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(26);

        for(auto c : s){
            cnt[c - 'a']++;
        }
        vector<int> div;
        div.push_back(1);
        for(int i = 2; i* i <=n;i++){

            if(n % i == 0){
                div.push_back(i);
                if(i * i != n) div.push_back(n/i);
            }
        }
        int ans = n;
        for(auto sz : div){
            string aux = s.substr(0,sz);
            int diff = 0;
            for(int i = 0 ; i < n;i++){

                if(s[i] != aux[i % sz]) diff++;

            }
            if(diff <=1){
                ans = sz;
                break;
            }

        }

        cout << ans << endl;

    }


    return 0;
}