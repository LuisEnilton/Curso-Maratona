#include <bits/stdc++.h>
using namespace std;
 
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ft first 
#define sd second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
int main(){
    optimize;
    int n; cin >> n;
    
    int counti=0;
    ll dano=0;

    multiset<int, greater<int>> s;

    while(n--){
        int escudo, meteoro;
        cin >> escudo >> meteoro;

        dano+=meteoro;

        if(meteoro > escudo) {
            counti++;
            dano-=meteoro;
        }
        else if(dano > escudo){
            if(!s.empty() && *s.begin() > meteoro){
                auto it = s.begin();
                dano-=*it;
                s.erase(it);
                counti++;
                s.insert(meteoro);
            }
            else{
                counti++;
                dano-=meteoro;
            }
        }
        else{
            s.insert(meteoro);
        }
    }

    cout << counti << endl;

    return 0;

}