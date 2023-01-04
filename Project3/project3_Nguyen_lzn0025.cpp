//  Long Nguyen
//  project3_Nguyen_lzn0025.cpp
//  Project 3
//
//  Created by Long Nguyen on 10/8/22.
//  I combined both code samples on hint to finish this project.
//  I also refer the discussion on the GroupMe to finish my readfile and main part.

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

//Input: (1) Array storing data retrieved from the file (i.e., instream)
//       (2) input file stream object
//Output: Size of array. Note: you need to use this parameter to control the array size.

//1. array_size <- readfile(inputArray[], instream)
int readfile(int inputArray[], ifstream& inStream) {
    int index = 0;
 
    inStream >> inputArray[index];
    while (!inStream.eof()) {
        index++;
        inStream >> inputArray[index];
    }
     
    return index;
}


// 2. outputArray_size <- sort(inputArray1[], inputArray1_size, inputArray2[], inputArray2_size, outputArray[])
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    int outputArray_size = inputArray1_size + inputArray2_size;

        for (int i = 0; i < inputArray1_size; i++) {
            outputArray[i] = inputArray1[i];
        }

        for (int j = 0; j < inputArray2_size; j++) {
            outputArray[inputArray1_size + j] = inputArray2[j];
        }

        for (int k = 0; k < outputArray_size; k++) {
            int l = outputArray[k];
            int m = k;

            while(m > 0 && l < outputArray[m - 1]) {
                outputArray[m] = outputArray[m - 1];
                m--;
            }

            outputArray[m] = l;
        }

        cout << endl;
        return inputArray1_size + inputArray2_size;
    }

// 3. void <- writefile(outputArray[], outputArray_size)
void writefile(int outputArray[], int outputArray_size) {
    string outputFilename;
    ofstream outStream;
    cout << "Enter the output file name: ";
    cin >> outputFilename;;
    
    outStream.open((char*)outputFilename.c_str());
    if (outStream.fail()) {
        exit(1);
    } else {
        for (int i = 0; i < outputArray_size; i++) {
            outStream << outputArray[i] << endl;;
        }
    }
        
    
    outStream.close();
    
    cout << "*** Please check the new file - " << outputFilename << " ***" << endl;
    cout << "*** Goodbye. *** ";
}

int main( )
{
    ifstream inStream;
    cout << "*** Welcome to Long's sorting program ***" << endl;
    // Scan and read input1.txt
    int iArray1[MAX_SIZE];
    int iArray1_size;
    string input1;
    
    cout << "Enter the first input file name: ";
    cin >> input1;
    
    inStream.open((char*)input1.c_str());
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
 
    iArray1_size = readfile(iArray1, inStream);
    inStream.close();
    
    cout << "The list of " << iArray1_size << " numbers in file " << input1 << " is: " << endl;
    for (int i = 0; i < iArray1_size; i++) {
        cout << iArray1[i] << endl;
    }
    
    cout << endl;
    
    // Scan and read input2.txt
    int iArray2[MAX_SIZE];
    int iArray2_size;
    string input2;
    cout << "Enter the second input file name: ";
    cin >> input2;
    
    inStream.open((char*)input2.c_str());
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
 
    iArray2_size = readfile(iArray2, inStream);
    inStream.close();
    cout << "The list of " << iArray2_size << " numbers in file " << input2 << " is: " << endl;
    for (int i = 0; i < iArray2_size; i++) {
        cout << iArray2[i] << endl;
    }
    
    // Output
    int iOutput[MAX_SIZE];
    int iOutput_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, iOutput);
    
    cout << "The sorted list of " << iOutput_size << " numbers is: ";
    for (int i = 0; i < iOutput_size; i++) {
        cout << iOutput[i] << " ";
    }
    cout << endl;

    writefile(iOutput, iOutput_size);
    
    return 0;
    
}
