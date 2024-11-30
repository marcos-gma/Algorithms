#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;

int BinarySearch(vector<pair<int, int>>& Array, int l, int r, int K) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (Array[m].first == K) {
            return m;
        } else if (Array[m].first < K) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int size, sum, number,searched, i, j, k;

    cin >> size >> sum;

    vector<pair<int,int>> array;
    array.reserve(size);

    for (i=0; i < size; i++){
        cin >> number;
        array.emplace_back(number, i);
    }
    
    sort(array.begin(),array.end());
    
    auto it = array.begin();
    
    bool found = false;
    

    while(!found && it != array.end()){
        searched = sum - it->first;
        k = BinarySearch(array, 0, size-1, searched);
        if (k != -1 && array[k].second != it->second){
            found = true;
            break;
        }
        it++;
    }

    if (!found){
        cout << "IMPOSSIBLE";
    } else if (it->second < array[k].second){
        cout << it->second + 1 << " " << array[k].second + 1;
    } else {
        cout << array[k].second + 1 << " " << it->second + 1;
    }
    return 0;
}

