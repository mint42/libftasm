TEST_FRAMEWORK_DIR = test_framework
TEST_FRAMEWORK_SRCS := $(wildcard $(TEST_FRAMEWORK_DIR)/*.c)
TEST_FRAMEWORK_SRCS += $(wildcard $(TEST_FRAMEWORK_DIR)/tests/*.c)
TEST_FRAMEWORK_OBJS := $(patsubst %.c,%.o,$(TEST_FRAMEWORK_SRCS))
TEST_FRAMEWORK_INCLUDES := -I./$(TEST_FRAMEWORK_DIR)/
