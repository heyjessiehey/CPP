
#include <iostream>


namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
    template <typename T>
    T max(const T* data, int N){
        int num = SMALLEST_NUMBER;
        for(int i=0; i<N; ++i){
            if(num < data[i])
                num = data[i];
        }
        return num;
    }

	// min returns the smallest item in data
	//
    template <typename T>
    T min(const T* data, int N){
        int num = LARGEST_NUMBER;
        for(int i=0; i<N; ++i){
            if(num > data[i])
                num = data[i];
        }
        return num;
    }
        
	// sum returns the sum of n items in data
	//    
    template <typename T>
    T sum(const T* data, int N){
        int sum = 0;
        for(int i=0; i<N; ++i){
            sum += data[i];
        }
        return sum;
    }
    
	// average returns the average of n items in data
	//
    template <typename T>
    double avg(const T* data, int N){
        double avg =0, total=0;
        total = sum(data, N);
        avg = total / N;
        return avg;
    }
    
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
    template <typename T>
    bool read(std::istream& input, T* data, int N){
        char comma;
        for(int i=0; i<N; ++i){
            T num;
            input >> comma;
            if(comma != ',')
                return false;
            if(input >> num)
                data[i] = num;
            else
                return false;
        }
        return true;
    }
    
	// display inserts n items of data into std::cout
	//
    template <typename T>
    void display(const char* name, const T* data, int N){
        std::cout.width(20);
        std::cout << std::right << name;
        for(int i=0; i<N; ++i){
            std::cout.width(COLUMN_WIDTH);
            std::cout << data[i];
        }
	std::cout << std::endl;
    }
    
	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

