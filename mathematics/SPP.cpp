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

class matrix {
    private:
    public:
        int size;
        int mod;
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
            result.mod = this->mod;
            int mod = this->mod;
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

int SPP(vector<int> &b, vector<int> &c, int k, int n, int p) {
    if(n <= k) {
        int sum = 0;
        for(int i = 0; i < n; i++) {sum += (b[i]%p); sum %= p;}
        return sum;
    }

    // preparing f_k
    vector<int> f_k;
    int sum = 0;
    for(int el: b) {sum += (el%p); sum %= p;}
    f_k.push_back(sum);
    for(int i = k-1; i >= 0; --i) f_k.push_back(b[i]);

    n -= k;

    // preparing T
    matrix T(k+1);
    T.m[0][0] = 1;
    for(int j = 1; j < k+1; j++) {T.m[0][j] = c[j-1]; T.m[1][j] = c[j-1];}
    for(int i = 2; i < k+1; i++) T.m[i][i-1] = 1;
    T.mod = p;

    // for(auto mt: T.m) {
    //     for(int el: mt) cout << el << " ";
    //     cout << endl;
    // }

    matrix res(k+1); res.identity(); res.mod = p;

    while(n) {
        if(n&1) res = res * T;
        T = T*T;
        n >>= 1;
    }

    int ans = 0;
    for(int i = 0; i < k+1; i++) {
        ans += ((res.m[0][i]%p)*(f_k[i]%p))%p; ans %= p;
    }

    return ans;
}

void solve() {
    int T; cin >> T;
    while(T--) {
        int k; cin >> k;
        vector<int> c(k), b(k);
        for(int i = 0; i < k; i++) cin >> b[i];
        for(int i = 0; i < k; i++) cin >> c[i];
        int m, n, p; cin >> m >> n >> p;

        int ans = ((SPP(b, c, k, n, p) - SPP(b, c, k, m-1, p)) + p)%p;
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