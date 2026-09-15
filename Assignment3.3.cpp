// L3 = {w| w does not contain the substring 110}

#include <iostream>  // For cin and cout
#include <string>    // For string type 
using namespace std; // Allows "string" instead of "std::string"

bool recognizeL3(const string& word) {
    enum State { EMPTY, SAW_1, SAW_11, FOUND_110 }; // States track our progress toward seeing "110"
    
    State currentState = EMPTY;
    
    for (char c : word) {
        switch (currentState) {
            case EMPTY: // Haven't started matching "110" yet
                if (c == '1') { 
                    currentState = SAW_1;  // First char of "110"
                }
                break;  // If c == '0', stay in EMPTY (no progress)
                
            case SAW_1: // We saw one '1'
                if (c == '1') {
                    currentState = SAW_11;  // Now we have "11"
                } else {
                    // c == '0': we have "10" and thus not part of "110"
                    currentState = EMPTY;   // Reset
                }
                break;
                
            case SAW_11:    // We saw "11"
                if (c == '0') {
                    currentState = FOUND_110;  // We found "110"
                }
                break;  // If c == '1', stay in SAW_11 ("111" is still "11")
                
            case FOUND_110: // Once we find "110", we stay rejected
                currentState = FOUND_110;
                break;
        }
    }
    
    // Accept only if we NEVER found "110"
    return currentState != FOUND_110;
}

int main() {
    string input;
    
    cout << "Q3: L3 = {w | w does not contain the substring 110}" << endl;
    cout << "====================================================" << endl;
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
    if (recognizeL3(input)) {
        cout << "Result: ACCEPT" << endl;
    } else {
        cout << "Result: REJECT" << endl;
    }
    
    return 0;
}