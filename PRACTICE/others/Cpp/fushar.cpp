#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;

const ll MOD = 1000000007;

#define REP(i,n) for (int i = 0; i < n; i++)

matrix matrix_mul(matrix a, matrix b)
{
    matrix c(a.size(), vector<ll>(b[0].size()));
    REP(i, a.size()) REP(j, b[0].size()) REP(k, b.size())
    {
        c[i][j] += (a[i][k] * b[k][j]) % MOD;
        c[i][j] %= MOD;
    }
    return c;
}

matrix matrix_pow(matrix a, ll p)
{
    if (p == 1)
        return a;
    if (p % 2 == 1)
        return matrix_mul(a, matrix_pow(a, p-1));
    matrix c = matrix_pow(a, p/2);
    return matrix_mul(c, c);
}

int N, B, K, X;
ll occ[10];

int main() {
    cin >> N >> B >> K >> X;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        occ[d]++;
    }

    vector<ll> f(X);
    f[0] = 1;

    matrix T(X);

    for (int i = 0; i < X; i++) {
        T[i] = vector<ll>(X);
    }

    for (int i = 0; i < X; i++) {
        for (int d = 1; d <= 9; d++) if (occ[d]) {
            int a = (i*10+d) % X;
            T[a][i] += occ[d];
        }
    }
    for(int i=0;i<T.size();i++,cout<<endl)
    for(int j=0;j<T[0].size();j++)
    cout<<T[i][j]<<" ";
    T = matrix_pow(T, B);
    for(int i=0;i<T.size();i++,cout<<endl)
    for(int j=0;j<T[0].size();j++)
    cout<<T[i][j]<<" ";
    for(int i=0;i<f.size();i++)
    cout<<f[i]<<" ";
    cout<<endl;
    ll res = 0;
    for (int i = 0; i < X; i++) {
        res = (res + T[K][i] * f[i] % MOD) % MOD;
    }

    cout << res << endl;
}
