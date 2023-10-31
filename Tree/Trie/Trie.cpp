
#include <iostream>
#include <conio.h>
#include <vector>

#include "trie.h"

int main()
{
    using namespace std;

    Trie trie;
    vector<string> words{"apple", "app", "pay", "bay"};

    for (const auto word : words)
    {
        trie.insert(word);
    }

    trie.display();
    cout << '\n';

    trie.search("app")
        ? cout << "Word found\n"
        : cout << "Word not found\n";

    trie.search("apps")
        ? cout << "Word found\n"
        : cout << "Word not found\n";

    getch();
    return 0;
}