NAME        = phonebook

# 1. 编译器与选项
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# 2. 源文件与目标文件
# 显式列出源文件，避免使用通配符 * 以防误伤当前目录下的其他测试文件
SRCS        = main.cpp Contact.cpp PhoneBook.cpp
# 将 .cpp 后缀替换为 .o
OBJS        = $(SRCS:.cpp=.o)

# 3. 核心规则
all: $(NAME)

# 链接阶段：将所有 .o 文件链接成可执行文件
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# 编译阶段：将每个 .cpp 独立编译成 .o
# $< 是第一个依赖文件 (.cpp)，$@ 是目标文件 (.o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 4. 清理规则
clean:
	rm -f $(OBJS)

# fclean 应该彻底清理，包括生成的二进制文件
fclean: clean
	rm -f $(NAME)

# 重新编译
re: fclean all

# 防止与同名文件冲突
.PHONY: all clean fclean re