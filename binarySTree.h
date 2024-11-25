#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class Node {
public:
    int data;
    Node* leftNext;
    Node* rightNext;
    
    Node(int value) : data(value), leftNext(nullptr), rightNext(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    
    Node* insertRecursive(Node* current, int value);
    void preOrderTraversalHelper(Node* node);
    void inOrderTraversalHelper(Node* node);
    void postOrderTraversalHelper(Node* node);

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();
    
    void deleteTree(Node* node);
    void insert(int value);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
};

#endif // BINARY_SEARCH_TREE_H