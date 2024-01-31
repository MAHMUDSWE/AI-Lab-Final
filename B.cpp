#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;

    vector<vector<int>> graph(n);

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
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int start = 0;
    int goal;

    stack<pair<int, int>> s;
    vector<bool> visited(n, false);

    visited[start] = true;
    s.push({start, 0});

    int depthLimit = 4;

    map<int, int> path;

    while (!s.empty())
    {
        start = s.top().first;
        int currentDepth = s.top().second;

        if (start == 6 || start == 7 || start == 8)
        {
            goal = start;
            break;
        }
        s.pop();

        if (currentDepth < depthLimit)
        {
            for (auto adj : graph[start])
            {
                if (!visited[adj])
                {
                    path[adj] = start;
                    visited[adj] = true;
                    s.push({adj, currentDepth + 1});
                }
            }
        }
    }

    cout << "Path: ";

    start = 0;

    for (int i = goal; i != start; i = path[i])
    {

        cout << nodeMap[i] << " -> ";
    }

    // for(auto it: path) {
    //     cout << it.first << " " << it.second << endl;
    // }
    cout << nodeMap[start] << endl;

    return 0;
}
