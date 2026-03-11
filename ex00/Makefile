NAME        = megaphone

# 编译器与标志
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# 源文件与目标文件转换
SRCS        = megaphone.cpp
OBJS        = $(SRCS:.cpp=.o)

# 默认目标
all: $(NAME)

# 链接规则：将 .o 文件链接成可执行文件
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# 编译规则：将 .cpp 编译成 .o
# -c 标志表示只编译不链接
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理规则：clean 只删中间文件
clean:
	rm -f $(OBJS)

# fclean：删除中间文件 + 可执行文件
fclean: clean
	rm -f $(NAME)

# 重新编译：先彻底清理再全部编译
re: fclean all

.PHONY: all clean fclean re