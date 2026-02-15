#include <iostream>
#include <cstring>

using namespace std;

struct Customer {
    char name[20];
    char username[20];
    char password[20];
    double balance;
};

void fullDetails(Customer C) {
    cout << "User ID: " << C.username << " | Name: " << C.name << endl;
    cout << "Balance: $" << C.balance << endl;
}

void basicDetails(Customer C) {
    cout << "Account Holder: " << C.name << endl;
    cout << "User: " << C.username << endl;
}

int main() {
    int num;
    cout << "How many customers would you like to register? ";
    cin >> num;

    Customer bankDB[num];

    for (int i = 0; i < num; i++) {
        cout << "\n     Registering Customer " << i + 1 << "    " << endl;
        cout << "Name: ";     cin >> bankDB[i].name;
        cout << "Username: "; cin >> bankDB[i].username;
        cout << "Password: "; cin >> bankDB[i].password;
        cout << "Balance: ";  cin >> bankDB[i].balance;
    }

    cout << "\nRegistration Complete. Switching to Login Portal...\n";

    // 1. Login Portal
    char u[20], p[20];
    cout << "\n--- LOGIN ---" << endl;
    cout << "Username (or 'staff'): "; cin >> u;
    cout << "Password: "; cin >> p;

    // Staff login
    if (strcmp(u, "staff") == 0) {

        // Manager check using company provided password
        if (strcmp(p, "Branch1*") == 0) {
            cout << "\nMANAGER VIEW (ALL RECORDS)";
            for (int i = 0; i < num; i++) {
                fullDetails(bankDB[i]);
            }
        }
        // Staff check using company provided password
        else if (strcmp(p, "Staff123*") == 0) {
            cout << "\nSTAFF VIEW (NAMES ONLY) ";
            for (int i = 0; i < num; i++) {
                basicDetails(bankDB[i]);
            }
        }
    }

    else {
        bool found = false;
        for (int i = 0; i < num; i++) {
            if (strcmp(u, bankDB[i].username) == 0 && strcmp(p, bankDB[i].password) == 0) {
                fullDetails(bankDB[i]);
                found = true;
                break;
            }
        }
        if (!found) cout << "Invalid Login." << endl;
    }

    return 0;
}
