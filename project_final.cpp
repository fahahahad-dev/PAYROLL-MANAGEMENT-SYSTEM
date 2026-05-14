#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	  system("color 1F");
    // Parallel arrays to store employee data (max 10 employees)
    int empID[10];
    string empName[10];
    double workingHours[10];
    double hourlyRate[10];
    double grossSalary[10];
    double deduction[10];
    double netSalary[10];
    
    int employeeCount = 0;  // Track number of employees added
    bool salaryCalculated = false;  // Track if salary has been calculated
    int choice;
    
    cout << "\n===================================\n";
    cout << "   PAYROLL MANAGEMENT SYSTEM\n";
    cout << "===================================\n";
    
    // Main menu loop
    do {
        // Display menu options
        cout << "\n----- MENU -----\n";
        cout << "1. Add Employee\n";
        cout << "2. Calculate Salary\n";
        cout << "3. Display Employee Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Input validation for menu choice
        if (cin.fail()) {
            cin.clear();  // Clear error flag
            cin.ignore(1000, '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        // Process menu choice
        switch (choice) {
            case 1: {  // Add Employee
                if (employeeCount >= 10) {
                    cout << "Maximum employee limit reached!\n";
                    break;
                }
                
                cout << "\n--- Add Employee ---\n";
                
                // Input Employee ID
                cout << "Enter Employee ID: ";
                cin >> empID[employeeCount];
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid ID! Employee not added.\n";
                    break;
                }
                
                cin.ignore();  // Clear input buffer
                
                // Input Employee Name
                cout << "Enter Employee Name: ";
                getline(cin, empName[employeeCount]);
                
                // Input Working Hours
                cout << "Enter Working Hours: ";
                cin >> workingHours[employeeCount];
                
                if (cin.fail() || workingHours[employeeCount] < 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid hours! Employee not added.\n";
                    break;
                }
                
                // Input Hourly Rate
                cout << "Enter Hourly Rate: ";
                cin >> hourlyRate[employeeCount];
                
                if (cin.fail() || hourlyRate[employeeCount] < 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid rate! Employee not added.\n";
                    break;
                }
                
                employeeCount++;
                salaryCalculated = false;  // Reset calculation flag
                cout << "\nEmployee added successfully!\n";
                break;
            }
            
            case 2: {  // Calculate Salary
                if (employeeCount == 0) {
                    cout << "\nNo employees to calculate! Please add employees first.\n";
                    break;
                }
                
                cout << "\n--- Calculating Salaries ---\n";
                
                // Calculate salary for all employees
                for (int i = 0; i < employeeCount; i++) {
                    // Step 1: Calculate Gross Salary
                    grossSalary[i] = workingHours[i] * hourlyRate[i];
                    
                    // Step 2: Apply Deduction Logic
                    if (grossSalary[i] > 30000) {
                        deduction[i] = grossSalary[i] * 0.10;  // 10% deduction
                    } else {
                        deduction[i] = grossSalary[i] * 0.05;  // 5% deduction
                    }
                    
                    // Step 3: Calculate Net Salary
                    netSalary[i] = grossSalary[i] - deduction[i];
                }
                
                salaryCalculated = true;
                cout << "Salaries calculated successfully for " << employeeCount << " employee(s)!\n";
                break;
            }
            
            case 3: {  // Display Employee Record
                if (employeeCount == 0) {
                    cout << "\nNo employees in the system!\n";
                    break;
                }
                
                if (!salaryCalculated) {
                    cout << "\nPlease calculate salary first!\n";
                    break;
                }
                
                int searchID;
                cout << "\n--- Display Employee Record ---\n";
                cout << "Enter Employee ID to search: ";
                cin >> searchID;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid ID!\n";
                    break;
                }
                
                // Search for employee
                bool found = false;
                for (int i = 0; i < employeeCount; i++) {
                    if (empID[i] == searchID) {
                        found = true;
                        
                        // Display employee details
                        cout << "\n===================================\n";
                        cout << "      EMPLOYEE SALARY DETAILS\n";
                        cout << "===================================\n";
                        cout << "Employee ID    : " << empID[i] << endl;
                        cout << "Employee Name  : " << empName[i] << endl;
                        cout << "Working Hours  : " << workingHours[i] << endl;
                        cout << "Hourly Rate    : " << fixed << setprecision(2) << hourlyRate[i] << endl;
                        cout << "-----------------------------------\n";
                        cout << "Gross Salary   : " << grossSalary[i] << endl;
                        cout << "Deduction      : " << deduction[i];
                        
                        // Show deduction percentage
                        if (grossSalary[i] > 30000) {
                            cout << " (10%)";
                        } else {
                            cout << " (5%)";
                        }
                        cout << endl;
                        cout << "-----------------------------------\n";
                        cout << "Net Salary     : " << netSalary[i] << endl;
                        cout << "===================================\n";
                        break;
                    }
                }
                
                if (!found) {
                	
                    cout << "\nNo employee found for ID " << searchID << "!\n";
                }
                break;
            }
            
            case 4:  // Exit
                cout << "\nThank you for using Payroll Management System!\n";
                cout << "Goodbye!\n";
                break;
                
            default:
                cout << "\nInvalid menu option! Please choose 1-4.\n";
        }
        
    } while (choice != 4);
    
    return 0;
}
