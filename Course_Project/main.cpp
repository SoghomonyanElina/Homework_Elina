#include "Shortest_path.cpp"
int main() {
    size_t size;
    std::ifstream infile("input.txt");
    if(!infile) {
        std::cerr << "Unable to open file input.txt";
        return 1;
    }
    infile >> size;
    auto Graph = input_Graph(size, infile);
    infile.close();
    int Node_1, Node_2;
    std::cout << "Enter the two nodes which shortest path must find: ";
    do {
        std::cin >> Node_1 >> Node_2;
    } 
    while(Node_1 > size || Node_2 > size || Node_1 == Node_2);
    auto Path = Shortest_path(Graph, Node_1, Node_2);
    Print_path(Path);
}