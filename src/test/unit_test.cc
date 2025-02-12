/*
 * Functions for testing convolution.h functions
 */

#include "test.h"
#include "conv_test.h"
#include "util_test.h"
#include "omp_test.h"

using namespace std;


int main(int argc, char *argv[]) {

    /* assemble structs with all tests */
    struct testType test0 = {"convUniform", 
                             "convolve a uniform grid", 
                             &convUniform};

    struct testType test1 = {"linearKernel",
                             "Check linear kernel has correct size and normalizes to 1", 
                             &linearKernel};

    struct testType test2 = {"areaStripSymmetry",
                             "Check area of strip above and below equator are the same",
                             &areaStripSymmetry};
    
    struct testType test3 = {"areaStripSumEqual",
                             "Sum of the area of strips should equal area of a sphere",
                             &areaStripSumEqual};

    struct testType test4 = {"convVerticalEdge",
                             "Chceck convolution across left right edge is correct",
                             &convVerticalEdge};

    struct testType test5 = {"convOverPoles",
                             "Chceck convolution across the upper/lower edge is correct",
                             &convOverPoles};

    /* assemble testType structs into single vector */
    vector<testType> allTests = {test0, test1, test2, test3, test4, test5};
    
    int success = allTests.size();       // counter for number of successful tests
    cout << endl;
    
    /* loop through test vector list */
    for (size_t i = 0; i < allTests.size(); i++) {
        cout << "Test " << i << ": " << allTests[i].testName << endl;
        cout << allTests[i].testDescription << endl;

        int result = allTests[i].testFunc();

        if (result != 0) {
            cout << "Test " << i << " failed" << endl;
            success--;
        }
        cout << endl;
    }

    cout << "******************* Test Results *******************" << endl;
    cout << "Successful Tests: " << success <<  "    " << "Total Tests: " << allTests.size() << endl;
    cout << "****************************************************" << endl;

    return 0;
}
