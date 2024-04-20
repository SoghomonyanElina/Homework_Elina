#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};


int lenghthOfList(SinglyLinkedListNode* head) {
    int count = 0;
    while(head != nullptr) {
        ++count;
        head = head->next;
    }
    return count;
}
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int length1 = lenghthOfList(head1);
    int length2 = lenghthOfList(head2);
    while(length1 > length2) {
        head1 = head1->next;
        --length1;
    }
    while(length1 < length2) {
        head2 = head2->next;
        --length2;
    }
    while(head1 != nullptr) {
        if(head1 == head2) {
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1->data;
}