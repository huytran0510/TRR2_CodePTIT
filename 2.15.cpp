#include <bits/stdc++.h>

using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int a[105][105]; // Ma trận có hướng gốc
int u[105][105]; // Ma trận vô hướng (gỡ bỏ mũi tên)
bool visited[105];

// DFS tuân thủ chiều mũi tên
void dfs_directed(int s) {
    visited[s] = true;
    for (int i = 1; i <= n; i++) {
        if (a[s][i] == 1 && !visited[i]) {
            dfs_directed(i);
        }
    }
}

// DFS trên đường 2 chiều
void dfs_undirected(int s) {
    visited[s] = true;
    for (int i = 1; i <= n; i++) {
        if (u[s][i] == 1 && !visited[i]) {
            dfs_undirected(i);
        }
    }
}

// Hàm kiểm tra liên thông mạnh
bool isStronglyConnected() {
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited)); // Reset trạng thái trước khi đi
        dfs_directed(i); // Bắt đầu đi từ đỉnh i
        
        // Kiểm tra xem có đỉnh nào bị bỏ sót không
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                return false; // Chỉ cần 1 đỉnh không tới được -> Chốt luôn là False
            }
        }
    }
    return true; // Tất cả các đỉnh đều đi được tới mọi nơi
}

// Hàm kiểm tra liên thông yếu
bool isWeaklyConnected() {
    memset(visited, false, sizeof(visited));
    dfs_undirected(1); // Chỉ cần xuất phát từ 1 đỉnh bất kỳ (chọn đỉnh 1)
    
    for (int j = 1; j <= n; j++) {
        if (!visited[j]) {
            return false; // Đã thành đường 2 chiều mà vẫn có đảo hoang -> Không liên thông
        }
    }
    return true;
}

int main() {
    faster();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    if (!(cin >> n)) return 0;

    // Nhập ma trận gốc và xây dựng ma trận vô hướng U
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            u[i][j] = a[i][j]; // Copy tạm thời
        }
    }

    // Biến U thành đồ thị vô hướng thực thụ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                u[i][j] = 1;
                u[j][i] = 1; // Mở đường ngược chiều lại
            }
        }
    }

    // Chạy qua 2 màng lọc để kết luận
    if (isStronglyConnected()) {
        cout << 1 << '\n';
    } else if (isWeaklyConnected()) {
        cout << 2 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}