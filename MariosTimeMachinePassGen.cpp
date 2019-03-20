/**
 ************************************************************************************************************************
 *
 *  @file                   MariosTimeMachinePassGen.cpp
 *  @brief                  Mario's Time Machine! Password Generator
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   March 19th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   For use with the N.E.S. Version
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>
#include <stdint.h>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Get bits as int
 *
 * @param   tempArray Array holding area completion values
 * @param   start The starting int
 * @param   bits The number of bits as int
 *
 * @return  bits as int
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
uint32_t getBitsAsInt(uint32_t* tempArray, int start, int bits)
{
	uint32_t temp = 0x00;
	for (int i = start; i < (start + bits); i++)
	{
        if (tempArray[i] == 1)
        {
            temp |= (1 << (i - start));
        }
	}
	return temp & 0xFFFFFFFF;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Get user input
 *
 * @param   area The are to get input for
 *
 * @return  1 if area completed, 0 if not
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int getUserInput(string area)
{
    string input = "";
    int areaComplete = 0;
    while (true) {
        cout << area << "? (0 for no, 1 for yes): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> areaComplete)
        {
            if (areaComplete >= 0 && areaComplete <= 1)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }
    return areaComplete;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    const uint32_t x[3] = {26,15,21};
    const uint32_t y[3] = {14,4,19};

    uint32_t tempArray[6];
    uint32_t tempArray2[5];
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    int x80mBCComplete = 0;
    int x776BCComplete = 0;
    int x31BCComplete = 0;
    int x1192Complete = 0;
    int x1520Complete = 0;
    int x1602Complete = 0;
    int x1687Complete = 0;
    int x1862Complete = 0;
    int x1879Complete = 0;
    int x1903Complete = 0;
    int x1905Complete = 0;
    int x1947Complete = 0;
    int x1969Complete = 0;
    int x1989Complete = 0;
    int xrandom = 0;

    cout << "Mario is Missing! password generator v 1.0" << endl;
    cout << "For use with the N.E.S." << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    x80mBCComplete = getUserInput("80m B.C completed");
    x776BCComplete = getUserInput("776 B.C. completed");
    x31BCComplete = getUserInput("31 B.C completed");
    x1192Complete = getUserInput("1192 completed");
    x1520Complete = getUserInput("1520 completed");
    x1602Complete = getUserInput("1602 completed");
    x1687Complete = getUserInput("1687 completed");
    x1862Complete = getUserInput("1862 completed");
    x1879Complete = getUserInput("1879 completed");
    x1903Complete = getUserInput("1903 completed");
    x1905Complete = getUserInput("1905 completed");
    x1947Complete = getUserInput("1947 completed");
    x1969Complete = getUserInput("1969 completed");
    x1989Complete = getUserInput("1989 completed");
    xrandom = getUserInput("Random");

    // 80 BC to 1520
    tempArray2[0] = x80mBCComplete;
    tempArray2[1] = x776BCComplete;
    tempArray2[2] = x31BCComplete;
    tempArray2[3] = x1192Complete;
    tempArray2[4] = x1520Complete;
    i = getBitsAsInt(tempArray2, 0, 5);

    // 1602 to 1903 
    tempArray2[0] = x1602Complete;
    tempArray2[1] = x1687Complete;
    tempArray2[2] = x1862Complete;
    tempArray2[3] = x1879Complete;
    tempArray2[4] = x1903Complete; 
    j = getBitsAsInt(tempArray2, 0, 5);

    // 1905 to Random
    tempArray2[0] = x1905Complete;
    tempArray2[1] = x1947Complete;
    tempArray2[2] = x1969Complete;
    tempArray2[3] = x1989Complete;
    tempArray2[4] = xrandom; 
    k = getBitsAsInt(tempArray2, 0, 5);

    tempArray[0] = (i ^ x[0]) & 31;
    tempArray[1] = (j ^ x[1]) & 31;
    tempArray[2] = (k ^ x[2]) & 31;
    tempArray[3] = (i ^ y[0]) & 31;
    tempArray[4] = (j ^ y[1]) & 31;
    tempArray[5] = (k ^ y[2]) & 31;

    string password;
	for(int i = 0; i < 6; i++)
    {
        password += "0123456789?BCDFGHJKLMNPQRSTVWXYZ"[tempArray[i]];
    }
    cout << endl;
    cout << "Generated password: " << password << endl;

    return(0);
}

