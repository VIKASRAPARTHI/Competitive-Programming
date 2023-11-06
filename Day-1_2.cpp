#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* getLastNode(Node* head) {
    while (head->next != NULL) {
        head = head->next;
    }

    return head;
}

void swapNodes(Node* node1, Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

Node* partition(Node* head, Node* tail) {
    int pivot = tail->data;
    Node* i = head->prev;

    for (Node* j = head; j != tail; j = j->next) {
        if (j->data < pivot) {
            i = (i == NULL) ? head : i->next;
            swapNodes(i, j);
        }
    }

    i = (i == NULL) ? head : i->next;
    swapNodes(i, tail);

    return i;
}

void quickSort(Node* head, Node* tail) {
    if (tail != NULL && head != tail && head != tail->next) {
        Node* pivot = partition(head, tail);
        quickSort(head, pivot->prev);
        quickSort(pivot->next, tail);
    }
}

Node* quickSortDoublyLinkedList(Node* head) {
    Node* tail = getLastNode(head);
    quickSort(head, tail);

    return head;
}

void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node* createLinkedList(vector<int>& elements) {
    Node* head = NULL;
    Node* prev = NULL;

    for (int i = 0; i < elements.size(); i++) {
        Node* node = new Node();
        node->data = elements[i];
        node->prev = prev;

        if (prev != NULL) {
            prev->next = node;
        } else {
            head = node;
        }

        prev = node;
    }

    return head;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> elements(n);

        for (int i = 0; i < n; i++) {
            cin >> elements[i];
        }

        Node* head = createLinkedList(elements);
        head = quickSortDoublyLinkedList(head);
        printLinkedList(head);
    }

    return 0;
}
