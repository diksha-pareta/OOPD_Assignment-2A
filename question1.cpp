#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;
const int MAX_LEN = 100;

class Person {
public:
    char pos[MAX_LEN];
    char name[MAX_LEN];
    char title[MAX_LEN];
    char email[MAX_LEN];
    char room[MAX_LEN];
    char phone[MAX_LEN];

    Person() {}

    Person(const char *p, const char *n, const char *t, const char *e, const char *r, const char *ph) {
        strncpy(pos, p, MAX_LEN);
        strncpy(name, n, MAX_LEN);
        strncpy(title, t, MAX_LEN);
        strncpy(email, e, MAX_LEN);
        strncpy(room, r, MAX_LEN);
        strncpy(phone, ph, MAX_LEN);
    }

    void showInfo() const {
        cout << "\nPosition: " << pos
             << "\nName: " << name
             << "\nTitle: " << title
             << "\nEmail: " << email
             << "\nRoom: " << room
             << "\nPhone: " << phone
             << "\n---------------------------";
    }
};

class Dean : public Person {
public:
    Dean(const char *n, const char *t, const char *e, const char *r, const char *ph)
        : Person("Dean", n, t, e, r, ph) {}
};

class Officer : public Person {
public:
    Officer(const char *n, const char *t, const char *e, const char *r, const char *ph)
        : Person("Officer", n, t, e, r, ph) {}
};

class AdminOfficer : public Person {
public:
    AdminOfficer(const char *n, const char *t, const char *e, const char *r, const char *ph)
        : Person("Administrative Officer", n, t, e, r, ph) {}
};

class Directory {
private:
    Person entries[MAX_SIZE];
    int count;

    void toLower(char *str) {
        for (int i = 0; str[i]; i++) {
            str[i] = tolower(str[i]);
        }
    }

public:
    Directory(const char *filename) : count(0) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Unable to open file: " << filename << endl;
            return;
        }

        char line[1024];
        file.getline(line, 1024); // Skip header line

        while (file.getline(line, 1024) && count < MAX_SIZE) {
            char *pos = strtok(line, ",");
            char *n = strtok(NULL, ",");
            char *t = strtok(NULL, ",");
            char *e = strtok(NULL, ",");
            char *r = strtok(NULL, ",");
            char *ph = strtok(NULL, ",");

            if (pos && n && t && e && r && ph) {
                if (strcmp(pos, "Dean") == 0) {
                    entries[count++] = Dean(n, t, e, r, ph);
                } else if (strcmp(pos, "Officer") == 0) {
                    entries[count++] = Officer(n, t, e, r, ph);
                } else if (strcmp(pos, "Administrative Officer") == 0) {
                    entries[count++] = AdminOfficer(n, t, e, r, ph);
                } else {
                    entries[count++] = Person(pos, n, t, e, r, ph); // Default case
                }
            }
        }

        file.close();
    }

    bool contains(const char *fullName, const char *searchName) {
        return strstr(fullName, searchName) != NULL;
    }

    void search(const char *searchName) {
        char searchNameLower[MAX_LEN];
        strncpy(searchNameLower, searchName, MAX_LEN);
        toLower(searchNameLower);

        bool found = false;
        for (int i = 0; i < count; ++i) {
            char nameLower[MAX_LEN];
            strncpy(nameLower, entries[i].name, MAX_LEN);
            toLower(nameLower);

            if (contains(nameLower, searchNameLower)) {
                entries[i].showInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "\nNo records found for: " << searchName << "\n";
        }
    }
};

bool isValid(const char *input) {
    for (int i = 0; input[i]; i++) {
        if (isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Directory dir("C:\\Users\\91935\\Desktop\\OOPD_Assignment-2A\\DB_departments.csv");

    char searchName[MAX_LEN];
    cout << " IIITD Information Center \n";

    while (true) {
        cout << "\nEnter a name to search: ";
        cin.getline(searchName, MAX_LEN);

        if (strlen(searchName) == 0 || !isValid(searchName)) {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        dir.search(searchName);
        break;
    }

    cout << "\n Thank you for using the system \n";

    return 0;
}
