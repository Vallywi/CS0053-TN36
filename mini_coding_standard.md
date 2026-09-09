# Student Software Development & Coding Standard

This document outlines the core coding and development standards required for student programming projects. Adhering to these standards ensures clean, maintainable, readable, and version-controlled code.

---

## 1. File Naming
* **Rule 1.1:** Use `snake_case` or `lower_kebab-case` for source files and headers (e.g., `grade_analyzer.cpp`, `student_record.h`). Avoid spaces or special characters in filenames.

## 2. Variable Naming
* **Rule 2.1:** Use `camelCase` for local variables and parameters (e.g., `studentScore`, `totalSum`). Use clear, descriptive names rather than single-letter abbreviations, except for simple loop counters (`i`, `j`).
* **Rule 2.2:** Constants must be written in `UPPER_SNAKE_CASE` (e.g., `PASSING_GRADE_THRESHOLD`, `MAX_BUFFER_SIZE`).

## 3. Function & Method Naming
* **Rule 3.1:** Function names must begin with a verb and use `camelCase` describing the action performed (e.g., `calculateAverage()`, `findHighestGrade()`, `displaySummaryReport()`).

## 4. Class & Struct Naming
* **Rule 4.1:** Use `PascalCase` for classes, structs, and enumerations (e.g., `StudentReport`, `GradeCalculator`, `SortOrder`).

## 5. Formatting & Indentation
* **Rule 5.1:** Use consistent 4-space indentation per level. Do not mix tabs and spaces.
* **Rule 5.2:** Keep line length under 100 characters. Always place braces `{}` on dedicated lines or consistent K&R/Allman style throughout the project.

## 6. Documentation & Comments
* **Rule 6.1:** Include a header docblock at the top of every file specifying file name, author, purpose, and date.
* **Rule 6.2:** Document every non-trivial function with a summary comment describing parameters, return values, and pre/post-conditions.

## 7. Code Organization & Modularity
* **Rule 7.1:** Keep functions short and single-purposed (< 30 lines). Avoid duplicate code logic by extracting reusable helper functions.
* **Rule 7.2:** Eliminate magic numbers; declare named constants or `constexpr` variables.

## 8. Version Control Practices
* **Rule 8.1:** Commit frequently with imperative, descriptive commit messages (e.g., `Add grade threshold check`, `Fix out-of-bounds error in average loop`).
* **Rule 8.2:** Never commit compiled binary files (`.exe`, `.o`, `.out`) or IDE configurations to version control.

## 9. Testing & Debugging
* **Rule 9.1:** Always verify code with boundary test cases (e.g., empty arrays, zero values, max values) before committing.
* **Rule 9.2:** Use interactive debuggers (GDB/VS Code Debugger) to isolate runtime exceptions rather than rely exclusively on `cout` statements.

## 10. Responsible AI Assistance Guidelines
* **Rule 10.1:** Critical Evaluation: Never copy-paste AI-generated code without line-by-line inspection, compilation, and functional testing.
* **Rule 10.2:** Accountability: The student developer remains 100% accountable for all submitted code and must be capable of explaining every syntax construct used.
