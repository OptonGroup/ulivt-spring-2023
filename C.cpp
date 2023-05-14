// @active_botane every day
#include <bits/stdc++.h>
#define endl '\n'    
#define all(x) x.begin(), x.end()                                   
typedef long long ll;
typedef long double ld;
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	

    map<char, char> codes;
    codes['A'] = 'T';
    codes['C'] = 'G';
    codes['T'] = 'A';
    codes['G'] = 'C';

    string v1;
    cin >> v1;
    string v2 = v1; reverse(all(v2));
    string v3 = ""; for (auto u: v1) v3 += codes[u];
    string v4 = ""; for (auto u: v2) v4 += codes[u];

    ll t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        string s;
        cin >> s;
        if (s == v1 || s == v2 || s == v3 || s == v4){
            cout << i;
            return 0;
        }
    }


	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}