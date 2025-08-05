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

const int mod = 1e9;

class matrix {
    private:
    public:
        int size;
        vector<vector<int>> m;

        matrix(int size) {
            this->size = size;
            m.resize(size, vector<int> (size, 0));
        }

        matrix(vector<vector<int>> m) {
            this->m = m;
            int size = m.size();
            this->size = size;
        }

        void identity() {
            int size = this->size;
            for(int i = 0; i < size; i++) (this->m)[i][i] = 1;
        }

        matrix operator*(matrix &t) {
            matrix result(size);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    for (int k = 0; k < size; k++) {
                        result.m[i][j] += ((this->m[i][k] % mod) * (t.m[k][j] % mod)) % mod; 
                        result.m[i][j] %= mod;
                    }
                }
            }
            return result;
        }
};

int SEQ(int k, vector<int> &b, vector<int> &c, int n) {
    if(n <= k) return b[n-1];

    vector<vector<int>> mat_T(k, vector<int> (k, 0));
    mat_T[0] = c;
    for(int i = 1; i < k; i++) mat_T[i][i-1] = 1;

    matrix T(mat_T);
    
    n -= k;
    
    matrix res(k); res.identity();
    
    while(n) {
        if(n&1) res = res * T;
        T = T * T;
        n >>= 1;
    }

    reverse(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < k; i++) {
        ans += ((res.m[0][i]%mod) * (b[i]%mod)) % mod; ans %= mod;
    }

    return ans;
}

void solve() {
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        vector<int> b(k, 0);
        for(int i = 0; i < k; i++) cin >> b[i];
        vector<int> c(k, 0);
        for(int i = 0; i < k; i++) cin >> c[i];
        int n; cin >> n;
        
        cout << SEQ(k, b, c, n) << endl;
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