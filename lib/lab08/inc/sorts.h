#ifndef CMPE126F17_LABS_SORTS_H
#define CMPE126F17_LABS_SORTS_H

#include "doubly_linked_list.h"
#include "node.h"

class sorts {
public:
    lab6::doubly_linked_list insertion_sort(lab6::doubly_linked_list input, int iterations);

    lab6::doubly_linked_list selection_sort(lab6::doubly_linked_list input, int iterations);

    lab6::doubly_linked_list bubble_sort(lab6::doubly_linked_list input, int iterations);

    lab6::doubly_linked_list cocktail_sort(lab6::doubly_linked_list input, int iterations);

    lab6::doubly_linked_list quick_sort(lab6::doubly_linked_list input);

    lab6::doubly_linked_list merge_sort(lab6::doubly_linked_list input);

    lab6::doubly_linked_list radix_sort(lab6::doubly_linked_list input);

    int partition(lab6::doubly_linked_list input, int start, int end);

    lab6::doubly_linked_list quickSortHelper(lab6::doubly_linked_list input, int start, int end);
    lab6::doubly_linked_list quickSort(lab6::doubly_linked_list&obj,int left,int right);
};

#endif //CMPE126F17_LABS_SORTS_H
