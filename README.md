Payroll Management System
A simple, interactive C++ console application for managing employee payroll. This program allows users to input employee data, calculate gross and net salaries with automated deductions, and display formatted salary slips.

Features
Add Employees: Input up to 10 employees with their ID, name, working hours, and hourly pay rate.

Input Validation: Prevents program crashes by validating numeric inputs and rejecting negative hours/rates.

Automated Salary Calculation: * Calculates Gross Salary (Working Hours × Hourly Rate).

Applies automated deductions: 10% deduction if the gross salary exceeds 30,000; otherwise, a 5% deduction is applied.

Calculates Net Salary.

Search & Display: Search for an employee by their ID to print a formatted salary slip detailing their pay breakdown.

Prerequisites
A C++ compiler (e.g., GCC, Clang, or MSVC).

Note on OS: The code includes the system("color 1F"); command, which changes the console background and text color. This specific command is native to Windows. If you are running this on macOS or Linux, the program will still compile and run, but that specific line may throw a minor console error or be ignored.

How to Compile and Run
Using g++ (Command Line / Terminal):

Save the code in a file named project_final.cpp.

Open your terminal or command prompt.

Navigate to the directory where the file is saved.

Compile the code using the following command:

Bash
g++ project_final.cpp -o payroll
Run the executable:

On Windows: payroll.exe

On Linux/macOS: ./payroll

Usage Instructions
Upon launching the program, you will be greeted by the Main Menu.

Select Option 1 to add an employee. You will need to provide a unique integer ID, a name, total working hours, and the hourly rate.

Select Option 2 to process the payroll. Note: You must run this step before attempting to view any salary slips.

Select Option 3 and enter an employee's ID to view their complete salary breakdown.

Select Option 4 to securely exit the program.

Limitations & Future Improvements
Data Persistence: Currently, all data is stored in the RAM. Once the program is closed, all employee records are lost. Implementing file handling (reading/writing to .txt or .csv) would make the data persistent.

Scalability: The system uses parallel arrays with a hardcoded limit of 10 employees. Upgrading the data structure to std::vector alongside a struct or class for the Employee object would make the program infinitely scalable and much cleaner.
