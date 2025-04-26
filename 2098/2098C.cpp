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
    auto arr = [&](int n){
        vector<int> a(n);
        generate(a.begin(), a.end(), [](){
            int x; 
            cin >> x; 
            return x;
        });
        return a;
    };
    auto solve = [&](const vector<int>& a) -> bool{
        map<int,int> mp;
        for (int x : a) 
            ++mp[x];
            
        if(any_of(mp.begin(), mp.end(), [](auto &p){return p.second >= 4;}))
            return true;
            
        vector<int> cnt;
        for (auto &[x, v] : mp){
            cnt.push_back(x);
        }
        
        sort(cnt.begin(), cnt.end());

        int cnt2 = 0;
        int prev = INT_MIN;
        for(auto k : cnt){
            if (k != prev + 1){
                cnt2 = 0;
            }
            if (mp[k] >= 2) {
                cnt2++;
                if(cnt2 >= 2){
                    return true;
                }
            }
            prev = k;
        }
        return false;
    };
    while(t--) {
        int n;
        cin >> n;
        auto ans1 = arr(n);
        cout << (solve(ans1) ? "Yes" : "No") << "\n";
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

