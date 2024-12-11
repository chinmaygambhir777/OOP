#include <iostream>
#include <fstream>
using namespace std;

class Employee {
    string Name;
    int ID;
    double salary;

public:
    void accept() {
        cout << "\nName: ";
        cin.ignore();
        getline(cin, Name);
        cout << "ID: ";
        cin >> ID;
        cout << "Salary: ";
        cin >> salary;
    }

    void display() {
        cout << "\nName: " << Name;
        cout << "\nID: " << ID;
        cout << "\nSalary: " << salary << endl;
    }

    // Save employee data to file (in text format)
    void saveToFile(ofstream & f)  {
        f << Name << "\n" << ID << "\n" << salary << "\n";
    }

    // Load employee data from file (in text format)
    void loadFromFile(ifstream & f) {
        getline(f, Name);
        f >> ID;
        f >> salary;
        f.ignore(); // Ignore the newline after reading the salary
    }
};

int main() {
    Employee o[5];
    ofstream outFile;
    ifstream inFile;
    int i, n;

    // Open file for writing (in text mode)
    outFile.open("demo.txt");
    if (!outFile) {
        cout << "Error opening file for writing!";
        return 1;
    }

    cout << "Enter the number of employees you want to store (max 5): ";
    cin >> n;
    if (n > 5) {
        cout << "Number of employees exceeds the limit of 5!";
        return 1;
    }

    for (i = 0; i < n; i++) {
        cout << "\nEnter information of Employee " << i + 1 << "\n";
        o[i].accept();
        o[i].saveToFile(outFile);
    }

    outFile.close();

    // Open file for reading (in text mode)
    inFile.open("demo.txt");
    if (!inFile) {
        cout << "Error opening file for reading!";
        return 1;
    }

    cout << "\nInformation of Employees is as follows:\n";
    for (i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << "\n";
        o[i].loadFromFile(inFile);
        o[i].display();
    }

    inFile.close();

    return 0;
}
