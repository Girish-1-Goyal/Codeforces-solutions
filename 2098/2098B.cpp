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
    auto arr = [&](int n) {
        vector<long long> a(n);
        generate(a.begin(), a.end(), [](){
            long long x;
            cin >> x;
            return x;
        });
        return a;
    };
    auto ans = [&](const vector<long long>& a, int k) {
        int n = (int)a.size();
        int check = n - k;
        if (check <= 0) 
            return 0LL;
        int lp = (check - 1) / 2;
        int rp = (n - 1) - (check - 1) / 2;
        return a[rp] - a[lp] + 1;
    };
    while (t--) {
        int n, k;
        cin >> n >> k;
        auto cnt = arr(n);
        sort(cnt.begin(), cnt.end());
        cout << ans(cnt, k) << "\n";
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

