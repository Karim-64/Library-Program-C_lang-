# Library Management System using Linked List

This project implements a simple library management system using a doubly linked list in C. It allows users to add, insert, delete, and view books in the library. The books can be viewed in different orders, such as the order they were added or sorted by price.

## Features

- Add a book to the library
- Insert a book at a specific position
- Delete a book by ID
- View the total number of books
- View details of a specific book
- View all books in the order they were added
- View books by a specific author
- View books sorted by price (ascending and descending)

## Prerequisites

- A C compiler (e.g., GCC)
- Standard C libraries
- `conio.h` for console input (typically available on Windows)

## Building the Project

To build the project, compile the source files using a C compiler. For example, with GCC:

```bash
gcc -o library_management main.c functions.c
```

This will create an executable named `library_management`.

**Note**: The project uses `_getch()` from `conio.h` for password input, which is specific to Windows. For other platforms, you may need to modify the code to use alternative methods for reading input without echoing.

## Running the Project

After building, run the executable:

```bash
./library_management
```

The program will prompt you to set a password and then present a menu of options to manage the library.

## Usage

Upon running the program, you will be asked to set a password. After setting and entering the correct password, you will see a menu with the following options:

 1. Add a book
 2. Add a book to a specified position
 3. Delete a book
 4. The number of books
 5. View the info of a book
 6. View all the books in the order they were added
 7. View books of a certain author
 8. View books from the cheapest
 9. View the books from the most expensive
10. Exit

Choose an option by entering the corresponding number and follow the prompts.

## File Structure

- `stdtypes.h`: Defines custom data types used in the project.
- `functions.h`: Contains function prototypes and type definitions for the linked list and nodes.
- `functions.c`: Implements the functions for list operations, input validation, and password handling.
- `main.c`: Contains the main function and user interface for interacting with the library management system.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License

This project does not currently specify a license. Consider adding a license to clarify how it can be used and distributed.