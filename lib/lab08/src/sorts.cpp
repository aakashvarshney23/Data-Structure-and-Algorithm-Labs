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
    lab6::doubly_linked_list working_list(input);
    return quickSort(working_list, 0, working_list.get_size() - 1); //working_list;
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {

    return lab6::doubly_linked_list();
}

//int sorts::partition(lab6::doubly_linked_list input, int start, int end)
//{
//    int pivot = input.get_data(end);
//    int pIndex = start;
//    for(int j = start; j<end; j++)
//    {
//        if(input.get_data(j)<= pivot)
//        {
//            input.swap(pIndex, j);
//            pIndex++;
//        }
//    }
//    input.swap(pIndex, end);
//    return pIndex;
//}
//lab6::doubly_linked_list sorts::quickSortHelper(lab6::doubly_linked_list input, int start, int end) {
//    if (start < end) {
//        int pi = partition(input, start, end);
//        quickSortHelper(input, start, pi - 1);
//        quickSortHelper(input, pi + 1, end);
//    }
//}
lab6::doubly_linked_list sorts::quickSort(lab6::doubly_linked_list &obj, int left, int right) {
    int i = left, j = right;
    int pivot = obj.get_data((left + right) / 2);
    while (i <= j) {
        while (obj.get_data(i) < pivot)
            i++;
        while (obj.get_data(j) > pivot)
            j--;
        if (i <= j) {
            obj.swap_data(i, j);
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(obj, left, j);
    if (i < right)
        quickSort(obj, i, right);
    return obj;
}