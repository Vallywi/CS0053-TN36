/**
 * @file improved_program.cpp
 * @brief Student Grade Analysis Program adhering to modern C++ coding standards.
 * @details Solves statistical calculations for student scores with robust type safety,
 *          modular function structure, and readable output presentation.
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

// Constants defining system thresholds
constexpr double PASSING_GRADE_THRESHOLD = 75.0;

/**
 * @brief Computes the arithmetic mean of a collection of grades.
 * @param grades Vector of student grade values.
 * @return Average grade as a double, or 0.0 if vector is empty.
 */
double calculateAverage(const std::vector<double>& grades) {
    if (grades.empty()) {
        return 0.0;
    }
    const double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / static_cast<double>(grades.size());
}

/**
 * @brief Finds the maximum grade value in the vector.
 * @param grades Vector of student grade values.
 * @return Highest grade value, or 0.0 if vector is empty.
 */
double findHighestGrade(const std::vector<double>& grades) {
    if (grades.empty()) {
        return 0.0;
    }
    return *std::max_element(grades.begin(), grades.end());
}

/**
 * @brief Counts the number of grades meeting or exceeding the passing threshold.
 * @param grades Vector of student grade values.
 * @param threshold Minimum score required to pass.
 * @return Number of passing students.
 */
std::size_t countPassingStudents(const std::vector<double>& grades, double threshold = PASSING_GRADE_THRESHOLD) {
    return std::count_if(grades.begin(), grades.end(), [threshold](double grade) {
        return grade >= threshold;
    });
}

/**
 * @brief Displays calculated statistical metrics for the student grades.
 * @param grades Vector of student grade values.
 */
void displaySummaryReport(const std::vector<double>& grades) {
    std::cout << "========================================\n";
    std::cout << "      STUDENT GRADE ANALYSIS REPORT     \n";
    std::cout << "========================================\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Students Recorded: " << grades.size() << "\n";

    const double totalSum = std::accumulate(grades.begin(), grades.end(), 0.0);
    std::cout << "Total Sum of Grades    : " << totalSum << "\n";
    std::cout << "Average Grade          : " << calculateAverage(grades) << "\n";
    std::cout << "Highest Grade Recorded : " << findHighestGrade(grades) << "\n";
    std::cout << "Passing Students (>=" << PASSING_GRADE_THRESHOLD 
              << "): " << countPassingStudents(grades) << "\n";

    std::cout << "========================================\n";
}

int main() {
    const std::vector<double> studentGrades = {85.5, 92.0, 78.5, 64.0, 89.5};

    displaySummaryReport(studentGrades);

    return 0;
}
