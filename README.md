# 🔐 Secure File Distribution System with Time-Limited Access Control

A desktop-based Information Security project developed in **C++** that demonstrates secure file sharing using **encryption**, **password-based authentication**, and **time-limited access control**. The system ensures that only authorized users can access shared files before the specified expiry time.

---

## 📖 About the Project

File sharing has become an essential part of modern communication, but traditional methods often fail to provide proper security after a file has been distributed. Once shared, the sender usually loses control over who accesses the file and for how long.

This project addresses that issue by implementing a **Secure File Distribution System** that protects files through encryption and restricts access using password verification and an expiry timer.

The project was developed as part of the **Information Security** course to demonstrate fundamental security concepts in a practical environment.

---

## 🎯 Project Objectives

- 🔐 Protect files using encryption
- 🔑 Restrict access through password authentication
- ⏳ Implement time-limited file access
- 📁 Secure confidential file sharing
- 📝 Maintain access logs
- 💻 Demonstrate core Information Security principles

---

# ✨ Features

- 🔒 File Encryption
- 🔓 File Decryption
- 🔑 Password Protection
- ⏰ Expiry Time Validation
- 📂 Metadata File Generation
- 📋 Access Log Generation
- ⚠️ Input Validation
- ❌ Invalid Password Detection
- 🗑️ Automatic Deletion After Expiry
- 🧩 Modular Multi-File Architecture
- 💻 Console-Based Interface

---

# 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Application Development |
| File Handling | Read/Write Files |
| XOR Encryption | Data Protection (Educational Purpose) |
| Time Library | Expiry Validation |
| Modular Programming | Code Organization |
| Visual Studio Code | Development Environment |
| MinGW g++ | Compilation |

---

# 📄 Source Code Overview

The project follows a modular architecture where each file is responsible for a specific task. This improves readability, maintainability, and code organization.

| File | Type | Responsibility |
|------|------|----------------|
| `main.cpp` | Source | Entry point of the application. Controls the program flow, initializes the system, and calls the menu functions. |
| `menu.cpp` | Source | Displays the console menu and handles user menu selections. |
| `menu.h` | Header | Contains function declarations for the menu module. |
| `filemanager.cpp` | Source | Core controller of the project. Coordinates encryption, metadata creation, password verification, decryption, and logging. |
| `filemanager.h` | Header | Declares the file management functions used throughout the application. |
| `encryption.cpp` | Source | Performs file encryption and decryption using XOR encryption and handles binary file operations. |
| `encryption.h` | Header | Contains function prototypes for encryption and decryption operations. |
| `accesscontrol.cpp` | Source | Manages password authentication, expiry time validation, metadata creation, and automatic deletion of expired files. |
| `accesscontrol.h` | Header | Declares functions related to access control and authentication. |
| `validator.cpp` | Source | Validates user input, checks file existence, and ensures valid expiry time values. |
| `validator.h` | Header | Contains declarations for validation functions. |
| `report.txt` | Sample File | Demonstration file used for testing the encryption and decryption process. |
| `report.txt.enc` | Generated File | Encrypted version of the original file that is shared with the receiver. |
| `report.txt.meta` | Generated File | Stores metadata including password and expiry timestamp required for authentication. |
| `access_log.txt` | Generated File | Records successful and failed file access attempts for monitoring purposes. |

---

# 📂 Project Structure

```text
SecureFileDistributionSystem/
│
├── 📁 Source
│   ├── main.cpp
│   ├── menu.cpp
│   ├── filemanager.cpp
│   ├── encryption.cpp
│   ├── accesscontrol.cpp
│   └── validator.cpp
│
├── 📁 Header Files
│   ├── menu.h
│   ├── filemanager.h
│   ├── encryption.h
│   ├── accesscontrol.h
│   └── validator.h
│
├── 📁 Sample Files
│   ├── report.txt
│   ├── report.txt.enc
│   ├── report.txt.meta
│   └── access_log.txt
│
├── 📁 Documentation
│   ├── Project Proposal.pdf
│   ├── Project Documentation.pdf
│   └── Presentation.pptx
│
└── README.md
```

---

# ⚙️ System Workflow

