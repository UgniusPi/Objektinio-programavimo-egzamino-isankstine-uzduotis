#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include "text_utils.h"

/**
 * @file main.cpp
 * @brief Skaityti `tekstas.txt`, normalizuoti ir surašyti pasikartojančius žodžius bei jų eilutes.
 *
 * Programa perskaito `tekstas.txt`, suskaičiuoja žodžius ir išsaugo rezultatus į
 * `pasikartojimai.txt` ir `cross_reference.txt`.
 */

using namespace std;

/**
 * @brief Programos įėjimo taškas.
 * @return 0 jei sėkmingai, kitoks skaičius jei įvyko klaida.
 */
int main()
{
    ifstream inFile("tekstas.txt");

    if (!inFile)
    {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 1;
    }

    map<string, int> wordCount;
    map<string, set<int>> wordLines;

    string line;
    int lineNumber = 0;

    while (getline(inFile, line))
    {
        lineNumber++;

        string word;

        for (size_t i = 0; i <= line.size(); i++)
        {
            if (i < line.size() && !isspace(static_cast<unsigned char>(line[i])))
            {
                word += line[i];
            }
            else
            {
                if (!word.empty())
                {
                    string normalized = normalizeWord(word);

                    if (!normalized.empty())
                    {
                        wordCount[normalized]++;
                        wordLines[normalized].insert(lineNumber);
                    }

                    word.clear();
                }
            }
        }
    }

    inFile.close();

    ofstream outCount("pasikartojimai.txt");

    if (!outCount)
    {
        cout << "Nepavyko sukurti pasikartojimai.txt" << endl;
        return 1;
    }

    outCount << "Zodziai, pasikartojantys daugiau nei viena karta\n";
    outCount << "==============================================\n\n";

    for (const auto& pair : wordCount)
    {
        if (pair.second > 1)
        {
            outCount << pair.first << " : "
                     << pair.second << endl;
        }
    }

    outCount.close();

    ofstream outCross("cross_reference.txt");

    if (!outCross)
    {
        cout << "Nepavyko sukurti cross_reference.txt" << endl;
        return 1;
    }

    outCross << "Cross-reference lentele\n";
    outCross << "=======================\n\n";

    for (const auto& pair : wordCount)
    {
        if (pair.second > 1)
        {
            outCross << pair.first << " ("
                     << pair.second << " kartai): ";

            bool first = true;

            for (int lineNum : wordLines[pair.first])
            {
                if (!first)
                    outCross << ", ";

                outCross << lineNum;
                first = false;
            }

            outCross << endl;
        }
    }

    outCross.close();

    cout << "Rezultatai issaugoti failuose:" << endl;
    cout << "1. pasikartojimai.txt" << endl;
    cout << "2. cross_reference.txt" << endl;

    return 0;
}