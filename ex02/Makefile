NAME        = account

# 编译器与选项
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# 源文件与目标文件
SRCS        = Account.cpp tests.cpp
OBJS        = $(SRCS:.cpp=.o)

# 编译指令
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# 显式规则：如何将 .cpp 编译为 .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re