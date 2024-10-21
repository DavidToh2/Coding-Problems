#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(9);
    int n; cin >> n;
    vector<double> x(n+1, 0.0), y(n+1, 0.0);
    for (int i=0; i<n; i++) { cin >> x[i] >> y[i]; }
    int m; cin >> m;

    vector<double> a(n+1, 0.0), b(n+1, 0.0), c(n+1, 0.0), d(n+1, 0.0), e(n+1, 0.0), f(n+1, 0.0);
    for (int k=0; k<n; k++) {
        a[k+1] = a[k] + x[k] * x[k];
        b[k+1] = b[k] + 2*x[k];
        c[k+1] = c[k] + (double)1;
        d[k+1] = d[k] - 2*x[k]*y[k];
        e[k+1] = e[k] - 2*y[k];
        f[k+1] = f[k] + y[k]*y[k];
    }

    for (int i=0; i<m; i++) {
        int L, R; double l = 0.0, X = 0.0;
        cin >> L >> R >> l >> X;
        
        double a1, b1, c1, d1, e1, f1;
        a1 = a[R] - a[L-1] + (double)l;
        b1 = b[R] - b[L-1];
        c1 = c[R] - c[L-1] + (double)l;
        d1 = d[R] - d[L-1];
        e1 = e[R] - e[L-1];
        f1 = f[R] - f[L-1];
        // cout << a << " " << b << "\n";
        double K = 1.0 * (2*c1*d1 - b1*e1) / (b1*b1 - 4*a1*c1);
        double B = 1.0 * (2*a1*e1 - b1*d1) / (b1*b1 - 4*a1*c1);

        cout << (K*X + B) << "\n";
    }

}