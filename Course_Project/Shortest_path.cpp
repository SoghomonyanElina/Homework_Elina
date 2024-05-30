#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, std::vector<int>>  input_Graph(size_t size, std::ifstream& infile) {
    std::unordered_map<int, std::vector<int>> Graph;
    for(size_t i = 0; i  < size; ++i) {
        int node;
        size_t size_v;
        infile >> node >> size_v;
        std::vector<int> neighbors;
        for(size_t i = 0; i < size_v; ++i) {
            int neighbor;
            infile >> neighbor;
            neighbors.push_back(neighbor);
        }
        Graph[node] = neighbors;
    }
    return Graph;
}

std::vector<int> Shortest_path(std::unordered_map<int, std::vector<int>>& Graph, int Node_1, int Node_2) {
    std::queue<int> queue;
    std::unordered_set<int> visited;
    std::unordered_map<int, int> parent;
    queue.push(Node_1);
    visited.insert(Node_1);
    int current;
    std::vector<int> path;
    while(!queue.empty()) {
        current = queue.front();
        queue.pop();
        if(current == Node_2) {
            for(int node = current; node != Node_1; node = parent[node]) {
                path.push_back(node);
            }
            path.push_back(Node_1);
            std::reverse(path.begin(), path.end());
            return path;
        }
        for(int neighbor : Graph[current]) {
            if(visited.find(neighbor) == visited.end()) {
                queue.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }
    return {};
}

void Print_path(std::vector<int> Path) {
    std::cout << "The shortest path is: " << std::endl;
    for(size_t i = 0; i < Path.size() - 1; ++i) {
        std::cout << Path[i] << "->";
    }
    std::cout << Path[Path.size() - 1] << std::endl;
}