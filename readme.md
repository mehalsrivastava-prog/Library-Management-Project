# 📚 Library Management System (C++)

This is a console-based Library Management System written in **C++**.
The program uses **file handling** to store and retrieve data so that
information is not lost between executions.

The complete implementation is contained in a single file: `main.cpp`.

---

## 📁 Files Used

- `main.cpp` – Complete source code
- `books.txt` – Stores book records
- `members.txt` – Stores member records and issued books

---

## 📂 File Handling

- Data is **automatically loaded** from files when the program starts
- Data is **automatically saved** to files when the program exits
- No separate menu option is provided for file handling

---

## 📘 books.txt format

BookID,Title,Author,Copies

Example:
101,Harry Potter,J K Rowling,5  
102,Dune,Frank Herbert,3

---

## 👤 members.txt format

MemberID,Name,IssuedBookIDs

Example:
1,Alice,101 102  
2,Bob,103  
3,Charlie,

- IssuedBookIDs are space-separated book IDs  
- If a member has not issued any book, the field is left empty

---

## ▶️ Compile and Run

g++ main.cpp library.cpp book.cpp member.cpp -o main 
./main

---

## 🎯 Learning Outcomes

- Understanding of Object-Oriented Programming in C++
- File handling using ifstream and ofstream
- Use of vectors, pointers, and iterators
- Menu-driven program design
- Real-world problem modelling

---

## 👩‍💻 Author

[Mehal Shrivastav]  
Library Management System – C++ College Project
