#include <iostream>
#include <string>
#include <iomanip>  // For formatting the output
using namespace std;

//________Version with structs_____________________
struct Student {
    string name;
    int age;
    float gpa;
    string gradeLevel;
};


void displayStudentsWithStruct(Student students[], int size) {
    cout << "\n===Displaying Students (With Struct)===\n";      // Stucts make everything so clean because we simply have to pass an array
    cout << left << setw(15) << "Name" << setw(6) << "Age" << setw(8) << "GPA" << setw(15) << "Grade Level" << endl;
    cout << string(50, '-') << endl;
    
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << students[i].name << setw(6) << students[i].age << setw(8) << fixed << setprecision(2) << students[i].gpa << setw(15) << students[i].gradeLevel << endl;
        // With structs, we can access all related data through one variable
    }
}

//Function to find students with GPA above a certain threshold using structs
void findHighPerformersWithStruct(Student students[], int size, float threshold) {
    cout << "\n--- Students with GPA above " << threshold << " (With Struct) ---\n";
    for (int i = 0; i < size; i++) {
        if (students[i].gpa >= threshold) {
            cout << students[i].name << " - GPA: " << students[i].gpa << endl;
        }
    }
}

//__________Version without structs_______________________
void displayStudentsWithoutStruct(string names[], int ages[], float gpas[], // WIthout structs we need separate arrays for everything
                                   string gradeLevels[], int size) {
    cout << "\n========== DISPLAYING STUDENTS (Without Struct) ==========\n";
    cout << left << setw(15) << "Name"  << setw(6) << "Age"  << setw(8) << "GPA"  << setw(15) << "Grade Level" << endl;
    cout << string(50, '-') << endl;
    
    for (int i = 0; i < size; i++) {
        // We have to keep track of the same index across 4 different arrays. If they get out of sync things will stop working
        cout << left << setw(15) << names[i] << setw(6) << ages[i] << setw(8) << fixed << setprecision(2) << gpas[i] << setw(15) << gradeLevels[i] << endl;
    }
}

// High performers fuction but without structs this time
void findHighPerformersWithoutStruct(string names[], float gpas[], int size, 
                                      float threshold) {
    cout << "\n--- Students with GPA above " << threshold << " (Without Struct) ---\n";
    for (int i = 0; i < size; i++) {
        if (gpas[i] >= threshold) {
            cout << names[i] << " - GPA: " << gpas[i] << endl;
        }
    }
}

// Main Functions Area
int main() {
    const int NUM_STUDENTS = 5;
    
    cout << "=================================================================\n";
    cout << "DEMONSTRATING THE VALUE OF STRUCTS IN C++\n";
    cout << "=================================================================\n";
    
    //__________With Structs_______________ 
    cout << "\n\n>>> Method 1: Using Structs <<<\n";
    
    Student students[NUM_STUDENTS] = {          // Create an array of Student structs
        {"Alice Johnson", 18, 3.8, "Freshman"}, // Each element is a complete student with all their information bundled together
        {"Bob Smith", 19, 3.2, "Sophomore"},
        {"Carol Davis", 20, 3.9, "Junior"},
        {"David Lee", 21, 3.5, "Senior"},
        {"Emma Wilson", 19, 3.7, "Sophomore"}
    };
 
    displayStudentsWithStruct(students, NUM_STUDENTS);  // Display all students
    
    findHighPerformersWithStruct(students, NUM_STUDENTS, 3.5);  // Find high performers 
    
    cout << "\n--- Adding a new student with struct is simple ---\n";  // Adding a new student is easy, it only takes one line 
    cout << "Student newStudent = {\"Frank Brown\", 18, 3.6, \"Freshman\"};\n";
    
    
    //___________Without Structs_________________
    cout << "\n\n>>> Method 2: Without Structs <<<\n";
    

    string names[NUM_STUDENTS] = {  // Without structs, we need SEPARATE arrays for each attribute. These "paralell arrays" must stay synchronized
        "Alice Johnson", 
        "Bob Smith", 
        "Carol Davis", 
        "David Lee", 
        "Emma Wilson"
    };
    
    int ages[NUM_STUDENTS] = {
        18, 19, 20, 21, 19
    };
    
    float gpas[NUM_STUDENTS] = {
        3.8, 3.2, 3.9, 3.5, 3.7
    };
    
    string gradeLevels[NUM_STUDENTS] = {
        "Freshman", 
        "Sophomore", 
        "Junior", 
        "Senior", 
        "Sophomore"
    };
    
    displayStudentsWithoutStruct(names, ages, gpas, gradeLevels, NUM_STUDENTS); // Display all students
    
    findHighPerformersWithoutStruct(names, gpas, NUM_STUDENTS, 3.5);    // Find high performers
    
    cout << "\n--- Adding a new student without struct requires 4 updates ---\n";  // Adding a new student requires updating 4 different arrays
    cout << "names[5] = \"Frank Brown\";\n";
    cout << "ages[5] = 18;\n";
    cout << "gpas[5] = 3.6;\n";
    cout << "gradeLevels[5] = \"Freshman\";\n";
    
    return 0;
}