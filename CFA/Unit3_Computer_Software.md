# Unit 3: Computer Software
**BCA – Tribhuvan University | 10 Hours**

---

## 3.1 Introduction to Software and Program

### What is Software?
**Software** is a collection of programs, data, and instructions that tell a computer how to perform specific tasks. Unlike hardware, software is intangible — it cannot be physically touched.

### What is a Program?
A **program** is a set of step-by-step instructions written in a programming language that directs the computer to perform specific operations.

**Relationship:**
- A **program** is a single set of instructions.
- **Software** is a broader term that includes programs, documentation, and data.

### Software vs Hardware
| Software | Hardware |
|---|---|
| Intangible (cannot be touched) | Tangible (can be touched) |
| Set of instructions | Physical components |
| Created by programming | Manufactured physically |
| Easy to copy and distribute | Difficult to copy |
| Example: Windows, MS Word | Example: CPU, RAM, HDD |

### Characteristics of Software
1. **Intangible**: Cannot be physically touched.
2. **Developed, not manufactured**: Written by programmers.
3. **Does not wear out**: But can become obsolete.
4. **Can be copied**: Intellectual property laws protect it.
5. **Flexible**: Can be updated and modified.

---

## 3.2 Types of Software (System and Application)

### A. System Software
Software that manages and controls the computer hardware, providing a platform for application software to run.

#### 1. Operating System (OS)
- The most important system software.
- Manages hardware resources and provides services to applications.
- Examples: Windows 11, macOS, Linux (Ubuntu), Android, iOS.

#### 2. Utility Software
- Performs maintenance tasks for the computer.
- Examples: Antivirus, disk cleanup, backup tools, file compression (WinZip).

#### 3. Device Drivers
- Software that allows the OS to communicate with hardware devices.
- Examples: Printer driver, graphics driver, network adapter driver.

#### 4. Language Translators
- Convert programs written in programming languages into machine code.
- Compiler, Interpreter, Assembler.

### B. Application Software
Software designed to help users perform specific tasks.

#### 1. General Purpose Application Software
Can be used for a wide range of tasks:
- Word Processors: MS Word, LibreOffice Writer
- Spreadsheets: MS Excel, Google Sheets
- Presentation: MS PowerPoint
- Browsers: Chrome, Firefox

#### 2. Special Purpose Application Software
Designed for a specific task:
- Accounting: Tally, QuickBooks
- Medical: Hospital Management Systems
- Banking: Core Banking Solutions

#### 3. Customized Software
Developed for a specific organization:
- Custom inventory systems
- Custom e-commerce platforms

### System vs Application Software
| System Software | Application Software |
|---|---|
| Manages hardware | Helps users perform tasks |
| Necessary for computer to run | Optional; installed as needed |
| Runs in background | Runs in foreground (user interacts) |
| Examples: OS, drivers, utilities | Examples: MS Word, Photoshop, VLC |

---

## 3.3 Operating System (Functions and Types)

### Definition
An **Operating System (OS)** is system software that acts as an **intermediary between the user and computer hardware**. It manages hardware resources and provides a convenient environment for executing programs.

### Functions of Operating System

**1. Process Management:**
- Creates, schedules, and terminates processes.
- Manages multitasking (running multiple programs simultaneously).
- Uses scheduling algorithms: FCFS, Round Robin, SJF.

**2. Memory Management:**
- Allocates and deallocates memory to processes.
- Manages RAM efficiently.
- Implements virtual memory (using disk space as extended RAM).

**3. File System Management:**
- Organizes files in directories/folders.
- Controls file creation, deletion, reading, and writing.
- File systems: NTFS (Windows), ext4 (Linux), HFS+ (Mac).

**4. Device Management:**
- Controls all hardware devices through device drivers.
- Manages I/O operations (keyboard, mouse, printer, disk).

**5. Security and Access Control:**
- User authentication (username/password).
- File permissions (read, write, execute).
- Protects system from unauthorized access.

**6. User Interface:**
- **CLI (Command Line Interface)**: Text-based (MS-DOS, Linux Terminal).
- **GUI (Graphical User Interface)**: Graphical icons and menus (Windows, macOS).

