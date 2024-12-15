#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class PersonalRecord {
    public :
	string name;
    string dob; // Format: YYYY-MM-DD
    string telephone;
};

void displayRecords( vector<PersonalRecord> & records) {
    cout << "Name\tDOB\tTelephone\n";
    for ( auto & record : records) {
        cout << record.name << "\t" << record.dob << "\t" << record.telephone << "\n";
    }
}


bool compareByName(PersonalRecord& a,PersonalRecord& b)
{
	return a.name < b.name;
}

int main() {
    vector<PersonalRecord> records;
    int n;

    cout << "Enter the number of records: ";
    cin >> n;
    cin.ignore(); // Clear the newline character from the input buffer

    // Input records
    for (int i = 0; i < n; ++i) {
        PersonalRecord record;
        cout << "Enter Name: ";
        getline(cin, record.name);
        cout << "Enter DOB (YYYY-MM-DD): ";
        getline(cin, record.dob);
        cout << "Enter Telephone: ";
        getline(cin, record.telephone);
        records.push_back(record);
    }

    sort(records.begin(), records.end(), compareByName);

    cout << "\nSorted Records:\n";
    displayRecords(records);

    string searchName;
    cout << "\nEnter the name to search: ";
    getline(cin, searchName);

    bool found = false;
    for ( auto & record : records) {
        if (record.name == searchName) {
            cout << "Record found: " << record.name << ", " << record.dob << ", " << record.telephone << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }

    return 0;
}
