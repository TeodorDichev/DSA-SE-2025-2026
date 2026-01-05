#include <iostream>
#include <vector>

void dfs(int current, std::vector<bool> &visited, std::vector<std::vector<int>> &graph, int currComponent, std::vector<int> componentMap)
{
    visited[current] = true;
    componentMap[current] = currComponent;
    for (int neighbor : graph[current])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, graph, currComponent, componentMap);
        }
    }
}

int main()
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
    std::vector<int> compMap(V, -1);
    int currComponent = 0;

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            continue;
        }

        dfs(i, visited, graph, currComponent, compMap);
        currComponent++;
    }

    int q;
    std::cin >> q;
    int start, end;
    for(int i = 0; i < q; i++)
    {
        std::cin >> start >> end;
        std::cout << (compMap[start] == compMap[end]) << ' ';
    }
}