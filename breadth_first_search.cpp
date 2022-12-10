#include <bits/stdc++.h>
#include "input.h"

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> dist(n);
    vector<bool> visited(n);
    vector<vector<bool>> adj(n);
    for (int i = 0; i < n; i++) adj[i].resize(n);
    for (int i = 0; i < m; i++) {
        int j = edges[i][0] - 1;
        int k = edges[i][1] - 1;
        adj[j][k] = true;
        adj[k][j] = true;
    }
    queue<int> q;
    visited[s-1] = true;
    q.push(s-1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                dist[i] = dist[v] + 6;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < n; i++) if (dist[i] == 0) dist[i] = -1;
    dist.erase(dist.begin() + s - 1);
    return dist;
}

int main() {
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);
        
        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size()-1) cout << " ";
        }

        cout << endl;
    }

    return 0;
}