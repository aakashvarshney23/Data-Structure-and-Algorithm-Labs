#include "gtest/gtest.h"

#include "../lib/lab06/inc/doubly_linked_list.h"
#include "../lib/lab06/inc/node.h"
#include "../lib/lab08/inc/sorts.h"

class Lab8_Tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        test_num=1;
        test_numbers=std::vector<unsigned>({1,2,3,4,5,6,7,8,9,10});
        Lposition = test_numbers.begin();
        Rposition = test_numbers.end();
        list1 =new lab6::doubly_linked_list;
        list2 =new lab6::doubly_linked_list(test_num);
        list3 = new lab6::doubly_linked_list(test_numbers);
        list4= new lab6::doubly_linked_list(*list3);
    }

public:
    Lab8_Tests() : Test() {
    }

    virtual ~Lab8_Tests() {

    }
    lab6::doubly_linked_list * list1, *list2, *list3, *list4;
    std::vector <unsigned> test_numbers;
    unsigned test_num;
    std::vector<unsigned>::iterator Lposition, Rposition;

};
TEST_F(Lab8_Tests, construct_with_check_size){
    EXPECT_EQ(list1->get_size(), 0);
    EXPECT_EQ(list2->get_size(),1);
    EXPECT_EQ(list3->get_size(),test_numbers.size());
    EXPECT_EQ(list4->get_size(),list3->get_size());
}

//unsure how to test destructor

TEST_F(Lab8_Tests, getters){
    //EXPECT_EQ(list1,); need exception handling: ASSERT_THROW()?
    EXPECT_EQ(list2->get_data(0),test_num);
    EXPECT_EQ(list3->get_data(4),test_numbers[4]);//could check list in a loop
    EXPECT_EQ(list3->get_set(2,5),std::vector<unsigned>(Lposition+2,Lposition+6));
}
