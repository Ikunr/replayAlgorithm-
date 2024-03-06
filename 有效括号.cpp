/* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include <iostream>
#include <string>
#include <stack>


bool isRight(std::string str)
{
    if (str.length() == 0)
    {
        return false;
    }
    const char * pStr = str.c_str();

    std::stack<char> my_stack;
    while(*pStr != '\0')
    {
        if (*pStr == '(' || *pStr == '[' || *pStr == '{')
        {
            my_stack.push(*pStr);
        }
        else
        {
            if (my_stack.empty())
            {
                return false;
            }
            char top = my_stack.top();
            my_stack.pop();
            switch (top)
            {
            case '(':
                if (*pStr != ')')
                {
                    return false;
                }
                break;
            case '[':
                if (*pStr != ']')
                {
                    return false;
                }
            break;
            case '{':
                if (*pStr != '}')
                {
                    return false;
                }
            break;            
            default:
                break;
            }


        }
        pStr++;
    }
    if (my_stack.empty())
    {
        return true;
    }

    return false;
}



int main()
{

    const char * str = "{{()}";


    int ret = isRight(str);
    if (ret == 1)
    {
        std::cout << "是有效括号 "<<ret << std::endl;
    }
    else
    {
        std::cout << "不是有括号 "<<ret << std::endl;
    }

}