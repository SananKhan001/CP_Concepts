#include <bits/stdc++.h>  // This will work only for g++ compiler.
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
//short hand for usual tokens
#define pb push_back
#define fi first
#define se second
#define int long long

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

bool DP_Solution(vector<int> &arr, int n, int m, bool isFirst, int sum, vector<vector<vector<int>>> &DP) {
    if(sum == 0 && !isFirst) return true;
    if(n == 0) return false;

    if(DP[n][sum][isFirst] != -1) return DP[n][sum][isFirst];

    int take = DP_Solution(arr, n-1, m, false, (sum + arr[n-1])%m, DP);
    int not_take = DP_Solution(arr, n-1, m, isFirst, sum%m, DP);

    return DP[n][sum][isFirst] = (take || not_take);
}
bool DIVSUB(vector<int> &arr, int n, int m) {
    if(m <= n) return true;

    vector<vector<vector<int>>> DP(n+1, vector<vector<int>> (m+1, vector<int> (2, -1)));

    return DP_Solution(arr, n, m, true, 0, DP);
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    bool divsub = DIVSUB(arr, n, m);
    if(divsub) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}