**7. Error Detection and Handling:**
- Monitors the system for errors.
- Handles hardware failures and software errors gracefully.

**8. Networking:**
- Manages network connections.
- Handles TCP/IP communication.

### Types of Operating Systems

**1. Batch Operating System:**
- Jobs are grouped into batches and processed without user interaction.
- No direct interaction between user and computer.
- Example: Early IBM mainframe systems.
- Advantage: Efficient use of CPU; Disadvantage: No user interaction.

**2. Time-Sharing (Multitasking) Operating System:**
- Multiple users share the CPU simultaneously.
- Each user gets a time slice (quantum).
- Example: UNIX, Linux.
- Advantage: Multiple users; fast response.

**3. Real-Time Operating System (RTOS):**
- Processes data and responds within a guaranteed time.
- Used in critical systems where timing is crucial.
- Types: Hard RTOS (aerospace, nuclear) and Soft RTOS (multimedia).
- Examples: VxWorks, FreeRTOS, RTLinux.

**4. Distributed Operating System:**
- Manages a network of computers as a single system.
- Users can access resources from any machine.
- Examples: Amoeba, LOCUS.

**5. Network Operating System:**
- Manages network resources and allows multiple computers to communicate.
- Examples: Windows Server, Novell NetWare.

**6. Mobile Operating System:**
- Designed for smartphones and tablets.
- Examples: Android (Google), iOS (Apple), HarmonyOS (Huawei).

**7. Embedded Operating System:**
- Designed for embedded systems (specialized devices).
- Examples: Embedded Linux, Windows Embedded, QNX.

---

## 3.4 Utility Software, Virus, and Antivirus Software

### Utility Software
Utility software is system software designed to help manage, maintain, and optimize computer performance.

**Types of Utility Software:**

| Utility | Function | Example |
|---|---|---|
| **Disk Defragmenter** | Reorganizes fragmented files on HDD for faster access | Windows Defragmenter |
| **Disk Cleanup** | Removes temporary files, cache, junk | Windows Disk Cleanup, CCleaner |
| **Backup Software** | Creates copies of data for recovery | Acronis, Windows Backup |
| **File Compression** | Reduces file size | WinZip, WinRAR, 7-Zip |
| **File Manager** | Browse, copy, move, delete files | Windows Explorer, Total Commander |
| **Antivirus** | Detects and removes malware | Avast, Norton, Kaspersky |
| **System Monitor** | Monitors CPU, RAM, disk usage | Task Manager, HWMonitor |
| **Screen Saver** | Protects screen from burn-in | Windows built-in screensavers |

### Computer Virus

**Definition:** A **computer virus** is a malicious program that attaches itself to legitimate programs or files, replicates itself, and can damage or destroy data.

**Characteristics of Virus:**
1. **Self-replication**: Can copy itself and spread.
2. **Needs a host**: Attaches to existing programs.
3. **Activation**: Triggered by an event (date, opening a file).
4. **Harmful**: Can delete files, corrupt data, slow down system.

**Types of Viruses:**

| Type | Description |
|---|---|
| **Boot Sector Virus** | Infects the boot sector of a disk; loads before OS |
| **File Virus** | Attaches to executable (.exe, .com) files |
| **Macro Virus** | Infects documents (MS Word, Excel macros) |
| **Worm** | Self-replicates and spreads across networks without a host |
| **Trojan Horse** | Disguises as legitimate software but has malicious intent |
| **Ransomware** | Encrypts user files and demands payment |
| **Spyware** | Secretly collects user information |
| **Adware** | Displays unwanted advertisements |
| **Rootkit** | Hides deeply in the OS, giving attackers admin access |

**How Viruses Spread:**
- Email attachments
- Infected USB drives
- Downloading from untrusted websites
- Peer-to-peer file sharing
- Infected software

### Antivirus Software
**Definition:** Antivirus software is a program designed to **detect, prevent, and remove** malicious software (malware).

**How Antivirus Works:**
1. **Signature-based Detection**: Compares files against a database of known virus signatures.
2. **Heuristic Detection**: Analyzes behavior of programs to detect unknown viruses.
3. **Sandboxing**: Runs suspicious programs in an isolated environment to check behavior.
4. **Real-time Protection**: Monitors system activity continuously.

