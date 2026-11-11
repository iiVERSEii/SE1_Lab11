// program

#include <iostream>
#include <vector>
using namespace std;

int count_absences(const vector<int>& attendance, size_t start_index){
    int absent_count = 0;
    for(size_t i = start_index; i < attendance.size(); ++i){
        absent_count += (attendance[i] == 0);
    }
    return absent_count;
}

// Intentionally starts at 1 to preserve the fault being tested.
bool fail_lecture(const vector<int>& attendance){
    return count_absences(attendance, 1) >= 3;
}

int main(){
    struct TestCase{
        const char* name;
        vector<int> attendance;
    };

    const vector<TestCase> test_cases{
        {"No error state", {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {"Error state, no failure", {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}},
        {"Error state and failure", {0, 0, 0, 1, 1, 1, 1, 1, 1, 1}}
    };

    for(const TestCase& test_case : test_cases){
        // Compare the correct count with the count produced by the faulty loop.
        const int expected_absences = count_absences(test_case.attendance, 0);
        const int actual_absences = count_absences(test_case.attendance, 1);
        const bool expected_failure = expected_absences >= 3;
        const bool actual_failure = fail_lecture(test_case.attendance);
        // An internal count mismatch is an error state; a wrong result is a failure.
        const bool error_state = expected_absences != actual_absences;
        const bool failure = expected_failure != actual_failure;

        cout << test_case.name << "\nAttendance:";
        for(int value : test_case.attendance){
            cout << " " << value;
        }
        cout << "\nExpected absence count: " << expected_absences
             << "\nActual absence count: " << actual_absences
             << "\nExpected output: " << (expected_failure ? "Fail" : "Pass")
             << "\nActual output: " << (actual_failure ? "Fail" : "Pass")
             << "\nError state: " << (error_state ? "Yes" : "No")
             << "\nFailure: " << (failure ? "Yes" : "No") << "\n\n";
    }

    return 0;
}