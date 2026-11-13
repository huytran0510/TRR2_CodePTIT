#include <bits/stdc++.h>

using namespace std;

int n,u,a[100][100];
bool vis[101];
int path[101];
int cnt = 0;

void dfs(int step, int cur){
    if (step == n){
        if (a[cur][u]){
            for (int i = 0; i < n; i++){
                cout << path[i] << " ";
            }
            cout << u << endl;
            cnt++;
        }
        return ;
    }
    for (int i = 1; i <= n; i++){
        if (a[cur][i] && !vis[i]){
            vis[i] = true;
            path[step] = i;
            dfs(step + 1, i);
            vis[i] = false;
        }
    }
}

int main(){

    vis[u] = true;
    path[0] = u;
    dfs(1, u);
}