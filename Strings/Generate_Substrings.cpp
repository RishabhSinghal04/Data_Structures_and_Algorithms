
#include <iostream>
#include <conio.h>
#include <string>

void generate_substrings(const std::string &);

int main()
{
    using namespace std;

    string st{};

    cout << "Enter a string : ";
    getline(cin >> ws, st);

    std::cout << "All substrings of "<< st << " are:-\n";
    generate_substrings(st);

    getch();
    return 0;
}

void generate_substrings(const std::string &st)
{
    const size_t LENGTH = st.length();

    for (size_t index = 0; index < LENGTH; ++index)
    {
        std::string sub_st{};
        for (size_t index_2 = index; index_2 < LENGTH; ++index_2)
        {
            sub_st += st.at(index_2);
            std::cout << sub_st << '\n';
        }
    }
}