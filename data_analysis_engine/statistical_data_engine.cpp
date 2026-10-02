#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std; // Allows use of standard library names without std::
/*************************************************************************************************/
// Function prototypes 
bool                dataChecks(const vector<double>& data, bool& negativeNumber); // checks data validation
void                bubbleSort(vector<double>& data); // sort data
double              calcMean(const vector<double>& data); // calculate mean
double              calcMedian(const vector<double>& data); // calculate median
vector<double>      calcMode(const vector<double>& data); // calculate mode
void                displayResults(const vector<double>& data); // display outcomes
bool                readFile(const string& filename, vector<double>& data); // read external files
bool                writeFile(const string& filename, const vector<double>& data); // generate a new file
/*************************************************************************************************/
int main() // main function
{
    vector<double> data;    // declares a vector to save datasets in
    // messages to inform user of the purpose of the program
    cout << "=====================================================================================\n";
    cout << "========================== Welcome to Bubble Sort Project ===========================\n";
    cout << "=====================================================================================\n";
    cout << "=     This program reads data from a file, sorts it using bubble sort, calculates   =\n";
    cout << "= statistics like (mean, median, mode, etc) and saves the sorted data to a new file.=\n";
    cout << "=====================================================================================\n\n\n";
    bool negativeNumber = false;
    string inputName; // declare a variable type string to save file name
    cout << "Enter the name of the input file (For Example: data.txt): "; // prompt user for a name
    cin >> inputName; // insert the name to a variable
    if (!readFile(inputName, data)) // invoke readFile function and checks its status
    {
        cerr << "Error reading file!" << endl;
        return 1; // exit program and inform user
    }
    if (!dataChecks(data, negativeNumber)) // invoke dataChecks function and checks its status
    {
        cerr << "File is empty!" << endl; // inform user that the file is empty
        cerr << "Program failed to complete successfully." << endl; 
        return 1; //if dataChecks return false the program is exit
    }
    if (negativeNumber)
    {
        cout << "The dataset provided contains a negative number(s)" << endl;
    }
    else
    {
        cout << "The file was read successfully and is not empty." << endl << endl; // process success
    }
    bubbleSort(data); // calls bubble sort function and pass data (vector) to it
    displayResults(data); // calls displayStats  function and pass data (vector) to it
    string outputName; // declare a string variable
    cout << "Please enter the output filename to save the console data: "; // ask user for a name
    cin >> outputName; // insert this name to the execited variable
    if (!writeFile(outputName, data)) // call readFile function and checks its status
    {
        cerr << "Error writing file!" << endl;
    }
    cout << "\nProgram completed successfully" << endl; // inform user that the program worked
    return 0; // return zero = program completed successfuly 
}
/*************************************************************************************************/
// This function read files and return a boolean value to show whether the program worked or not
bool readFile(const string& filename, vector<double>& data) 
{
    ifstream inFile(filename); // create an input fill stream called inFile
    if (!inFile)
    {
        return false; // file failed to open
    }
    double value; // declare a variable called value
    
    while (inFile >> value) // add data to (vector) "data"
    {
        data.push_back(value); // add each new value to the end of the vector
    }
   
    inFile.close(); // close file
    return true; // inform main function that the function worked
}
/*************************************************************************************************/
// This function checks for the data validation such if the file is empty or if there are negative values
bool dataChecks(const vector<double>& data, bool& negativeNumber) 
{
    if (data.empty()) // checks if file is empty
    {
        return false; // if the file is empty, return false
    }
    
    for (int i = 0; i < data.size(); i++) // loop through every element in the vector
    {
        if (data[i] < 0) // checks if the element is less than zero
        {
            negativeNumber = true;
            break; // inform user if the negative is detected then complete executing
        }
    }
   return true; // return true if the function worked
}
/*************************************************************************************************/
// This function sorts data in ascending order
void bubbleSort(vector<double>& data)
{
    const int LENGTH = data.size(); // declare variable for data size
    bool swapped; // declare variabel to track swaps
    int i = 0; 
    do // utilize do while loop to go through data one time at least
    {
        swapped = false; // swap is set to false as no swaps occured yet
        for (int j = 0; j < LENGTH - 1 - i; j++)  // loop through elements and reduce range after each pass
        {    
            if (data[j] > data[j + 1]) // compare the adjacent elements
            {         
                double temp = data[j]; // declare a temporarily variable
                data[j] = data[j + 1]; // switch the values
                data[j + 1] = temp; 
                // insert the value of element data[j+1] to the temporarily variable to aviod lossing data
                swapped = true; // after the swap happened set swapped variable to true
            }
        }
        i++; // increase i by one
    } while (swapped); // if swap occured go through the loop again
}
/*************************************************************************************************/
// This function calculates the mean of the dataset
double calcMean(const vector<double>& data)
{
    const int LENGTH = data.size(); // declare a constant variable 
    double sum = 0, mean =0; // declare 2 variables, sum and mean 
   
    for (int i = 0; i < LENGTH; i++) // loop through all elements
    {
        sum = sum + data[i]; // add each new element to the previous ones
    }
    mean = sum / LENGTH; // divide the final sum by number of elements
    return mean; // return mean after the function is called
}
/*************************************************************************************************/
// This function calculates the median of the dataset
double calcMedian(const vector<double>& data)
{
    const int LENGTH = data.size(); // declare variable for data size
    double median = 0; // declare variable for median
    
    if (LENGTH % 2 == 0) // if the integer division of LENGTH is zero = LENGTH is even
    {
        median = (data[((LENGTH / 2) - 1)] + data[(LENGTH / 2)]) / 2.0;
        // add the two middle number and divide them by two 
    }
    else // LENGTH is odd
    {
        median = (data[LENGTH / 2]); // pick the middle number
    }
    return median; // return median after function is called
}
/*************************************************************************************************/
// This function finds the mode(s) of the dataset
vector<double> calcMode(const vector<double>& data)
{
    vector<double> modes; 
    // declare a vector to save mode(s) in as the number of modes is not known
    int maxFrequency = 1, frequency = 1; // declare vaiable to save max frequency in 
    for (int i = 1; i < data.size(); i++) // loop through the dataset
    {
        // when the data is sorted the if the number appers twic it will appear adjacent to each other
        if (data[i] == data[i - 1])
            frequency++; // increase frequency by one
        else
            frequency = 1; // keep frequency as it is
        if (frequency > maxFrequency) // asgin frequency to max frequency if it is greater
            maxFrequency = frequency;
    }
    
    if (maxFrequency == 1) // max frequency did not change so there is no mode = empty vector
        return modes;
    frequency = 1;
    for (int i = 1; i < data.size(); i++) // loop through data
    {
        if (data[i] == data[i - 1]) // count frequency of each element
            frequency++;
        else
            frequency = 1;
        if (frequency == maxFrequency) // if the element frequency = max frequency add it to modes
        {
            // add the new number after checking that the number is not added already (safety)
            if (modes.empty() || modes.back() != data[i])
                modes.push_back(data[i]);
        }
    }
    return modes; // return modes (vector) after the function is called
}
/*************************************************************************************************/
// This function display the sorted data and the statistics of the dataset
void displayResults(const vector<double>& data)
{
    const int LENGTH = data.size(); // declare constant variable to save size 
    string displayData; // declare vaiable to save user respond
    cout << "Do you want to display sorted data (Please write yes or no): ";
    // ask user if sorted data want to be displayed (any answer except yes would be considered as no)
    cin >> displayData; // save his respond
    cout << endl; // end line
    if (displayData == "yes") // compare his respond
    {
        // if user respond is yes the sorted data will be displayed
        cout << "=======================================================" << endl;
        cout << "The sorted data stored in the file are: " << endl << endl;
        for (int x = 0; x < LENGTH; x++) // loop through elements
        {
            cout << setw(20) << right << data[x] << endl; 
            // print each element in the middle of a separite line 
        }
        cout << "=======================================================" << endl;
    }
    const double* ptr = &data[0]; // Points to first element of vector
    double minimum = *ptr;   // First element (minimum in sorted data)
    double maximum = *(ptr + LENGTH - 1); // Last element (maximum in sorted data)
    // output statistics
    cout << endl << "The Measures of Central Tendency and Spread are as follow: " << endl << endl;
    cout << "Length: " << LENGTH << endl; // print data size
    cout << "Minimum: " << minimum << endl; // minimum = first element in sorted data
    cout << "Maximum: " << maximum << endl; // maximum = last element in sorted data
    cout << "Mean: " << calcMean(data) << endl; // print mean by calling mean function
    cout << "Median: " << calcMedian(data) << endl; // print median by calling median function
    const vector<double> MODES = calcMode(data); // constant vector to ensure data safety
    if (MODES.empty()) // checks what inside the vector
    {
        // if empty = no mode
        cout << "Mode: No mode (all values are unique)" << endl;
    }
    else // not empty = there is mode(s)
    {
        const int LENGTH2 = MODES.size(); // constant varialbe to save vector size
        cout << "Mode: ";
        for (int i = 0; i < LENGTH2; i++) // loop through the vector of modes
        {
            // Print all modes with proper punctuation
            if (i < LENGTH2 - 2)
                cout << MODES[i] << " , ";
            else if (i < LENGTH2 - 1)
                cout << MODES[i] << " and ";
            else
                cout << MODES[i] << endl; 
        }
    }
    cout << "=======================================================" << endl;
    cout << endl; // end of dislayResults() function
}
/*************************************************************************************************/
// This function write the sorted data to a external file 
bool writeFile(const string& filename, const vector<double>& data)
{
    ofstream outFile(filename); // create an output fill stream called outFile
    if (!outFile) 
    {
        cerr << "Error: could not create file " << filename << "'\n";
        return false; // file failed to creat
    }
    for (double value : data) // loop that goes until no more data is in the vector
    {
        outFile << value << endl; // print elements in the new file
    }  
    outFile.close(); // close file
    cout << "Sorted data saved in " << filename << " successfully.\n"; // inform user of success 
    return true; // return true = function proceed successufly 
}
/*************************************************************************************************/