Question1:
IIITD Information Center - 
This program searches IIITD personnel details from a CSV file. Users can enter a name, and the program retrieves the corresponding information like position, title, email, room, and phone.

Build Instructions:-
1.Open a terminal.
2.Compile the program using: g++ -o info_center question1.cpp
3.Run the program: ./info_center

CSV File Format:-
The input file (DB_departments.csv) should have the following columns: Position,Name,Title,Email,Room,Phone

Usage:- 
1.Enter a name to search when prompted.
2.The program will display the person's details if found.


Question2:
Faculty Directory Program:-
Purpose: Manages faculty information based on departments at IIITD.
Building the Program
Command to compile: g++ -o question2 question2.cpp

Input File Format:
File Name: DB_Faculties.csv
Format: Department,Position,Name,Room,Phone
Computer Science and Engineering,Professor,John Doe,101,1234567890
Usage:
Run the program:./question2
Search for faculty:
Enter the department name (e.g., CSE, ECE, MATH) when prompted.



Question3:
Escalation Management System-
This C++ program implements an escalation management system for various academic positions within an organization. It demonstrates how complaints are escalated through a hierarchy of positions, from the Registrar to various Deans and Administrative Officers.

Build Instructions
To compile the code, navigate to the directory containing the source file and run the following command in terminal:g++ -o question question3.cpp
Replace question3.cpp with the name of your source file if different.

Running the Program
To execute the compiled program, run the following command:
./question3
Input Format
This program does not require external input files. The hierarchy and escalation process are predefined in the code. It showcases the escalation paths based on the academic and administrative positions without requiring user input.

Output
The program outputs the escalation path for complaints based on various departments within the organization, displaying the current position and the next position to escalate to.