#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<int> get_divisors(int n){
    vector<int> divisors;
    
    for(int i=1; i * i <= n; i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(i != n/i){
                divisors.push_back(n/i);
            }
        }
    }
    
    return divisors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    while(n--){
        int num;
        
        cin >> num;
        
        vector<int> d = get_divisors(num);
        
        cout << d.size() << endl;
    }
    
    
    return 0;
}
