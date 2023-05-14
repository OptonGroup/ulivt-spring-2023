// @active_botane every day
#include <bits/stdc++.h>
#define endl '\n'    
#define all(x) x.begin(), x.end()                                   
typedef long long ll;
typedef long double ld;
using namespace std;

struct struc{
    string n;
    int z, h;

    bool operator < (struc a){
        if (z != a.z){
            return z > a.z;
        }
        if (h != a.h){
            return h < a.h;
        }
        return n < a.n;
    }
};

int main() {
#ifndef ONLINE_JUDGE
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	

    map <string, array<int, 2>> mp;
    ll t;
    cin >> t;
    t *= 2;
    while (t--){
        string n;
        int z, h;
        cin >> n >> z >> h;
        mp[n][0] += z;
        mp[n][1] += h;
    }
    vector <struc> v;
    for (auto u: mp){
        struc st;
        st.n = u.first;
        st.z = u.second[0];
        st.h = u.second[1];
        v.push_back(st);
    }

    sort(all(v));
    for (auto u: v){
        cout << u.n << " " << u.z << " " << u.h << endl;
    }

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}