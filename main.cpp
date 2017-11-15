#include "lib/lab06/inc/deck.h"
#include "lib/lab07/inc/tree.h"
#include "lib/lab08/inc/sorts.h"

int main() {
    sorts sorting_machine;
    lab6::doubly_linked_list *unsorted_list;
    std::vector <unsigned> unsorted_numbers;
    std::vector<unsigned>::iterator Lposition, Rposition;
    unsorted_numbers=std::vector<unsigned>({72, 96, 26, 94, 33,  2, 42,
                                            89, 41, 36, 63, 65, 56, 16,
                                            17, 59, 35, 39, 40,  1, 69});
    Lposition = unsorted_numbers.begin();
    Rposition = unsorted_numbers.end();
    unsorted_list = new lab6::doubly_linked_list(unsorted_numbers);

    lab6::doubly_linked_list *test_list = new lab6::doubly_linked_list();

    *test_list = sorting_machine.insertion_sort(*unsorted_list, 20);
    int a = 1;
    return 1;
}