# Student Management System

## Description
This project implements a simple Student Management System in C. It utilizes a linked list data structure to store and manage student records, including ID, Name, Age, and GPA. The system provides a console-based interface for performing various operations such as adding, displaying, searching, updating, calculating average GPA, finding the highest GPA, and deleting student records.



## Features

- **Add Student**: Add new student records with unique IDs, Name, Age, and GPA.
- **Display Students**: View a list of all registered students.
- **Search Student by ID**: Find a specific student's details using their ID.
- **Update Student Data**: Modify existing student information.
- **Calculate Average GPA**: Compute the average GPA of all students.
- **Search Highest GPA**: Identify the student with the highest GPA.
- **Delete Student**: Remove a student record from the system.



## How to Compile and Run

To compile this project, you will need a C compiler (e.g., GCC). Follow these steps:

1.  **Save the code**: Save the provided C code into two files: `Functions.c` and `program.c`.
2.  **Compile**: Open a terminal or command prompt and navigate to the directory where you saved the files. Then, compile the code using the following command:

    ```bash
    gcc program.c Functions.c -o student_management
    ```

3.  **Run**: After successful compilation, run the executable:

    ```bash
    ./student_management
    ```

## Usage

Upon running the program, you will be presented with a menu of options. Enter the number corresponding to the action you wish to perform:

```
Make a decision 
1-Add student
2-Display students 
3-Search student by ID 
4-Update student data 
5-Calculate the avg GPA
6-Highest GPA
7-Delete student
8-Exit the program
```

Follow the prompts to input student details or perform other operations.

