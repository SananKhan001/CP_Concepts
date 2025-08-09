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

int dfs(vector<vector<pair<int, int>>> &graph, int n, int s, vector<int> &visited, int &res) {
    visited[s] = true;
    int size = 0;
    for(auto v: graph[s]) {
        if(visited[v.first] == 0) {
            int sub_size = dfs(graph, n, v.first, visited, res);
            size += sub_size;
            res += 2*min(sub_size, n-sub_size)*(v.second);
        }
    }
    return size+1;
}

void solve() {
    int t; cin >> t;
    int test_case = 1;
    while(test_case <= t) {
        int n; cin >> n;
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>()); // from: {to, weight}
        for(int i = 0; i < n-1; i++) {
            int from, to, wt; cin >> from >> to >> wt;
            graph[from-1].push_back({to-1, wt});
            graph[to-1].push_back({from-1, wt});
        }

        vector<int> visited(n, 0);
        int res = 0;
        dfs(graph, n, 0, visited, res);
        cout << "Case #" << test_case << ": " << res << endl;

        test_case++;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}