#include "sorts.h"

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    unsigned compare_location;
    if(++iterations > working_list.get_size()) iterations = working_list.get_size();
    for(unsigned iteration = 1; iteration < iterations; iteration++)
    {
        compare_location = iteration-1;
        unsigned iteration_data_value = working_list.get_data(iteration);
        working_list.remove(iteration);
        while(compare_location >= 0)
        {
            if(iteration_data_value < working_list.get_data(compare_location))
            {
                if(compare_location) compare_location--;
                else
                {
                    working_list.insert_before(0, iteration_data_value);
                    break;
                }
            }
            else
            {
                working_list.insert_after(compare_location, iteration_data_value);
                break;
            }
        }
    }
    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if(iterations > working_list.get_size()) iterations = working_list.get_size();
    for(unsigned iteration = 0; iteration < iterations; iteration++)
    {
        unsigned lowest_value_location = iteration;
        for(unsigned completed_iterations = iteration+1; completed_iterations<working_list.get_size(); completed_iterations++)
        {
            if(working_list.get_data(completed_iterations) < working_list.get_data(lowest_value_location))
                lowest_value_location = completed_iterations;
        }
        if(lowest_value_location != iteration) working_list.swap(lowest_value_location, iteration);
    }
    return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if(iterations > working_list.get_size()) iterations = working_list.get_size();
    for(unsigned iteration = 0; iteration < iterations; iteration++)
    {
        bool swapped = false;
        unsigned compare_location = 0;
        while(compare_location+1 < working_list.get_size())
        {
            if(working_list.get_data(compare_location) > working_list.get_data(compare_location+1))
            {
                working_list.swap(compare_location, compare_location+1);
                swapped = true;
            }
            compare_location++;
        }
        if(!swapped) break;
    }
    return working_list;
}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    if(iterations > working_list.get_size()) iterations = working_list.get_size();
    for(unsigned iteration = 0; iteration < iterations; iteration++)
    {
        bool swapped = false;
        unsigned compare_location = 0;
        while(compare_location+1 < working_list.get_size())
        {
            if(working_list.get_data(compare_location) > working_list.get_data(compare_location+1))
            {
                working_list.swap(compare_location, compare_location+1);
                swapped = true;
            }
            compare_location++;
        }
        while(compare_location > 0)
        {
            if(working_list.get_data(compare_location) < working_list.get_data(compare_location-1))
            {
                working_list.swap(compare_location, compare_location-1);
                swapped = true;
            }
            compare_location--;
        }
        if(!swapped) break;
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
