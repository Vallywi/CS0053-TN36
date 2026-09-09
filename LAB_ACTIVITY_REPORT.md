# Laboratory Activity Report: Exploring Software Development Tools and Standards with AI Assistance

**Course:** Programming Tools and Techniques  
**Laboratory Title:** Exploring Software Development Tools and Standards with AI Assistance  
**Language Environment:** C++ (GCC 13.2 / MinGW-w64, Visual Studio Code)  
**Version Control System:** Git 2.4x  
**Duration:** 1–2 hours  

---

## Part A – Identify Software Development Tools

### Development Tools Summary Table

| Development Tool | Tool Used | Purpose |
| :--- | :--- | :--- |
| **Code Editor / IDE** | Visual Studio Code / MinGW GCC | Provides a graphical code editor with syntax highlighting, auto-completion, and integrated build/debug workflows. |
| **Compiler / Interpreter** | GCC (`g++` C++17) | Translates human-readable C++ source code into machine-executable binary code (`.exe`). |
| **Version Control** | Git | Tracks file modifications, manages revision history, and enables branching, merging, and change auditing. |
| **Debugger** | GDB / VS Code Debugger | Pauses program execution, steps through instructions, inspects memory/variables, and diagnoses runtime errors. |
| **Code Formatter** | Clang-Format / IDE Auto-Formatter | Automatically enforces consistent code layout, indentation, line breaks, and bracket placement. |
| **Linter / Static Analyzer** | Clang-Tidy / GCC Compiler Flags (`-Wall -Wextra`) | Analyzes source code without execution to detect potential bugs, type mismatches, and style violations. |
| **AI Assistant** | Antigravity AI (Gemini Flash Model) | Performs automated code reviews, refactoring recommendations, prompt-driven debugging, and standards enforcement. |

---

### AI-Assisted Task: Role of Software Development Tools

#### AI Prompt Used:
> *I am learning about software development tools. Explain the role of an IDE, compiler/interpreter, version control system, debugger, formatter, linter, testing tool, and AI coding assistant. For each tool, explain what problem it solves during software development.*

#### Explanation of Tool Roles and Problems Solved:

1. **Integrated Development Environment (IDE) / Code Editor**
   - **Role:** Central workspace combining editing, building, debugging, and file management tools.
   - **Problem Solved:** Prevents context-switching between separate terminal text editors, file managers, and build scripts by providing syntax highlighting, symbol navigation, and integrated tooling.

2. **Compiler / Interpreter**
   - **Role:** Converts high-level source code into binary machine code (compiler) or interprets instructions line-by-line (interpreter).
   - **Problem Solved:** Bridges the abstraction gap between human-readable logic and hardware-level execution while checking syntax correctness.

3. **Version Control System (VCS)**
   - **Role:** Records code changes in a structured time-series repository.
   - **Problem Solved:** Eliminates accidental code loss, overwriting, and manual file copy backups (`main_v2_final.cpp`); allows painless rollbacks and collaborative team development.

4. **Debugger**
   - **Role:** Executes code under controlled monitoring with breakpoints, call stack evaluation, and variable inspection.
   - **Problem Solved:** Replaces blind guessing and ad-hoc print logging by pinpointing the precise line and state condition causing runtime crashes or logic defects.

5. **Code Formatter**
   - **Role:** Standardizes visual code styling (spacing, indentation, brace alignment).
   - **Problem Solved:** Resolves team arguments over formatting styles and prevents readable code degradation caused by inconsistent developer habits.

6. **Linter / Static Analyzer**
   - **Role:** Inspects code structure statically against best-practice rules and potential defect patterns.
   - **Problem Solved:** Identifies subtle vulnerabilities, dead code, uninitialized variables, and type conversion defects before code is compiled or deployed.

7. **Testing Tool**
   - **Role:** Automates execution of test suites (unit testing, integration testing).
   - **Problem Solved:** Prevents regressions by automatically verifying that new features or bug fixes do not break existing functionality.

8. **AI Coding Assistant**
   - **Role:** Context-aware code synthesis, review, refactoring, and explanation partner.
   - **Problem Solved:** Accelerates boilerplate writing, clarifies complex compiler diagnostics, suggests architectural improvements, and speeds up feature prototyping.

