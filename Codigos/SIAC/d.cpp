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

    vi a(n);
    for(auto & x :a ) cin >> x;

    vi esquerda(n,0),direita(n,n - 1);

    vi st;

    for(int i = 0 ;i < n;i++){

        while(st.size() && a[st.back()] <= a[i]) st.pop_back();

        esquerda[i] = (st.size()?st.back():0);
        st.push_back(i);
    }
    st.clear();

    for(int i = n - 1;i >=0 ;i--){

        while(st.size() && a[st.back()] <= a[i]) st.pop_back();

        direita[i] = (st.size()?st.back(): n-1 );
        st.push_back(i);
    }

    for(int i = 0 ;i < n;i++){

        cout << (direita[i] - esquerda[i] + 1) << " ";
    }
    cout << endl;

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