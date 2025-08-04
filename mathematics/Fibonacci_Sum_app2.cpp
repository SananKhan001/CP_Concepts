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

int fibSumTill(int n) {
    if(n < 0) return 0;
    if(n < 2) return n;

    n -= 1;

    matrix T(3); T.identity();
    T.setAtIndex(0, 1, 1); T.setAtIndex(0, 2, 1); 
    T.setAtIndex(1, 2, 1); T.setAtIndex(2, 1, 1); 
    T.setAtIndex(2, 2, 0); 

    matrix res(3); res.identity();

    while(n) {
        if(n&1) res = res * T;
        T = T * T;
        n >>= 1;
    }

    auto final_T = res.getMat();
    int ans = ((final_T[0][0]%mod) + (final_T[0][1]%mod))%mod;
    return ans;
}

int fibSum(int n, int m) {
    return ((fibSumTill(m) - fibSumTill(n-1))+mod)%mod;
}

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        cout << fibSum(n, m) << endl;
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