#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define pb push_back
#define fi first 
#define se second 
#define setpre(n) fixed << setprecision(n)
#define gcd __gcd
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define mod 1000000007

int main() {
    faster();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t,n;
    cin >> t >> n;
    vector<int> deg_vao(n + 1, 0), deg_ra(n + 1, 0);
    vector<pair<int, int>> edge;
    int m = 0;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        deg_ra[i] = k;
        while (k--){
            int x;
            cin >> x;
            deg_vao[x]++;
            m++;
            edge.pb({i, x});
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
        }
    }else if (t == 2){
        cout << n << " " << m << endl;
        for (auto x : edge){
            cout << x.fi << " " << x.se << endl;
        }
    }
    return 0;
}