**Popular Antivirus Software:**
- Avast Free Antivirus
- Norton Antivirus
- Kaspersky Internet Security
- McAfee
- Windows Defender (built-in)
- Bitdefender

**Precautions Against Viruses:**
1. Install and regularly update antivirus software.
2. Do not open suspicious email attachments.
3. Avoid downloading from untrusted sources.
4. Scan USB drives before use.
5. Keep OS and software updated.
6. Use a firewall.

---

## 3.5 Programming Language and Types of Language Translators

### Programming Language
A **programming language** is a formal language consisting of a set of instructions used to communicate with a computer and create programs.

### Levels of Programming Languages

#### 1. Machine Language (First Generation)
- Consists of binary code (0s and 1s).
- **Directly understood by the computer**.
- Machine-dependent (different for each CPU).
- Example: `10110000 01100001`
- Advantage: Fastest execution; Disadvantage: Very difficult to write and understand.

#### 2. Assembly Language (Second Generation)
- Uses mnemonics (short abbreviations) instead of binary.
- Example: `MOV AX, 5` instead of binary.
- Requires an **assembler** to translate to machine code.
- Still machine-dependent.
- Advantage: Easier than machine language; Disadvantage: Still complex, machine-specific.

#### 3. High-Level Languages (Third Generation – 3GL)
- Closer to human language; easy to read and write.
- **Machine-independent**.
- Requires a **compiler** or **interpreter**.
- Examples: C, C++, Java, Python, BASIC, FORTRAN, COBOL, Pascal.

#### 4. Very High-Level Languages (4GL)
- Closer to natural language; more abstract.
- Often used for database queries and report generation.
- Examples: SQL, MATLAB, R.

#### 5. Natural Language / AI Languages (5GL)
- Uses natural human language.
- Based on constraints and logic.
- Examples: Prolog, LISP (used in AI).

### Types of Language Translators

A **language translator** converts a program written in one language (source code) into machine language (object code).

#### 1. Assembler
- Translates **assembly language** into machine language.
- One-to-one translation (one assembly instruction → one machine instruction).
- Example: NASM, MASM.

```
Assembly Code → [ASSEMBLER] → Machine Code
```

#### 2. Compiler
- Translates **high-level language** into machine language **all at once**.
- Reads the entire program, checks for errors, then generates a complete machine code file (executable).
- The original source code is not needed to run the compiled program.
- **Faster execution** after compilation.
- Examples: GCC (C/C++), javac (Java bytecode).

```
Source Code → [COMPILER] → Object Code → [Linker] → Executable
```

#### 3. Interpreter
- Translates **high-level language** into machine language **line by line** at runtime.
- Translates and executes one statement at a time.
- **Slower execution** (re-translates every time).
- Stops at the first error encountered.
- Examples: Python interpreter, JavaScript engine.

```
Source Code → [INTERPRETER] → Executes line by line
```

### Compiler vs Interpreter

| Feature | Compiler | Interpreter |
|---|---|---|
| Translation | Entire program at once | Line by line |
| Speed | Faster (after compilation) | Slower (translates each run) |
| Error Detection | Shows all errors after compilation | Stops at first error |
| Output | Creates executable file | No separate executable |
| Memory | Requires more memory | Less memory |
| Examples | C, C++, Java (bytecode) | Python, PHP, JavaScript |

---

## TU Exam Format Questions – Unit 3

---

### 📝 Long Answer Questions (10 Marks)

**Q1. What is an operating system? Explain the functions of an operating system in detail.**

**Answer:**

**Definition:** An Operating System (OS) is system software that serves as an intermediary between the user and the computer hardware. It manages hardware resources, provides services to application programs, and offers a user-friendly interface.

**Functions of an Operating System:**

**1. Process Management:**
A process is a program in execution. The OS manages the lifecycle of all processes:
- **Process Creation**: When a user opens a program, the OS creates a process.
- **Process Scheduling**: The OS allocates CPU time to each process using scheduling algorithms like FCFS (First Come First Served), SJF (Shortest Job First), and Round Robin.
- **Process Termination**: Frees resources when a process finishes.
- **Deadlock Handling**: Prevents and resolves situations where two processes wait for each other's resources indefinitely.

