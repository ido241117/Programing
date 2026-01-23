#include "../include/common.h"
#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task3.h"
#include "../include/task4.h"
#include "functest.cpp"

void runTestCase(const string& inputFile, const string& outputFile, const string& testName) {
    // Mở file output để ghi kết quả
    ofstream ofs(outputFile);
    if (!ofs.is_open()) {
        cerr << "Cannot create output file: " << outputFile << endl;
        return;
    }
    
    // Ghi header
    ofs << "===== " << testName << " =====" << endl;
    ofs << "Input file: " << inputFile << endl << endl;
    
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    
    if (!readInputFile(inputFile, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        ofs << "ERROR: Failed to read input file" << endl;
        cerr << "Failed to read: " << inputFile << endl;
        ofs.close();
        return;
    }
    
    // Ghi input values
    ofs << "Input values:" << endl;
    ofs << "HP1=" << HP1 << " HP2=" << HP2 << endl;
    ofs << "EXP1=" << EXP1 << " EXP2=" << EXP2 << endl;
    ofs << "M1=" << M1 << " M2=" << M2 << endl;
    ofs << "E1=" << E1 << " E2=" << E2 << " E3=" << E3 << endl << endl;
    
    // Test Task 1
    ofs << "--- Task 1: firstMeet ---" << endl;
    ofs << "Before: EXP1=" << EXP1 << ", EXP2=" << EXP2 << ", E1=" << E1 << endl;
    int exp1_copy = EXP1, exp2_copy = EXP2;
    int result1 = firstMeet(exp1_copy, exp2_copy, E1);
    ofs << "After:  EXP1=" << exp1_copy << ", EXP2=" << exp2_copy << endl;
    ofs << "Result: " << result1 << endl << endl;
    
    // TODO: Test Task 2
    ofs << "--- Task 2: traceLuggage ---" << endl;
    ofs << "TODO: Implement task 2 tests" << endl << endl;
    
    // TODO: Test Task 3
    ofs << "--- Task 3: chaseTaxi ---" << endl;
    ofs << "TODO: Implement task 3 tests" << endl << endl;
    
    ofs << "===== Test Complete =====" << endl;
    ofs.close();
    
    // In thông báo ra console
    cout << "Test completed: " << testName << endl;
    cout << "Output saved to: " << outputFile << endl;
}

// Hàm trích xuất tên test case từ đường dẫn input
string getTestName(const string& inputPath) {
    size_t lastSlash = inputPath.find_last_of("/\\");
    size_t lastDot = inputPath.find_last_of(".");
    
    if (lastSlash == string::npos) lastSlash = 0;
    else lastSlash++;
    
    if (lastDot == string::npos || lastDot < lastSlash) {
        return inputPath.substr(lastSlash);
    }
    return inputPath.substr(lastSlash, lastDot - lastSlash);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        // Run specific test case from command line
        string inputFile = argv[1];
        
        // Tự động tạo tên file output trong tests/output/
        string testName = getTestName(inputFile);
        string outputFile = "tests/output/" + testName + "_output.txt";
        
        // Nếu user muốn đặt tên output khác
        if (argc > 2) {
            testName = argv[2];
        }
        
        runTestCase(inputFile, outputFile, testName);
    } else
    {


    }

    
    
    return 0;
}
