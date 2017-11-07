#include <iostream>
#include "../inc/tree.h"
namespace lab7 {
    void clear(node *to_clear);

    void node_print_gtl(node *top);
    void insert_recursively(node *top, int value);
    int level_recursively(node* top, int key);
    bool in_tree_recursively(node* top, int key);
    unsigned size_recursively(node* top);
    int get_frequency_recursively(node* top, int key);
    unsigned depth_recursively(node* top);
    void path_recursively(node* top, int key);
    void print_recursively(node* top);

    // Construct an empty tree
    tree::tree() {
        root = nullptr;
    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
        if( root == nullptr ){
            root = new node(value);
        }
        else{
            insert_recursively(root, value);
        }
    }

    // Remove key
    bool tree::remove(int key) {


    }

    // What level is key on?
    int tree::level(int key) {
        if(in_tree(key)) return level_recursively(root, key);
        else return -1;
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        if(in_tree(key)) path_recursively(root, key);
    }

    // Number of items in the tree
    unsigned tree::size() {
        if( root == nullptr ) return 0;
        else return size_recursively(root);
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        if( size() <= 1) return 0;
        else return depth_recursively(root) - 1;
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        return in_tree_recursively(root, key);
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        return get_frequency_recursively(root, key);
    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        print_recursively(root);
        std::cout << std::endl;
    }

    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }

    void node_print_gtl(node *top) {
        if(top == nullptr) return;
        node_print_gtl(top->right);
        for(int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    void insert_recursively(node *top, int value)
    {
        //if( top == nullptr ) return;
        if( value > top->data )
        {
            if( top->right == nullptr ) top->right = new node(value);
            else insert_recursively( top->right, value);
        }
        else if( value < top->data )
        {
            if( top ->left == nullptr ) top->left = new node(value);
            else insert_recursively(top->left, value);
        }
        else if( value == top->data ) top->frequency++;
    }

    int level_recursively(node* top, int key)
    {
        if( top -> data == key ) return 0;
        else if (key < top->data) return 1 + level_recursively(top->left, key);
        else if (key > top->data) return 1 + level_recursively(top->right, key);
    }

    bool in_tree_recursively(node* top, int key)
    {
        if(top == nullptr) return false;
        else if(top->data == key) return true;
        else if(key < top->data) return in_tree_recursively(top->left, key);
        else if(key > top->data) return in_tree_recursively(top->right, key);
    }

    unsigned size_recursively(node* top)
    {
        if(top == nullptr) return 0;
        else return top->frequency + size_recursively(top->left) + size_recursively(top->right);
    }

    int get_frequency_recursively(node* top, int key)
    {
        if(top == nullptr) return 0;
        else if(top->data == key) return top->frequency;
        else if(key < top->data) return get_frequency_recursively(top->left, key);
        else if(key > top->data) return get_frequency_recursively(top->right, key);
    }

    unsigned depth_recursively(node* top){
        if(top == nullptr) return 0;
        unsigned left = 0, right = 0;
        left = 1 + depth_recursively(top->left);
        right = 1 + depth_recursively(top->right);
        if(left > right) return left;
        else return right;
    }

    void path_recursively(node* top, int key){
        std::cout << top->data;
        if(top->data == key){
            std::cout << std::endl;
            return;
        }
        else {
            std::cout << " -> ";
            if(key < top->data) path_recursively(top->left, key);
            else path_recursively(top->right, key);
        }
    }

    void print_recursively(node* top)
    {
        if(top == nullptr) return;
        print_recursively(top->left);
        for(int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        print_recursively(top->right);
    }
}