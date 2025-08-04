/*
    S(n) = F(0) + F(1) + F(2) + ......+ F(n)
    S(m) = F(0) + F(1) + F(2) + ......+ F(m)
    S(m) - S(n-1) = sum from m till n
    
    f(n) = f(n-1) + f(n-2)
    => f(n-2) = f(n) - f(n-1)
    => f(n-3) = f(n-1) - f(n-2)
    => f(n-4) = f(n-2) - f(n-3)
    |
    |
    |
    => f(0) = f(2) - f(1)
    ---------------------------------
    add lhs and rhs
    f(0)+f(1)+f(2)+......+f(n-2) = f(n)-f(1)

    s(n-1) = F(n)-1
    therefore, s(n) = F(n+2)-1
    s(n.....m) = s(m) - s(n-1)
    =>s(m) = F(m+2)-1
    =>s(n-1) = F(n+1)-1
    s(n...m) = F(m+2)-F(n+1)
*/

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

const int mod = 1e9+7;

class matrix{
    private:
        int size;
        vector<vector<int>> mat;
    public:
        matrix(int size) {
            this->size = size;
            mat.resize(size, vector<int> (size, 0));
        }

        vector<vector<int>> getMat() {
            return this->mat;
        }

        int getSize() {
            return this->size;
        }
        
        void identity() {
            int n = this->size;
            for(int i = 0; i < n; i++) {
                (this->mat)[i][i] = 1;
            }
        }

        void setAtIndex(int i, int j, int val) {
            (this->mat)[i][j] = val;
        }

        matrix operator*(matrix mt) {
            int n = this->size;
            matrix res(n);
            vector<vector<int>> t = mt.getMat();
        
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int sum = 0;
                    for (int k = 0; k < n; k++) {
                        sum += (((this->mat[i][k])%mod) * ((t[k][j])%mod))%mod; sum %= mod;
                    }
                    res.setAtIndex(i, j, sum);
                }
            }
            return res;
        }
};

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    n -= 1;
    matrix T(2);
    T.setAtIndex(0, 0, 1); T.setAtIndex(0, 1, 1); T.setAtIndex(1, 0, 1);

    matrix res(2); res.identity();
    while(n) {
        if(n&1) res = res * T;
        T = T * T;
        n >>= 1;
    }

    vector<vector<int>> mat = res.getMat();
    return mat[0][0];
}

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int ans = (((fib(m+2)%mod) - (fib(n+1)%mod))+mod)%mod;
        cout << ans << endl;
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