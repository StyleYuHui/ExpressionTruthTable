//
// Created by 31007 on 2025/4/21.
//

#include <expressionTruthTable.h>
char getOptrCode(char c){
    switch(c)
    {
        case '+':	return 0;
        case '-':	return 1;
        case '|':	return 2;
        case '&':	return 3;
        case '!':	return 4;
        case '(':	return 5;
        case ')':	return 6;
        case '\0':  return 7;
        default:	return -1;
    }
}
// 计算两个操作数运算的结果
bool calc(char op, bool d1, bool d2=true)
{
    switch(op)
    {
        case 0:		if(d1==d2){
                return true;
            }else{
                return false;
            }
        case 1:		if(d1==true&&d2==false){
                return false;
            }else{
                return true;
            }
        case 2:		return d1 || d2;
        case 3:		return d1 && d2;
        case 4:		return !d1;
        default:	return 0;
    }
}

// 从表达式express的第ip个字符开始提取数字串, 并转换为浮点数存放到d中
// 函数返回数字子串结束后下一个字符的下标
// 该函数可以解析含有一个小数点的浮点数和整数
int getOpnd(const char *express, int ip, double &d)
{
    int i, j;
    char c;
    bool isFirst = true;
    static char str[256] = {0};

    for(i=ip, j=0; express[i] != '\0'; i++)
    {
        c = express[i];
        if (isdigit(c)) str[j++] = c;
        else if(c == '.')
        {
            if (isFirst)
            {
                str[j++] = c;
                isFirst = false;
            }
            else break;
        }
        else break ;
    }
    str[j] = '\0';
    d = atof(str);
    return ip + j;
}
// 表达式求值函数
// express:			输入表达式字符串
// isOk:			如果表达式解析正常*isOk赋值为true, 否则赋值为false
// 返回值:			返回表达式求值结果
int evaluate(const char *express, bool *isOk)
{
    GStack<double> opnd;
    GStack<char> optr;

    *isOk = false;
    optr.push(7);
    int ip = 0;
    double d = 0;
    while (optr.top() != 7 || express[ip] != '\0')
    {
        char ch = express[ip];
        if (isdigit(ch))
        {
            ip = getOpnd(express, ip, d);
            opnd.push(d);
        }
        else
        {
            double d1, d2;
            char op1 = optr.top();
            char op2 = getOptrCode(ch);
            if (op2 < 0) return 0;
            char pri = OPTR_PRI[op1][op2];
            switch(pri)
            {
                case '<':
                    optr.push(op2);
                    ip++;
                    break;
                case '>':
                    if (op1!='\004') {
                        optr.pop();
                        d2 = opnd.top();
                        opnd.pop();
                        d1 = opnd.top();
                        opnd.pop();
                        d = calc(op1, d1, d2);
                        opnd.push(d);
                        break;
                    } else{
                        d1 = opnd.top();
                        opnd.pop();
                        d = calc(op1, d1);
                        opnd.push(d);
                    }
                case '=':
                    optr.pop();
                    ip++;
                    break;
                case 'x':
                    return 0;
            }
        }
    }

    if (opnd.isEmpty())  return 0;

    *isOk = true;
    return opnd.top();
}

arrayList<int > temp(10);
int n,res=1;//res代表的是方案数目
int ans[1010][1010];
void dfs (int x)//x表示的是，搜索到第几位
{
    if (x > n)//搜索完了
    {
        for (int i = 1; i <= x; i++)//优化成栈
            ans[res][i] = temp[i];
        res++;
        return;
    }
    for (int i = 0; i <= 1; i++)//每一位上有这两种状态，分别是01
    {
        temp[x] = i;
        dfs(x + 1);
    }
}

void console_out(char* express){//输出主体函数
    char *p=express;
    char letter[100];

    printf("真值表：\n");
    int num=0;
    while (*p!='\000'){
        int len=strlen(letter);
        if (*p>='a'&&*p<='z'||*p>='A'&&*p<='Z'){
            if (len==0){
                letter[num]=*p;
                num++;
            } else{
                bool isHave =false;
                for (int i = 0; i < len; ++i) {
                    if (letter[i]==*p){
                        isHave=true;
                    }
                }
                if (!isHave){
                    letter[num]=*p;
                    num++;
                }
            }
        }
        p++;
    }

    n=strlen(letter);

    for (int i = 0; i < n; ++i) {
        printf("%c ",letter[i]);
    }
    printf("  express");
    printf("\n");

    dfs(1);
    char pTemp[512];
    std::string minExpress("主析取范式：");
    for (
            int i = 0;
            i < [](int base,int index){
                int powerNum=1;
                for (int i = 0; i < index ; ++i) {
                    powerNum*=base;
                }
                return powerNum;
            }(2, strlen(letter));
            ++i
            ) {
        strcpy(pTemp,express);

        bool isPrint[strlen(letter)];
        for (int j = 0; j < strlen(letter); ++j) {
            isPrint[j]= false;
        }

        for (int j = 0; j < strlen(pTemp); ++j) {
            for (int k = 0; k < strlen(letter); ++k) {
                if (pTemp[j]==letter[k]){
                    if (!isPrint[k]) {
                        printf("%d ", ans[i + 1][k + 1]);
                        isPrint[k]= true;
                    }
                    pTemp[j]=ans[i+1][k+1]==0?'0':'1';
                }
            }
        }
        bool isOk;
        int val=evaluate(pTemp, &isOk);
        if (!isOk){
            printf("ERROR\n");
        }else{
            //printf("%s ",pp);
            printf("  %d \n",val);
        }


        //求主析取范式
        if (val==1){
            std::string demo;
            for (int j = 0; j < strlen(letter); ++j) {
                if (ans[i+1][j+1]==1){
                    demo.push_back(letter[j]);
                    demo.push_back('&');
                } else if (ans[i+1][j+1]==0){
                    demo.push_back('!');
                    demo.push_back(letter[j]);
                    demo.push_back('&');
                }
            }
            demo.erase(demo.end()-1);
            minExpress.append(demo);
            minExpress.push_back(' ');
            minExpress.push_back('|');
            minExpress.push_back(' ');
        }
    }
    minExpress.erase(minExpress.end()-2);
    std::cout<<minExpress<<std::endl;
}