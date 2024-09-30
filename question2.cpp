#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_S = 100;
const int MAX_LEN = 100;

class Faculty
{
public:
    char dept[MAX_LEN];
    char pos[MAX_LEN];
    char name[MAX_LEN];
    char room[MAX_LEN];
    char phone[MAX_LEN];

    Faculty() {}

    Faculty(const char *d, const char *p, const char *n, const char *r, const char *ph)
    {
        strncpy(dept, d, MAX_LEN);
        strncpy(pos, p, MAX_LEN);
        strncpy(name, n, MAX_LEN);
        strncpy(room, r, MAX_LEN);
        strncpy(phone, ph, MAX_LEN);
    }

    virtual void show() const
    {
        cout << "\nDept: " << dept
             << "\nPos: " << pos
             << "\nName: " << name
             << "\nRoom: " << room
             << "\nPhone: " << phone << "\n";
    }
};

class Admin : public Faculty
{
protected:
    char email[MAX_LEN];

public:
    Admin(const char *d, const char *p, const char *n, const char *r, const char *ph, const char *e)
        : Faculty(d, p, n, r, ph)
    {
        strncpy(email, e, MAX_LEN);
    }

    void show() const override
    {
        Faculty::show();
        cout << "Email: " << email << "\n";
    }
};

class Directory
{
private:
    Faculty dir[MAX_S];
    int size;

    void toLower(char *s)
    {
        for (int i = 0; s[i]; i++)
        {
            s[i] = tolower(s[i]);
        }
    }

    bool contains(const char *s, const char *sub)
    {
        return strstr(s, sub) != NULL;
    }

public:
    Directory(const char *filename) : size(0)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        char line[1024];
        file.getline(line, 1024);

        while (file.getline(line, 1024) && size < MAX_S)
        {
            char *dept = strtok(line, ",");
            char *pos = strtok(NULL, ",");
            char *name = strtok(NULL, ",");
            char *room = strtok(NULL, ",");
            char *phone = strtok(NULL, ",");

            if (dept && pos && name && room && phone)
            {
                if (contains(dept, "Computational Biology"))
                {
                    dir[size++] = Faculty("CB", pos, name, room, phone);
                }
                else if (contains(dept, "Electronics and Communication Engineering"))
                {
                    dir[size++] = Faculty("ECE", pos, name, room, phone);
                }
                else if (contains(dept, "Computer Science and Engineering"))
                {
                    dir[size++] = Faculty("CSE", pos, name, room, phone);
                }
                else if (contains(dept, "Mathematics"))
                {
                    dir[size++] = Faculty("MATH", pos, name, room, phone);
                }
                else if (contains(dept, "Human-Centered Design"))
                {
                    dir[size++] = Faculty("HCD", pos, name, room, phone);
                }
                else if (contains(dept, "Social Sciences And Humanities"))
                {
                    dir[size++] = Faculty("SSH", pos, name, room, phone);
                }
            }
        }

        file.close();
    }

    void searchByDept(const char *searchDept)
    {
        char deptLower[MAX_LEN];
        strncpy(deptLower, searchDept, MAX_LEN);
        deptLower[MAX_LEN - 1] = '\0';
        toLower(deptLower);
        bool found = false;
        for (int i = 0; i < size; ++i)
        {
            char lowerDept[MAX_LEN];
            strncpy(lowerDept, dir[i].dept, MAX_LEN);
            lowerDept[MAX_LEN - 1] = '\0';
            toLower(lowerDept);

            if (contains(lowerDept, deptLower))
            {
                dir[i].show();
                found = true;
            }
        }

        if (!found)
        {
            cout << "\nWrong department: " << searchDept << "\n";
        }
    }
};

bool isValid(const char *input)
{
    for (int i = 0; input[i]; i++)
    {
        if (!isalpha(input[i]) && !isspace(input[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Directory dir("C:\\Users\\91935\\Desktop\\OOPD_Assignment-2A\\DB_Faculties.csv");

    char searchName[MAX_LEN];
    cout << "IIITD INFO CENTER " << endl;

    while (true)
    {
        cout << "\nEnter the department name to search: ";
        cout << "\n1. CSE\n"
             << "2. ECE\n"
             << "3. CB\n"
             << "4. SSH\n"
             << "5. MATH\n"
             << "6. HCD\n";
        cin.getline(searchName, MAX_LEN);

        if (strlen(searchName) == 0 || !isValid(searchName))
        {
            cout << "Error: Invalid input. Try Again.\n";
            continue;
        }

        dir.searchByDept(searchName);
        break;
    }

    cout << "\nTHANK YOU " << endl;

    return 0;
}