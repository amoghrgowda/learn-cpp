// Each function will be designed to potentially throw a different type of standard exception. In the main function, we'll call these functions within try-catch blocks to demonstrate how to handle these exceptions.

#include <iostream>     // For std::cout, std::cerr, std::endl
#include <vector>       // For std::vector
#include <string>       // For std::string
#include <stdexcept>    // For standard exception classes like std::out_of_range, std::invalid_argument, etc.
#include <new>          // For std::bad_alloc

// Function that might throw std::out_of_range
void accessVectorElement(const std::vector<int>& vec, int index) {
    std::cout << "\nAttempting to access element at index " << index << "..." << std::endl;
    if (index < 0 || index >= vec.size()) {
        // Manually throwing for clarity, vec.at(index) would also throw
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range for vector of size " + std::to_string(vec.size()));
    }
    std::cout << "Element at index " << index << " is: " << vec.at(index) << std::endl; // vec.at() also throws std::out_of_range
}

// Function that might throw std::invalid_argument
double calculateSquareRoot(double num) {
    std::cout << "\nAttempting to calculate square root of " << num << "..." << std::endl;
    if (num < 0) {
        throw std::invalid_argument("Cannot calculate square root of a negative number: " + std::to_string(num));
    }
    // For simplicity, we're not actually calculating sqrt here, just checking the argument.
    // In a real scenario, you'd use std::sqrt from <cmath>
    return num; // Placeholder
}

// Function that might throw a generic std::runtime_error
void performRiskyOperation(bool shouldFail) {
    std::cout << "\nPerforming a risky operation..." << std::endl;
    if (shouldFail) {
        throw std::runtime_error("The risky operation failed as instructed!");
    }
    std::cout << "Risky operation succeeded!" << std::endl;
}

// Function that might throw std::length_error
void createLargeString(size_t size) {
    std::cout << "\nAttempting to create a string of size " << size << "..." << std::endl;
    try {
        std::string veryLongString;
        // std::string::max_size() is the theoretical limit.
        // We'll try a large, but not necessarily max_size(), value.
        // Actual failure point depends on system memory and std::string implementation.
        if (size > veryLongString.max_size() / 2 ) { // Heuristic to suggest a very large size
             throw std::length_error("Requested string size is too large: " + std::to_string(size));
        }
        veryLongString.resize(size); // This might throw std::length_error or std::bad_alloc
        std::cout << "Successfully created a string of size " << size << "." << std::endl;
    } catch (const std::length_error& le) {
        // Re-throw if we want the caller to handle it, or handle it here
        // For this example, we explicitly throw to demonstrate catching std::length_error.
        // If resize itself threw, we wouldn't need this explicit throw for length_error
        throw; // Re-throws the caught exception. Throws it to the 
    }
    // Note: std::string::resize can also throw std::bad_alloc if memory runs out
}

// Function that attempts to cause std::bad_alloc
void allocateHugeMemory() {
    std::cout << "\nAttempting to allocate a huge amount of memory..." << std::endl;
    try {
        // Attempt to allocate an extremely large array (e.g., several gigabytes)
        // The exact size to trigger bad_alloc depends on your system's available memory.
        // Using a very large number of long doubles.
        // (~2 billion * 16 bytes = ~32 GB, likely to fail on most systems)
        size_t numElements = 2000000000; // This is a very large number
        long double* massiveArray = new long double[numElements];

        // If allocation succeeds (unlikely for this size), do something to prevent optimization
        std::cout << "Amazingly, massive memory allocation succeeded (this is rare for such a size!)." << std::endl;
        massiveArray[0] = 1.0; // Touch the memory
        delete[] massiveArray;
    } catch (const std::bad_alloc& ba) {
        std::cerr << "Caught std::bad_alloc inside allocateHugeMemory: " << ba.what() << std::endl;
        throw; // Re-throw to be caught in main
    }
}

int main() {
    std::vector<int> myVector = {10, 20, 30};

    // 1. Test std::out_of_range
    try {
        accessVectorElement(myVector, 1);    // Valid access
        accessVectorElement(myVector, 5);    // Invalid access, should throw
    } catch (const std::out_of_range& oor) {
        std::cerr << "Error (std::out_of_range): " << oor.what() << std::endl;
    } catch (const std::exception& e) { // Catch any other standard exceptions
        std::cerr << "A standard exception occurred: " << e.what() << std::endl;
    }

    // 2. Test std::invalid_argument
    try {
        calculateSquareRoot(25.0);  // Valid argument
        calculateSquareRoot(-5.0);  // Invalid argument, should throw
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Error (std::invalid_argument): " << ia.what() << std::endl;
    }

    // 3. Test std::runtime_error
    try {
        performRiskyOperation(false); // Should succeed
        performRiskyOperation(true);  // Should fail and throw
    } catch (const std::runtime_error& rte) {
        std::cerr << "Error (std::runtime_error): " << rte.what() << std::endl;
    }

    // 4. Test std::length_error
    try {
        createLargeString(100);        // Small string, likely fine
        createLargeString(std::string().max_size()); // Very large, likely to throw std::length_error or std::bad_alloc
    } catch (const std::length_error& le) {
        std::cerr << "Error (std::length_error): " << le.what() << std::endl;
    } catch (const std::bad_alloc& ba) { // std::string operations can also throw bad_alloc
        std::cerr << "Error (std::bad_alloc from string): " << ba.what() << std::endl;
    }


    // 5. Test std::bad_alloc (Memory allocation failure)
    // This is less predictable and might make your system slow or kill the program
    // depending on OS and available memory.
    std::cout << "\n--- Testing std::bad_alloc (this might take a moment or fail dramatically) ---" << std::endl;
    try {
        allocateHugeMemory();
    } catch (const std::bad_alloc& ba) {
        std::cerr << "Error (std::bad_alloc from new): " << ba.what() << std::endl;
    } catch (const std::exception& e) { // Fallback for any other exceptions
        std::cerr << "An unexpected standard exception occurred during memory allocation test: " << e.what() << std::endl;
    }


    // 6. Catching base std::exception
    std::cout << "\n--- Testing catching by base std::exception ---" << std::endl;
    try {
        // Let's trigger one of the previous errors again
        accessVectorElement(myVector, 10);
    } catch (const std::exception& e) { // This will catch any standard exception
        std::cerr << "Caught a standard exception (using base class): " << e.what() << std::endl;
        // We can find out the actual type if needed using RTTI (Run-Time Type Information)
        // but that's a more advanced topic. For now, .what() is very useful.
    }

    // 7. What happens if an exception is not caught?
    // std::cout << "\n--- Demonstrating an unhandled exception (program will terminate) ---" << std::endl;
    // Note: Uncommenting the line below will likely cause the program to terminate abruptly
    // after printing an error message to stderr, because no try-catch block in main handles it directly here.
    // throw std::runtime_error("This is an unhandled exception demonstration!");

    std::cout << "\nProgram finished successfully after handling exceptions." << std::endl;
    return 0;
}
