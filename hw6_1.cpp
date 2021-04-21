/*
 * Title: hw6_1.cpp
 * Abstract: C++ program to conduct the radix sort.
 * Author: Justin Mello
 * ID: 2002
 * Date: 04/19/2021
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
static int CONST = 10;

void displayVector(vector<int> vector) {
    for(int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

int returnCount(vector<int> vector) {
    int numbers;
    int max = 0;
    for(int x = 0; x < vector.size(); x++)
    {
        numbers = 1;
        while (vector[x] /= CONST) {
            numbers++;
        }
        if (max < numbers)
            max = numbers;

    }
    return max;
}

void pass(vector<int> &array, int position) {
    vector<vector<int> > groups(CONST);
    vector<int> temp(array.size());


    for (int i = 0; i < array.size(); i++) {
        temp[i] = array[i] / pow(CONST, position);
    }

    for (int i = 0; i < array.size(); i++) {
        groups[temp[i] % CONST].push_back(array[i]);
    }

    array.clear();


    for(int i = 0; i < groups.size(); i++) {
        for(int j = 0; j < groups[i].size(); j++) {
            if (groups[i].size() > 0)
                array.push_back(groups[i][j]);
        }
    }
}

void rSort(vector<int> &array) {
    int passes = returnCount(array);

    for (int x = 0; x < passes; x++) {
        pass(array, x);
        displayVector(array);
    }
}

int main() {

    int numbers;
    cin >> numbers;
    vector<int> array(numbers);

    //Gather user input
    for(int i = 0; i < numbers; i++) {
        cin >> array[i];
    }

    rSort(array);

    return 0;
}
