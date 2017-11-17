#include "../inc/tree.h"
#include "iostream"

namespace lab7 {
    using namespace std;

    void clear(node *to_clear);

    void node_print_gtl(node *to_print);

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

        addLeaf(value, root);
    }

// Remove key
    bool tree::remove(int key) {
        removeNode(key, root);
    }

// What level is key on?
    int tree::level(int key) {
        getLevelUtil(root, key, 1);
    }

// Print the path to the key, starting with root
    void tree::path_to(int key) {
        node *current = root;
        bool found = false;
        if (current == nullptr) {
            std::cout << "Empty tree " << std::endl;
        } else {
            while (current != nullptr && !found) {
                std::cout << current->data << "->";
                if (current->data == key) {
                    found = true;
                } else if (current->data > key) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
        }
    }

// Number of items in the tree
    unsigned tree::size() {
        size(root);
    }

// Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        maxDepth(root);

    }

// Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        int fre = frequency(root, key);
        if (fre == 0)
            return false;
        else if (fre > 0)
            return true;
    }

// Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        frequency(root, key);
    }

// Print the tree least to greatest, Include duplicates
    void tree::print() {
        printInOrder(root);
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

    void tree::addLeaf(int value, node *ptr) {
        if (root == nullptr)
            root = new node(value);
        else if (value < ptr->data) {
            if (ptr->left != nullptr)
                addLeaf(value, ptr->left);
            else
                ptr->left = new node(value);
        } else if (value > ptr->data) {
            if (ptr->right != nullptr)
                addLeaf(value, ptr->right);
            else
                ptr->right = new node(value);
        }
    }

    void tree::printInOrder(node *ptr) {
        if (root != nullptr) {
            if (ptr->left != nullptr) {
                printInOrder(ptr->left);
            }
            cout << ptr->data << " ";
            if (ptr->right != nullptr) {
                printInOrder(ptr->right);
            }
        } else
            cout << "The tree is empty" << endl;
    }

    void tree::removeNode(int key, node *ptr) {
        if (root != nullptr) {
            if (root->data == key)
                removeRootMatch();
            else {
                if (key < ptr->data && ptr->data != 0) {
                    ptr->left->data == key ?
                    removeMatch(ptr, ptr->left, true) :
                    removeNode(key, ptr->left);

                } else if (key < ptr->data && ptr->data != 0) {
                    ptr->right->data == key ?
                    removeMatch(ptr, ptr->right, false) :
                    removeNode(key, ptr->right);

                }
            }


        } else
            cout << "The tree is empty" << endl;
    }

    void tree::removeRootMatch() {
        if (root != nullptr) {
            node *delPtr = root;
            int rootKey = root->data;
            int smallestInRightTree;
            if (root->data == 0 && root->right == nullptr) {
                root = nullptr;
                delete delPtr;
            } else if (root->left == nullptr && root->right != nullptr) {
                root = root->left;
                delPtr->left = nullptr;
                delete delPtr;
            } else {
                smallestInRightTree = findSmallest(root->right);
                removeNode(smallestInRightTree, root);
                root->data = smallestInRightTree;
            }
        } else
            cout << "The tree is empty" << endl;
    }

    void tree::removeMatch(node *parent, node *match, bool left) {
        if (root != nullptr) {
            node *delPtr;
            int matchKey = match->data;
            int smallestInRightTree;

            if (match->left == nullptr && match->right == nullptr) {
                delPtr = match;
                left == true ? parent->left = nullptr : parent->right = nullptr;
                delete delPtr;
            } else if (match->left == nullptr && match->right != nullptr) {

                left == true ? parent->left = match->right : parent->right = match->right;
                match->right = nullptr;
                delPtr = match;
                delete delPtr;
            } else if (match->left != nullptr && match->right == nullptr) {

                left == true ? parent->left = match->left : parent->right = match->left;
                match->left = nullptr;
                delPtr = match;
                delete delPtr;
            } else {
                smallestInRightTree = findSmallest(match->right);
                removeNode(smallestInRightTree, match);
                match->data = smallestInRightTree;
            }
        } else {
            cout << "The tree is empty" << endl;
        }
    }

    int tree::findSmallest(node *ptr) {
        if (root == nullptr)
            cout << "The tree is empty" << endl;
        else {
            if (ptr->left != nullptr)
                return findSmallest(ptr->left);
            else
                return ptr->data;
        }

    }

    int tree::size(node *ptr) {
        if (ptr == nullptr)
            return 0;
        else
            return (size(ptr->left) + 1 + size(ptr->right));
    }

    int tree::maxDepth(node *node) {
        if (node == nullptr)
            return 0;
        else {
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else return (rDepth + 1);
        }
    }

    int tree::getLevelUtil(struct node *node, int data, int level) {
        if (node == nullptr)
            return 0;

        if (node->data == data)
            return level;

        int downlevel = getLevelUtil(node->left, data, level + 1);
        if (downlevel != 0)
            return downlevel;

        downlevel = getLevelUtil(node->right, data, level + 1);
        return downlevel;
    }

/* Returns level of given data value */
    int tree::frequency(node *ptr, int key) {
        int count = 0;
        ptr = root;
        if (ptr->data == key && ptr != nullptr)
            count++;
        else if (key < ptr->data) {
            frequency(ptr->left, key);
        } else if (key > ptr->data) {
            frequency(ptr->right, key);
        }
        return count;
    }
}