---

## Part B – Examine a Sample Program

### Program Examination Details
- **Program File:** [sample_program.cpp](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/sample_program.cpp)
- **Program Purpose:** Calculates statistical metrics (sum, average, highest grade, passing count) for a group of student grades.
- **Inputs:** Hardcoded array of 5 double values (`85.5`, `92.0`, `78.5`, `64.0`, `89.5`).
- **Outputs:** Terminal text output showing total student count, grade sum, average, highest score, and number of passing students.

### Initial Observations Table

| No. | Observation | Possible Improvement |
| :--- | :--- | :--- |
| 1 | Global array `arr[100]` and global variable `st_cnt = 5` pollute the global namespace and use raw C-style arrays. | Use `std::vector<double>` encapsulated within functions or local scope in `main()`. |
| 2 | Inconsistent naming conventions (`st_cnt`, `Total_Sum`, `calc_avg`, `get_highest_Grade`, variable `x`). | Apply consistent `camelCase` for variables/functions and `UPPER_SNAKE_CASE` for constants. |
| 3 | Duplicated iteration loops: grade sum is calculated twice (once inside `calc_avg()` and again in `main()`). | Eliminate duplicate calculation in `main()` by delegating entirely to the helper function. |
| 4 | Poor code formatting and indentation (missing spaces around operators, uneven block indentation, missing blank lines). | Format using 4-space indentation, consistent spacing around binary operators, and standard brace placement. |
| 5 | Hardcoded magic number `75.0` used directly in conditional grade check without explanation. | Define a named constant `constexpr double PASSING_GRADE_THRESHOLD = 75.0;`. |

---

## Part C – AI-Assisted Code Review

### Suggested AI Review Prompt
> *Act as a software development code reviewer. Review the following program for readability, maintainability, naming conventions, formatting, unnecessary repetition, possible errors, and coding-standard violations. Do not rewrite the code yet. Explain each issue and recommend an improvement.*

### AI Recommendation Evaluation Table

| AI Recommendation | Accept / Reject | Reason |
| :--- | :--- | :--- |
| **1. Replace raw C-style array with `std::vector<double>`** | **Accept** | Dynamic vectors eliminate hardcoded maximum capacity limits (`[100]`) and offer standard library bounds protection and iterator support. |
| **2. Standardize function naming to `camelCase`** | **Accept** | `calc_avg()` and `get_highest_Grade()` mix conventions. Standardizing to `calculateAverage()` and `findHighestGrade()` improves readability. |
| **3. Extract passing grade threshold into `constexpr` constant** | **Accept** | Hardcoded literals (`75.0`) reduce maintainability if pass/fail requirements change. Named constants clarify intent. |
| **4. Use `<numeric>` standard algorithm `std::accumulate`** | **Accept** | Hand-rolled loops for summation are verbose and prone to indexing errors. `std::accumulate` is self-documenting and optimized. |
| **5. Automatically read grades from an external database API** | **Reject** | Over-engineering for a simple student laboratory exercise. File or vector input is sufficient for the target scope. |

---

## Part D – Apply Coding Standards

### Analysis of Standards Areas

#### 1. Naming Conventions
- **Variables:** Replaced cryptic names like `arr`, `st_cnt`, `s`, `h`, `p`, `x` with descriptive identifiers like `studentGrades`, `totalSum`, `highestGrade`, `passingCount`.
- **Constants:** Introduced `constexpr double PASSING_GRADE_THRESHOLD = 75.0;`.
- **Functions:** Renamed functions to active verb phrases: `calculateAverage()`, `findHighestGrade()`, `countPassingStudents()`, `displaySummaryReport()`.

#### 2. Formatting
- Enforced 4-space indentation throughout.
- Added spaces around assignment and comparison operators (`i = 0; i < size; ++i`).
- Kept function signatures and statements within 100 characters per line.
- Organized code with clean vertical whitespace separating logical sections.

