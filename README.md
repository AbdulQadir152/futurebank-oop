# 💳 FutureBank – C++ Banking System

**FutureBank** is a console-based banking system built using **Object-Oriented Programming (OOP)** in C++. It simulates core real-world banking functionalities and is structured for modularity and clarity through multiple classes, inheritance, and dynamic memory management.

---

## 🏦 Key Features

- **Branch Management**  
  Add and remove branches, each uniquely identified by a branch code and location.

- **Customer Accounts**  
  Support for multiple account types:
  - 🔹 Saving Account (with minimum balance checks)
  - 🔹 Loan Account (take and repay loans, with history)
  - 🔹 Corporate Account (annual interest application)

- **Core Banking Operations**
  - Deposits & Withdrawals
  - Loan Issuance & Repayment
  - Apply Annual Interest
  - View Customer & Branch Details

- **Modular Design**
  - Composition: `Bank` → `Branch` → `Account`
  - Inheritance: Saving, Loan, and Corporate accounts from `Account`
  - Multiple Inheritance: `Customer` combines all account types

---

## 📊 UML Diagram Overview

![UML Diagram](UML_Diagram.jpeg)

This UML class diagram illustrates the architecture of FutureBank:
- Inheritance hierarchy among account types
- Composition between Bank, Branch, and Account
- Multiple inheritance used to model customers with diverse features

---

## 🛠 Technologies Used

- Language: **C++**
- Concepts: Object-Oriented Programming (OOP)
- Interface: Console-based
- Core Concepts: Inheritance, Virtual Inheritance, Dynamic Memory Allocation, Constructors, Destructors

---

## 📁 Project Structure
- `main.cpp`: Entry point, contains the user interface and menu
- `Account.*`, `Loan.*`, etc.: Core OOP components
- `UML.jpeg`: UML class diagram
- `README.md`: Project documentation
