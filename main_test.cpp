#include <iostream>
#include <string>
using namespace std;

const int SIZE = 23;
const int SEED = 79;
const int TOTAL = 20;

// Mid-Square Hash Function
int hashFunction(int key)
{
    int square = key * key;
    string s = to_string(square);

    while (s.length() < 4)
    {
        s = "0" + s;
    }

    int middle = stoi(s.substr(1, 2));

    return middle % SIZE;
}

// Generate personalized dataset
void generateDataset(int arr[])
{
    for (int i = 0; i < TOTAL; i++)
    {
        arr[i] = (SEED + 13 * i) % 100;
    }
}

// Test dataset generation
bool testDataset()
{
    int arr[TOTAL];

    int expected[TOTAL] = {
        79, 92, 5, 18, 31,
        44, 57, 70, 83, 96,
        9, 22, 35, 48, 61,
        74, 87, 0, 13, 26
    };

    generateDataset(arr);

    for (int i = 0; i < TOTAL; i++)
    {
        if (arr[i] != expected[i])
        {
            return false;
        }
    }

    return true;
}

// Test hash function
bool testHashFunction()
{
    int values[TOTAL] = {
        79, 92, 5, 18, 31,
        44, 57, 70, 83, 96,
        9, 22, 35, 48, 61,
        74, 87, 0, 13, 26
    };

    int expected[TOTAL] = {
        1, 0, 2, 9, 4,
        1, 1, 21, 19, 21,
        8, 2, 22, 7, 3,
        1, 10, 0, 16, 21
    };

    for (int i = 0; i < TOTAL; i++)
    {
        if (hashFunction(values[i]) != expected[i])
        {
            return false;
        }
    }

    return true;
}

// Display test results
int main()
{
    cout << "====================================\n";
    cout << "       HASH TABLE TESTING\n";
    cout << "====================================\n";

    cout << "Student: Swanandi Mahesh Patil\n";
    cout << "PRN: 202501100079\n";
    cout << "Roll No: 54\n";

    cout << "\nHash Table Size: " << SIZE;
    cout << "\nHash Method: Mid-Square";
    cout << "\nCollision Handling: Separate Chaining\n";

    cout << "\n---------- TEST RESULTS ----------\n";

    if (testDataset())
    {
        cout << "Test 1: Dataset Generation: PASSED\n";
    }
    else
    {
        cout << "Test 1: Dataset Generation: FAILED\n";
    }

    if (testHashFunction())
    {
        cout << "Test 2: Mid-Square Hash Function: PASSED\n";
    }
    else
    {
        cout << "Test 2: Mid-Square Hash Function: FAILED\n";
    }

    cout << "\n====================================\n";
    cout << "           TESTING COMPLETED\n";
    cout << "====================================\n";

    return 0;
}