#### 3. Code Organization
- Removed global variables entirely; data is passed explicitly via `const std::vector<double>&` to preserve immutability.
- Consolidated output generation into a dedicated function `displaySummaryReport()`.
- Added Doxygen comment blocks (`/** ... */`) to document function behaviors, parameters, and return values.

#### 4. Readability
- Code is now self-documenting. Any C++ programmer can immediately understand the program logic without stepping through unformatted loop constructs.

---

## Part E – Use a Formatter and Linter

### Formatter and Linter Results Table

| Tool | Issues Found | Changes/Suggestions |
| :--- | :--- | :--- |
| **Formatter (Clang-Format / VS Code)** | - Missing whitespace around operators (`Total_Sum=Total_Sum+arr[i]`) <br>- Irregular block indentation in `calc_avg()` | Applied uniform 4-space indentation and standard C++ operator spacing. |
| **Linter (GCC `-Wall -Wextra`)** | - Implicit conversion warnings between signed/unsigned loop indices (`int i` vs container size) | Updated loop counters and size types to `std::size_t` and `static_cast<double>()`. |
| **IDE Inspection (VS Code C++)** | - Global variable declaration warnings (`st_cnt`, `arr`) <br>- Unused include `<cmath>` | Removed unnecessary `<cmath>` header and moved global variables into local function scope. |

---

### Comparison of Review Methods Table

| Review Method | Example Issue Found |
| :--- | :--- |
| **Student / Human Review** | Identified redundant grade summation loop present in both `calc_avg()` and `main()`. |
| **Formatter / Linter** | Identified missing spaces around operators and implicit signed-to-unsigned integer comparison warnings (`int i` vs `size_t`). |
| **AI Assistant** | Suggested replacing raw loop constructs with standard algorithms (`std::accumulate`, `std::count_if`) and implementing `constexpr` constants. |

#### Synthesis Answer:
**Which method provided the most useful feedback, and why?**  
> *The **AI Assistant combined with Human Review** provided the most useful feedback overall. While linters and formatters excel at automated syntax enforcement and rule checking, AI contextualizes logic flaws and suggests high-level architectural improvements (such as adopting `std::vector` and algorithm headers). Human review remains crucial to filter out over-engineered AI suggestions and ensure changes align with project goals.*

---

## Part F – AI-Assisted Refactoring

### Suggested Refactoring Prompt
> *Refactor the following code according to appropriate coding standards. Improve naming, formatting, readability, and maintainability without changing the program's intended behavior. Explain the major changes you made.*

### Code Changes Documentation Table

| Original Code / Practice | Improved Version | Reason for Change |
| :--- | :--- | :--- |
| `double arr[100] = {85.5, ...};` | `const std::vector<double> studentGrades = {85.5, ...};` | Prevents buffer overflow risks and eliminates fixed array sizing. |
| `double calc_avg() { ... for loop ... }` | `double calculateAverage(const std::vector<double>& grades)` | Pass by `const` reference prevents unnecessary memory copying and guarantees immutability. |
| Hand-written summation loops in `main()` and `calc_avg()` | `std::accumulate(grades.begin(), grades.end(), 0.0)` | Replaces verbose manual loops with safe, readable standard library algorithms. |
| Hardcoded threshold `if (arr[i] >= 75.0)` | `constexpr double PASSING_GRADE_THRESHOLD = 75.0;` | Centralizes configuration constants for maintainability and readability. |

---

## Part G – Version Control Activity

### Git Execution Sequence Log
```bash
# Initialize repository
git init

# Stage and commit original program
git add sample_program.cpp
git commit -m "Initial version of sample program"

# Add improved code, buggy code, ignore file, and standard document
git add .
git commit -m "Improve code formatting and naming conventions"
```

### Git Commit Log Output (`git log --stat`)
```text
commit 3564f1021b11087788578d75fc194e87630702b0
Author: Student Developer <student@example.com>
Date:   Wed Sep 9 16:27:47 2026 +0800

    Improve code formatting and naming conventions

 .gitignore              |  4 +++
 buggy_program.cpp       | 21 +++++++++++++
 improved_program.cpp    | 82 +++++++++++++++++++++++++++++++++++++++++++++++++
 mini_coding_standard.md | 42 +++++++++++++++++++++++++
 4 files changed, 149 insertions(+)

commit 6954776f682ca241f1366ac05af0b1dddc55667b
Author: Student Developer <student@example.com>
Date:   Wed Sep 9 16:27:18 2026 +0800

    Initial version of sample program

 sample_program.cpp | 55 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 55 insertions(+)
```

