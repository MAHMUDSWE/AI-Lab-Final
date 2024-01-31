#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;

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

    vector<vector<pair<int, int>>> graph(n);

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

    map<int, int> heuristicMap;

    for (int i = 0; i < n; i++)
    {
        int heuristic;
        cin >> heuristic;
        heuristicMap[i] = heuristic;
    }

    dist[start] = 0;

    pq.push({dist[start] + heuristicMap[start], start});

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
                pq.push({dist[v] + heuristicMap[v], v});
            }
        }
    }

    cout << "Minimum Distance to Goal: " << dist[goal] << endl;

    cout << "Path: ";
    for (int i = goal; i != start; i = path[i])
    {
        if (i == 6 || i == 7 || i == 8)
            cout << nodeMap[i] << " -> ";
        else
            cout << nodeMap[i] << " -> ";
    }

    cout << " " << nodeMap[0] << endl;

    return 0;
}

/*
9 13
0 1
0 2
1 3
1 2
1 4
2 8
2 4
2 5
3 0
4 7
4 7
5 4
7 5

100 10 25 1 3 6 0 0 0

*/