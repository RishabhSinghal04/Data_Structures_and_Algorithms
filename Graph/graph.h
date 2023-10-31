#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

template <typename T>
class Graph
{
protected:
    std::unordered_map<T, std::vector<T>> adjacency_list{};

public:
    Graph() = default;

    virtual void add_edge(const T &, const T &) = 0;
    virtual void delete_vertex(const T &, const T &) = 0;

    bool empty() { return adjacency_list.empty(); }

    void display()
    {
        for (const auto &pair : adjacency_list)
        {
            std::cout << "\nAjacency list of vertex " << pair.first << "\n head ";
            for (const auto &element : pair.second)
            {
                std::cout << "-> " << element;
            }
            std::cout << '\n';
        }
    }

    std::vector<T> BFS(const T &source)
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        std::unordered_map<T, bool> visited{};
        std::vector<T> bfs{};

        BFS(source, visited, bfs);
        return bfs;
    }

    std::vector<T> BFS()
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        std::unordered_map<T, bool> visited{};
        std::vector<T> bfs{};

        for (const auto &key : adjacency_list)
        {
            BFS(key.first, visited, bfs);
        }
        return bfs;
    }

    std::vector<T> DFS(const T &source)
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        std::unordered_map<T, bool> visited{};
        std::vector<T> dfs{};
        DFS(source, visited, dfs);
        return dfs;
    }

    std::vector<T> DFS()
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        std::unordered_map<T, bool> visited{};
        std::vector<T> dfs{};

        for (const auto &key : adjacency_list)
        {
            DFS(key.first, visited, dfs);
        }
        return dfs;
    }

private:
    void BFS(const T &source, std::unordered_map<T, bool> &visited, std::vector<T> &bfs)
    {
        std::queue<T> q;
        bfs.reserve(10);

        if (!visited[source])
        {
            visited[source] = true;
            q.emplace(source);

            while (!q.empty())
            {
                const T element = q.front();
                bfs.emplace_back(element);
                q.pop();

                if (adjacency_list.find(element) != adjacency_list.end())
                {
                    for (const auto &neighbour : adjacency_list.at(element))
                    {
                        if (!visited[neighbour])
                        {
                            visited[neighbour] = true;
                            q.emplace(neighbour);
                        }
                    }
                }
            }
        }
    }

    void DFS(const T &element, std::unordered_map<T, bool> &visited, std::vector<T> &dfs)
    {
        visited[element] = true;
        dfs.emplace_back(element);

        if (adjacency_list.find(element) != adjacency_list.end())
        {
            for (const auto &neighbour : adjacency_list.at(element))
            {
                if (!visited[neighbour])
                {
                    DFS(neighbour, visited, dfs);
                }
            }
        }
    }
};

template <typename T>
class Directed_Graph : public Graph<T>
{
public:
    void add_edge(const T &vertex_1, const T &vertex_2)
    {
        this->adjacency_list[vertex_1].emplace_back(vertex_2);
    }

    void delete_vertex(const T &vertex_1, const T &vertex_2)
    {
        if(this->empty())
        {
            throw std::runtime_error("empty");
        }

        auto it = std::find(this->adjacency_list[vertex_1].begin(),
                            this->adjacency_list[vertex_1].end(), vertex_2);

        if (it != this->adjacency_list[vertex_1].end())
        {
            this->adjacency_list[vertex_1].erase(it);
        }
    }
};

template <typename T>
class Undirected_Graph : public Graph<T>
{
public:
    void add_edge(const T &vertex_1, const T &vertex_2)
    {
        this->adjacency_list[vertex_1].emplace_back(vertex_2);
        this->adjacency_list[vertex_2].emplace_back(vertex_1);
    }

    void delete_vertex(const T &vertex_1, const T &vertex_2)
    {
        if(this->empty())
        {
            throw std::runtime_error("empty");
        }

        auto it = std::find(this->adjacency_list[vertex_1].begin(),
                            this->adjacency_list[vertex_1].end(), vertex_2);

        if (it != this->adjacency_list[vertex_1].end())
        {
            this->adjacency_list[vertex_1].erase(it);
        }

        it = std::find(this->adjacency_list[vertex_2].begin(),
                       this->adjacency_list[vertex_2].end(), vertex_1);

        if (it != this->adjacency_list[vertex_2].end())
        {
            this->adjacency_list[vertex_2].erase(it);
        }
    }
};