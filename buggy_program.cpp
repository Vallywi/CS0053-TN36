#include <iostream>
#include <vector>

double calculateAverage(const std::vector<double>& grades) {
    double totalSum = 0.0;
    // INTENTIONAL BUG: Off-by-one error accessing grades.size() out-of-bounds (i <= grades.size())
    for (std::size_t i = 0; i <= grades.size(); ++i) {
        totalSum += grades[i];
    }
    return totalSum / grades.size();
}

int main() {
    std::vector<double> grades = {85.5, 92.0, 78.5, 64.0, 89.5};
    
    std::cout << "Calculating average..." << std::endl;
    double avg = calculateAverage(grades);
    std::cout << "Calculated Average: " << avg << std::endl;

    return 0;
}
