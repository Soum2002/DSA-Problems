#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in aa set(counting from zero)

const int MOD = 1e9 + 7;
// const int MOD = 998244353;

int power(int aa, int n, int m = MOD) {
	int ans = 1LL;
	while(n) {
		if(n&1) ans = 1LL * (ans%m * aa%m)%m;
		aa = (1LL*aa%m * aa%m)%m;
		n >>= 1;
	}
	return ans;
}

const int N = 1e5+1;


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(auto &e : a) cin >> e;
	vector<int> dp1(n),dp2(n);
	for(int i = 1; i < n; i++) {
		if(i-a[i]>=0) dp1[i] = 1;
		// if(dp1[i]) {
		// 	dp1[i] = (i-a[i] == 0 ? -1 : dp1[i-a[i]-1]);
		// }
	}
	for(int i=n-2; i>=0; i--) {
		if(i+a[i] < n) dp2[i] = 1;
		// if(dp2[i]) {
		// 	dp2[i] = (i+a[i] == n-1 ? n : dp2[i+a[i]+1]);
		// }
	}
	if(dp2[0] == n || dp1[n-1] == -1) {
		cout << "YES" << endl;
		return ;
	}
	for(int i=0; i<n; i++) cout << dp1[i] << " " ;
	cout << endl;
	for(int i=0; i<n; i++) cout << dp2[i] << " " ;
	cout << endl;
	for(int i = 1; i < n-1; i++) {
		if(dp1[i] == -1 && dp2[i+1] == n) {
			cout << "YES" << endl;
			return ;
		}
	}
	cout << "NO" << endl;

}


int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	
	int t = 1;
	cin >> t;
	// for(int i=1; i<=t; i++) {
	//     cout << "Case #" << i << ": ";
	//     solve();
	// }
	while(t--) {
		solve();
	}
	return 0;
}       
