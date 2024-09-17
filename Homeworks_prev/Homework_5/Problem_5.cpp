#include <vector>
bool has_cycle(Node* head) {
    std::vector<Node *> nodes;
    while(head != nullptr) {
        for(int i = 0; i < nodes.size(); ++i) {
             if(head == nodes[i]) {
                  return true;
             }
        }
        nodes.push_back(head);
        head = head->next;
    }
    return false;
}