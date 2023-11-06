#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseBlock(Node* head, int block_size) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while (curr != NULL && count < block_size) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseBlock(next, block_size);
    }
    return prev;
}

Node* reverseLinkedList(Node* head, vector<int>& B) {
    Node* curr = head;
    Node* prevBlockEnd = NULL;

    for (int i = 0; i < B.size(); i++) {
        int block_size = B[i];
        Node* blockStart = curr;

        // Find the end of the current block
        for (int j = 1; j < block_size && curr != NULL; j++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            break;
        }

        Node* blockEnd = curr;
        curr = curr->next;

        // Reverse the current block
        Node* reversedBlockStart = reverseBlock(blockStart, block_size);

        // Connect the reversed block to the previous block or to the head of the linked list
        if (prevBlockEnd != NULL) {
            prevBlockEnd->next = reversedBlockStart;
        } else {
            head = reversedBlockStart;
        }
        prevBlockEnd = blockEnd;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* curr = head;

    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* createLinkedList(vector<int>& elements) {
    Node* head = NULL;
    Node* prev = NULL;

    for (int i = 0; i < elements.size(); i++) {
        Node* newNode = new Node();
        newNode->data = elements[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            prev = newNode;
        } else {
            prev->next = newNode;
            prev = newNode;
        }
    }
    return head;
}

int main() {
    // Create the linked list from user input
    int numElements;
    cin >> numElements;

    vector<int> elements(numElements);
   
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    Node* head = createLinkedList(elements);
    // Get the block sizes from user input
    int numBlocks;
    cin >> numBlocks;
    vector<int> blockSizes(numBlocks);
    
    for (int i = 0; i < numBlocks; i++) {
        cin >> blockSizes[i];
    }

    // Reverse the linked list based on the block sizes
    head = reverseLinkedList(head, blockSizes);

    printLinkedList(head);

    return 0;
}
