// @active_botane every day
#include <bits/stdc++.h>
#define endl '\n'    
#define all(x) x.begin(), x.end()                                   
typedef long long ll;
typedef long double ld;
using namespace std;


struct pt {
	ld x, y;
};

pt last_inter;
 
const double EPS = 1E-9;
 
inline ld det (ld a, ld b, ld c, ld d) {
	return a * d - b * c;
}
 
inline bool between (ld a, ld b, double c) {
	return min(a,b) <= c + EPS && c <= max(a,b) + EPS;
}
 
inline bool intersect_1 (ld a, ld b, ld c, ld d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	ld A1 = a.y-b.y,  B1 = b.x-a.x,  C1 = -A1*a.x - B1*a.y;
	ld A2 = c.y-d.y,  B2 = d.x-c.x,  C2 = -A2*c.x - B2*c.y;
	ld zn = det (A1, B1, A2, B2);
	if (zn != 0) {
		double x = - det (C1, B1, C2, B2) * 1. / zn;
		double y = - det (A1, C1, A2, C2) * 1. / zn;
        last_inter.x = x; last_inter.y = y;
		return between (a.x, b.x, x) && between (a.y, b.y, y)
			&& between (c.x, d.x, x) && between (c.y, d.y, y);
	}
	else
		return det (A1, C1, A2, C2) == 0 && det (B1, C1, B2, C2) == 0
			&& intersect_1 (a.x, b.x, c.x, d.x);
}


int main() {
#ifndef ONLINE_JUDGE
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	

    string time;
    cin >> time;
    int hh = abs((time[0]-'0')*10 + (time[1]-'0') - 12);
    int mm = (time[3]-'0')*10 + (time[4]-'0');
    
    int n; ld r;
    cin >> n >> r;
    ld gr_hh = 360.0/12 * hh + 360.0/12/60 * mm;
    ld gr_mm = 360.0/60 * mm;

    ld rad_hh = gr_hh * M_PI / 180;
    ld rad_mm = gr_mm * M_PI / 180;
    // cout << gr_hh << " " << gr_mm << endl;
    // cout << rad_hh << " " << rad_mm << endl;

    ld x_hh = r * sin(rad_hh);
    ld y_hh = r * cos(rad_hh);
    // cout << x_hh << " " << y_hh << endl;

    ld x_mm = r * sin(rad_mm);
    ld y_mm = r * cos(rad_mm);
    // cout << x_mm << " " << y_mm << endl;

    pt ff1, ff2, ff3, ff4;
    ff1.x = 0; ff1.y = 0;
    ff2.x = x_hh; ff2.y = y_hh;

    ff3.x = 0; ff3.y = -r;
    for (int i = 0; i <= n; i++){
        double angle = 2*M_PI*i/n - M_PI/2;
        ff4.x = r*cos(angle); ff4.y = r*sin(angle);
        // cout << fixed << setprecision(6) << "x = " << ff4.x << "  y = " << ff4.y << endl;
        if (intersect(ff1, ff2, ff3, ff4)){
            cout << fixed << setprecision(6) << last_inter.x << " " << last_inter.y << endl;
            break;
        }
        ff3.x = ff4.x; ff3.y = ff4.y;
    }

    
    
    ff1.x = 0; ff1.y = 0;
    ff2.x = x_mm; ff2.y = y_mm;
    ff3.x = 0; ff3.y = -r;
    for (int i = 0; i <= n; i++){
        double angle = 2*M_PI*i/n - M_PI/2;
        ff4.x = r*cos(angle); ff4.y = r*sin(angle);
        // cout << fixed << setprecision(6) << "x = " << ff4.x << "  y = " << ff4.y << endl;
        if (intersect(ff1, ff2, ff3, ff4)){
            cout << fixed << setprecision(6) << last_inter.x << " " << last_inter.y << endl;
            break;
        }
        ff3.x = ff4.x; ff3.y = ff4.y;
    }


	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
