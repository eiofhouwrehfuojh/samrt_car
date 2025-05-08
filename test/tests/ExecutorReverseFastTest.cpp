#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas {

// 测试输入：FBM
TEST(ExecutorReverseFastTest, should_return_x_minus_2_given_status_is_fast_and_reverse_command_is_M_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); 

    // when
    executor->Execute("FBM");

    // then
    const Pose target{-2, 0, 'E'}; 
    ASSERT_EQ(target, executor->Query());
}

// 测试输入：FBL（后退一格再向左转）
TEST(ExecutorReverseFastTest, should_return_S_and_x_minus_1_given_status_is_fast_command_is_L_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); 

    // when
    executor->Execute("FBL");

    const Pose target{-1, 0, 'S'}; 
    ASSERT_EQ(target, executor->Query());
}

// 测试输入：FBR（后退一格再向右转）
TEST(ExecutorReverseFastTest, should_return_N_and_x_minus_1_given_status_is_fast_and_command_is_R_and_facing_is_E) {
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); 

    // when
    executor->Execute("FBR");
    
    const Pose target{-1, 0, 'N'}; 
    ASSERT_EQ(target, executor->Query());
}

} // namespace adas