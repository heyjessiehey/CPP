//Name: Gayeon Ko
//Section: OPP244S
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Jan 23 2018
#define MAX_NO_OF_SAMPLES 20

void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);

