
#include <iostream>
#include <conio.h>

#include "graph.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    for (const auto &element : vec)
    {
        out << element << ", ";
    }
    out << "\b\b \b";
    return out;
}

int main()
{
    using namespace std;

    cout << "Directed Graph:-\n";

    Directed_Graph<uint16_t> directed_graph;
    std::vector<uint16_t> bfs, dfs;

    directed_graph.add_edge(1, 2);
    directed_graph.add_edge(1, 3);
    directed_graph.add_edge(1, 4);
    directed_graph.add_edge(1, 5);
    directed_graph.add_edge(2, 6);
    directed_graph.add_edge(2, 7);

    directed_graph.display();
    cout << '\n';

    cout << "____________________\nBFS:-\n";
    bfs = directed_graph.BFS();
    cout << bfs << '\n';
    bfs.clear();

    bfs = directed_graph.BFS(2);
    cout << bfs << '\n';
    
    cout << "____________________\nDFS:-\n";
    dfs = directed_graph.DFS();
    cout << dfs << '\n';
    dfs.clear();

    dfs = directed_graph.DFS(1);
    cout << dfs << '\n';

    directed_graph.delete_vertex(1, 2);
    directed_graph.display();
    cout << '\n';

    cout << "___________________________\nUndirected Graph:-\n";

    Undirected_Graph<uint16_t> undirected_graph;
    std::vector<uint16_t> bfs_2, dfs_2;

    undirected_graph.add_edge(1, 2);
    undirected_graph.add_edge(1, 3);
    undirected_graph.add_edge(1, 4);
    undirected_graph.add_edge(1, 5);
    undirected_graph.add_edge(2, 6);
    undirected_graph.add_edge(2, 7);

    undirected_graph.display();
    cout << '\n';

    cout << "____________________\nBFS:-\n";
    bfs_2 = undirected_graph.BFS();
    cout << bfs_2 << '\n';
    bfs_2.clear();

    bfs_2 = undirected_graph.BFS(2);
    cout << bfs_2 << '\n';
    
    cout << "____________________\nDFS:-\n";
    dfs_2 = undirected_graph.DFS();
    cout << dfs_2 << '\n';
    dfs_2.clear();

    dfs_2 = undirected_graph.DFS(1);
    cout << dfs_2 << '\n';

    undirected_graph.delete_vertex(1, 2);
    undirected_graph.display();
    cout << '\n';

    getch();
    return 0;
}