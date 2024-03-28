#pragma once

char* maxBitString(int n, char* str)
{
    if (n < 2)
    {
        return str;
    }
    //int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1') {
            continue;
        }
        else //current bit is 0
        {
            if (i >= 1 && str[i - 1] == '0')
            {
                str[i - 1] = '1';
            }
            else if (i >= 2 && str[i - 1] == '1' && str[i - 2] == '0')
            {
                str[i - 2] = '1';
                str[i - 1] = '0';
                str[i] = '1';
            }
        }
    }
    return str;
}

void runMaxBitString()
{
    char input[5] = "0010";
    char* str = maxBitString(4, input);
    std::cout << str;
}
