#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void dfs1(int node,
          vector<vector<int>> &adj,
          vector<int> &visited,
          stack<int> &st)
{
    visited[node] = 1;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs1(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}
vector<vector<int>> getTranspose(
    int V,
    vector<vector<int>> &adj)
{
    vector<vector<int>> transpose(V);

    for (int i = 0; i < V; i++)
    {
        for (int neighbor : adj[i])
        {
            transpose[neighbor].push_back(i);
        }
    }

    return transpose;
}
void dfs2(int node,
          vector<vector<int>> &transpose,
          vector<int> &visited,
          vector<int> &component)
{
    visited[node] = 1;

    component.push_back(node);

    for (int neighbor : transpose[node])
    {
        if (!visited[neighbor])
        {
            dfs2(neighbor,
                 transpose,
                 visited,
                 component);
        }
    }
}
vector<vector<int>> kosaraju(
    int V,
    vector<vector<int>> &adj)
{
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs1(i, adj, visited, st);
        }
    }
    vector<vector<int>> transpose =
        getTranspose(V, adj);
    visited.assign(V, 0);
    vector<vector<int>> SCC;
    while (!st.empty())
    {
        int node = st.top();

        st.pop();

        if (!visited[node])
        {
            vector<int> component;

            dfs2(node,
                 transpose,
                 visited,
                 component);

            SCC.push_back(component);
        }
    }

    return SCC;
}
void printSCC(
    vector<vector<int>> &SCC,
    vector<char> &name)
{
    cout << "\nStrongly Connected Components:\n";

    for (int i = 0; i < SCC.size(); i++)
    {
        cout << "{ ";

        for (int vertex : SCC[i])
        {
            cout << name[vertex] << " ";
        }

        cout << "}\n";
    }
}
void addEdge(
    vector<vector<int>> &adj,
    int u,
    int v)
{
    adj[u].push_back(v);
}
int main()
{
    int V = 6;

    vector<vector<int>> adj(V);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 5);
    addEdge(adj, 5, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 5, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    vector<char> name =
    {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f'
    };
    vector<vector<int>> SCC =
        kosaraju(V, adj);

    printSCC(SCC, name);
    return 0;
}