---

### Part G Questions & Answers

1. **What files were modified?**  
   - `sample_program.cpp` was initially added. In the second commit, `improved_program.cpp`, `buggy_program.cpp`, `mini_coding_standard.md`, and `.gitignore` were tracked.

2. **What changes are shown in the version history?**  
   - The version history shows an initial snapshot of the original unformatted sample program (55 line insertions) followed by a refactoring commit adding 149 lines introducing standard-compliant code, mini development standards, and debugging code.

3. **Why is version control important when using AI-generated code?**  
   - AI models can generate plausible-sounding but functionally flawed code. Version control provides an immutable history that isolates AI experiments into separate commits or branches, allowing developers to audit diffs before merging.

4. **How can Git help if an AI-generated change introduces an error?**  
   - If an AI-suggested refactoring breaks existing code, developers can use `git diff` to inspect exact line changes, `git checkout` or `git revert` to undo the commit, or `git bisect` to locate the commit where the regression occurred.

---

## Part H – Debugging with AI Assistance

### Debugging Scenario & Investigation
- **Buggy Program File:** [buggy_program.cpp](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/buggy_program.cpp)
- **Introduced Fault:** Off-by-one loop boundary condition (`i <= grades.size()`) in `calculateAverage()`.
- **Observed Behavior:** The loop iterates 6 times for a 5-element vector, attempting to access memory at index `5` (`grades[5]`), which is out-of-bounds undefined behavior.
- **Relevant Variable Values during execution:**
  - `grades.size() = 5`
  - Valid indices: `0, 1, 2, 3, 4`
  - Index `i = 5` read arbitrary heap/stack memory (`0.0`), producing incorrect arithmetic or potential crash.
- **Location:** Line 7 of `buggy_program.cpp`.
- **Suspected Cause:** Use of `<=` instead of `<` in the loop continuation check.

---

### AI Debugging Prompt & Diagnosis

#### Prompt:
> *The following C++ program is producing incorrect average results: `buggy_program.cpp`. Based on the source code and loop behavior, identify possible causes. Explain your reasoning and suggest a correction.*

#### AI Diagnosis Output:
> *The error is caused by an **off-by-one index error** on line 7: `for (std::size_t i = 0; i <= grades.size(); ++i)`. In C++, `std::vector` indexing is zero-based, meaning valid indices range from `0` to `grades.size() - 1`. The condition `i <= grades.size()` attempts to access `grades[5]`, causing undefined behavior. Correct the condition to `i < grades.size()` or use a range-based for loop `for (double g : grades)`.*

#### Comparison & Evaluation:
**Did the AI identify the same problem? Explain.**  
> *Yes, the AI accurately identified the off-by-one loop indexing condition (`i <= grades.size()`). It correctly explained zero-based vector indexing in C++ and recommended the exact fix (`i < grades.size()`) as well as a safer alternative (range-based `for` loop).*

---

## Part I – Mini Software Development Standard

The mini development standard document was created as a standalone reference file: [mini_coding_standard.md](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/mini_coding_standard.md).

### Standard Overview:
1. **File Naming:** Use `snake_case` or `kebab-case` for source and header files.
2. **Variable Naming:** Use `camelCase` for variables/parameters and `UPPER_SNAKE_CASE` for constants.
3. **Function Naming:** Use verb-first `camelCase` (e.g., `calculateAverage`).
4. **Class Naming:** Use `PascalCase` for structs/classes (e.g., `StudentReport`).
5. **Indentation:** Use consistent 4-space indentation; keep lines under 100 chars.
6. **Comments:** Include top-of-file header docblocks and function parameter descriptions.
7. **Code Organization:** Keep functions focused (< 30 lines) and avoid magic numbers.
8. **Version Control:** Commit frequently with atomic, imperative commit messages.
9. **Testing:** Verify code with boundary cases before committing.
10. **Responsible AI Usage:** Inspect and test 100% of AI-generated code before adoption.

