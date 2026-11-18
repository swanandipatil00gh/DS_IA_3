#include <iostream>
#include <string>
using namespace std;

// PRN: 202501100079
// Name: Swanandi Mahesh Patil
// Scenario: Cold-drink flavours
// Seed: 79
// Dataset Size: 20
// Hash Table Size: 23
// Hash Function: Mid-Square Method
// Collision Strategy: Separate Chaining

const int SIZE = 23;
const int N = 20;

struct Node
{
    int key;
    Node* next;

    Node(int value)
    {
        key = value;
        next = NULL;
    }
};

class HashTable
{
private:

    Node* table[SIZE];

public:

    // Constructor
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }

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

    // Insert Operation
    void insertKey(int key)
    {
        if (key < 0 || key > 99)
        {
            cout << "Invalid key! Enter 0 to 99.\n";
            return;
        }

        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << "Duplicate key! Already exists.\n";
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(key);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            cout << "Collision detected at index "
                 << index << endl;

            temp = table[index];

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Key " << key
             << " inserted at index "
             << index << endl;
    }

    // Search Operation
    void searchKey(int key)
    {
        if (key < 0 || key > 99)
        {
            cout << "Invalid key!\n";
            return;
        }

        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << "Key " << key
                     << " found at index "
                     << index << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Key not found!\n";
    }

    // Delete Operation
    void deleteKey(int key)
    {
        if (key < 0 || key > 99)
        {
            cout << "Invalid key!\n";
            return;
        }

        int index = hashFunction(key);

        Node* temp = table[index];
        Node* previous = NULL;

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (previous == NULL)
                {
                    table[index] = temp->next;
                }
                else
                {
                    previous->next = temp->next;
                }

                delete temp;

                cout << "Key " << key
                     << " deleted successfully.\n";

                return;
            }

            previous = temp;
            temp = temp->next;
        }

        cout << "Key not found!\n";
    }

    // Display Hash Table
    void display()
    {
        cout << "\n========== FINAL HASH TABLE ==========\n";

        cout << "Index\tLinked List\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << "\t";

            Node* temp = table[i];

            if (temp == NULL)
            {
                cout << "NULL";
            }

            while (temp != NULL)
            {
                cout << temp->key;

                if (temp->next != NULL)
                {
                    cout << " -> ";
                }

                temp = temp->next;
            }

            cout << endl;
        }
    }

    // Load Personalized Dataset
    void loadDataset()
    {
        int data[N] =
        {
            79, 92, 5, 18, 31,
            44, 57, 70, 83, 96,
            9, 22, 35, 48, 61,
            74, 87, 0, 13, 26
        };

        cout << "\nPERSONALIZED DATASET\n";

        for (int i = 0; i < N; i++)
        {
            cout << data[i] << " ";
        }

        cout << "\n\nINSERTION PROCESS\n";

        for (int i = 0; i < N; i++)
        {
            insertKey(data[i]);
        }
    }

    // Destructor
    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* temp = table[i];

            while (temp != NULL)
            {
                Node* nextNode = temp->next;

                delete temp;

                temp = nextNode;
            }
        }
    }
};

int main()
{
    HashTable ht;

    cout << "====================================\n";
    cout << " COLD DRINK FLAVOUR HASH TABLE\n";
    cout << "====================================\n";

    cout << "Name: Swanandi Mahesh Patil\n";
    cout << "PRN: 202501100079\n";
    cout << "Roll No: 54\n";

    cout << "Hash Table Size: " << SIZE << endl;

    ht.loadDataset();

    int choice, key;

    do
    {
        cout << "\n========== MAIN MENU ==========\n";

        cout << "1. Insert Key\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter key: ";
                cin >> key;

                ht.insertKey(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;

                ht.searchKey(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;

                ht.deleteKey(key);
                break;

            case 4:
                ht.display();
                break;

            case 5:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
