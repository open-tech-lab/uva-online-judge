#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int case_num;
    bool is_first = true;

    cin >> case_num;
    while (case_num--) {
        int row_num, col_num, str_num;

        cin >> row_num >> col_num;

        char table[row_num][col_num];

        for (int row = 0; row < row_num; row++) {
            for (int col = 0; col < col_num; col++) {
                char input_char;

                cin >> input_char;
                table[row][col] = tolower(input_char);
            }
        }

        if (is_first) {
            is_first = false;
        } else {
            cout << endl;
        }

        cin >> str_num;
        while (str_num--) {
            string input_str;
            int ans_row = -1, ans_col = -1;

            cin >> input_str;
            transform(input_str.begin(), input_str.end(), input_str.begin(), ::tolower);

            for (int row = 0; row < row_num; row++) {
                for (int col = 0; col < col_num; col++) {
                    string test_str;

                    if (table[row][col] != input_str[0]) {
                        continue;
                    }

                    test_str = "";
                    for (int x = row; x >= 0 && test_str.length() < input_str.length(); x--) {
                        test_str += table[x][col];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int x = row; x < row_num && test_str.length() < input_str.length(); x++) {
                        test_str += table[x][col];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int y = col; y >= 0 && test_str.length() < input_str.length(); y--) {
                        test_str += table[row][y];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int y = col; y < col_num && test_str.length() < input_str.length(); y++) {
                        test_str += table[row][y];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int x = row, y = col; x >= 0 && y >= 0 && test_str.length() < input_str.length(); x--, y--) {
                        test_str += table[x][y];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int x = row, y = col; x >= 0 && y < col_num && test_str.length() < input_str.length(); x--, y++) {
                        test_str += table[x][y];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int x = row, y = col; x < row_num && y >= 0 && test_str.length() < input_str.length(); x++, y--) {
                        test_str += table[x][y];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }

                    test_str = "";
                    for (int x = row, y = col; x < row_num && y < col_num && test_str.length() < input_str.length(); x++, y++) {
                        test_str += table[x][y];
                    }
                    if (input_str == test_str) {
                        ans_row = row;
                        ans_col = col;
                        break;
                    }
                }
                if (ans_row != -1 && ans_col != -1) {
                    break;
                }
            }

            cout << ans_row + 1 << " " << ans_col + 1 << endl;
        }
    }

    return 0;
}
