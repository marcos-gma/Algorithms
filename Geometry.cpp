#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

template<typename T>

struct Point{
    T x,y;
    Point(T x = 0, T y =0) : x(x), y(y){}
    Point operator + (Point p){return Point(x + p.x, y + p.y);}
    Point operator - (Point p){return Point(x - p.x, y - p.y);}
    Point operator * (T k){return Point(x * k, y * k);}
    double len(){return hypot(x,y);}
    T cross (Point p) {return x*p.y - y*p.x;} 
    T dot (Point p) {return x*p.x + y*p.y;}
    bool operator < (const Point &p) const {return x < p.x || (x == p.x && y < p.y);}
    bool operator == (const Point &p) const {return x == p.x && y == p.y;}
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll cases;

    cin >> cases;

    while(cases--){
        ll x1,y1,x2,y2,x3,y3;

        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point line = Point(x1,y1) - Point(x2,y2);
        
        ll k = line.cross(Point(x1,y1) - Point(x3,y3));

        if(k > 0) cout << "LEFT" << endl;
        else if (k == 0) cout << "TOUCH" << endl;
        else cout << "RIGHT" << endl;


    }
    return 0;
}