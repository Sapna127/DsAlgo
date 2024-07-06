
// a custom node to create a node of a linkedlist
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// linkedlist class and the usage of above listnode 
class LinkedList {
private:
    ListNode* head; // head pointer from where linkedlist will start

public:
    LinkedList() {
        head = nullptr; 
    }

    // Insert a node at the beginning of the linked list
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val); // way to create a node using listNode class
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at the end of the linked list
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node from the linked list
    void deleteNode(int val) {
        if (head == nullptr) {
            return;
        }
        if (head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr && temp->next->val != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Node with value " << val << " not found." << endl;
            return;
        }
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Print the linked list
    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Reverse the linked list
    void reverseList() {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

