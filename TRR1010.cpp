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
    int a[1001][1001] = {0};
    vector<int> deg(1001, 0);
    int b[1001][1001] = {0};
    int m = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if ((a[i][j] <= 50  && a[i][j] > 0) && (i < j)){
                deg[i]++;
                deg[j]++;
                m++;
                b[m][0] = i;
                b[m][1] = j;
                b[m][2] = a[i][j];
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }else if (t == 2){
        cout << n << " " << m << endl;
        for (int i = 1; i <= m; i++){
            cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << endl;  
        }
    }
    return 0;
}