/**
 * @file url_utils.cpp
 * @brief Implementacija URL ištraukimo iš teksto funkcijų.
 */

#include "url_utils.h"
#include <regex>

using namespace std;

/**
 * @brief Iš teksto suranda URL adresus, naudodamas reguliarias išraiškas.
 * @param text Įvesties tekstas.
 * @return Vektorius rastų URL adresų.
 */
vector<string> extractUrls(const string& text)
{
    // Using a simpler "non-space" class ([^ ]) to avoid escape-sequence issues
    regex urlRegex(R"((https?:\/\/(?:www\.)?[A-Za-z0-9\-]+\.[A-Za-z]{2,}(?:\/[^ ]*)?)|(www\.[A-Za-z0-9\-]+\.[A-Za-z]{2,}(?:\/[^ ]*)?)|([A-Za-z0-9\-]+\.[A-Za-z]{2,}(?:\/[^ ]*)?))");

    vector<string> results;
    sregex_iterator begin(text.begin(), text.end(), urlRegex);
    sregex_iterator end;

    for (sregex_iterator i = begin; i != end; ++i)
    {
        results.push_back(i->str());
    }

    return results;
}
