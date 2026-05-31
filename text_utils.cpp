#include "text_utils.h"
#include <cctype>

using namespace std;

string normalizeWord(const string& word)
{
    string result;

    for (char c : word)
    {
        if (isalnum(static_cast<unsigned char>(c)))
        {
            result += tolower(static_cast<unsigned char>(c));
        }
    }

    return result;
}
