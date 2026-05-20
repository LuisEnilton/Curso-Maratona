    #include <bits/stdc++.h>
    #define endl '\n'
    using namespace std;


    void print_arr(vector<int> & a){

        for(auto x : a){
            cout << x << " ";
        }
        cout << endl;
    }

    bool is_lower(char c){
        return c >= 'a' && c <= 'z';
    }

    bool is_upper(char c){
        return c >= 'A' && c <= 'Z';
    }

    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        string s;
        getline(cin,s);

        for(char & c : s){

            if(is_lower(c)){
                int indice = c - 'a';
                indice = (indice + 13) % 26;
                c = char('a' + indice);
            }
            if(is_upper(c)){
                int indice = c - 'A';
                indice = (indice + 13) % 26;
                c = char('A' + indice);
            }

        }
        cout << s << endl;


        return 0;
    }