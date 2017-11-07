#include "../inc/tree.h"
namespace lab7 {
    void clear(node *to_clear);

    void node_print_gtl(node *to_print);
    void insert_recursively(node *top, int value);

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

    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {

    }

    // Number of items in the tree
    unsigned tree::size() {

    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {

    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {

    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {

    }

    // Print the tree least to greatest, Include duplicates
    void tree::print() {

    }

    void tree::print_gtl() {
        //WILL BE PROVIDED FOR YOU
    }

    void node_print_gtl(node *to_print) {
        //WILL BE PROVIDED FOR YOU
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
}