```text
                Sender
                   │
                   ▼
          Select Original File
                   │
                   ▼
          Enter Password & Time
                   │
                   ▼
             Encrypt File
                   │
                   ▼
       Create Metadata (.meta)
                   │
                   ▼
      Share .enc + .meta Files
                   │
──────────────────────────────────────
                   │
                   ▼
               Receiver
                   │
                   ▼
          Enter Password
                   │
                   ▼
        Verify Password
                   │
                   ▼
       Check Expiry Time
          │            │
      Valid          Expired
        │               │
        ▼               ▼
Decrypt & View      Access Denied
                        │
                        ▼
             Delete Expired Files
```

---

# 📁 Project Modules

## 📌 Main Module

Controls the overall execution of the application and manages the main program loop.

---

## 📌 Menu Module

Displays menu options and handles user interaction.

---

## 📌 File Manager Module

Acts as the central controller that coordinates encryption, decryption, metadata creation, and access verification.

---

## 📌 Encryption Module

Responsible for:

- Encrypting files
- Decrypting files
- Reading and writing binary data

> **Note:** This project uses XOR-based encryption for educational purposes.

---

## 📌 Access Control Module

Responsible for:

- Password verification
- Expiry time validation
- Metadata management
- Automatic deletion after expiry

---

## 📌 Validator Module

Responsible for:

- File existence checking
- Input validation
- Time validation

---

# 🔄 Project Execution

## Step 1 — Secure File

- Enter file name
- Enter password
- Enter expiry time
- File is encrypted
- Metadata file is generated

Generated files:

```
report.txt.enc
report.txt.meta
```

---

## Step 2 — Share Files

Send these files to the receiver:

```
report.txt.enc
report.txt.meta
```

---

## Step 3 — Open Secure File

Receiver:

- Runs the application
- Enters file name
- Enters password

If:

✔ Password is correct

✔ File has not expired

➡ File is decrypted successfully.

Otherwise,

❌ Access is denied.

---

# 🔐 Security Concepts Demonstrated

- Confidentiality
- Authentication
- Access Control
- Time-Based Restrictions
- Secure File Handling
- Basic Cryptography
- Input Validation

---

# 📷 Sample Output

## Main Menu

```text
=============================
 Secure File System
=============================
1 Secure File
2 Open Secure File
3 Exit
```

---

## Secure File

```text
Enter file name:
report.txt

Set password:
1234

Enter expiry time:
5

File secured successfully.
```

---

## Open Secure File

```text
Enter file name:
report.txt

Enter password:
1234

File Content:

Information Security Notes...
```

---

# 🚀 How to Run

### Compile

```bash
g++ *.cpp -o securefile
```

### Run

```bash
./securefile
```

Windows PowerShell

```powershell
.\securefile.exe
```

---

# 📚 Learning Outcomes

This project demonstrates practical implementation of:

- File Encryption
- Authentication
- Access Control
- Time Validation
- Modular Programming
- Secure File Management

---

# ⚠️ Limitations

- Uses XOR encryption instead of AES.
- Works as a local desktop application.
- No network-based file transfer.
- Console-based interface.
- Educational prototype only.

---

# 🚀 Future Enhancements

- AES-256 Encryption
- PBKDF2 Password-Based Key Derivation
- SHA-256 Password Hashing
- Graphical User Interface (GUI)
- Secure Network File Sharing
- Database Integration
- Digital Signatures
- Multi-User Authentication
- Cloud Storage Support

---

# 🧩 Design Principles

This project follows several software engineering principles:

- 📦 Modular Programming
- 🔄 Separation of Concerns
- 📂 Organized File Structure
- ♻️ Code Reusability
- 🛡️ Basic Information Security Practices
- ✅ Input Validation
- 📖 Easy Maintainability

Each module performs a single responsibility, making the code easier to understand, debug, and extend in future versions.

# 📖 Project Documentation

This repository also includes:

- 📄 Project Proposal
- 📘 Complete Project Documentation
- 📊 Presentation Slides

---

# 🎓 Academic Information

**Course:** Information Security

**Project Type:** Info Sec 4th Semester Project

**Language:** C++

**Development Environment:** Visual Studio Code

**Year:** 2026

---

# 👨‍💻 Author

## Talha Yaseen
## Roll NO: BITF24M041

🎓 BS Information Technology

🏫 FCIT

📚 Information Security Project (2026)

🌐 GitHub:
https://github.com/Talha-Yaseen-Hub

---

# ⭐ Support

If you found this project useful, please consider giving this repository a ⭐ **Star**.

Your support motivates me to continue building and sharing educational projects.

---

# 📜 License

This project is developed for **educational purposes only**.

It demonstrates fundamental Information Security concepts and should not be considered a production-ready secure file sharing solution.