**2. Memory Management:**
The OS manages the computer's primary memory (RAM):
- Tracks which parts of memory are in use and by whom.
- Allocates memory when a process needs it.
- Deallocates memory when a process finishes.
- Implements **virtual memory**: Uses disk space (paging/swapping) as an extension of RAM, allowing programs larger than physical RAM to run.

**3. File System Management:**
The OS organizes data on storage devices:
- Creates, reads, updates, and deletes files.
- Maintains a hierarchical directory (folder) structure.
- Controls access permissions (read, write, execute).
- Manages different file systems: NTFS, FAT32, ext4.

**4. Device Management (I/O Management):**
- Controls all I/O devices through device drivers.
- Manages communication between software and hardware.
- Uses **spooling** (e.g., print queue) to manage device requests.

**5. Security and Access Control:**
- Authenticates users with usernames and passwords.
- Implements file and directory permissions.
- Protects system from unauthorized programs.
- Maintains audit logs.

**6. User Interface:**
- **CLI**: Command-line interaction (Linux Bash, Windows CMD).
- **GUI**: Graphical interaction with icons, windows, menus (Windows, macOS).

**7. Error Detection and Recovery:**
- Monitors hardware and software for errors.
- Handles exceptions and error messages.
- Prevents one application crash from affecting the entire system.

**8. Networking:**
- Manages network connections and protocols.
- Provides inter-process communication.
- Implements TCP/IP stack.

---

**Q2. Differentiate between compiler and interpreter. Explain the types of programming languages.**

**Answer:**

**Compiler vs Interpreter:**

| Feature | Compiler | Interpreter |
|---|---|---|
| Translation method | Entire program at once | Line by line, at runtime |
| Execution speed | Fast (once compiled) | Slow (translates each time) |
| Error detection | Lists all errors after full scan | Stops at first error |
| Output file | Creates standalone executable | No standalone file |
| Memory usage | Requires more memory | Less memory |
| Debugging | Harder (must recompile) | Easier (stops at error line) |
| Examples | GCC (C/C++), javac | Python, JavaScript, PHP |
| Distribution | Can distribute compiled executable | Source code needed |

**Types of Programming Languages:**

**1. Machine Language (1GL):**
- Binary code (0 and 1) directly understood by CPU.
- Fastest execution, but nearly impossible for humans to write.
- Example: `10110000 01100001`

**2. Assembly Language (2GL):**
- Uses mnemonics (MOV, ADD, SUB) to represent machine instructions.
- Translated by an **assembler**.
- Machine-dependent.
- Used in system programming, embedded systems.
- Example: `MOV AX, 10` / `ADD AX, BX`

**3. High-Level Languages (3GL):**
- Human-readable syntax.
- Machine-independent.
- Require compiler or interpreter.
- Examples:
  - **FORTRAN** (1957): Scientific computing
  - **COBOL** (1959): Business applications
  - **C** (1972): System programming
  - **C++** (1983): Object-oriented programming
  - **Java** (1995): Platform-independent
  - **Python** (1991): General purpose, AI/ML

**4. Fourth Generation Languages (4GL):**
- Very high-level, closer to natural language.
- Focuses on *what* to do rather than *how*.
- Examples: SQL (database queries), MATLAB, R.
- `SELECT * FROM students WHERE grade = 'A'`

**5. Fifth Generation Languages (5GL):**
- Based on constraints and logic.
- Used in AI and expert systems.
- Examples: Prolog, Mercury, LISP.

---

### 📝 Short Answer Questions (5 Marks)

**Q3. What is a computer virus? Explain the types of viruses.**

**Answer:**

A **computer virus** is a malicious self-replicating program that attaches to legitimate files or programs, spreads to other computers, and can cause damage to data or the system.

**Types of Computer Viruses:**

**1. Boot Sector Virus:** Infects the Master Boot Record (MBR) of a hard disk or floppy. Loads before the OS, very difficult to remove. Example: Stone virus.

