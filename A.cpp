#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v;

    cin >> n >> v;

    vector<vector<pair<int, int>>> graph(n);

    map<int, string> nodeMap;

    nodeMap[0] = "S";
    nodeMap[1] = "A";
    nodeMap[2] = "B";
    nodeMap[3] = "C";
    nodeMap[4] = "D";
    nodeMap[5] = "E";
    nodeMap[6] = "G1";
    nodeMap[7] = "G2";
    nodeMap[8] = "G3";

    for (int i = 0; i < v; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }

    int start = 0;
    int goal;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    dist[start] = 0;

    pq.push({0, start});

    map<int, int> path;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == 6 || u == 7 || u == 8)
        {
            goal = u;
            break;
        }
        for (auto adj : graph[u])
        {
            int v = adj.first;
            int weight = adj.second;

            if (dist[v] > dist[u] + weight)
            {
                path[v] = u;
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Minimum Distance to Goal: " << dist[goal] << endl;

    cout << "Path: ";
    for (int i = goal; i != start; i = path[i])
        cout << nodeMap[i] << " -> ";

    cout << " " << nodeMap[0] << endl;

    return 0;
}

/*
9 13
0 1 1
0 2 7
1 3 1
1 2 2
1 4 15
2 8 11
2 4 10
2 5 4
3 0 2
4 7 3
4 7 6
5 4 3
7 5 6

100 10 25 1 3 6 0 0 0

*/