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
    auto valid = [](long long x){
        return __builtin_popcountll(x);
    };
    auto chk = [&](long long r){
        if (r == 0){
            return 2LL;
        }
        if (valid(r) >= 2){
            return r;
        }
        for (int b = 0; b < 63; ++b){
            if (!((r >> b) & 1)){
                return r + (1LL << (b + 1));
            }
        }
        return r + 2LL;
    };
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        if (n == 1){
            cout << (x > 0 ? x : -1) << "\n";
            continue;
        }
        long long cnt = LLONG_MAX;
        int nax = (int)min(n, 30LL);

        for (int k = 1; k <= nax; ++k){
            long long r = x ^ ((n - k) & 1);
            long long res = LLONG_MAX;
            res = (k == 1 ? (r > 0 ? r : LLONG_MAX) : k == 2 ? chk(r) : (r == 0 && k == 3) ? 6LL : (valid(r) >= k) ? r : LLONG_MAX);
            if (res < LLONG_MAX){
                cnt = min(cnt, (n - k) + res);
            }
        }
        cout << (cnt == LLONG_MAX ? -1 : cnt) << "\n";
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

