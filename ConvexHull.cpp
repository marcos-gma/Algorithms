#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

template<typename T>
struct Point {
    T x, y;
    int id;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator + (Point p){return Point(x + p.x, y + p.y);}
    Point operator - (Point p){return Point(x - p.x, y - p.y);}
    Point operator * (T k){return Point(x * k, y * k);}
    double len(){return hypot(x,y);}
    T cross (Point p) {return x*p.y - y*p.x;} 
    
    bool operator < (const Point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    
    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point<ll>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i +1;
    }

    sort(p.begin(), p.end());
 
    n = p.size();

    if (n <= 2) {
        for (auto pt : p){
           cout << pt.id << " "; 
        } 
        cout << endl;
        return 0;
    }

    vector<Point<ll>> hull;

    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2) {
            Point<ll> A = hull[hull.size() - 2];
            Point<ll> B = hull.back();
            Point<ll> C = p[i];
            if ((B - A).cross(C - A) < 0) hull.pop_back();
            else break;
        }
        hull.push_back(p[i]);
    }

    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size) {
            Point<ll> A = hull[hull.size() - 2];
            Point<ll> B = hull.back();
            Point<ll> C = p[i];
            if ((B - A).cross(C - A) < 0) hull.pop_back();
            else break;
        }
        hull.push_back(p[i]);
    }

    hull.pop_back();
    
    set<int> ids;
    
    for(auto pt : hull){
        ids.insert(pt.id);
    }

    for (auto id : ids) {
        cout << id << " " ;
    }

    return 0;
}
