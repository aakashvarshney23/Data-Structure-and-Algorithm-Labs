#include "gtest/gtest.h"

#include "../lib/lab05/inc/expression.h"
#include "../lib/lab05/inc/stack.h"
#include "../lib/lab05/inc/queue.h"

class Lab05_Fixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {

    }

public:
    Lab05_Fixture() : Test() {
    }

    virtual ~Lab05_Fixture() {

    }
    lab5::expression *test_expression;
    lab5::stack *test_stack;
    lab5::queue * test_queue;
};
