#include "gtest/gtest.h"
#include "linked_list.h"


class Lab04_Fixture : public ::testing::Test {
protected:
    virtual void SetUp() {

    }
    lab4::linked_list * test_list;
};


TEST_F(Lab04_Fixture, constructor_test) {
    test_list=new lab4::linked_list(2);
    delete test_list;
    int intArray[]={0,1,2,3,4,5};
    test_list = new lab4::linked_list(intArray,6);
}


TEST_F(Lab04_Fixture, print_test) {
    test_list=new lab4::linked_list(2);
    std::string output;

    testing::internal::CaptureStdout();
    test_list->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("2 -> null",output);

    delete test_list;
    int intArray[]={0,1,2,3,4,5};
    test_list = new lab4::linked_list(intArray,6);

    testing::internal::CaptureStdout();
    test_list->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0 -> 1 -> 2 -> 3 -> 4 -> 5 -> null",output);
}


TEST_F(Lab04_Fixture, print_mid_test) {
    test_list=new lab4::linked_list(2);
    std::string output;

    testing::internal::CaptureStdout();
    test_list->print_middle();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("2",output);

    delete test_list;
    int intArray[]={0,1,2,3,4};
    test_list = new lab4::linked_list(intArray,5);

    testing::internal::CaptureStdout();
    test_list->print_middle();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("2",output);

    delete test_list;
    int intArray2[]={0,1,2,3,4,5};
    test_list = new lab4::linked_list(intArray2,6);

    testing::internal::CaptureStdout();
    test_list->print_middle();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("2",output) << "this test has an list with even length\nso"
                        " the middle is ambiguous\nprint position n/2"
                        " rounded down\nwhere n is the highest position"
                        "\nin the zero indexed list";

}


TEST_F (Lab04_Fixture, append_test) {
    test_list = new lab4::linked_list;
    std::string output;

    test_list->append(0);

    testing::internal::CaptureStdout();
    test_list->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0 -> null",output);

    test_list->append(1);

    testing::internal::CaptureStdout();
    test_list->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0 -> 1 -> null",output);

    test_list->append(2);

    testing::internal::CaptureStdout();
    test_list->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0 -> 1 -> 2 -> null",output);

    int intArray[]={3,4,5};
    test_list->append(intArray,3);

    testing::internal::CaptureStdout();
    test_list->print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0 -> 1 -> 2 -> 3 -> 4 -> 5 -> null",output);
}

TEST_F(Lab04_Fixture, insert_test) {
    int intArray[] = {0,1,2,3};
    test_list= new lab4::linked_list(intArray,4);
    }
