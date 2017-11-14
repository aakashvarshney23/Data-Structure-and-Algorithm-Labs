#include "sorts.h"

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if(iterations > working_list.get_size()) iterations = working_list.get_size();
    for(unsigned iteration = 1; iteration <= iterations; iteration++)
    {
        unsigned compare_location = iteration-1;
        while(compare_location >= 0)
        {
            if(compare_location == 0)
            {
                working_list.swap(compare_location, iteration);
                break;
            }
            else if(working_list.get_data(iteration) < working_list.get_data(compare_location))
            {
                compare_location--;
            }
            else{
                working_list.swap(compare_location, iteration);
                break;
            }
        }
    }
    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if(iterations > working_list.get_size()) iterations = working_list.get_size();
    for(unsigned iteration = 1; iteration <= iterations; iteration++)
    {

    }
    return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    return lab6::doubly_linked_list();
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
