#include "StdAfx.h"
#include "SecretPath.h"

bool SecretPath::ValidateSecretPath(LPCTSTR lptsc_path)
{
    bool result1 = false;
    bool result2 = false;

    std::basic_string<TCHAR> path(lptsc_path);
    std::basic_string<TCHAR> dir;
    std::basic_string<TCHAR> name;
    size_t pos = path.find_last_of(TEXT("\\/"));
    if (pos != std::string::npos)
    {
        dir = path.substr(0, pos);
        name = path.substr(pos + 1);
    }

    unsigned int index = dir.length() - 1;

    if (index > 4)
    {
        for (index = dir.length() - 1; index > 0; index--)
        {
            if (toupper(dir[index]) == dir[index])
            {
                break;
            }
        }
    }

    if (index > 4)
    {
        unsigned int x1 = dir[index - 3] - TEXT('a');
        unsigned int x2 = dir[index - 2] - TEXT('a');
        unsigned int x3 = dir[index - 1] - TEXT('a');

        if (x3 == ThirdSymbolGenerationAlgorithm(x1, x2))
        {
            result1 = true;
        }
    }

    index = name.length() - 1;
    if (index > 6)
    {
        unsigned int x1 = name[index - 6] - TEXT('a');
        unsigned int x2 = name[index - 5] - TEXT('a');
        unsigned int x3 = name[index - 4] - TEXT('a');

        if (x3 == ThirdSymbolGenerationAlgorithm(x1, x2))
        {
            result2 = true;
        }
    }

    if (result1 == false)
    {
        return false;
    }
    if (result2 == false)
    {
        return false;
    }

    return true;
}


unsigned int SecretPath::ThirdSymbolGenerationAlgorithm(unsigned int ch_a, unsigned int ch_b)
{
    unsigned int sum = ch_a + ch_b;
    return (sum * sum * sum) % 26;
}
