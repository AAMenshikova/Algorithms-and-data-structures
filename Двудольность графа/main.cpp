#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfs(vector<vector<int>> &graph, int vertex, vector<int> &visited, int color) {
    visited[vertex] = color;
    for (int v: graph[vertex]) {
        if (visited[v] == -1) {
            if (!dfs(graph, v, visited, 1 - color)) {
                return false;
            }
        }
        else if (visited[v] == color) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<int> visited(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == -1) {
            if (!dfs(graph, i, visited, 0)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    set<int> first;
    set<int> second;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            first.insert(i + 1);
        } else {
            second.insert(i + 1);
        }
    }
    cout << '\n';
    for (auto i: first) {
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i: second) {
        cout << i << ' ';
    }
    return 0;
}