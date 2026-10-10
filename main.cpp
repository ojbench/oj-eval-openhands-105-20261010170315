#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    int r = n - m; // target remaining apples
    if (r >= n) {
        cout << "0.00\n";
        return 0;
    }
    vector<double> E(n + 1, 0.0);
    vector<double> prefix(n + 1, 0.0); // prefix sum of E from r+1 to i
    // E[k] = 0 for k <= r already
    for (int k = r + 1; k <= n; ++k) {
        double sum = prefix[k - 1]; // sum_{j=r+1}^{k-1} E[j]
        E[k] = 1.0 + sum / k;
        prefix[k] = prefix[k - 1] + E[k];
    }
    cout.setf(ios::fixed); cout << setprecision(2) << E[n] << "\n";
    return 0;
}
