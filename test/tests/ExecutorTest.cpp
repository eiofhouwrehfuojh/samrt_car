#include "Executor.hpp"
#include <gtest/gtest.h>
#include <memory>
//#include <tuple>
#include "PoseEq.hpp"

namespace adas
{
    // bool operator==(const Pose &lhs, const Pose &rhs)
    // {
    //     return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    // }

    // 测试Executor::NewExecutor
    // test 1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 2
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        // when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 3
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("M");

        // then
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
     // test 4
    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

        // when
        executor->Execute("M");

        // then
        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 5
    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

        // when
        executor->Execute("M");

        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 6
    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

        // when
        executor->Execute("M");

        // then
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    // test cases 7-10 for command 'L'
    // test 7
    TEST(ExecutorTest, should_return_facing_N_given_commandd_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("L");

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 8
    TEST(ExecutorTest, should_return_facing_S_given_commandd_is_L_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

        // when
        executor->Execute("L");

        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 9
    TEST(ExecutorTest, should_return_facing_E_given_commandd_is_L_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

        // when
        executor->Execute("L");

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 10
    TEST(ExecutorTest, should_return_facing_W_given_commandd_is_L_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

        // when
        executor->Execute("L");

        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // test cases 11-14 for command 'R'
    // test 11
    TEST(ExecutorTest, should_return_facing_S_given_commandd_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("R");

        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 12
    TEST(ExecutorTest, should_return_facing_N_given_commandd_is_R_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

        // when
        executor->Execute("R");

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 13
    TEST(ExecutorTest, should_return_facing_W_given_commandd_is_R_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));

        // when
        executor->Execute("R");

        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // test 14
    TEST(ExecutorTest, should_return_facing_E_given_commandd_is_R_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

        // when
        executor->Execute("R");

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
}