---

## Part J – Reflection Answers

1. **Which software development tool was most useful during the activity? Why?**  
   > *The Git version control system was the most useful tool during this activity. It provided a safety net while evaluating AI recommendations and refactoring code, allowing clear tracking of every modification between the original and improved versions.*

2. **What is the difference between a formatter, linter, and debugger?**  
   > *A formatter automatically adjusts code layout and style without affecting syntax rules. A linter performs static analysis to find potential logic defects, type warnings, and bad practices before compilation. A debugger monitors active runtime execution, allowing developers to inspect variable states and step through code during execution.*

3. **How do coding standards improve software quality?**  
   > *Coding standards establish uniformity across a codebase, reducing cognitive load when developers read each other's code. They minimize common syntax errors, enforce modern language practices, and make long-term maintenance significantly easier.*

4. **What recommendations did the AI provide that you decided not to follow? Why?**  
   > *The AI suggested adding external file parsing and database connection drivers to store student records. This recommendation was rejected because it introduced unnecessary complexity for a simple 5-student lab exercise.*

5. **What advantages does AI provide during code review and refactoring?**  
   > *AI rapidly scans source code to highlight anti-patterns, propose standard library idioms (like `<numeric>` algorithms), and write clear explanations. It acts as an instant second pair of eyes that accelerates refactoring.*

6. **What risks are involved in accepting AI-generated code without verification?**  
   > *AI-generated code may contain subtle bugs, off-by-one errors, deprecated functions, or security vulnerabilities that appear clean at first glance. Blindly accepting AI code without testing leads to unverified logic and developer reliance on code they cannot explain.*

7. **Why should developers use version control when working with AI coding assistants?**  
   > *Version control isolates AI-assisted changes into separate commits or branches. If an AI suggestion introduces unexpected side effects or regressions, developers can easily compare diffs or revert to a known working state.*

8. **How should AI tools and traditional development tools work together?**  
   > *AI tools should serve as advisory assistants for ideation, review, and explanation, while traditional tools (compilers, linters, debuggers, version control) serve as objective verification mechanisms. Human judgment connects the two to ensure correctness.*

---

## Deliverables Checklist & AI Prompt Log

### Submitted Artifacts
- [x] **Original Source Code:** [sample_program.cpp](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/sample_program.cpp)
- [x] **Improved Source Code:** [improved_program.cpp](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/improved_program.cpp)
- [x] **Buggy Program Code:** [buggy_program.cpp](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/buggy_program.cpp)
- [x] **Mini Development Standard:** [mini_coding_standard.md](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/mini_coding_standard.md)
- [x] **Git Repository Commit History:** Executed in directory `CS0053-TN36`
- [x] **Laboratory Activity Report:** [LAB_ACTIVITY_REPORT.md](file:///c:/Users/Cynthia%20Molato/Downloads/CS0053-TN36/LAB_ACTIVITY_REPORT.md)

### List of AI Prompts Used
1. **Tool Roles Prompt:** *"I am learning about software development tools. Explain the role of an IDE, compiler/interpreter, version control system, debugger, formatter, linter, testing tool, and AI coding assistant. For each tool, explain what problem it solves during software development."*
2. **Code Review Prompt:** *"Act as a software development code reviewer. Review the following program for readability, maintainability, naming conventions, formatting, unnecessary repetition, possible errors, and coding-standard violations. Do not rewrite the code yet. Explain each issue and recommend an improvement."*
3. **Refactoring Prompt:** *"Refactor the following code according to appropriate coding standards. Improve naming, formatting, readability, and maintainability without changing the program's intended behavior. Explain the major changes you made."*
4. **Debugging Prompt:** *"The following C++ program is producing incorrect average results: buggy_program.cpp. Based on the source code and loop behavior, identify possible causes. Explain your reasoning and suggest a correction."*
5. **Standards Suggestion Prompt:** *"Suggest a simple coding and development standard suitable for student programming projects. Include rules for naming, formatting, comments, version control, testing, and responsible use of AI."*
