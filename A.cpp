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

    ld a;
    cin >> a;
    cout << fixed << setprecision(6) << 5./9. * (a - 32.);

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}