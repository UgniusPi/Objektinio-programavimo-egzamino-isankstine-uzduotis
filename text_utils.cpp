/**
 * @file text_utils.cpp
 * @brief Implementacija `normalizeWord` funkcijos.
 */

#include "text_utils.h"
#include <cctype>

using namespace std;

/**
 * @brief Pašalina skyrybos ženklus ir paverčia žodį mažosiomis raidėmis.
 * @param word Įvestas žodis.
 * @return Normalizuotas žodis (tik raides ir skaitmenis, mažosiomis).
 */
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
