#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

void subsetSums(const vector<ll>& arr, vector<ll>& sums, ll index, ll currentSum) {
    if (index == arr.size()) {
        sums.push_back(currentSum);
        return;
    }
    subsetSums(arr, sums, index + 1, currentSum);
    subsetSums(arr, sums, index + 1, currentSum + arr[index]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases;

	ll size, sum, num;

	cin >> size >> sum;

	vector<ll> arr1;
	vector<ll> arr2;

	ll middle = (size + 1) / 2;

	for(int i=0; i < middle; i++) {
		cin >> num;
		arr1.push_back(num);
	}

	for(int i=middle; i < size; i++) {
		cin >> num;
		arr2.push_back(num);
	}

	vector<ll> sums1;
	vector<ll> sums2;

	subsetSums(arr1, sums1, 0, 0);
    subsetSums(arr2, sums2, 0, 0);

    sort(sums2.begin(),sums2.end());
    
    ll ways = 0;
    
    for(auto s : sums1){
    
        auto it1 = lower_bound(sums2.begin(),sums2.end(),sum - s);
        auto it2 = upper_bound(sums2.begin(),sums2.end(),sum - s);
        
        ways += it2 - it1;
    }
    
    cout << ways << endl;

	return 0;
}
