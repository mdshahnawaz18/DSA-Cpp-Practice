bool isValidParenthesis(string s)
{

    stack<char> second;
    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            // if opening bracket
            second.push(ch);
        }
        else
        {
            // if closed bracket
            if (!second.empty())
            {
                char top = second.top();

                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']'))
                {
                    second.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (second.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}