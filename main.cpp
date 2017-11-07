#include "lib/lab06/inc/deck.h"
#include "lib/lab07/inc/tree.h"

int main() {
    //lab6::deck newdeck = lab6::deck();
    lab7::tree test_tree = lab7::tree();
    test_tree.insert(10);
    test_tree.insert(5);
    test_tree.insert(15);
    test_tree.insert(7);
    test_tree.insert(3);
    test_tree.insert(2);
    test_tree.insert(1);
    test_tree.insert(4);
    test_tree.insert(9);
    test_tree.insert(8);
    test_tree.insert(6);
    test_tree.insert(5);
    return 0;
}