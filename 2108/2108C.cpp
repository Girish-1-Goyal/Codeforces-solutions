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
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> a(n);
        for (auto& x : a){
            cin >> x;
        }

        auto chk = [&](int i, int j){
            long long sum = a[i];
            bool ans1  = (i == 0) ? true : (a[i-1] < sum);
            bool ans2 = (j == n - 1) ? true : (a[j+1] < sum);
            return ans1 && ans2;
        };

        int nax = 0;
        for (int i = 0; i < n; ){
            int cnt = int(find_if(begin(a) + i + 1, end(a), [&](long long x){
                return x != a[i];
            }) - begin(a));
            if (cnt == n || a[cnt] != a[i]){
                --cnt;
            }   
            nax += chk(i, cnt) ? 1 : 0;
            i = cnt + 1;
        }

        cout << nax << "\n";
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

