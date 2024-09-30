#include <iostream>
#include <string>
using namespace std;

class Position {
protected:
    string name;

public:
    Position(string n) : name(n) {}

    void display() const {
        cout << "Position: " << name << endl;
    }

    virtual void escalate() = 0; 
};

class Registrar : public Position {
public:
    Registrar() : Position("Registrar") {}

    void escalate() override {
        display();
        cout << "No further escalation possible." << endl;
    }
};

class DeanIRD : public Position {
public:
    DeanIRD() : Position("Dean of Innovation, Research & Development (DIRD)") {}

    void escalate() override {
        display();
        cout << "Escalating to Registrar..." << endl;
        Registrar().escalate();
    }
};

class AssociateDeanIRD : public Position {
public:
    AssociateDeanIRD() : Position("Associate Dean of Innovation, Research & Development (ADIRD)") {}

    void escalate() override {
        display();
        cout << "Escalating to Dean..." << endl;
        DeanIRD().escalate();
    }
};

class AdministrativeOfficerIRD : public Position {
public:
    AdministrativeOfficerIRD() : Position("Administrative Officer (IRD)") {}

    void escalate() override {
        display();
        cout << "Escalating to Associate Dean..." << endl;
        AssociateDeanIRD().escalate();
    }
};

class LibraryOfficer : public Position {
public:
    LibraryOfficer() : Position("Library Officer (SG)") {}

    void escalate() override {
        display();
        cout << "Escalating to Registrar..." << endl;
        Registrar().escalate();
    }
};

class JuniorLibraryOfficer : public Position {
public:
    JuniorLibraryOfficer() : Position("Junior Library Officer") {}

    void escalate() override {
        display();
        cout << "Escalating to Library Officer..." << endl;
        LibraryOfficer().escalate();
    }
};

class JuniorAdminOfficerStore : public Position {
public:
    JuniorAdminOfficerStore() : Position("Junior Administrative Officer (Store & Purchase)") {}

    void escalate() override {
        display();
        cout << "Escalating to Registrar..." << endl;
        Registrar().escalate();
    }
};

class AssistantAdminOfficerStore : public Position {
public:
    AssistantAdminOfficerStore() : Position("Assistant Administrative Officer (Store & Purchase) (SG)") {}

    void escalate() override {
        display();
        cout << "Escalating to Junior Administrative Officer..." << endl;
        JuniorAdminOfficerStore().escalate();
    }
};

class AdminOfficerStore : public Position {
public:
    AdminOfficerStore() : Position("Administrative Officer (Store & Purchase)") {}

    void escalate() override {
        display();
        cout << "Escalating to Assistant Administrative Officer..." << endl;
        AssistantAdminOfficerStore().escalate();
    }
};

class DeanAdmin : public Position {
public:
    DeanAdmin() : Position("Dean (Admin)") {}

    void escalate() override {
        display();
        cout << "Escalating to Registrar..." << endl;
        Registrar().escalate();
    }
};

class AssociateDeanAdmin : public Position {
public:
    AssociateDeanAdmin() : Position("Associate Dean (Admin)") {}

    void escalate() override {
        display();
        cout << "Escalating to Dean..." << endl;
        DeanAdmin().escalate();
    }
};

class AdminOfficerAdmin : public Position {
public:
    AdminOfficerAdmin() : Position("Administrative Officer (Admin)") {}

    void escalate() override {
        display();
        cout << "Escalating to Associate Dean..." << endl;
        AssociateDeanAdmin().escalate();
    }
};

class HeadOfDepartment : public Position {
public:
    HeadOfDepartment() : Position("Head of Department") {}

    void escalate() override {
        display();
        cout << "Escalating to Registrar..." << endl;
        Registrar().escalate();
    }
};

class AdminOfficerAcad : public Position {
public:
    AdminOfficerAcad() : Position("Administrative Officer (Acad)") {}

    void escalate() override {
        display();
        cout << "Escalating to Head of Department..." << endl;
        HeadOfDepartment().escalate();
    }
};

class FacultyMember : public Position {
public:
    FacultyMember() : Position("Faculty Member") {}

    void escalate() override {
        display();
        cout << "Escalating to Administrative Officer..." << endl;
        AdminOfficerAcad().escalate();
    }
};

void escalateComplaint(const string& department) {
    cout << "\n--- Escalating complaint for " << department << " ---\n";
    
    if (department == "IRD") {
        AdministrativeOfficerIRD ao;
        ao.escalate();
    } else if (department == "Library") {
        JuniorLibraryOfficer jlo;
        jlo.escalate();
    } else if (department == "Store & Purchase") {
        AdminOfficerStore aso;
        aso.escalate();
    } else if (department == "Academics") {
        FacultyMember f;
        f.escalate();
    } else if (department == "Administration") {
        AdminOfficerAdmin aoa;
        aoa.escalate();
    } else {
        cout << "Invalid department!" << endl;
    }
}

int main() {
    cout << "Complaint Escalation System\n";

    escalateComplaint("IRD");
    escalateComplaint("Library");
    escalateComplaint("Store & Purchase");
    escalateComplaint("Academics");
    escalateComplaint("Administration");

    return 0;
}
