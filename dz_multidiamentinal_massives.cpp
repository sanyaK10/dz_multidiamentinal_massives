#include <iostream>
using namespace std;
int main()
{
    //number 1
    //const int ROWS = 3;
    //const int COLS = 4;
    //int arr[ROWS][COLS];
    //int number;
    //cout << "Enter number: ";
    //cin >> number;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        if (i == 0 && j == 0) {
    //            arr[i][j] = number;
    //        }
    //        else if (j > 0) {
    //            arr[i][j] = arr[i][j - 1] * 2;
    //        }
    //        else {
    //            arr[i][j] = arr[i - 1][COLS - 1] * 2;
    //        }
    //        cout << arr[i][j] << "\t";
    //    }
    //    cout << '\n';
    //}


    //number 2
    //const int ROWS = 3;
    //const int COLS = 4;
    //int arr[ROWS][COLS];
    //int number;
    //cout << "Enter number: ";
    //cin >> number;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        if (i == 0 && j == 0) {
    //            arr[i][j] = number;
    //        }
    //        else if (j > 0) {
    //            arr[i][j] = arr[i][j - 1] + 1;
    //        }
    //        else {
    //            arr[i][j] = arr[i - 1][COLS - 1] + 1;
    //        }
    //        cout << arr[i][j] << "\t";
    //    }
    //    cout << '\n';
    //}


    //number 3
    const int ROWS = 3;
    const int COLS = 6;
    int arr[ROWS][COLS];
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    cout << "Start array:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    int shifts;
    char direction;
    cout << "Enter number of shifts: ";
    cin >> shifts;
    cout << "Enter direction (L, R, U, D): ";
    cin >> direction;
    if (direction == 'L') {
        shifts = shifts % COLS;
        for (int k = 0; k < shifts; k++) {
            for (int i = 0; i < ROWS; i++) {
                int temp = arr[i][0];

                for (int j = 0; j < COLS - 1; j++) {
                    arr[i][j] = arr[i][j + 1];
                }

                arr[i][COLS - 1] = temp;
            }
        }
    }
    else if (direction == 'R') {
        shifts = shifts % COLS;
        for (int k = 0; k < shifts; k++) {
            for (int i = 0; i < ROWS; i++) {
                int temp = arr[i][COLS - 1];
                for (int j = COLS - 1; j > 0; j--) {
                    arr[i][j] = arr[i][j - 1];
                }
                arr[i][0] = temp;
            }
        }
    }
    else if (direction == 'U') {
        shifts = shifts % ROWS;
        for (int k = 0; k < shifts; k++) {
            for (int j = 0; j < COLS; j++) {
                int temp = arr[0][j];
                for (int i = 0; i < ROWS - 1; i++) {
                    arr[i][j] = arr[i + 1][j];
                }
                arr[ROWS - 1][j] = temp;
            }
        }
    }
    else if (direction == 'D') {
        shifts = shifts % ROWS;
        for (int k = 0; k < shifts; k++) {
            for (int j = 0; j < COLS; j++) {
                int temp = arr[ROWS - 1][j];
                for (int i = ROWS - 1; i > 0; i--) {
                    arr[i][j] = arr[i - 1][j];
                }
                arr[0][j] = temp;
            }
        }
    }
    else {
        cout << "Wrong direction!\n";
        return 0;
    }
    cout << "Result:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << '\n';
}