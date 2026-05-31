#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * @file tests/test_suite.cpp
 * @brief Paprastas testų paleidimo rinkinys `normalizeWord` ir `extractUrls` funkcijoms.
 */

#include "../text_utils.h"
#include "../url_utils.h"

using namespace std;

int failures = 0;

void expectEq(const string& name, const string& expected, const string& actual)
{
    if (expected == actual)
    {
        cout << "[PASS] " << name << endl;
    }
    else
    {
        cout << "[FAIL] " << name << " - expected: '" << expected << "', got: '" << actual << "'" << endl;
        failures++;
    }
}

void expectVecEq(const string& name, const vector<string>& expected, const vector<string>& actual)
{
    if (expected.size() != actual.size())
    {
        cout << "[FAIL] " << name << " - size mismatch: expected " << expected.size() << ", got " << actual.size() << endl;
        failures++;
        return;
    }

    for (size_t i = 0; i < expected.size(); ++i)
    {
        if (expected[i] != actual[i])
        {
            cout << "[FAIL] " << name << " - at index " << i << " expected '" << expected[i] << "', got '" << actual[i] << "'" << endl;
            failures++;
            return;
        }
    }

    cout << "[PASS] " << name << endl;
}

int main()
{
    // Tests for normalizeWord
    expectEq("normalize_basic", "hello", normalizeWord("Hello"));
    expectEq("normalize_punct", "helloworld", normalizeWord("Hello, World!"));
    expectEq("normalize_numbers", "test123", normalizeWord("TeSt123"));
    expectEq("normalize_cpp", "c", normalizeWord("C++"));

    // Tests for extractUrls
    string sample = "Visit https://www.vu.lt and http://vu.lt and www.vu.lt and vu.lt and https://vu.lt/page";
    vector<string> expected = {"https://www.vu.lt", "http://vu.lt", "www.vu.lt", "vu.lt", "https://vu.lt/page"};
    vector<string> found = extractUrls(sample);
    expectVecEq("extract_urls_basic", expected, found);

    string none = "No urls here, just text.";
    vector<string> foundNone = extractUrls(none);
    expectVecEq("extract_urls_none", {}, foundNone);

    if (failures == 0)
    {
        cout << "All tests passed." << endl;
        return 0;
    }
    else
    {
        cout << failures << " test(s) failed." << endl;
        return 1;
    }
}
