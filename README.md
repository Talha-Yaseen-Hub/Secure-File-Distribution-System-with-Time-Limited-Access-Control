<a name="top"></a>
<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:1e3c72,100:2a5298&height=220&section=header&text=Secure%20File%20Distribution&fontSize=46&fontColor=ffffff&animation=fadeIn&fontAlignY=32&desc=Time-Limited%20Access%20Control%20System%20%7C%20C%2B%2B%20%7C%20Information%20Security&descAlignY=52&descSize=16" width="100%"/>

<img src="https://readme-typing-svg.demolab.com/?font=Poppins&weight=600&size=21&duration=2800&pause=900&color=F4C95D&center=true&vCenter=true&width=650&lines=Encrypt+%F0%9F%94%92+Authenticate+%F0%9F%94%91+Expire+%E2%8F%B3+Protect+%F0%9F%9B%A1%EF%B8%8F;A+Console-Based+Secure+File+Sharing+Engine;Built+in+C%2B%2B+for+the+Information+Security+Course" alt="Typing SVG" />

<br/>

<img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/Compiler-MinGW%20g++-1E3C72?style=for-the-badge" />
<img src="https://img.shields.io/badge/IDE-VS%20Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" />
<img src="https://img.shields.io/badge/Status-Completed-2ECC71?style=for-the-badge" />
<img src="https://img.shields.io/badge/Course-Information%20Security-FFD700?style=for-the-badge&logoColor=black" />
<img src="https://img.shields.io/badge/Year-2026-2A5298?style=for-the-badge" />

<br/><br/>


</div>

<br/>

> A desktop-based Information Security project that demonstrates secure file sharing using **encryption**, **password-based authentication**, and **time-limited access control** — ensuring only authorized users can open a shared file, and only before it expires.

<br/>

### ⚡ Quick Start

```bash
git clone https://github.com/Talha-Yaseen-Hub/Secure-File-Distribution-System.git
cd Secure-File-Distribution-System
g++ *.cpp -o securefile
./securefile
```

<br/>

## 📑 Table of Contents

<table>
<tr>
<td valign="top">

