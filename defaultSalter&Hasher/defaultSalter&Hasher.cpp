#include <fstream>
#include "sha256.h"
#include "CopyToClipboard.h"

using std::string;
using std::cout;
using std::cin;
using std::ifstream;

string ToLower(string text)
{
    string result;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
        result[i] = tolower(text[i]);

    return result;
}

int main(int argc, char *argv[])
{
    string input;
    string output;
    string salt;
    string lowercase_input;
    ifstream saltfile("salt.txt");

    if (saltfile.is_open())
        saltfile >> salt;

    cout << "Input password: ";

    cin >> input;

    cout << "\n" << lowercase_input << "\n";

    output = sha256(lowercase_input+salt);

    cout << output;

    CopyTextToClipboard(output);

    return 0;
}