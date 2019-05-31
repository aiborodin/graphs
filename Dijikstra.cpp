#include <bits/stdc++.h>

using namespace std;

int N;
const int inf = INT_MAX;

void dijikstra (vector<vector <int>> &matrix, int source, int dest) {
    
    vector<int> marks(N, inf);
    vector<int> rezult(N,source);
    marks[source] = 0;
    
    set<int> visited;
    
    while (visited.size() < N) {
        
        int min = INT_MAX;
        int min_index = 0;
        int v;
        bool no_way = true;
        
        for (int i = 0; i<N; i++) {
            if (marks[i] < min && visited.find(i) == visited.end()) {
                min = marks[i];
                min_index = i;
                no_way = false;
            }
        }
        
        if (no_way) {
         cout << "\nError : no edges between entered vertexes\n\n";
         return;
         }
        
        v = min_index;
        visited.insert(v);
        
        
        for (int i = 0; i < N; i++) {
            if (matrix[v][i] != 0) {
                if (marks[i] > marks[v] + matrix[v][i]) {
                    marks[i] = marks[v] + matrix[v][i];
                    rezult[i] = v;
                }
            }
        }
    }
    
    vector<int> print;
    
    print.push_back(dest);
    int temp = rezult[dest];
    
    while (temp != source) {
        print.push_back(temp);
        temp = rezult[temp];
    }
    
    print.push_back(source);
    
    auto it = print.rbegin();
    
    cout << "\nMinimal path : ";
    
    while (it != print.rend()) {
        cout << *it+1 << " ";
        it++;
    }
    
    cout << "\nCost : " << marks[dest] << endl << endl;
    
}

int main() {
    
    int source, dest;
    
    cout << "Enter amount of vertices : ";
    cin >> N;
    
    cout << "Enter star vertex : ";
    cin >> source;
    
    cout << "Enter end vertex : ";
    cin >> dest;
    
    cout << "Enter matrix : \n\n";
    
    vector<vector<int>> matrix (N, vector<int>(N));
    
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    dijikstra(matrix, source-1, dest-1);
    
    return 0;
}
