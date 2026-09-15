// L5 = {w | w contains an even number of 0s, or exactly two 1s}

#include <iostream>  // For cin and cout
#include <string>    // For string type 
using namespace std; // Allows "string" instead of "std::string"

bool recognizeL5(const string& word) {  // States track both the count of 1s (0,1,2,3+) AND parity of 0s (even or odd)
    enum State {
        ONES_0_ZEROS_EVEN,      // 0 ones, even zeros
        ONES_0_ZEROS_ODD,       // 0 ones, odd zeros
        ONES_1_ZEROS_EVEN,      // 1 one, even zeros
        ONES_1_ZEROS_ODD,       // 1 one, odd zeros
        ONES_2_ZEROS_EVEN,      // 2 ones, even zeros
        ONES_2_ZEROS_ODD,       // 2 ones, odd zeros
        ONES_3PLUS_ZEROS_EVEN,  // 3+ ones, even zeros
        ONES_3PLUS_ZEROS_ODD    // 3+ ones, odd zeros
    };
    
    State currentState = ONES_0_ZEROS_EVEN; // Start with 0 ones and 0 zeros (even)
    
    for (char c : word) {
        State nextState;
        
        if (c == '0') { // Seeing a '0' flips the zero-parity, keeps one-count same
            switch (currentState) {
                case ONES_0_ZEROS_EVEN:
                    nextState = ONES_0_ZEROS_ODD;
                    break;
                case ONES_0_ZEROS_ODD:
                    nextState = ONES_0_ZEROS_EVEN;
                    break;
                case ONES_1_ZEROS_EVEN:
                    nextState = ONES_1_ZEROS_ODD;
                    break;
                case ONES_1_ZEROS_ODD:
                    nextState = ONES_1_ZEROS_EVEN;
                    break;
                case ONES_2_ZEROS_EVEN:
                    nextState = ONES_2_ZEROS_ODD;
                    break;
                case ONES_2_ZEROS_ODD:
                    nextState = ONES_2_ZEROS_EVEN;
                    break;
                case ONES_3PLUS_ZEROS_EVEN:
                    nextState = ONES_3PLUS_ZEROS_ODD;
                    break;
                case ONES_3PLUS_ZEROS_ODD:
                    nextState = ONES_3PLUS_ZEROS_EVEN;
                    break;
            }
        } else {  // c == '1' , Seeing a '1' increments one-count, keeps zero-parity same
            switch (currentState) {
                case ONES_0_ZEROS_EVEN:
                    nextState = ONES_1_ZEROS_EVEN;
                    break;
                case ONES_0_ZEROS_ODD:
                    nextState = ONES_1_ZEROS_ODD;
                    break;
                case ONES_1_ZEROS_EVEN:
                    nextState = ONES_2_ZEROS_EVEN;
                    break;
                case ONES_1_ZEROS_ODD:
                    nextState = ONES_2_ZEROS_ODD;
                    break;
                case ONES_2_ZEROS_EVEN:
                    nextState = ONES_3PLUS_ZEROS_EVEN;
                    break;
                case ONES_2_ZEROS_ODD:
                    nextState = ONES_3PLUS_ZEROS_ODD;
                    break;
                case ONES_3PLUS_ZEROS_EVEN:
                    nextState = ONES_3PLUS_ZEROS_EVEN;  // Stay at 3+, there is no state to step to after this
                    break;
                case ONES_3PLUS_ZEROS_ODD:
                    nextState = ONES_3PLUS_ZEROS_ODD;   // Stay at 3+, there is no state to step up to after this
                    break;
            }
        }
        
        currentState = nextState;
    }
    
    // Accept if (even 0s) OR (exactly two 1s)
    // All the states that allow this are as follows:
    return currentState == ONES_0_ZEROS_EVEN ||    // even 0s, any ones
           currentState == ONES_1_ZEROS_EVEN ||    // even 0s, any ones
           currentState == ONES_2_ZEROS_EVEN ||    // even 0s OR exactly 2 ones
           currentState == ONES_2_ZEROS_ODD ||     // exactly 2 ones
           currentState == ONES_3PLUS_ZEROS_EVEN;  // even 0s, any ones
}

int main() {
    string input;
    
    cout << "Q5: L5 = {w | w contains even number of 0s, OR exactly two 1s}" << endl;
    cout << "================================================================" << endl;
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
    if (recognizeL5(input)) {
        cout << "Result: ACCEPT" << endl;
    } else {
        cout << "Result: REJECT" << endl;
    }
    
    return 0;
}