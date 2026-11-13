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
    int a[105][105] = {0};
    vector<int> deg_ra(105, 0), deg_vao(105, 0);
    vector<pair<pair<int, int> , int>> edge;
    int m = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] > 0 && a[i][j] <= 50){
                deg_ra[i]++;
                deg_vao[j]++;
                m++;   
                edge.pb({{i,j}, a[i][j]});
            }
        }
    }
    
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
        }
    }else if (t == 2){
        cout << n << " " << m << endl;
        for (auto x : edge){
            cout << x.fi.fi << " " << x.fi.se << " ";
            cout << x.se << endl;
        }
    }
    return 0;
}