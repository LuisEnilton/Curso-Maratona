#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;

vector < string > RET = {"NO", "YES"};

void solve(){
    
    int n; cin >> n;


    // valor do item no dia 1, sempre > 0
    vi a(n);
    for(auto & x : a) cin >> x;
    priority_queue<int> pq;
    int curr = 1;
    for(auto x : a){

        if(x <= curr){
            pq.push(x);
            curr -=x;
        }else{
            if(pq.size() && pq.top() > x){ // devolve o item que peguei e pega esse
                curr += pq.top();
                pq.pop();
                curr -= x;
                pq.push(x);
            }
        }
        curr++;
    }
    cout << pq.size() << endl;
}

signed main(){
    optimize;
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}