#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string input_str;
    unordered_map<char, char> mirror_table;

    mirror_table['A'] = 'A';
    mirror_table['E'] = '3';
    mirror_table['H'] = 'H';
    mirror_table['I'] = 'I';
    mirror_table['J'] = 'L';
    mirror_table['L'] = 'J';
    mirror_table['M'] = 'M';
    mirror_table['O'] = 'O';
    mirror_table['S'] = '2';
    mirror_table['T'] = 'T';
    mirror_table['U'] = 'U';
    mirror_table['V'] = 'V';
    mirror_table['W'] = 'W';
    mirror_table['X'] = 'X';
    mirror_table['Y'] = 'Y';
    mirror_table['Z'] = '5';
    mirror_table['1'] = '1';
    mirror_table['2'] = 'S';
    mirror_table['3'] = 'E';
    mirror_table['5'] = 'Z';
    mirror_table['8'] = '8';

    while (cin >> input_str) {
        bool is_palin = true, is_mirror = true;
        int left_index = 0, right_index = input_str.length() - 1;

        while (left_index <= right_index) {
            char left_char = input_str[left_index], right_char = input_str[right_index];

            if (left_char != right_char) {
                is_palin = false;
            }
            if (mirror_table[left_char] != right_char) {
                is_mirror = false;
            }
            if (!is_palin && !is_mirror) {
                break;
            }
            left_index++;
            right_index--;
        }

        cout << input_str << " -- ";
        if (is_palin) {
            if (is_mirror) {
                cout << "is a mirrored palindrome.\n\n";
                continue;
            }
            cout << "is a regular palindrome.\n\n";
            continue;
        }
        if (is_mirror) {
            cout << "is a mirrored string.\n\n";
            continue;
        }
        cout << "is not a palindrome.\n\n";
    }

    return 0;
}
