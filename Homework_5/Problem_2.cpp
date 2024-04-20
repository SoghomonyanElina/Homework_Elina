#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* current = llist;
    if(llist == nullptr) {
        llist = new_node;
        return llist;
    }
    if(new_node->data <= current->data) {
        new_node->next = current;
        llist = new_node;
        return llist;
    }
    while(current->next != nullptr && new_node->data >= current->next->data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return llist;
}