# Unit 2: Computer Hardware
**BCA – Tribhuvan University | 10 Hours**

---

## 2.1 Basic Computer Organization and Architecture

### Computer Organization
Computer **organization** refers to the operational units of a computer and their interconnections that realize the architectural specifications. It deals with *how* hardware components are connected and work together.

### Computer Architecture
Computer **architecture** refers to the design of a computer system, including the instruction set, hardware components, and system organization. It deals with *what* a computer can do (from a programmer's perspective).

**Key Difference:**
| Organization | Architecture |
|---|---|
| Physical structure and implementation | Logical design and instruction set |
| Deals with hardware details | Deals with system design visible to programmers |
| Example: How CPU communicates with RAM | Example: Number of bits in an instruction |

### Von Neumann Architecture
Proposed by **John von Neumann** (1945). It is the basis of modern computer design.

**Key Concepts:**
1. Single memory space stores both data and instructions.
2. Instructions are executed sequentially.
3. Components: Input, CPU (ALU + CU + Registers), Memory, Output.
4. Data bus, Address bus, and Control bus connect components.

---

## 2.2 Component of Computer (Hardware, Software, User, Data, and Procedure)

A computer system consists of five components:

### 1. Hardware
The **physical** components of a computer that can be seen and touched.
- Input devices (keyboard, mouse)
- Processing unit (CPU)
- Memory (RAM, ROM, HDD)
- Output devices (monitor, printer)

### 2. Software
Set of instructions (programs) that tell hardware what to do.
- **System Software**: OS, utilities (Windows, Linux)
- **Application Software**: MS Word, Photoshop, browsers

### 3. User (Humanware/Liveware)
People who interact with the computer system:
- **End Users**: Who use applications
- **System Analysts**: Design systems
- **Programmers**: Write programs
- **Operators**: Maintain systems

### 4. Data
Raw, unprocessed facts and figures entered into the computer.
- Can be text, numbers, images, sound, video.
- After processing, data becomes **information**.

### 5. Procedure
Rules, instructions, and guidelines for using the computer system correctly.
- Documentation, manuals, and policies.

---

## 2.3 Component of CPU (ALU, CU, and RA)

The **Central Processing Unit (CPU)** is the brain of the computer. It has three main components:

### A. Arithmetic Logic Unit (ALU)
- Performs all **arithmetic operations**: addition, subtraction, multiplication, division.
- Performs all **logical operations**: comparisons (>, <, =), Boolean operations (AND, OR, NOT, XOR).
- Results are temporarily stored in the **Accumulator** register.

### B. Control Unit (CU)
- Manages and coordinates all CPU operations.
- Fetches instructions from memory (Fetch → Decode → Execute cycle).
- Does NOT process data itself; only controls the flow.
- Generates control signals to direct other units.

### C. Registers (RA – Register Array)
Registers are **small, ultra-fast storage locations** inside the CPU used to temporarily hold data during processing.

| Register | Full Form | Function |
|---|---|---|
| **PC** | Program Counter | Holds address of next instruction |
| **IR** | Instruction Register | Holds current instruction being executed |
| **AR** | Address Register | Holds memory address |
| **DR** | Data Register | Temporarily holds data |
| **AC** | Accumulator | Stores intermediate results |
| **MAR** | Memory Address Register | Address of memory to be accessed |
| **MDR** | Memory Data Register | Data to be written/read from memory |

---

## 2.4 Computer Memory and Memory Hierarchy

### Types of Memory

#### Primary Memory (Main Memory)
- Directly accessible by CPU.
- Fast but limited in size.

**RAM (Random Access Memory):**
- **Volatile** (data lost when power off)
- Used for running programs and current data
- Types: SRAM (Static RAM) – faster, expensive; DRAM (Dynamic RAM) – cheaper, slower

**ROM (Read Only Memory):**
- **Non-volatile** (data retained without power)
- Stores BIOS/firmware
- Types: PROM, EPROM, EEPROM

#### Secondary Memory (Auxiliary Memory)
- Not directly accessible by CPU.
- Non-volatile, large capacity, slower.
- Examples: Hard Disk Drive (HDD), SSD, CD/DVD, USB Flash Drive, Magnetic Tape

#### Cache Memory
- Very fast memory between CPU and RAM.
- Stores frequently used instructions/data.
- L1 Cache (inside CPU), L2 Cache, L3 Cache.

### Memory Hierarchy

```
         ┌──────────────┐  ← Fastest, Most Expensive, Smallest
         │   Registers  │
         ├──────────────┤
         │ Cache Memory │  (L1, L2, L3)
         ├──────────────┤
         │     RAM      │  (Primary Memory)
         ├──────────────┤
         │  Hard Disk   │  (Secondary Memory)
         ├──────────────┤
         │  Optical /   │
         │  Tape Drive  │  ← Slowest, Cheapest, Largest
         └──────────────┘
```

### Primary vs Secondary Memory

| Primary Memory | Secondary Memory |
|---|---|
| Directly accessed by CPU | Not directly accessed by CPU |
| Volatile (RAM) | Non-volatile |
| Fast but expensive | Slower but cheaper |
| Limited capacity | Large capacity |
| Example: RAM, ROM | Example: HDD, SSD, CD |

---

## 2.5 Motherboard and Its Parts, Slots, Ports, Interface, Processor, Memory Chips

### Motherboard
The **motherboard** (also called system board or mainboard) is the main printed circuit board (PCB) of a computer. It connects all components together.

### Key Components on the Motherboard

| Component | Description |
|---|---|
| **CPU Socket** | Where the processor is installed (e.g., LGA 1200 for Intel) |
| **RAM Slots (DIMM)** | Slots for installing memory modules |
| **PCIe Slots** | For graphics cards, sound cards, network cards |
| **SATA Ports** | For connecting HDD, SSD, optical drives |
| **USB Headers** | Internal connectors for front-panel USB ports |
| **BIOS Chip** | Stores firmware for booting the computer |
| **CMOS Battery** | Maintains BIOS settings and system clock |
| **Chipset (Northbridge/Southbridge)** | Controls data flow between CPU, RAM, and peripherals |
| **Power Connector (ATX)** | 24-pin power supply connector |
| **VRM (Voltage Regulator Module)** | Regulates voltage to the CPU |

### Ports on Motherboard (Rear Panel)
- **USB Ports** (2.0, 3.0, 3.1, Type-C)
- **HDMI / DisplayPort / VGA** – Video output
- **Ethernet (RJ-45)** – Network
- **Audio Jacks** – 3.5mm audio in/out
- **PS/2 Ports** – Legacy keyboard/mouse

### Processor
The **processor (CPU)** is plugged into the CPU socket. Modern processors:
- Intel Core i3/i5/i7/i9
- AMD Ryzen 3/5/7/9
- Measured in GHz (clock speed)
- Multi-core architecture

### Memory Chips
- **DIMM** (Dual Inline Memory Module) – Standard desktop RAM
- **SO-DIMM** – Laptop RAM
- **DDR4, DDR5** – Current RAM standards

---

## 2.6 BIOS, SMPS, CMOS, and Microprocessor Chips

### BIOS (Basic Input/Output System)
- Firmware stored on a ROM chip on the motherboard.
- **Function**: Performs POST (Power-On Self-Test), initializes hardware, and loads the operating system from the boot device.
- Modern systems use **UEFI** (Unified Extensible Firmware Interface) instead of legacy BIOS.
- Settings stored in **CMOS** memory.

### SMPS (Switch Mode Power Supply)
- Converts **AC current** from the wall into **DC current** required by computer components.
- Provides multiple voltages: +12V, +5V, +3.3V.
- Connects to motherboard via ATX 24-pin connector.
- Has a **fan** for cooling.
- Measured in **Watts** (e.g., 500W, 750W PSU).

### CMOS (Complementary Metal-Oxide-Semiconductor)
- A small memory chip on the motherboard powered by a **coin cell battery** (CR2032).
- Stores BIOS configuration settings: date/time, boot sequence, hardware configuration.
- **CMOS battery** maintains these settings even when the computer is off.
- If battery fails, BIOS resets to default.

### Microprocessor Chips
- An **integrated circuit (IC)** that contains the entire CPU on a single chip.
- Invented by **Intel** in 1971 (Intel 4004 – first microprocessor).
- Modern microprocessors contain **billions of transistors**.
- Key specifications:
  - **Clock Speed**: GHz (how many cycles per second)
  - **Cores**: Number of processing units (dual-core, quad-core, octa-core)
  - **Cache Size**: L1, L2, L3 cache
  - **Architecture**: 32-bit vs 64-bit

**Examples of Microprocessors:**
- Intel 8086, 80286, 80386, 80486, Pentium series, Core i-series
- AMD Athlon, Ryzen series
- Apple M1, M2 (ARM-based)

---

## TU Exam Format Questions – Unit 2

---

### 📝 Long Answer Questions (10 Marks)

**Q1. Explain the memory hierarchy of a computer with a diagram. Differentiate between primary and secondary memory.**

**Answer:**

**Memory Hierarchy** organizes different types of memory based on speed, cost, and capacity. As we go up the hierarchy, memory becomes faster and more expensive but smaller in capacity.

```
         ┌──────────────────────┐
         │      Registers       │  ← Nanoseconds, Very Expensive
         ├──────────────────────┤
         │    Cache Memory      │  ← (L1 < 1ns, L2 ~5ns, L3 ~20ns)
         │    (L1, L2, L3)      │
         ├──────────────────────┤
         │    Main Memory       │  ← RAM (~100ns)
         │       (RAM)          │
         ├──────────────────────┤
         │   Secondary Memory   │  ← HDD (~10ms), SSD (~0.1ms)
         │   (HDD, SSD, USB)    │
         ├──────────────────────┤
         │   Tertiary Storage   │  ← Magnetic Tape, Optical (slowest)
         └──────────────────────┘
              ↑ Speed/Cost               ↓ Capacity/Size
```

**Levels Explained:**

**1. Registers:** Fastest memory, located inside the CPU. Stores data being immediately processed. Very small (a few bytes).

**2. Cache Memory:** A bridge between CPU registers and RAM. Stores frequently accessed data/instructions. L1 is inside CPU; L2 and L3 may be shared between cores. Size: KB to MB.

**3. Main Memory (RAM):** Temporary working memory. CPU loads programs and data here before processing. Volatile. Size: GB range.

**4. Secondary Memory:** Permanent storage. Not directly accessible by CPU. Non-volatile. Size: GB to TB. Examples: HDD (Hard Disk Drive), SSD, USB Flash Drive.

**5. Tertiary Storage:** Used for archiving large amounts of data. Very slow, cheapest per GB. Examples: Magnetic tape, cloud storage.

**Primary vs Secondary Memory:**

| Feature | Primary Memory | Secondary Memory |
|---|---|---|
| Speed | Very fast | Slow |
| Volatility | Volatile (RAM) | Non-volatile |
| Access | Directly by CPU | Via I/O channels |
| Capacity | Limited (GB) | Large (TB) |
| Cost | Expensive per GB | Cheap per GB |
| Examples | RAM, ROM, Cache | HDD, SSD, CD-ROM, USB |
| Purpose | Active processing | Permanent storage |

---

**Q2. What is a motherboard? Explain its major components in detail.**

**Answer:**

**Definition:** A motherboard is the main printed circuit board (PCB) of a computer. It is the central backbone that connects all hardware components, allowing them to communicate with each other.

**Major Components:**

**1. CPU Socket:** The slot where the processor is installed. Different CPUs require different socket types (e.g., Intel LGA 1200, AMD AM4). Locks the CPU in place with a ZIF (Zero Insertion Force) mechanism.

**2. RAM Slots (DIMM Slots):** Usually 2 to 4 slots for inserting RAM modules. Supports DDR4 or DDR5 memory. Dual-channel configuration improves performance.

**3. PCIe (Peripheral Component Interconnect Express) Slots:**
- PCIe x16: For discrete graphics cards (GPU)
- PCIe x1: For sound cards, network cards
- Provides high-bandwidth data transfer

**4. SATA Ports:** Serial ATA interfaces for connecting hard drives, SSDs, and optical drives. Supports SATA I/II/III (speeds up to 6 Gbps).

**5. M.2 Slot:** High-speed slot for NVMe SSDs. Much faster than SATA (up to 32 Gbps).

**6. BIOS/UEFI Chip:** ROM chip storing firmware. Controls hardware initialization during startup.

**7. CMOS Battery (CR2032):** Small lithium battery. Powers CMOS chip to retain BIOS settings, date/time when computer is off.

**8. Chipset:** Controls communication between CPU, RAM, and I/O devices. Modern Intel boards have a single PCH (Platform Controller Hub).

**9. Power Connectors:** 24-pin ATX main power and 4/8-pin CPU power connectors from SMPS.

**10. I/O Ports (Rear Panel):** USB (2.0, 3.0, 3.2, Type-C), HDMI, DisplayPort, Ethernet (RJ-45), audio jacks.

**11. Front Panel Headers:** Connectors for power button, reset button, HDD LED, front USB, audio.

**12. USB Headers:** Internal connectors for additional USB ports on the case.

---

### 📝 Short Answer Questions (5 Marks)

**Q3. What is BIOS? Explain its functions.**

**Answer:**

**BIOS** (Basic Input/Output System) is firmware stored in a non-volatile ROM chip on the motherboard.

**Functions of BIOS:**

1. **POST (Power-On Self-Test):** When the computer starts, BIOS tests all hardware components (RAM, CPU, keyboard, storage) to ensure they work correctly. If a problem is detected, it produces beep codes.

2. **Bootstrap Loader:** Finds and loads the operating system from the boot device (HDD, SSD, USB) into RAM.

3. **BIOS Setup:** Allows users to configure hardware settings (boot order, CPU clock, RAM timing) through the BIOS Setup utility (accessed by pressing Del, F2, or F12 during startup).

4. **Hardware Initialization:** Identifies and configures installed hardware (RAM, CPU, storage).

5. **Interrupt Handling:** Provides low-level interrupt services for communication between OS and hardware.

**Modern Replacement:** UEFI (Unified Extensible Firmware Interface) has largely replaced legacy BIOS. UEFI supports larger hard drives (>2TB), faster boot times, and a graphical interface.

---

**Q4. Explain SMPS and its role in a computer system.**

**Answer:**

**SMPS** (Switch Mode Power Supply) is the power supply unit (PSU) of a computer. It converts the **alternating current (AC)** from the electrical outlet into the **direct current (DC)** required by computer components.

**How it works:** It uses high-frequency switching transistors to efficiently convert and regulate power, which makes it more efficient than linear power supplies.

**Output Voltages:**
- **+12V**: Powers CPU, GPU, motors
- **+5V**: Powers motherboard, USB, older components
- **+3.3V**: Powers RAM, modern chipsets

**Key Features:**
- Measured in **Watts** (e.g., 500W, 650W, 800W)
- Has protection circuits: Over-voltage, under-voltage, short-circuit
- Contains a **fan** for cooling
- Connected to motherboard via 24-pin ATX connector
- **80 PLUS Certification** indicates efficiency rating (Bronze, Silver, Gold, Platinum)

**Importance:** Without a stable SMPS, the computer would not function. An inadequate PSU can cause crashes, data loss, or hardware damage.

---

**Q5. What is a microprocessor? Describe its key characteristics.**

**Answer:**

A **microprocessor** is a single integrated circuit (IC) chip that contains the complete central processing unit (CPU) of a computer. It was invented by Intel in 1971 (Intel 4004).

**Key Characteristics:**

1. **Clock Speed (GHz):** The number of instruction cycles per second. Higher GHz = faster processing. Modern CPUs operate at 3–5 GHz.

2. **Number of Cores:** Each core is an independent processing unit. Dual-core, quad-core, octa-core processors can handle multiple tasks simultaneously (multitasking).

3. **Cache Memory:** Built-in fast memory (L1, L2, L3). Reduces time to access frequently used data.

4. **Word Length:** Number of bits processed at once. Modern processors are **64-bit**, meaning they can address 2^64 memory locations.

5. **Instruction Set Architecture (ISA):** RISC (Reduced Instruction Set Computing) – ARM processors; CISC (Complex Instruction Set Computing) – Intel x86.

6. **Transistor Count:** Modern processors contain billions of transistors on a tiny chip (e.g., Apple M2 has 20 billion transistors).

7. **Power Consumption:** Measured in watts (TDP – Thermal Design Power).

---

**Q6. Define register. List and explain the types of registers in a CPU.**

**Answer:**

A **register** is a small, extremely fast storage location built directly into the CPU. It temporarily holds data, instructions, or addresses that the CPU is currently using.

**Types of Registers:**

1. **Program Counter (PC):** Holds the memory address of the next instruction to be fetched. Automatically increments after each instruction.

2. **Instruction Register (IR):** Holds the current instruction being decoded and executed.

3. **Accumulator (AC):** Stores intermediate arithmetic and logic results. Main working register of the ALU.

4. **Memory Address Register (MAR):** Holds the address in memory that the CPU wants to read from or write to.

5. **Memory Data Register (MDR) / Memory Buffer Register (MBR):** Holds the data that has been fetched from or is about to be written to memory.

6. **Index Register:** Used to modify operand addresses (useful in loops and arrays).

7. **Stack Pointer (SP):** Points to the top of the call stack in memory.

8. **Flag Register (Status Register):** Contains bits (flags) that indicate the result of operations: Zero flag, Carry flag, Sign flag, Overflow flag.

---

### 📝 Very Short / Objective Questions (1–2 Marks)

**Q7. What does SMPS stand for?**
→ **Switch Mode Power Supply**

**Q8. What is the function of CMOS battery?**
→ To maintain BIOS settings (date, time, boot order) when the computer is powered off.

**Q9. What is cache memory?**
→ A small, very fast memory located between the CPU and RAM that stores frequently accessed data to speed up processing.

**Q10. Name the first microprocessor.**
→ **Intel 4004** (1971)

**Q11. What does POST stand for?**
→ **Power-On Self-Test**

**Q12. What is the difference between RAM and ROM?**
→ RAM is volatile (data lost when power off), read/write. ROM is non-volatile (data retained), read-only.

**Q13. What is UEFI?**
→ **Unified Extensible Firmware Interface** – modern replacement for BIOS.

**Q14. What type of bus transfers memory addresses from CPU to RAM?**
→ **Address Bus**

**Q15. What is the purpose of PCIe slots on a motherboard?**
→ To connect expansion cards such as graphics cards, sound cards, and network interface cards.

**Q16. What is the full form of ALU?**
→ **Arithmetic Logic Unit**

**Q17. Give two examples of secondary storage devices.**
→ **Hard Disk Drive (HDD)** and **Solid State Drive (SSD)**

---

*End of Unit 2*
