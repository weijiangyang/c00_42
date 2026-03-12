#include <iostream>
#include <cctype> // 必须包含此头文件以使用 std::toupper

int main(int argc, char **argv)
{
    // argc 是参数计数器，argc == 1 表示只有程序名本身，没有额外参数
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        // 从第一个真正有效的参数开始遍历 (argv[1])
        for (int i = 1; i < argc; i++)
        {
            // 遍历当前字符串 argv[i] 的每一个字符，直到遇到字符串结束符 '\0'
            for (int j = 0; argv[i][j]; j++)
            {
                // 将字符强制转换为大写并输出
                // std::toupper 返回 int，所以需要 (char) 强制类型转换
                std::cout << (char)std::toupper(argv[i][j]);
            }
            
            // 如果不是最后一个参数，在参数之间打印一个空格
            if (i < argc - 1)
            {
                std::cout << ' ';
            }
        }   
    }
    // 无论哪种情况，最后都输出一个换行符
    std::cout << std::endl;
    
    return (0);
}