- [📖 About the Project](#about-the-project)
- [🎯 Project Objectives](#project-objectives)
- [✨ Key Features](#key-features)
- [🧠 System Workflow](#system-workflow)
- [🔄 Sequence Diagram](#sequence-diagram)
- [🧩 Module Architecture](#module-architecture)
- [🛠️ Tech Stack](#tech-stack)
- [📂 Project Structure](#project-structure)
- [📄 Source Code Overview](#source-code-overview)

</td>
<td valign="top">

- [🔄 Project Execution](#project-execution)
- [🔐 Security Concepts Demonstrated](#security-concepts-demonstrated)
- [📷 Sample Output](#sample-output)
- [🚀 Getting Started](#getting-started)
- [📚 Learning Outcomes](#learning-outcomes)
- [⚠️ Limitations](#limitations)
- [🚀 Future Enhancements](#future-enhancements)
- [🎓 Academic Information](#academic-information)
- [👨‍💻 Author](#author)

</td>
</tr>
</table>

---

## 📖 About the Project

File sharing has become an essential part of modern communication, but traditional methods often fail to provide proper security **after** a file has been distributed. Once shared, the sender usually loses all control over who accesses the file and for how long.

This project solves that problem with a **Secure File Distribution System** — it protects files through encryption and restricts access using password verification combined with an automatically enforced expiry timer.

Developed as part of the **Information Security** course, this project demonstrates fundamental security concepts — confidentiality, authentication, and access control — in a practical, hands-on environment.

<br/>

## 🎯 Project Objectives

<div align="center">

| | Objective |
|:---:|---|
| 🔐 | Protect files using encryption |
| 🔑 | Restrict access through password authentication |
| ⏳ | Implement time-limited file access |
| 📁 | Enable secure confidential file sharing |
| 📝 | Maintain a complete access log |
| 💻 | Demonstrate core Information Security principles in practice |

</div>

<br/>

## ✨ Key Features

| | Feature | Description |
|:---:|---|---|
| 🔒 | **File Encryption** | Encrypts files with XOR-based encryption before they're shared |
| 🔓 | **File Decryption** | Restores original content only after successful authentication |
| 🔑 | **Password Protection** | Access is locked behind a sender-defined password |
| ⏰ | **Expiry Validation** | Every access attempt is checked against a hard expiry timestamp |
| 📂 | **Metadata Generation** | Password + expiry data stored in a dedicated `.meta` file |
| 📋 | **Access Logging** | Every attempt — successful or failed — is written to `access_log.txt` |
| ⚠️ | **Input Validation** | Blocks invalid file names, empty passwords, and malformed expiry values |
| ❌ | **Invalid Access Detection** | Flags and rejects incorrect password attempts |
| 🗑️ | **Auto-Deletion** | Expired files are automatically removed, closing the access window for good |
| 🧩 | **Modular Architecture** | Each responsibility lives in its own isolated module |
| 💻 | **Console Interface** | Lightweight, dependency-free, runs anywhere g++ does |

<br/>

## 🧠 System Workflow

```mermaid
flowchart TD
    A([👤 Sender]) --> B[📁 Select Original File]
    B --> C[🔑 Enter Password & Expiry Time]
    C --> D[🔐 Encrypt File — XOR]
    D --> E[📝 Generate Metadata .meta]
    E --> F[📤 Share .enc + .meta Files]
    F --> G([👤 Receiver])
    G --> H[🔑 Enter Password]
    H --> I{✅ Password Correct?}
    I -- No --> J[❌ Access Denied]
    I -- Yes --> K{⏳ Expired?}
    K -- Yes --> L[🗑️ Auto-Delete File]
    L --> J
    K -- No --> M[🔓 Decrypt & View File]

    style A fill:#1E3C72,color:#fff,stroke:#FFD700,stroke-width:2px
    style G fill:#1E3C72,color:#fff,stroke:#FFD700,stroke-width:2px
    style M fill:#2ECC71,color:#fff,stroke:#1E3C72
    style J fill:#E74C3C,color:#fff,stroke:#1E3C72
    style L fill:#E74C3C,color:#fff,stroke:#1E3C72
```

<br/>

## 🔄 Sequence Diagram

```mermaid
sequenceDiagram
    actor Sender
    participant System as 🔐 Secure File System
    actor Receiver

    Sender->>System: Select file + set password + expiry
    System->>System: Encrypt file (XOR)
    System->>System: Generate metadata (.meta)
    System-->>Sender: report.txt.enc + report.txt.meta
    Sender->>Receiver: Share .enc + .meta files

    Receiver->>System: Enter password
    System->>System: Validate password

    alt Password Invalid
        System-->>Receiver: ❌ Access Denied
    else Password Valid
        System->>System: Check expiry timestamp
        alt Expired
            System->>System: Delete file automatically
            System-->>Receiver: ❌ File Expired
        else Not Expired
            System->>System: Decrypt file
            System-->>Receiver: ✅ Decrypted Content
        end
    end
```

<br/>

## 🧩 Module Architecture

```mermaid
graph TD
    Main[["🚀 main.cpp"]] --> Menu["🧭 menu.cpp"]
    Menu --> FM["🗂️ filemanager.cpp"]
    FM --> ENC["🔐 encryption.cpp"]
    FM --> AC["🔑 accesscontrol.cpp"]
    FM --> VAL["✅ validator.cpp"]
    AC --> META[("📝 .meta files")]
    ENC --> ENCFILE[("🔒 .enc files")]
    AC --> LOG[("📋 access_log.txt")]

    classDef core fill:#1E3C72,color:#fff,stroke:#FFD700,stroke-width:1px;
    classDef data fill:#2A5298,color:#fff,stroke:#FFD700,stroke-width:1px,stroke-dasharray: 3 3;
    class Main,Menu,FM,ENC,AC,VAL core;
    class META,ENCFILE,LOG data;
```

> `filemanager.cpp` is the central controller — it's the only module that talks directly to encryption, access control, and validation, keeping every other module decoupled from the rest.

<br/>

## 🛠️ Tech Stack

<div align="center">

<img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/File%20Handling-2A5298?style=flat-square" />
<img src="https://img.shields.io/badge/XOR%20Encryption-1E3C72?style=flat-square" />
<img src="https://img.shields.io/badge/Time%20Library-FFD700?style=flat-square&logoColor=black" />
<img src="https://img.shields.io/badge/Modular%20Design-00D9FF?style=flat-square&logoColor=black" />
<img src="https://img.shields.io/badge/VS%20Code-007ACC?style=flat-square&logo=visualstudiocode&logoColor=white" />
<img src="https://img.shields.io/badge/MinGW%20g++-4479A1?style=flat-square" />

</div>

| Technology | Purpose |
|---|---|
| **C++** | Application development |
| **File Handling** | Reading/writing encrypted and metadata files |
| **XOR Encryption** | Data protection (educational purpose) |
| **Time Library** | Expiry timestamp validation |
| **Modular Programming** | Code organization and separation of concerns |
| **Visual Studio Code** | Development environment |
| **MinGW g++** | Compilation |

<br/>

## 📂 Project Structure

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

<br/>

## 📄 Source Code Overview

| File | Type | Responsibility |
|---|---|---|
| `main.cpp` | Source | Entry point. Controls program flow, initializes the system, calls menu functions |
| `menu.cpp` | Source | Displays the console menu and handles user selections |
| `menu.h` | Header | Function declarations for the menu module |
| `filemanager.cpp` | Source | Central controller — coordinates encryption, metadata creation, password verification, decryption, and logging |
| `filemanager.h` | Header | Declares the file management functions used throughout the app |
| `encryption.cpp` | Source | Performs XOR encryption/decryption and handles binary file operations |
| `encryption.h` | Header | Prototypes for encryption/decryption operations |
| `accesscontrol.cpp` | Source | Manages password authentication, expiry validation, metadata, and auto-deletion |
| `accesscontrol.h` | Header | Declares access-control-related functions |
| `validator.cpp` | Source | Validates user input, file existence, and expiry values |
| `validator.h` | Header | Declarations for validation functions |
| `report.txt` | Sample | Demonstration file used to test encryption/decryption |
| `report.txt.enc` | Generated | Encrypted version of the original file, shared with the receiver |
| `report.txt.meta` | Generated | Stores metadata — password and expiry timestamp |
| `access_log.txt` | Generated | Records successful and failed access attempts |

<br/>

## 🔄 Project Execution

<table>
<tr><td width="33%" valign="top">

### 1️⃣ Secure File
- Enter file name
- Enter password
- Enter expiry time
- File is encrypted
- Metadata is generated

```text
report.txt.enc
report.txt.meta
```

</td><td width="33%" valign="top">

### 2️⃣ Share Files
Send both generated files to the receiver:

```text
report.txt.enc
report.txt.meta
```

</td><td width="33%" valign="top">

### 3️⃣ Open Secure File
Receiver runs the app and enters:
- File name
- Password

✔ Correct password
✔ Not expired
➡️ **Decrypted successfully**

❌ Otherwise → **Access denied**

</td></tr>
</table>

<br/>

## 🔐 Security Concepts Demonstrated

<div align="center">

<img src="https://img.shields.io/badge/Confidentiality-1E3C72?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/Authentication-2A5298?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/Access%20Control-00599C?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/Time--Based%20Restrictions-FFD700?style=flat-square&logoColor=black" />
<img src="https://img.shields.io/badge/Secure%20File%20Handling-00D9FF?style=flat-square&logoColor=black" />
<img src="https://img.shields.io/badge/Basic%20Cryptography-4479A1?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/Input%20Validation-2ECC71?style=flat-square&logoColor=white" />

</div>

<br/>

## 📷 Sample Output

<table>
<tr><td valign="top">

**Main Menu**
```text
=============================
 Secure File System
=============================
1 Secure File
2 Open Secure File
3 Exit
```

</td><td valign="top">

**Secure File**
```text
Enter file name:
report.txt

Set password:
1234

Enter expiry time:
5

File secured successfully.
```

</td><td valign="top">

**Open Secure File**
```text
Enter file name:
report.txt

Enter password:
1234

File Content:
Information Security Notes...
```

</td></tr>
</table>

> 💡 Tip: Replace these console captures with real terminal screenshots or a short GIF demo — it's one of the highest-impact upgrades you can make to this README.

<br/>

## 🚀 Getting Started

**Prerequisites:** a C++ compiler (g++ / MinGW) and a terminal.

<details>
<summary><b>🪟 Windows (PowerShell)</b></summary>

```powershell
g++ *.cpp -o securefile
.\securefile.exe
```
</details>

<details>
<summary><b>🐧 Linux / 🍎 macOS</b></summary>

```bash
g++ *.cpp -o securefile
./securefile
```
</details>

<br/>

## 📚 Learning Outcomes

This project demonstrates practical implementation of:

- File Encryption
- Authentication
- Access Control
- Time Validation
- Modular Programming
- Secure File Management

<br/>

## ⚠️ Limitations

| Limitation | Note |
|---|---|
| XOR encryption | Used for educational purposes — not cryptographically strong like AES |
| Local desktop only | No network-based file transfer |
| Console interface | No GUI |
| Prototype scope | Built for learning, not production deployment |

<br/>

## 🚀 Future Enhancements

- [ ] AES-256 Encryption
- [ ] PBKDF2 password-based key derivation
- [ ] SHA-256 password hashing
- [ ] Graphical User Interface (GUI)
- [ ] Secure network-based file sharing
- [ ] Database integration
- [ ] Digital signatures
- [ ] Multi-user authentication
- [ ] Cloud storage support

<br/>

## 🧩 Design Principles

<div align="center">

<img src="https://img.shields.io/badge/📦_Modular_Programming-1E3C72?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/🔄_Separation_of_Concerns-2A5298?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/📂_Organized_Structure-00599C?style=flat-square&logoColor=white" />
<img src="https://img.shields.io/badge/♻️_Reusability-00D9FF?style=flat-square&logoColor=black" />
<img src="https://img.shields.io/badge/✅_Input_Validation-2ECC71?style=flat-square&logoColor=white" />

</div>

Each module performs a single responsibility, making the code easier to understand, debug, and extend in future versions.

<br/>

## 📖 Documentation

This repository also includes:

- 📄 Project Proposal
- 📘 Complete Project Documentation
- 📊 Presentation Slides

<br/>

## 🎓 Academic Information

| | |
|---|---|
| **Course** | Information Security |
| **Project Type** | Info Sec — 4th Semester Project |
| **Language** | C++ |
| **Development Environment** | Visual Studio Code |
| **Year** | 2026 |

<br/>

## 👨‍💻 Author

<div align="center">

### Talha Yaseen
**Roll No: BITF24M041**

🎓 BS Information Technology &nbsp;•&nbsp; 🏫 FCIT &nbsp;•&nbsp; 📚 Information Security Project (2026)

<a href="mailto:talhavectorarts@gmail.com">
  <img src="https://img.shields.io/badge/Gmail-EA4335?style=for-the-badge&logo=gmail&logoColor=white" />
</a>
<a href="https://www.linkedin.com/in/talha-yaseen-44a41a341">
  <img src="https://img.shields.io/badge/LinkedIn-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white" />
</a>
<a href="https://github.com/Talha-Yaseen-Hub">
  <img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white" />
</a>

</div>

<br/>

## ⭐ Support This Project

<div align="center">

If this project helped you understand file security concepts, consider giving it a **star** — it genuinely helps and motivates further educational builds like this one.

<img src="https://img.shields.io/badge/⭐_Star_this_repo-FFD700?style=for-the-badge&logoColor=black" />

</div>

<br/>

## 📜 MIT License

<div align="center">

<img src="https://img.shields.io/badge/License-MIT-FFD700?style=for-the-badge&labelColor=1E3C72" />

This project is licensed under the **MIT License** — see the [LICENSE](./LICENSE) file for full details.

</div>

<br/>

<div align="center">

[⬆ Back to Top](#top)

### 🔐 Happy Learning!

*"Security is a continuous process, not a one-time solution."*

</div>

<br/>

<div align="center">

[⬆ Back to Top](#top)

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:2a5298,100:1e3c72&height=100&section=footer" width="100%"/>

</div>
