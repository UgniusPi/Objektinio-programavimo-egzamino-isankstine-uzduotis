#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

#include "url_utils.h"

using namespace std;

int main()
{
    ifstream inFile("url_tekstas.txt");

    if (!inFile)
    {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 1;
    }

    // Perskaitome visą failą
    string text((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

    inFile.close();

    // Randame URL'us naudojant išorinę funkciją
    vector<string> urls = extractUrls(text);

    ofstream outFile("url_adresai.txt");

    if (!outFile)
    {
        cout << "Nepavyko sukurti rezultatu failo!" << endl;
        return 1;
    }

    outFile << "Rasti URL adresai\n";
    outFile << "=================\n\n";

    int nr = 1;

    for (const auto& u : urls)
    {
        outFile << nr++ << ". " << u << endl;
    }

    outFile.close();

    cout << "URL adresai issaugoti faile url_adresai.txt" << endl;

    return 0;
}