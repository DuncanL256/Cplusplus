#include <iostream>
#include <string>

using namespace std; //Saves me a little on printout lines

int main() {
    cout << "Enter family names (one per line). Type '.' to stop.\n\n";
    
    string smallest, largest, last; // Initializing our variables
    
    // Flag to know if we've seen at least one name yet
    bool hasAny = false;
    
    while (true) {  // Continue until the user stops the code
        cout << "> ";
        
        string name;    // Read full line (can include spaces in names like "Van der Waals")
        getline(cin, name);
        
        size_t start = name.find_first_not_of(" \t");   // I found this as a way to remove leading and trailing spaces or tabs
        if (start == string::npos) {
            name = "";  // if the whole line was just spaces we will treat it as empty
        } else {
            size_t end = name.find_last_not_of(" \t");
            name = name.substr(start, end - start + 1);
        }
        
        if (name == ".") {  // User wants to stop
            break;
        }
        
        if (name.empty()) { // Skip empty inputs
            continue;
        }
        
        if (!hasAny) {
            smallest = largest = last = name;
            hasAny = true;  // This shows that we have at least 1 name
        } else {
            if (name < smallest) {  // Compare using normal string < and > (lexicographical order)
                smallest = name;
            }
            if (name > largest) {
                largest = name;
            }
            
            last = name;
        }
    }
    
    // After loop ends we can show what we found
    if (hasAny) {
        cout << "\nResults:\n";
        cout << "Smallest (lexicographically): " << smallest << endl;
        cout << "Largest  (lexicographically): " << largest  << endl;
        cout << "Last entered                 : " << last     << endl;
    } else {
        cout << "\nNo names were entered." << endl;
    }
    
    return 0;
}