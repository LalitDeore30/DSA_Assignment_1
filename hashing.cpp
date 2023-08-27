#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    int id;

    Employee()
    {
        id = -1;
    }

    Employee(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

class HashTable
{
private:
    Employee records[10];

public:
    int hashValue(int id)
    {
        return id % 10;
    }

    void insertRecord(string name, int id)
    {
        int index = hashValue(id);
        while (records[index].id != -1)
        {
            index = (index + 1) % 10; // Linear probing
        }
        records[index] = Employee(name, id);
    }

    void searchRecordByID()
    {
        int id;
        cout << "Enter employee ID to search: ";
        cin >> id;

        int index = hashValue(id);
        if (records[index].id == id)
        {
            cout << "Name: " << records[index].name << " ID: " << records[index].id << endl;
        }
        else
        {
            cout << "Employee not found." << endl;
        }
    }

    void displayAllRecords()
    {
        cout << "\nEmployee Records:\n";
        for (int i = 0; i < 10; i++)
        {
            Employee emp = records[i];
            if (emp.id != -1)
            {
                cout << "Name: " << emp.name << " ID: " << emp.id << endl;
            }
        }
    }
};

void getInputRecords(HashTable &ht)
{
    for (int i = 0; i < 8; i++)
    {
        string name;
        int id;

        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> id;
        cin.ignore();

        ht.insertRecord(name, id);
    }
}

int main()
{
    HashTable ht;
    getInputRecords(ht);
    ht.displayAllRecords();

    ht.searchRecordByID();

    return 0;
}
