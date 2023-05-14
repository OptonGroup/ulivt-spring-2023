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

    map<char, string> codes;
    codes['a'] = ".-";
    codes['b'] = "-...";
    codes['c'] = "-.-.";
    codes['d'] = "-..";
    codes['e'] = ".";
    codes['f'] = "..-.";
    codes['g'] = "--.";
    codes['h'] = "....";
    codes['i'] = "..";
    codes['j'] = ".---";
    codes['k'] = "-.-";
    codes['l'] = ".-..";
    codes['m'] = "--";
    codes['n'] = "-.";
    codes['o'] = "---";
    codes['p'] = ".--.";
    codes['q'] = "--.-";
    codes['r'] = ".-.";
    codes['s'] = "...";
    codes['t'] = "-";
    codes['u'] = "..-";
    codes['v'] = "...-";
    codes['w'] = ".--";
    codes['x'] = "-..-";
    codes['y'] = "-.--";
    codes['z'] = "--..";
    map <char, ld> times;
    times['.'] = 0.2;
    times['-'] = 0.6;

    string s;
    cin >> s;
    ld ans = 0.3 * (s.size()-1);
    for (auto u: s){
        for (auto el: codes[u]){
            ans += times[el];
        }
    }
    cout << (int)ans;


	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}