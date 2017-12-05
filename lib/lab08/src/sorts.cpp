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
    lab6::doubly_linked_list copy_list(input);
    return quickSort(copy_list, 0, copy_list.get_size() - 1); //working_list;
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
    lab6::doubly_linked_list copy_list = input;
    int size = copy_list.get_size();


    if(size <= 1)
        return copy_list;

    lab6::doubly_linked_list Left_list;
    lab6::doubly_linked_list Right_list;

    for(unsigned i = 0; i < size; i++)
    {
        if(i < size/2)
            Left_list.append(copy_list.get_data(i));
        else
            Right_list.append(copy_list.get_data(i));
    }

    Left_list = merge_sort(Left_list);
    Right_list = merge_sort(Right_list);
    return merge(Left_list,Right_list);

    return copy_list;
}

lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {
 lab6::doubly_linked_list copy_list(input);
    int size = copy_list.get_size();
    return radixsort(copy_list, size);
}

lab6::doubly_linked_list sorts::quickSort(lab6::doubly_linked_list &input_list, int left, int right) {
    int i = left, j = right;
    int pivot = input_list.get_data((left + right) / 2);
    while (i <= j) {
        while (input_list.get_data(i) < pivot)
            i++;
        while (input_list.get_data(j) > pivot)
            j--;
        if (i <= j) {
            input_list.swap_data(i, j);
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(input_list, left, j);
    if (i < right)
        quickSort(input_list, i, right);
    return input_list;
}

lab6::doubly_linked_list sorts::merge(lab6::doubly_linked_list left, lab6::doubly_linked_list right) //other
{
    lab6::doubly_linked_list result;
    while (!left.is_empty() && !right.is_empty())
    {
        if(left.get_data(0) <= right.get_data(0))
        {
            result.append(left.get_data(0));
            left.remove(0);
        }
        else {
            result.append(right.get_data(0));
            right.remove(0);
        }
    }
    while (!left.is_empty())
    {
        result.append(left.get_data(0));
        left.remove(0);
    }
    while (!right.is_empty())
    {
        result.append(right.get_data(0));
        right.remove(0);
    }
    return result;
}
lab6::doubly_linked_list sorts::radixsort(lab6::doubly_linked_list &input_list, int n)
{

    int m = input_list.get_data(0);
    for (int i = 1; i < n; i++)
        if (input_list.get_data(i) > m)
            m = input_list.get_data(i);

    for (int exp = 1; m/exp > 0; exp *= 10)
        sort_count(input_list, n, exp);

    return input_list;
}

void sorts::sort_count(lab6::doubly_linked_list &input_list, int n, int exp)
{
    int output_array[n];
    int i, counter[10] = {0};

    for (i = 0; i < n; i++)
        counter[ (input_list.get_data(i)/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        counter[i] += counter[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output_array[counter[ (input_list.get_data(i)/exp)%10 ] - 1] = input_list.get_data(i);
        counter[ (input_list.get_data(i)/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        input_list.setter(i,output_array[i]);
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