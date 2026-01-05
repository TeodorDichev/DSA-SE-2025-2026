#include <iostream>
#include <vector>

void dfs(int current, std::vector<bool> &visited, std::vector<std::vector<int>> &graph)
{
    visited[current] = true;

    for (int neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, graph);
        }
    }
}

int solve()
{
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> graph(V);

    int v, w;
    for (int e = 0; e < E; e++)
    {
        std::cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    std::vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            continue;
        }

        dfs(i, visited, graph);
        count++;
    }

    return count;
}

int main()
{
    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        int answer = solve();
        std::cout << answer << " ";
    }

    return 0;
}