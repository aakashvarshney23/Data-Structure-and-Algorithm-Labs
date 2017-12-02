#include "sorts.h"

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if (iterations == 0) //handles 0 iteration case
    {
        return working_list;
    }
    if (iterations > working_list.get_size() - 1) // handles case for where iterations will pass the linked list
    {
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
    for (int i = 0; i <= iterations; i++) {
        int min = i;
        for (int j = i + 1; j < iterations; j++) {
            if (working_list.get_data(min) > working_list.get_data(j)) {
                min = j;
            }
            working_list.swap(min, i);
        }
    }
    return working_list;
}


lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    int i, j;
    for (i = 0; i <= iterations; i++)
        for (j = 0; j < iterations - i - 1; j++)
            if (working_list.get_data(j) > working_list.get_data(j + 1))
                working_list.swap(j, j + 1);
    return working_list;
}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    bool swapped = true;
    int start = 0;
    int end = working_list.get_size() - 1;

    while (swapped) {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;

        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) {
            if (working_list.get_data(i) > working_list.get_data(i + 1)) {
                working_list.swap(i, i + 1);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // move the end point back by one, because
        //  item at the end is in its rightful spot
        --end;

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (working_list.get_data(i) > working_list.get_data(i + 1)) {
                working_list.swap(i, i + 1);
                swapped = true;
            }
        }

        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
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
