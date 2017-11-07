#include "lib/lab06/inc/deck.h"
#include "lib/lab07/inc/tree.h"

int main() {
    //lab6::deck newdeck = lab6::deck();
    lab7::tree test_tree = lab7::tree();
    test_tree.insert(10);
    std::cout << test_tree.size() << std::endl;
    test_tree.insert(5);
    std::cout << test_tree.depth() << std::endl;

    test_tree.insert(15);
    test_tree.insert(7);
    test_tree.insert(3);
    test_tree.insert(2);
    test_tree.insert(1);
    std::cout << test_tree.level(1) << std::endl;
    test_tree.insert(4);
    test_tree.insert(9);
    test_tree.insert(8);
    test_tree.insert(6);
    test_tree.insert(5);
    std::cout << test_tree.level(10) << std::endl;
    std::cout << test_tree.size() << std::endl;
    std::cout << test_tree.get_frequency(5) << std::endl;
    std::cout << test_tree.get_frequency(11) << std::endl;
    std::cout << test_tree.depth() << std::endl;
    return 0;
}