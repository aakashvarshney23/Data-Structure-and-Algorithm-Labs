#include "sorts.h"

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if (iterations == 0) //handles 0 iteration case
    {
        return working_list;
    }
    if (iterations > working_list.get_size() - 1) {
        iterations = working_list.get_size() - 1;
    }
    for (int i = 1; i <= iterations; i++) //general case
    {
        for (int j = i; j > 0; j--) {
            if (working_list.get_data(j) < working_list.get_data(j - 1)) {
                working_list.swap(j, j - 1);
            } else {
                break;
            }
        }
    }
    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    int len = working_list.get_size();
    for (int i = 0; i < iterations; i++) {
        int imin = i;
        for (int j = i + 1; j < len; j++) {
            if (working_list.get_data(imin) > working_list.get_data(j)) {
                imin = j;
            }
        }
        if (imin != i) {
            working_list.swap(i, imin);
        }
    }
    return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    int len = working_list.get_size();
    int i, j;
    for (i = 0; i < iterations; i++)
        for (j = 0; j < len - i - 1; j++)
            if (working_list.get_data(j) > working_list.get_data(j + 1))
                working_list.swap(j, j + 1);
    return working_list;
}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    bool swapped = true;
    int start = 0;
    int end = working_list.get_size() - 1;
    for (int k = 0; k < iterations; k++) {

        for (int i = start; i < end; ++i) {
            if (working_list.get_data(i) > working_list.get_data(i + 1)) {
                working_list.swap(i, i + 1);

            }
        }
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (working_list.get_data(i) > working_list.get_data(i + 1)) {
                working_list.swap(i, i + 1);
            }
        }
        ++start;
    }

    return working_list;
}

lab6::doubly_linked_list sorts::quick_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}
