#include <iostream>
#include <fstream>
#include <string>
#include <regex>

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
    string text(
        (istreambuf_iterator<char>(inFile)),
        istreambuf_iterator<char>()
    );

    inFile.close();

    /*
        Aptinka:
        https://www.vu.lt
        https://vu.lt
        http://vu.lt
        www.vu.lt
        vu.lt
    */
    regex urlRegex(
        R"((https?:\/\/(?:www\.)?[A-Za-z0-9\-]+\.[A-Za-z]{2,}(?:\/[^\s]*)?)|(www\.[A-Za-z0-9\-]+\.[A-Za-z]{2,}(?:\/[^\s]*)?)|([A-Za-z0-9\-]+\.[A-Za-z]{2,}(?:\/[^\s]*)?))"
    );

    ofstream outFile("url_adresai.txt");

    if (!outFile)
    {
        cout << "Nepavyko sukurti rezultatu failo!" << endl;
        return 1;
    }

    outFile << "Rasti URL adresai\n";
    outFile << "=================\n\n";

    sregex_iterator begin(text.begin(), text.end(), urlRegex);
    sregex_iterator end;

    int nr = 1;

    for (sregex_iterator i = begin; i != end; ++i)
    {
        outFile << nr++ << ". "
                << i->str()
                << endl;
    }

    outFile.close();

    cout << "URL adresai issaugoti faile url_adresai.txt" << endl;

    return 0;
}