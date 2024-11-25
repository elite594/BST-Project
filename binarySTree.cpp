#include "binarySTree.h"
#include <iostream>

// Destructor
BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

// Helper function to delete the tree
void BinarySearchTree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->leftNext);
        deleteTree(node->rightNext);
        delete node;
    }
}


Node* BinarySearchTree::insertRecursive(Node* current, int value) {
    if (current == nullptr) {
        return new Node(value);
    }
    
    if (value < current->data) {
        current->leftNext = insertRecursive(current->leftNext, value);
    } else if (value > current->data) {
        current->rightNext = insertRecursive(current->rightNext, value);
    }
    
    return current;
}

// Public insertion function
void BinarySearchTree::insert(int value) {
    root = insertRecursive(root, value);
}

// Pre-order traversal helper
void BinarySearchTree::preOrderTraversalHelper(Node* node) {
    if (node) {
        std::cout << node->data << " ";
        preOrderTraversalHelper(node->leftNext);
        preOrderTraversalHelper(node->rightNext);
    }
}

// In-order traversal helper
void BinarySearchTree::inOrderTraversalHelper(Node* node) {
    if (node) {
        inOrderTraversalHelper(node->leftNext);
        std::cout << node->data << " ";
        inOrderTraversalHelper(node->rightNext);
    }
}

// Post-order traversal helper
void BinarySearchTree::postOrderTraversalHelper(Node* node) {
    if (node) {
        postOrderTraversalHelper(node->leftNext);
        postOrderTraversalHelper(node->rightNext);
        std::cout << node->data << " ";
    }
}

// Public traversal functions
void BinarySearchTree::preOrderTraversal() {
    std::cout << "Pre-order traversal: ";
    preOrderTraversalHelper(root);
    std::cout << std::endl;
}

void BinarySearchTree::inOrderTraversal() {
    std::cout << "In-order traversal: ";
    inOrderTraversalHelper(root);
    std::cout << std::endl;
}

void BinarySearchTree::postOrderTraversal() {
    std::cout << "Post-order traversal: ";
    postOrderTraversalHelper(root);
    std::cout << std::endl;
}