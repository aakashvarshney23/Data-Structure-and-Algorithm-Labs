#include "gtest/gtest.h"

#include "../lib/lab06/inc/doubly_linked_list.h"
#include "../lib/lab06/inc/node.h"
#include "../lib/lab08/inc/sorts.h"

class Lab8_Tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        unsorted_numbers=std::vector<unsigned>({72, 96, 26, 94, 33,  2, 42,
                                                 89, 41, 36, 63, 65, 56, 16,
                                                 17, 59, 35, 39, 40,  1, 69});
        Lposition = unsorted_numbers.begin();
        Rposition = unsorted_numbers.end();
        unsorted_list = new lab6::doubly_linked_list(unsorted_numbers);
    }

public:
    Lab8_Tests() : Test() {
    }

    virtual ~Lab8_Tests() {

    }
    sorts sorting_machine;
    lab6::doubly_linked_list *unsorted_list;
    std::vector <unsigned> unsorted_numbers;
    std::vector<unsigned>::iterator Lposition, Rposition;
};


TEST_F(Lab8_Tests, insertion_sort){
    // First iteration through insertion sort
    // Nothing should change because the first two numbers are already sorted
    std::vector<unsigned> sorted_vec_1 = std::vector<unsigned>({72, 96, 26, 94, 33,  2, 42,
                                                                  89, 41, 36, 63, 65, 56, 16,
                                                                  17, 59, 35, 39, 40,  1, 69});
    lab6::doubly_linked_list *sorted1 = new lab6::doubly_linked_list(sorted_vec_1);
    EXPECT_EQ(sorting_machine.insertion_sort(*unsorted_list,1), *sorted1);


    // 5th pass through insertion sort
    // First 6 numbers should be sorted now
    std::vector<unsigned> sorted_vec_5 = std::vector<unsigned>({ 2, 26, 33, 72, 94, 96, 42,
                                                                  89, 41, 36, 63, 65, 56, 16,
                                                                  17, 59, 35, 39, 40,  1, 69});
    lab6::doubly_linked_list *sorted5 = new lab6::doubly_linked_list(sorted_vec_5);
    EXPECT_EQ(sorting_machine.insertion_sort(*unsorted_list,5), *sorted5);

    // 10th pass through insertion sort
    // First 11 numbers should be sorted now
    std::vector<unsigned> sorted_vec_10 = std::vector<unsigned>({ 2, 26, 33, 36, 41, 42, 63,
                                                                   72, 89, 94, 96, 65, 56, 16,
                                                                   17, 59, 35, 39, 40,  1, 69});
    lab6::doubly_linked_list *sorted10 = new lab6::doubly_linked_list(sorted_vec_10);
    EXPECT_EQ(sorting_machine.insertion_sort(*unsorted_list,10), *sorted10);

    // 20th pass through insertion sort
    // All numbers should be sorted now
    std::vector<unsigned> sorted_vec_20 = std::vector<unsigned>({ 1,  2, 16, 17, 26, 33, 35,
                                                                   36, 39, 40, 41, 42, 56, 59,
                                                                   63, 65, 69, 72, 89, 94, 96});
    lab6::doubly_linked_list *sorted20 = new lab6::doubly_linked_list(sorted_vec_20);
    EXPECT_EQ(sorting_machine.insertion_sort(*unsorted_list,20), *sorted20);

    // 25th pass through insertion sort
    // All numbers should be sorted now
    std::vector<unsigned> sorted_vec_25 = std::vector<unsigned>({ 1,  2, 16, 17, 26, 33, 35,
                                                                   36, 39, 40, 41, 42, 56, 59,
                                                                   63, 65, 69, 72, 89, 94, 96});
    lab6::doubly_linked_list *sorted25 = new lab6::doubly_linked_list(sorted_vec_25);
    EXPECT_EQ(sorting_machine.insertion_sort(*unsorted_list,20), *sorted25);

    // Delete all doubly linked lists used for testing
    delete sorted1, sorted5, sorted10, sorted20, sorted25;
}

TEST_F(Lab8_Tests, selection_sort){
}

TEST_F(Lab8_Tests, bubble_sort){
}

TEST_F(Lab8_Tests, cocktail_sort){
}

TEST_F(Lab8_Tests, merge_sort){
}

TEST_F(Lab8_Tests, quick_sort){
}