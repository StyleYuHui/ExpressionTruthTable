#include <string>
#include <expressionTruthTable.h>

int main(int argc, char *argv[])
{
    system("chcp 65001");
    char expr[512];
    std::cout << "请输入逻辑表达式（使用运算符+,-,|,&,!,(,)）：" << std::endl;
    std::cout << "注: + 表示等价, - 表示蕴含, | 表示或, & 表示与, ! 表示非" << std::endl;
    std::cin.getline(expr, 512);

    if (strlen(expr) == 0) {
        std::cout << "表达式不能为空！" << std::endl;
        return 1;
    }
    console_out(expr);
    system("Pause");
    return 0;
}