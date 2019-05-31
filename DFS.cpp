#include "iostream"

using namespace std;

int n;
bool used[101];
int matrix[101][101];

void dfs (int v) {
    used[v] = true;
    for (int i = 1; i<=n; i++) {
        if (matrix[v][i] && !used[i]) {
            cout << v << " " << i << endl;
            dfs(i);
        }
    }
}

int main() {
    
    cout << "Enter amount of vertexes : ";
    
    cin >> n;
    
    cout << "Enter matrix: " << endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Edges in DFS tree:\n";
    dfs(1);
    
    return 0;
}