**2. File Infector Virus:** Attaches to executable files (.exe, .com). When the infected file runs, the virus activates and spreads. Example: Jerusalem virus.

**3. Macro Virus:** Infects document files that contain macros (MS Word, Excel). Spreads when infected documents are opened and shared. Example: Melissa virus.

**4. Worm:** A standalone program that replicates itself across networks without needing a host file. Spreads rapidly and consumes bandwidth. Example: ILOVEYOU, Morris Worm.

**5. Trojan Horse:** Disguises as a useful program but contains malicious code. Does not self-replicate. Example: Remcos RAT, keyloggers.

**6. Ransomware:** Encrypts victim's files and demands a ransom payment (usually cryptocurrency) to decrypt them. Example: WannaCry, Petya.

**7. Spyware:** Secretly monitors user activity and sends data to attackers. Collects passwords, browsing history, credit card numbers.

---

**Q4. Define utility software. Mention five types of utility software with examples.**

**Answer:**

**Utility software** is a type of system software designed to help maintain, manage, analyze, and optimize the performance of a computer.

**Five Types of Utility Software:**

1. **Antivirus Software:** Detects, prevents, and removes malicious software. Examples: Avast, Norton, Windows Defender. Performs signature-based and heuristic scanning.

2. **Disk Defragmenter:** Reorganizes fragmented data on a hard disk drive so that related pieces of files are stored contiguously, improving read speeds. Example: Windows built-in Disk Defragmenter.

3. **File Compression Utility:** Reduces file sizes to save disk space and facilitate faster data transfer. Creates compressed archives. Examples: WinZip, WinRAR, 7-Zip.

4. **Backup Software:** Creates copies of data that can be restored in case of data loss, hardware failure, or accidental deletion. Examples: Acronis True Image, Windows Backup and Restore.

5. **Disk Cleanup Utility:** Removes unnecessary files (temporary files, cache, recycle bin contents) to free up disk space. Example: Windows Disk Cleanup, CCleaner.

---

**Q5. What is system software? How does it differ from application software?**

**Answer:**

**System Software** is software that manages and controls the computer hardware and provides a platform for application software to run. It works in the background and is essential for the computer to function.

**Examples:** Operating System (Windows, Linux), Device Drivers, Language Translators, Utilities.

**Application Software** is software designed to help users perform specific tasks. It works in the foreground and interacts directly with the user.

**Examples:** MS Word, Adobe Photoshop, VLC Media Player, Google Chrome.

| Basis | System Software | Application Software |
|---|---|---|
| Purpose | Manages hardware resources | Helps users perform specific tasks |
| Necessity | Essential for computer to work | Optional; installed as needed |
| User interaction | Minimal (runs in background) | Direct user interaction |
| Development language | Low-level (C, Assembly) | High-level (Java, Python) |
| Dependence | Independent; base for apps | Depends on system software |
| Examples | Windows OS, Linux, drivers | MS Office, Chrome, Photoshop |

---

### 📝 Very Short / Objective Questions (1–2 Marks)

**Q6. What is the difference between a compiler and an assembler?**
→ A **compiler** translates high-level language to machine code. An **assembler** translates assembly language to machine code.

**Q7. Name any two types of operating systems.**
→ **Batch OS** and **Real-Time OS**

**Q8. What does GIGO stand for in the context of computing?**
→ **Garbage In, Garbage Out**

**Q9. What is a Trojan horse?**
→ A malicious program disguised as legitimate software that performs harmful actions when executed.

**Q10. Name two examples of 4th generation languages.**
→ **SQL** and **MATLAB**

**Q11. What is virtual memory?**
→ A technique where a portion of the hard disk is used as an extension of RAM, allowing programs larger than physical memory to run.

**Q12. What is spooling in OS?**
→ **Simultaneous Peripheral Operations On-Line** – a technique where data is temporarily stored (e.g., print queue) allowing the CPU to continue other tasks while a slow device (printer) catches up.

**Q13. Full form of GUI.**
→ **Graphical User Interface**

**Q14. Which type of virus infects the Master Boot Record?**
→ **Boot Sector Virus**

---

*End of Unit 3*
