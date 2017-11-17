#ifndef CMPE126F17_LABS_LIB_LAB07_INC_TREE_H
#define CMPE126F17_LABS_LIB_LAB07_INC_TREE_H

#include "node.h"

namespace lab7 {
    class tree {
        node *root;

        void addLeaf(int value, node *ptr);

        void printInOrder(node *ptr);

        void removeNode(int key, node *ptr);

        void removeRootMatch();

        void removeMatch(node *parent, node *match, bool left);

        int size(node *ptr);

        int findSmallest(node *ptr);

        int getLevelUtil(struct node *node, int data, int level);

        int maxDepth(node *node);

        int frequency(node *ptr, int key);

    public:
        tree();

        ~tree();

        void insert(int value);

        bool remove(int key);

        bool in_tree(int key);

        int get_frequency(int key);

        int level(int key);

        void path_to(int key);

        unsigned size();

        unsigned depth();

        void print();

        void print_gtl();
    };
}
#endif //CMPE126F17_LABS_LIB_LAB07_INC_TREE_H
