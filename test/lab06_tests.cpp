//
// Created by gokay on 10/5/17.
//

#include "gtest/gtest.h"

#include "doubly_linked_list.h"
#include "node.h"

class NodeFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        test_num=1;
        test_numbers=std::vector<unsigned>({1,2,3,4,5,6,7,8,9,10});
        Lposition = test_numbers.begin();
        Rposition = test_numbers.end();
        list1 =new doubly_linked_list;
        list2 =new doubly_linked_list(test_num);
        list3 = new doubly_linked_list(test_numbers);
        list4= new doubly_linked_list(*list3);
    }

public:
    NodeFixture() : Test() {
    }

    virtual ~NodeFixture() {

    }
    doubly_linked_list * list1, *list2, *list3, *list4;
    std::vector <unsigned> test_numbers;
    unsigned test_num;
    std::vector<unsigned>::iterator Lposition, Rposition;

};
TEST_F(NodeFixture, construct_with_check_size) {
    EXPECT_EQ(list1->get_size(), 0);
    EXPECT_EQ(list2->get_size(),1);
    EXPECT_EQ(list3->get_size(),test_numbers.size());
    EXPECT_EQ(list4->get_size(),list3->get_size());
}

//unsure how to test destructor

TEST_F(NodeFixture, getters){
    //EXPECT_EQ(list1,); need exception handling: ASSERT_THROW()?
    EXPECT_EQ(list2->get_data(0),test_num);
    EXPECT_EQ(list3->get_data(4),test_numbers[4]);//could check list in a loop
    EXPECT_EQ(list3->get_set(2,5),std::vector<unsigned>(Lposition,Rposition));


}

//doubly_linked_list();
//doubly_linked_list(unsigned input);
//doubly_linked_list(std::vector <unsigned> values );
//doubly_linked_list(const doubly_linked_list& original);
//~doubly_linked_list();
//
//unsigned get_data(unsigned position);
//std::vector<unsigned> get_set(unsigned position_from, unsigned position_to);
//unsigned get_size();
//bool is_empty();
//
//void append(unsigned data);
//void merge(doubly_linked_list rhs);
//void insert_before(unsigned position, unsigned data);
//void insert_after(unsigned position, unsigned data);
//void remove(unsigned position);
//
//doubly_linked_list split_before(unsigned position);
//doubly_linked_list split_after(unsigned position);
//doubly_linked_list split_set(unsigned position_from, unsigned position_to);
//
//void swap(unsigned position1, unsigned position2);
//void swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from, unsigned position2_to);
//
//doubly_linked_list operator+(const doubly_linked_list& rhs )const;//returns list with *this appended to rhs does not alter *this or rhs
//doubly_linked_list &operator=(const doubly_linked_list& RHS);
//doubly_linked_list &operator+=(const doubly_linked_list& RHS);