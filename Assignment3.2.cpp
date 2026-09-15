//L2 = {w| w starts with 0 and has odd length, or starts with 1 and has even length}

#include <iostream>  // For cin and cout
#include <string>    // For string type 
using namespace std; // Allows "string" instead of "std::string"

bool recognizeL2(const string& word) {
    if (word.empty()) { // Empty string doesn't satisfy either condition
        return false;
    }
    
    enum State { START, ZERO_ODD, ZERO_EVEN, ONE_ODD, ONE_EVEN };   // What we started with in part 1 + the current length parity
    
    State currentState = START; // Starting state
    
    for (char c : word) {
        switch (currentState) {
            case START: // First character determines our path
                if (c == '0') {
                    currentState = ZERO_ODD;  // Started with 0, length=1 (odd)
                } else {
                    currentState = ONE_ODD;   // Started with 1, length=1 (odd)
                }
                break;
                
            case ZERO_ODD:
                currentState = ZERO_EVEN;   // Started with 0, was odd, now even
                break;
                
            case ZERO_EVEN:
                currentState = ZERO_ODD;    // Started with 0, was even, now odd
                break;
                
            case ONE_ODD:
                currentState = ONE_EVEN;    // Started with 1, was odd, now even
                break;
                
            case ONE_EVEN:
                currentState = ONE_ODD;     // Started with 1, was even, now odd
                break;
        }
    }
    
    return currentState == ZERO_ODD || currentState == ONE_EVEN;    // Accept if (started 0 AND odd) OR (started 1 AND even)
}

int main() {
    string input;
    
    cout << "Q2: L2 = {w | starts with 0 & odd length, OR starts with 1 & even length}" << endl;
    cout << "=========================================================================" << endl;
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
    if (recognizeL2(input)) {
        cout << "Result: ACCEPT" << endl;
    } else {
        cout << "Result: REJECT" << endl;
    }
    
    return 0;
}