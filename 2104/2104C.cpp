/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

template < class c > struct rge {
    c b, e;
};
template < class c > rge<c> range(c i, c j){
    return rge<c>{i, j};
}
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return * this;
    }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return * this << range(begin(i), end(i)); 
    }
    template < class c, class b > debug & operator << (pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
};  
#define imie(...) " [" << #__VA_ARGS__ " : " << (__VA_ARGS__) << "]"

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string str;
        cin >> n >> str;

        vector<int> arr1, arr2;
        arr1.reserve(n);
        arr2.reserve(n);

        for(int i = 0; i < n; ++i){
            (str[i] == 'A' ? arr1 : arr2).push_back(i+1);
        }
        sort(arr2.begin(), arr2.end());

        auto chk = [&](int a) {
            if(a == 1) {
                return any_of(arr2.begin(), arr2.end(), [&](int b){
                    return b > 1 && b < n; 
                });
            }
            else if(a == n){
                return binary_search(arr2.begin(), arr2.end(), 1);
            }
            else {
                return upper_bound(arr2.begin(), arr2.end(), a) != arr2.end();
            }
        };
        bool res = any_of(arr1.begin(), arr1.end(), [&](int a){
            return !chk(a);
        });
        cout << (res ? "Alice" : "Bob") << "\n";
    }
}

void init_code(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    init_code();
    solve();
    return 0;
}

