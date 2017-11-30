#include "../inc/tree.h"
#include <iostream>

using namespace std;

namespace lab7 {
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
        node *temp1, *temp2, *temp3, *temp4, *temp5;
        temp1 = temp2 = temp3 = temp4 = root;
        temp5 = nullptr;

        if(root->data == key && root->frequency > 1)
        {
            root->frequency--;
            return true;
        }

        else if(root->data == key && root->frequency <= 1)
        {
            if (temp1->left != nullptr)
            {
                temp1 = temp1->left;
                temp3 = temp3->left;
                temp4 = temp4->right;

                while (temp1->right != nullptr)
                {
                    temp2 = temp1;
                    temp1 = temp1->right;
                }
                if (temp1->left != nullptr)
                {
                    temp5 = temp1->left;
                    temp1 = temp1->right;
                }
                temp2->right = temp5;
                root = temp1;
                root->right = temp4;
                root->left = temp3;
                return true;
            }

            else if (temp1->right != nullptr)
            {
                temp1 = temp1->right;
                temp3 = temp3->left;
                temp4 = temp4->right;

                while (temp1->left != nullptr)
                {
                    temp2 = temp1;
                    temp1 = temp1->left;
                }
                if (temp1->right != nullptr)
                {
                    temp5 = temp1->right;
                    temp1 = temp1->left;
                }
                temp2->left = temp5;
                root = temp1;
                root->right = temp4;
                root->left = temp3;
                return true;
            }
        }

        while (true) {

            if((temp1->data == key) && (temp1->frequency > 1))
            {
                temp1->frequency--;
                return true;
            }

            if (temp1->left != nullptr && temp1->data > key)
            {
                temp2 = temp1;
                temp1 = temp1->left;
            }

            else if (temp1->right != nullptr && temp1->data < key)
            {
                temp2 = temp1;
                temp1 = temp1->right;
            }

            else if ((temp1->data == key) && (temp1->right != nullptr) && (temp2->right == temp1))
            {
                temp2->right = temp1->right;
                temp2 = temp2->right;
                temp2->left = temp1->left;
                return true;
            }

            else if ((temp1->data == key) && (temp1->right != nullptr) && (temp2->left == temp1))
            {
                temp2->left = temp1->right;
                temp2 = temp2->left;
                temp2->left = temp1->left;
                return true;
            }

            else if ((temp1->data == key) && (temp1->right == nullptr) && (temp1->left != nullptr) && (temp2->right == temp1))
            {
                temp2->right = temp1->left;
                return true;
            }

            else if ((temp1->data == key) && (temp1->right == nullptr) && (temp1->left != nullptr) && (temp2->left == temp1))
            {
                temp2->left = temp1->left;
                return true;
            }

            else if ((temp1->data == key) && (temp1->right == nullptr) && (temp1->left == nullptr) && (temp2->right == temp1))
            {
                temp2->right = nullptr;
                return true;
            }

            else if ((temp1->data == key) && (temp1->right == nullptr) && (temp1->left == nullptr) && (temp2->left == temp1))
            {
                temp2->left = nullptr;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // What level is key on?
    int tree::level(int key) {
        int a = getLevelUtil(root, key, 1);
        return a - 1;
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        node *current = root;
        bool found = false;
        if (current == nullptr) {
            std::cout << "Empty tree " << std::endl;
        } else if (get_frequency(key) >= 1) {
            while (current != nullptr && !found) {
                std::cout << current->data;
                if (current->data != key)
                    std::cout << " -> ";
                if (current->data == key) {
                    found = true;
                    std::cout << endl;

                } else if (current->data > key) {
                    current = current->left;
                }
//
                else {
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
        //  maxDepth(root);
        int a = maxDepth(root);
        if (a == 0)
            return 0;
        else
            return a - 1;

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
        cout << endl;
    }

    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }

    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);

        //missing code
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    void tree::addLeaf(int value, node *ptr) {
        if (root == nullptr) {
            root = new node(value);
        } else if (value == ptr->data) {
            ptr->frequency++;
        } else if (value < ptr->data) {
            if (ptr->left != nullptr)
                addLeaf(value, ptr->left);
            else {
                ptr->left = new node(value);
            }
        } else if (value > ptr->data) {
            if (ptr->right != nullptr)
                addLeaf(value, ptr->right);
            else {
                ptr->right = new node(value);
            }
        }


    }

    void tree::printInOrder(node *ptr) {
        if (root != nullptr) {
            if (ptr->left != nullptr) {
                printInOrder(ptr->left);
            }
            if (frequency(root, ptr->data) > 1) {
                for (int i = 0; i < frequency(root, ptr->data); i++)
                    cout << ptr->data << " ";
            } else if (frequency(root, ptr->data) == 1)
                cout << ptr->data << " ";

            if (ptr->right != nullptr) {
                printInOrder(ptr->right);
            }
        } else
            cout << "The tree is empty";
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
        else {
            int count = ptr->frequency;
            count += size(ptr->left);
            count += size(ptr->right);
            return count;
        }
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
        int next;

        if (ptr == nullptr)
            return 0;
        if (ptr->data == key)
            return ptr->frequency;;

        next = frequency(ptr->left, key);
        if (next != 0)
            return next;
        next = frequency(ptr->right, key);
    }
}