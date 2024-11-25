

#include "binarySTree.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    // Create a vector to store the original numbers
    std::vector<int> numbers;
    
    // Set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 99);
    
    // Generate 35 random numbers
    std::cout << "Original numbers:" << std::endl;
    for (int i = 0; i < 35; i++) {
        int num = dis(gen);
        numbers.push_back(num);
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
    
   
    BinarySearchTree bst;
    for (int num : numbers) {
        bst.insert(num);
    }
    
    // Perform all three traversals
    bst.preOrderTraversal();
    bst.inOrderTraversal();
    bst.postOrderTraversal();
    
    return 0;
}