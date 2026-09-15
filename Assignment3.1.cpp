// L1= {w| w has length at least 3, and its third symbol is a 0}

#include <iostream>  // For cin and cout
#include <string>    // For string type 
using namespace std; // Allows "string" instead of "std::string"

bool recognizeL1(const string& word) {
    enum State { START, POS1, POS2, ACCEPT, REJECT }; // Define our 5 states
    
    State currentState = START; // Begin in START state
    
    for (char c : word) {   // Process each character one by one
        switch (currentState) {
            case START:
                currentState = POS1;    // First character moves to POS1 regardless of value
                break;
                
            case POS1:
                currentState = POS2;    // Second character moves to POS2 regardless of value
                break;
                
            case POS2:
                if (c == '0') {
                    currentState = ACCEPT;  // Third character is 0, accept
                } else {
                    currentState = REJECT;  // Third character is 1, reject
                }
                break;
                
            case ACCEPT:
                currentState = ACCEPT; // If already accepted, stay in ACCEPT
                break;
                
            case REJECT:
                currentState = REJECT;  // If already rejected, stay in REJECT
                break;
        }
    }
    
    return currentState == ACCEPT; // Accept only if we ended in ACCEPT state
}

int main() {
    string input;
    
    cout << "Q1: L1 = {w | w has length >= 3, and 3rd symbol is 0}" << endl;
    cout << "======================================================" << endl;
    cout << "Enter a string consisting of 0 or 1: ";
    cin >> input;
    
    // Validate input
    bool valid = true;
    for (char c : input) {
        if (c != '0' && c != '1') {
            valid = false;
            break;
        }
    }
    
    if (!valid) {
        cout << "Error: Input must only contain 0 and 1" << endl;
        return 1;
    }
    
    // Test the language
    if (recognizeL1(input)) {
        cout << "Result: ACCEPT" << endl;
    } else {
        cout << "Result: REJECT" << endl;
    }
    
    return 0;
}