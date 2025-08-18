#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

struct Applicant {
    string fullName;
    string department;

    bool isVerified = false;

    bool requiresVisa = false;
    bool visaSubmitted = false;

    bool tuitionPaid = false;

    bool needsHousing = false;
    string housingDetails;

    string advisor;
    bool enrolledExtra = false;
    string extraSubject;
};

void resetInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool confirmChoice(const string& message) {
    while (true) {
        cout << message << " (y/n): ";
        char response;
        if (!(cin >> response)) { resetInput(); continue; }
        response = tolower(response);
        if (response == 'y') return true;
        if (response == 'n') return false;
        cout << "Please enter y or n.\n";
    }
}

string getInputLine(const string& message) {
    cout << message;
    string input;
    getline(cin, input); // ✅ No need to call cin.ignore() here
    return input;
}


void fillForm(Applicant& a) {
    cout << "\n--- Registration Form ---\n";
    if (a.fullName.empty()) a.fullName = getInputLine("Enter full name: ");
    if (a.department.empty()) a.department = getInputLine("Enter department: ");

    cout << "Form submitted to department.\n";
    cout << "Saved to Applicant Database.\n";
}

void verifyDetails(Applicant& a) {
    cout << "\n--- Admission Verification ---\n";
    cout << "Reviewing form for " << a.fullName << " (" << a.department << ")\n";
    do {
        cout << "Verifying...\n";
        a.isVerified = confirmChoice("Are the details correct?");
        if (!a.isVerified) {
            cout << "Please correct the form.\n";
            if (confirmChoice("Edit name?")) a.fullName = getInputLine("New name: ");
            if (confirmChoice("Edit department?")) a.department = getInputLine("New department: ");
        }
    } while (!a.isVerified);
    cout << "Verification complete.\n";
}

void processVisa(Applicant& a) {
    cout << "\n--- Visa Process ---\n";
    a.requiresVisa = confirmChoice("Does the applicant need a visa?");
    if (a.requiresVisa) {
        cout << "Notify applicant to apply for visa.\n";
        do {
            a.visaSubmitted = confirmChoice("Has the visa been submitted?");
            if (!a.visaSubmitted) cout << "Waiting for visa submission...\n";
        } while (!a.visaSubmitted);
        cout << "Visa application received.\n";
    } else {
        cout << "Visa not required.\n";
    }
}

void processPayment(Applicant& a) {
    cout << "\n--- Tuition Payment ---\n";
    cout << "Processing tuition fee...\n";
    do {
        a.tuitionPaid = confirmChoice("Has the tuition fee been paid?");
        if (!a.tuitionPaid) cout << "Awaiting payment...\n";
    } while (!a.tuitionPaid);
    cout << "Payment confirmed.\n";
}

void assignHousing(Applicant& a) {
    cout << "\n--- Housing Assignment ---\n";
    a.needsHousing = confirmChoice("Does the applicant need housing?");
    if (a.needsHousing) {
        a.housingDetails = getInputLine("Enter housing details (room/hostel): ");
        cout << "Housing assigned: " << a.housingDetails << "\n";
    } else {
        cout << "No housing requested.\n";
    }
}

void assignAdvisor(Applicant& a) {
    cout << "\n--- Advisor Assignment ---\n";
    if (a.advisor.empty())
        a.advisor = getInputLine("Enter advisor name: ");
    cout << "Advisor assigned: " << a.advisor << "\n";
}

void enrollExtraCourse(Applicant& a) {
    cout << "\n--- Extra Course Enrollment ---\n";
    a.enrolledExtra = confirmChoice("Is the applicant taking extra credits?");
    if (a.enrolledExtra) {
        a.extraSubject = getInputLine("Enter extra course name: ");
        cout << "Extra course enrolled: " << a.extraSubject << "\n";
    } else {
        cout << "No extra course selected.\n";
    }
}

void showSummary(const Applicant& a) {
    cout << "\n--- Registration Summary ---\n";
    cout << "Applicant: " << a.fullName << " (" << a.department << ")\n";
    cout << "Verified: " << (a.isVerified ? "Yes" : "No") << "\n";
    cout << "Visa: " << (a.requiresVisa ? (a.visaSubmitted ? "Submitted" : "Required (not submitted)") : "Not required") << "\n";
    cout << "Tuition Paid: " << (a.tuitionPaid ? "Yes" : "No") << "\n";
    cout << "Housing: " << (a.needsHousing ? a.housingDetails : "Not requested") << "\n";
    cout << "Advisor: " << (a.advisor.empty() ? "Not assigned" : a.advisor) << "\n";
    cout << "Extra Course: " << (a.enrolledExtra ? a.extraSubject : "None") << "\n";
    cout << "Registration complete.\n";
}

void saveToDatabase(const Applicant& a) {
    bool addHeader = false;

    ifstream fileCheck("applicants.csv");
    if (!fileCheck.good() || fileCheck.peek() == ifstream::traits_type::eof()) {
        addHeader = true;
    }
    fileCheck.close();

    ofstream dbFile("applicants.csv", ios::app);
    if (!dbFile) {
        cerr << "Error opening database file!\n";
        return;
    }

    if (addHeader) {
        dbFile << "FullName,Department,Verified,Visa,TuitionPaid,Housing,Advisor,ExtraCourse\n";
    }

    dbFile << a.fullName << ","
           << a.department << ","
           << (a.isVerified ? "Yes" : "No") << ","
           << (a.requiresVisa ? (a.visaSubmitted ? "Submitted" : "Required") : "Not required") << ","
           << (a.tuitionPaid ? "Yes" : "No") << ","
           << (a.needsHousing ? a.housingDetails : "Not requested") << ","
           << (a.advisor.empty() ? "Not assigned" : a.advisor) << ","
           << (a.enrolledExtra ? a.extraSubject : "None") << "\n";

    dbFile.close();
    cout << "Applicant data saved to applicants.csv\n";
}

int main() {
    Applicant applicant;

    fillForm(applicant);
    verifyDetails(applicant);
    processVisa(applicant);
    processPayment(applicant);
    assignHousing(applicant);
    assignAdvisor(applicant);
    enrollExtraCourse(applicant);
    showSummary(applicant);
    saveToDatabase(applicant);

    return 0;
}
