#include <vector>
#include <iostream>
using namespace std;

bool hasCycleDirectedDFS(vector<vector<int>>& graph, int curr, vector<bool>& visited, vector<bool>& onPath)
{
    visited[curr] = true;
    onPath[curr] = true;

    for(auto& child: graph[curr])
    {
        if(!visited[child])
        {
            if(hasCycleDirectedDFS(graph, child, visited, onPath))
            {
                return true;
            }
        }
        else if(onPath[child] == true)
        {
            return true;
        }
    }

    onPath[curr] = false;
    return false;
}

bool hasCycleDirected(vector<vector<int>>& graph)
{
    // Could be unordered_set when labels are not 0 ... V-1
    vector<bool> visited(graph.size(), false);
    vector<bool> onPath(graph.size(), false); 

    for (int i = 0; i < graph.size(); i++)
    {
        if(!visited[i])
        {
            if (hasCycleDirectedDFS(graph, i, visited, onPath))
            {
                return true;
            }
        }
    }

    return false;
}

bool hasCycleUndirectedDFS(vector<vector<int>>& graph, int curr, vector<bool>& visited, int parent)
{
    visited[curr] = true;

    for(auto& child: graph[curr])
    {
        if(!visited[child])
        {
            if(hasCycleUndirectedDFS(graph, child, visited, curr))
            {
                return true;
            }
        }
        else if(parent != child)
        {
            return true;
        }
    }

    return false;
}

bool hasCycleUndirected(vector<vector<int>>& graph)
{
    // Could be unordered_set when labels are not 0 ... V-1
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if(!visited[i])
        {
            if (hasCycleUndirectedDFS(graph, i, visited, -1))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    // We assume elements are labeled 0 ... V-1
    // Otherwise we should use unordered_map
    vector<vector<int>> adjList(V);
    for(int i = 0; i < E; i++)
    {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        // If it is undirected, we do this, too:
        // adjList[to].push_back(from);
    }

    hasCycleDirected(adjList);
    // hasCycleUndirected(adjList);
}