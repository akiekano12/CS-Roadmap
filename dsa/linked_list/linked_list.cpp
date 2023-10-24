#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insertion Methods:
    // Add a new node with the given value to the end of the linked list.
    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    // Add a new node with the given value to the beginning of the linked list.
    void prepend(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    // Insert a new node with the given value after the specified node.
    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            std::cerr << "The previous node is null. Cannot insert after." << std::endl;
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = prevNode->next;
        prevNode->next = new_node;
    }

    // Insert a new node with the given value before the specified node.
    void insertBefore(Node* nextNode, int data) {
        if (nextNode == nullptr || head == nullptr) {
            std::cerr << "The next node is null or the linked list is empty. Cannot insert before." << std::endl;
            return;
        }
        if (head == nextNode) {
            Node* new_node = new Node(data);
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next != nextNode) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* new_node = new Node(data);
            new_node->next = current->next;
            current->next = new_node;
        } else {
            std::cerr << "The next node was not found in the linked list. Cannot insert before." << std::endl;
        }
    }

    // Deletion Methods:
    // Delete the specified node from the linked list.
    void deleteNode(Node* nodeToDelete) {
        if (head == nullptr) {
            std::cerr << "The linked list is empty. Cannot delete." << std::endl;
            return;
        }
        if (head == nodeToDelete) {
            head = head->next;
            delete nodeToDelete;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next != nodeToDelete) {
            current = current->next;
        }
        if (current->next != nullptr) {
            current->next = current->next->next;
            delete nodeToDelete;
        } else {
            std::cerr << "Node to delete was not found in the linked list." << std::endl;
        }
    }

    // Delete the first node with the specified value from the linked list.
    void deleteValue(int value) {
        if (head == nullptr) {
            std::cerr << "The linked list is empty. Cannot delete." << std::endl;
            return;
        }
        if (head->data == value) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        } else {
            std::cerr << "Value to delete was not found in the linked list." << std::endl;
        }
    }

    // Delete the node at the specified index in the linked list.
    void deleteAtIndex(int index) {
        if (head == nullptr) {
            std::cerr << "The linked list is empty. Cannot delete." << std::endl;
            return;
        }
        if (index == 0) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next == nullptr) {
                std::cerr << "Index is out of bounds. Cannot delete." << std::endl;
                return;
            }
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        } else {
            std::cerr << "Index is out of bounds. Cannot delete." << std::endl;
        }
    }

    // Traversal and Display Methods:
    // Display the elements of the linked list.
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Get the value of the node at the specified index.
    int get(int index) {
        if (head == nullptr) {
            std::cerr << "The linked list is empty." << std::endl;
            return -1; // Return a sentinel value (you can choose a different value or approach).
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            if (current->next == nullptr) {
                std::cerr << "Index is out of bounds." << std::endl;
                return -1; // Return a sentinel value.
            }
            current = current->next;
        }
        return current->data;
    }

    // Return the number of nodes in the linked list.
    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Check if the linked list is empty.
    bool isEmpty() {
        return head == nullptr;
    }

    // Search and Access Methods:
    // Search for a node with the specified value in the linked list and return it.
    Node* search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Value not found.
    }

    // Find the index of the first occurrence of the specified value in the linked list.
    int indexOf(int value) {
        int index = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Value not found.
    }
};

int main() {
    LinkedList myLinkedList;

    // Append some nodes to the linked list
    myLinkedList.append(1);
    myLinkedList.append(2);
    myLinkedList.append(3);

    // Insert a new node with data 4 after the second node
    Node* secondNode = myLinkedList.search(2);
    myLinkedList.insertAfter(secondNode, 4);

    // Insert a new node with data 0 before the third node
    Node* thirdNode = myLinkedList.search(3);
    myLinkedList.insertBefore(thirdNode, 0);

    // Display the linked list
    std::cout << "Linked list contents: ";
    myLinkedList.display();

    // Get the value at index 2
    int valueAtIndex2 = myLinkedList.get(2);
    std::cout << "Value at index 2: " << valueAtIndex2 << std::endl;

    // Get the size of the linked list
    int listSize = myLinkedList.size();
    std::cout << "Size of the linked list: " << listSize << std::endl;

    // Check if the linked list is empty
    bool isEmpty = myLinkedList.isEmpty();
    std::cout << "Is the linked list empty? " << (isEmpty ? "Yes" : "No") << std::endl;

    // Find the index of value 2
    int index2 = myLinkedList.indexOf(2);
    std::cout << "Index of value 2: " << index2 << std::endl;

    // Delete the first node
    myLinkedList.deleteNode(myLinkedList.head);

    // Delete the node with data 4
    Node* nodeToDelete = myLinkedList.search(4);
    myLinkedList.deleteNode(nodeToDelete);

    // Delete the node at index 2
    myLinkedList.deleteAtIndex(2);

    // Display the modified linked list
    std::cout << "Modified linked list contents: ";
    myLinkedList.display();

    return 0;
}
