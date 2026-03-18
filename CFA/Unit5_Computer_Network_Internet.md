# Unit 5: Computer Network and Internet
**BCA – Tribhuvan University | 5 Hours**

---

## 5.1 Introduction to Networks, Intranet, Internet

### What is a Computer Network?
A **computer network** is a collection of two or more computers and other devices (printers, servers) connected together to share resources, data, and services.

**Advantages of Computer Networks:**
1. **Resource Sharing**: Share printers, hard disks, internet connections.
2. **Communication**: Email, instant messaging, video conferencing.
3. **Data Sharing**: Transfer files and access shared databases.
4. **Centralized Management**: Manage all systems from a central server.
5. **Cost Efficiency**: Shared resources reduce costs.
6. **Reliability**: Data backup across multiple machines.

### Intranet
An **intranet** is a private network restricted to members of an organization. It uses internet technologies (TCP/IP, web browsers) but is accessible only internally.

- Example: A company's internal website for employees to access HR policies, news, and shared documents.
- **Secure**: Protected by firewalls from outside access.
- Used for internal communication, document sharing, project management.

### Extranet
An **extranet** extends the intranet to authorized external users (suppliers, partners, customers) via the internet.

### Internet
The **Internet** is a global network of networks — billions of computers connected worldwide using the **TCP/IP** protocol suite.

**Key Internet Services:**
- **WWW (World Wide Web)**: Collection of web pages accessed via browsers.
- **Email**: Electronic messaging (SMTP, POP3, IMAP).
- **FTP**: File Transfer Protocol for uploading/downloading files.
- **VoIP**: Voice over Internet Protocol (Skype, Zoom).
- **Telnet/SSH**: Remote login to computers.
- **Streaming**: Audio/video streaming (YouTube, Spotify).

**Intranet vs Internet:**

| Feature | Intranet | Internet |
|---|---|---|
| Accessibility | Private (organization only) | Public (worldwide) |
| Security | High (firewall protected) | Lower (needs security measures) |
| Ownership | Owned by an organization | No single owner |
| Size | Small (within organization) | Global |
| Cost | Lower bandwidth cost | Higher but shared globally |

---

## 5.2 Types of Networks and LAN Topologies

### Types of Networks Based on Area

#### 1. PAN (Personal Area Network)
- Range: ~10 meters
- Personal devices around a single individual
- Examples: Bluetooth, infrared (TV remote), personal hotspot
- Uses: Wireless headphones, smartwatch to phone sync

#### 2. LAN (Local Area Network)
- Range: Within a building or campus (up to ~1 km)
- Owned and managed by a single organization
- High speed (100 Mbps to 10 Gbps)
- Uses: School labs, office networks
- Technologies: Ethernet, Wi-Fi

#### 3. MAN (Metropolitan Area Network)
- Range: City-wide (~10–100 km)
- Connects multiple LANs within a city
- Examples: Cable TV network, city-wide Wi-Fi
- Higher speed than WAN

#### 4. WAN (Wide Area Network)
- Range: Country or worldwide
- Connects LANs and MANs over large distances
- Lower speed than LAN
- Examples: The Internet, PSTN (telephone network)
- Technologies: Leased lines, satellite, fiber optic

| Type | Range | Speed | Example |
|---|---|---|---|
| PAN | ~10m | Low | Bluetooth, USB |
| LAN | ~1 km | Very High | Office network |
| MAN | ~100 km | High | City network |
| WAN | Worldwide | Lower | Internet |

### LAN Topologies
**Network topology** describes how devices (nodes) are physically or logically arranged and connected in a network.

#### 1. Bus Topology
```
Computer1 — Computer2 — Computer3 — Computer4
         ←─────────────────────────────→
                  Single Backbone Cable
```
- All devices connected to a single central cable (backbone).
- Data travels in both directions along the bus.
- **Advantages**: Simple, cheap, easy to install.
- **Disadvantages**: If backbone cable fails, entire network fails. Performance degrades with more devices.

#### 2. Star Topology
```
     Computer1
          \
Computer4 — HUB/SWITCH — Computer2
          /
     Computer3
```
- All devices connected to a central hub or switch.
- Most common topology in modern LANs.
- **Advantages**: Easy to add/remove devices; a single cable failure doesn't affect others; easy troubleshooting.
- **Disadvantages**: If the hub/switch fails, entire network fails; requires more cable.

#### 3. Ring Topology
```
Computer1 → Computer2 → Computer3 → Computer4 → Computer1
```
- Devices connected in a circular loop; each device connects to exactly two neighbors.
- Data travels in one direction (or both in dual-ring).
- **Token Ring**: A token is passed around; only the device holding the token can transmit.
- **Advantages**: Equal access for all devices; no collision.
- **Disadvantages**: Single device failure can disrupt the network; difficult to troubleshoot.

#### 4. Mesh Topology
- Every device connects to every other device.
- **Full Mesh**: n(n-1)/2 connections for n devices.
- **Partial Mesh**: Some devices have multiple connections.
- **Advantages**: Highly fault-tolerant; no single point of failure; high reliability.
- **Disadvantages**: Very expensive; complex installation.

#### 5. Tree (Hierarchical) Topology
- Hybrid of bus and star topology.
- Devices arranged in a hierarchical manner.
- Used in wide-area networks.
- **Advantages**: Scalable; easy to add segments.
- **Disadvantages**: If backbone fails, entire segment fails.

#### 6. Hybrid Topology
- Combination of two or more topologies.
- Most real-world networks use hybrid topology.

---

## 5.3 Transmission Media and Network Devices

### Transmission Media
**Transmission media** is the physical path through which data travels from sender to receiver.

#### A. Wired (Guided) Media

**1. Twisted Pair Cable:**
- Pairs of copper wires twisted together to reduce electromagnetic interference.
- **UTP (Unshielded Twisted Pair)**: Common; used in Ethernet (Cat5e, Cat6, Cat6a).
- **STP (Shielded Twisted Pair)**: Has additional shielding; used in high-interference environments.
- Speed: 10 Mbps to 10 Gbps depending on category.
- Inexpensive and easy to install.

**2. Coaxial Cable:**
- Central copper conductor surrounded by insulation, metallic shield, and outer jacket.
- Better noise resistance than twisted pair.
- Used for cable TV, older Ethernet (10Base2, 10Base5).
- Speed: Up to 10 Gbps.

**3. Fiber Optic Cable:**
- Uses light (photons) to transmit data through glass or plastic fiber.
- **Fastest** transmission medium available.
- **Single-mode fiber**: Long-distance, thin core, laser light.
- **Multi-mode fiber**: Shorter distances, LED light.
- **Advantages**: Very high speed (100 Gbps+), immune to electromagnetic interference, very low signal loss, secure.
- **Disadvantages**: Expensive, fragile, difficult to install.

#### B. Wireless (Unguided) Media

**1. Radio Waves:**
- Frequency: 3 Hz to 300 GHz.
- Used for Wi-Fi (2.4 GHz, 5 GHz), AM/FM radio, Bluetooth.
- Travels through walls and obstacles.

**2. Microwaves:**
- High-frequency radio waves (300 MHz to 300 GHz).
- Requires line-of-sight transmission.
- Used for satellite communication, cellular networks, microwave towers.

**3. Infrared:**
- Short-range communication.
- Requires line-of-sight.
- Used in TV remotes, old mobile phones (IrDA).

**4. Satellite:**
- Geostationary satellites at ~36,000 km altitude.
- Cover large geographic areas.
- Used for GPS, satellite TV, international internet connectivity.
- **Disadvantage**: High latency (~250ms round trip).

### Network Devices

| Device | Function |
|---|---|
| **Hub** | Broadcasts data to all connected devices; Layer 1; dumb device |
| **Switch** | Sends data only to the intended recipient; Layer 2; uses MAC addresses |
| **Router** | Connects different networks; routes packets using IP addresses; Layer 3 |
| **Repeater** | Amplifies weak signals to extend network distance |
| **Bridge** | Connects two similar network segments; Layer 2 |
| **Gateway** | Connects networks with different protocols; acts as a translator |
| **Modem** | Converts digital signals to analog (modulation) and back (demodulation) for transmission over telephone lines |
| **Access Point (AP)** | Provides wireless connectivity in a wired network (Wi-Fi) |
| **Firewall** | Monitors and controls incoming/outgoing network traffic based on security rules |
| **NIC (Network Interface Card)** | Hardware that allows a computer to connect to a network |

---

## 5.4 Data Communication and Transmission Mode

### Data Communication
**Data communication** is the exchange of data between devices through a transmission medium.

**Components of Data Communication:**
1. **Sender**: Device that sends data (e.g., computer).
2. **Receiver**: Device that receives data (e.g., another computer).
3. **Message**: The data being communicated (text, audio, video).
4. **Transmission Medium**: Physical path (cable, air).
5. **Protocol**: Rules governing communication (TCP/IP, HTTP).

### Transmission Modes
**Transmission mode** (communication mode) defines the direction of data flow between two devices.

#### 1. Simplex Mode
- Data flows in **one direction only**.
- Sender can only send; receiver can only receive.
- Example: Television broadcast, keyboard to CPU.
- **Advantage**: Simple; full channel used for transmission.

```
Computer A ──────────────────► Computer B
         (sends only)          (receives only)
```

#### 2. Half-Duplex Mode
- Data flows in **both directions**, but **not simultaneously**.
- Only one device can transmit at a time.
- Example: Walkie-talkie, CB radio.
- **Advantage**: Both directions possible.
- **Disadvantage**: Cannot transmit and receive at the same time.

```
Computer A ◄─────────────────► Computer B
         (one at a time)
```

#### 3. Full-Duplex Mode
- Data flows in **both directions simultaneously**.
- Both devices can send and receive at the same time.
- Example: Telephone call, modern network switches.
- **Advantage**: Most efficient use of bandwidth.

```
Computer A ◄══════════════════► Computer B
         (simultaneously both ways)
```

| Mode | Direction | Example |
|---|---|---|
| Simplex | One way only | TV broadcast, keyboard |
| Half-Duplex | Both ways, not simultaneously | Walkie-talkie |
| Full-Duplex | Both ways simultaneously | Phone call, internet |

### Data Transmission Modes (Serial vs Parallel)

**Serial Transmission:**
- Bits are sent one at a time over a single channel.
- Slower but used for long distances.
- Examples: USB, Ethernet, fiber optic.

**Parallel Transmission:**
- Multiple bits sent simultaneously over multiple channels.
- Faster but expensive; used for short distances.
- Example: Old printer ports (parallel port).

### Analog vs Digital Signal
- **Analog Signal**: Continuous wave; varies smoothly. Example: Traditional telephone.
- **Digital Signal**: Discrete values (0 and 1). Example: Modern networks.
- **Bandwidth**: The range of frequencies a channel can transmit; measured in Hz (analog) or bps (digital).

---

## 5.5 OSI Reference Model and Network Protocol

### OSI Model (Open Systems Interconnection)
The **OSI model** is a conceptual framework developed by ISO that standardizes the communication functions of a telecommunication or computing system into **7 layers**.

```
┌────────────────────────────────────┐
│  Layer 7: Application Layer        │  HTTP, FTP, SMTP, DNS
├────────────────────────────────────┤
│  Layer 6: Presentation Layer       │  Encryption, Data Format (JPEG, MP4)
├────────────────────────────────────┤
│  Layer 5: Session Layer            │  Session management, Authentication
├────────────────────────────────────┤
│  Layer 4: Transport Layer          │  TCP, UDP (Port numbers, Segmentation)
├────────────────────────────────────┤
│  Layer 3: Network Layer            │  IP, ICMP (IP Addressing, Routing)
├────────────────────────────────────┤
│  Layer 2: Data Link Layer          │  Ethernet, MAC Addressing, Switches
├────────────────────────────────────┤
│  Layer 1: Physical Layer           │  Cables, Hubs, Bits (0s and 1s)
└────────────────────────────────────┘
```

**Mnemonic:** "**A**ll **P**eople **S**eem **T**o **N**eed **D**ata **P**rocessing"

| Layer | Name | Function | Protocol/Device |
|---|---|---|---|
| 7 | **Application** | User interface; network services to apps | HTTP, HTTPS, FTP, SMTP, DNS |
| 6 | **Presentation** | Data translation, encryption, compression | SSL/TLS, JPEG, ASCII |
| 5 | **Session** | Establishes, manages, terminates sessions | NetBIOS, PPTP |
| 4 | **Transport** | Reliable end-to-end delivery, flow control | TCP, UDP |
| 3 | **Network** | Logical addressing, routing | IP, ICMP, Routers |
| 2 | **Data Link** | Physical addressing (MAC), error detection | Ethernet, Switches, Wi-Fi |
| 1 | **Physical** | Transmits raw bits over physical medium | Cables, Hubs, NIC |

### TCP/IP Model
The **TCP/IP model** is the practical model used on the internet. It has 4 layers:

| TCP/IP Layer | OSI Equivalent |
|---|---|
| Application | Application + Presentation + Session |
| Transport | Transport |
| Internet | Network |
| Network Access | Data Link + Physical |

### Network Protocols

| Protocol | Full Form | Function |
|---|---|---|
| **TCP** | Transmission Control Protocol | Reliable, connection-oriented data transfer |
| **UDP** | User Datagram Protocol | Fast, connectionless, unreliable transfer |
| **IP** | Internet Protocol | Logical addressing and routing |
| **HTTP** | HyperText Transfer Protocol | Web page transfer |
| **HTTPS** | HTTP Secure | Encrypted web browsing |
| **FTP** | File Transfer Protocol | File upload/download |
| **SMTP** | Simple Mail Transfer Protocol | Sending emails |
| **POP3/IMAP** | Post Office Protocol / Internet Message Access Protocol | Receiving emails |
| **DNS** | Domain Name System | Converts domain names to IP addresses |
| **DHCP** | Dynamic Host Configuration Protocol | Assigns IP addresses automatically |
| **ICMP** | Internet Control Message Protocol | Error reporting (ping) |
| **ARP** | Address Resolution Protocol | Maps IP address to MAC address |

---

## 5.6 Concept of Web, WWW, URL, DNS, Client-Server

### World Wide Web (WWW)
The **World Wide Web** is an information system where documents (web pages) are linked using hyperlinks and accessed via the internet using web browsers. Invented by **Tim Berners-Lee** in 1989 at CERN.

**Web ≠ Internet:** The internet is the infrastructure; the web is one service that runs on it.

### Web Terminology

**Web Page:** A single document written in HTML, displayed in a browser.

**Website:** A collection of related web pages under a common domain name.

**Web Browser:** Software to access and display web pages (Chrome, Firefox, Edge, Safari).

**Web Server:** A computer that hosts websites and responds to HTTP requests (Apache, Nginx, IIS).

### URL (Uniform Resource Locator)
A **URL** is the address of a resource on the web.

**Structure of a URL:**
```
https://www.example.com:443/path/page.html?query=value#section
│       │   │           │   │             │           │
│       │   │           │   │             │           Fragment
│       │   │           │   │             Query String
│       │   │           │   Path
│       │   │           Port (optional)
│       │   Domain Name
│       Subdomain
Protocol (Scheme)
```

**Parts:**
- **Protocol**: http, https, ftp
- **Domain Name**: The address of the web server (e.g., www.tu.edu.np)
- **Port**: Optional (default 80 for HTTP, 443 for HTTPS)
- **Path**: Location of the specific resource on the server
- **Query String**: Additional parameters (?search=BCA)

### DNS (Domain Name System)
**DNS** is a distributed hierarchical system that translates **human-readable domain names** (www.google.com) into **machine-readable IP addresses** (142.250.0.1).

**How DNS works:**
1. User types `www.google.com` in browser.
2. Computer checks local DNS cache.
3. If not found, queries the **Recursive DNS Resolver** (ISP's DNS server).
4. Resolver queries **Root Name Server** → **TLD Name Server** (.com server) → **Authoritative Name Server** (Google's DNS).
5. IP address returned to the browser.
6. Browser connects to that IP address.

**DNS Record Types:**
- **A Record**: Maps domain to IPv4 address.
- **AAAA Record**: Maps domain to IPv6 address.
- **MX Record**: Mail exchange server.
- **CNAME**: Canonical name (alias).
- **NS Record**: Name server for the domain.

### Client-Server Model
In the **client-server model**, clients request services and servers provide them.

```
     Client                         Server
  (Web Browser)   ──HTTP Request──►  (Web Server)
                  ◄──HTTP Response──
```

**Client:** Device that requests a service (browser, email client, phone app).

**Server:** Device that provides a service (web server, database server, file server).

**Characteristics:**
- Servers wait for requests; clients initiate communication.
- One server can serve many clients.
- Servers are more powerful and have dedicated resources.

**Types of Servers:**
- **Web Server**: Serves web pages (Apache, Nginx).
- **Database Server**: Manages databases (MySQL, Oracle).
- **File Server**: Stores and shares files (FTP server, NAS).
- **Mail Server**: Manages emails (Sendmail, Exchange).
- **DNS Server**: Resolves domain names.

---

## TU Exam Format Questions – Unit 5

---

### 📝 Long Answer Questions (10 Marks)

**Q1. Explain the OSI reference model with a diagram. Describe the functions of each layer.**

**Answer:**

**OSI Model:** The Open Systems Interconnection (OSI) model is a conceptual framework developed by the ISO (International Standards Organization) in 1984 that divides network communication into 7 layers, each with specific functions.

**Diagram:**
```
         Sender                              Receiver
┌────────────────────┐               ┌────────────────────┐
│ 7. Application     │◄─────────────►│ 7. Application     │
├────────────────────┤               ├────────────────────┤
│ 6. Presentation    │               │ 6. Presentation    │
├────────────────────┤               ├────────────────────┤
│ 5. Session         │               │ 5. Session         │
├────────────────────┤               ├────────────────────┤
│ 4. Transport       │               │ 4. Transport       │
├────────────────────┤               ├────────────────────┤
│ 3. Network         │               │ 3. Network         │
├────────────────────┤               ├────────────────────┤
│ 2. Data Link       │               │ 2. Data Link       │
├────────────────────┤               ├────────────────────┤
│ 1. Physical        │◄─── Media ───►│ 1. Physical        │
└────────────────────┘               └────────────────────┘
```

**Layer-by-Layer Description:**

**Layer 1 – Physical Layer:**
- Deals with the physical transmission of raw bits (0s and 1s) over a medium.
- Defines hardware specifications: cables, connectors, voltages, frequencies.
- Devices: Cables, Hubs, Repeaters, NIC.
- Protocols: Ethernet (physical), USB, Bluetooth (physical).

**Layer 2 – Data Link Layer:**
- Responsible for node-to-node delivery (between devices on the same network).
- Uses **MAC (Media Access Control) addresses** to identify devices.
- Performs error detection (CRC – Cyclic Redundancy Check).
- Divides data into **frames**.
- Devices: Switches, Bridges.
- Protocols: Ethernet (802.3), Wi-Fi (802.11), PPP.
- Sub-layers: LLC (Logical Link Control) and MAC.

**Layer 3 – Network Layer:**
- Responsible for end-to-end delivery across multiple networks (routing).
- Uses **IP addresses** for logical addressing.
- Divides data into **packets**.
- Determines the best path from source to destination (**routing**).
- Devices: Routers.
- Protocols: IP (IPv4/IPv6), ICMP, OSPF, BGP.

**Layer 4 – Transport Layer:**
- Provides reliable end-to-end communication between applications.
- **Segmentation**: Divides data into segments and reassembles at destination.
- **Flow control**: Prevents overwhelming the receiver.
- **Error recovery**: Retransmits lost segments.
- **TCP (Transmission Control Protocol)**: Reliable, connection-oriented.
- **UDP (User Datagram Protocol)**: Unreliable, connectionless, fast.
- Uses **port numbers** to identify applications.

**Layer 5 – Session Layer:**
- Establishes, manages, and terminates communication sessions between applications.
- Handles session authentication, authorization, and synchronization.
- Manages half-duplex vs full-duplex sessions.
- Protocols: NetBIOS, RPC (Remote Procedure Call).

**Layer 6 – Presentation Layer:**
- Acts as a translator between the application and the network.
- **Data translation**: Converts data formats (EBCDIC to ASCII).
- **Encryption/Decryption**: SSL/TLS encrypts data here.
- **Compression**: Reduces data size for transmission.
- Protocols: SSL/TLS, JPEG, MPEG, ASCII, EBCDIC.

**Layer 7 – Application Layer:**
- The topmost layer; directly interacts with user applications.
- Provides network services to applications.
- Handles protocols for specific application types.
- Protocols: HTTP, HTTPS (web), SMTP/POP3/IMAP (email), FTP (file transfer), DNS, DHCP.

---

**Q2. What are LAN topologies? Compare and contrast bus, star, and ring topologies.**

**Answer:**

**Network Topology** is the arrangement of nodes (computers, devices) and the links (cables) connecting them in a network.

**Bus Topology:**

```
T ─── Computer1 ─── Computer2 ─── Computer3 ─── Computer4 ─── T
     (Terminator)                              (Terminator)
            ←──────────── Single Coaxial Cable ────────────→
```

In bus topology, all devices are connected to a single backbone cable. Data is broadcast to all devices, but only the intended recipient accepts it. Terminators are required at both ends.

**Advantages:** Cheap, simple, easy to implement for small networks.
**Disadvantages:** Backbone failure brings down entire network; performance degrades with load; difficult to troubleshoot; limited cable length.

---

**Star Topology:**

```
        Computer1
             |
Computer4 ── Switch/Hub ── Computer2
             |
        Computer3
```

All devices connect to a central switch or hub. Most widely used topology in modern networks.

**Advantages:** Single cable failure doesn't affect others; easy to add/remove devices; easy fault isolation; better performance than bus.
**Disadvantages:** Central device failure breaks the entire network; more cable required; higher cost than bus.

---

**Ring Topology:**

```
Computer1 → Computer2
    ↑              ↓
Computer4 ← Computer3
```

Devices connect in a closed loop. Data travels in one direction (unidirectional) using token passing.

**Advantages:** Equal access for all devices; no collisions; predictable performance.
**Disadvantages:** Single node failure disrupts entire ring; difficult to troubleshoot; adding/removing nodes is complex.

**Comparison Table:**

| Feature | Bus | Star | Ring |
|---|---|---|---|
| Central device needed | No | Yes (Switch/Hub) | No |
| Cable required | Less | More | Moderate |
| Cost | Low | Moderate | Moderate |
| Failure impact | Whole network | Only that device | Whole network |
| Performance | Degrades with load | Good | Predictable |
| Troubleshooting | Difficult | Easy | Moderate |
| Scalability | Limited | Easy | Moderate |
| Use case | Small/old networks | Modern office LANs | Token Ring networks |

---

### 📝 Short Answer Questions (5 Marks)

**Q3. What is DNS? Explain how DNS works.**

**Answer:** Refer to Section 5.6 DNS above for detailed explanation. (Short version:)

DNS (Domain Name System) is the internet's phonebook — it translates domain names (www.google.com) into IP addresses (142.250.0.1) that computers use to communicate.

**Process:** User enters URL → Browser checks cache → Queries ISP's recursive resolver → Resolver queries root server → TLD server → Authoritative DNS server → IP address returned → Browser connects.

---

**Q4. Explain the transmission media used in computer networks.**

**Answer:** Refer to Section 5.3. (Wired: twisted pair, coaxial, fiber optic. Wireless: radio waves, microwave, infrared, satellite. Include comparison of speed, cost, distance.)

---

**Q5. Define network devices: Hub, Switch, Router, and Modem.**

**Answer:**

**Hub (Layer 1):** A basic networking device that connects multiple computers. When one device sends data, the hub broadcasts it to ALL connected devices. This causes unnecessary traffic and collisions. Older technology, largely replaced by switches.

**Switch (Layer 2):** An intelligent device that learns the MAC addresses of connected devices and forwards data only to the intended recipient. More efficient than hub; reduces network traffic. Used in modern LANs.

**Router (Layer 3):** Connects different networks (e.g., home LAN to the internet). Uses IP addresses to determine the best path to route packets. Every home broadband connection has a router.

**Modem (Modulator/Demodulator):** Converts digital signals from a computer into analog signals for transmission over telephone/cable lines, and vice versa. Needed to connect to the ISP.

---

### 📝 Very Short / Objective Questions (1–2 Marks)

**Q6. What does URL stand for?**
→ **Uniform Resource Locator**

**Q7. Who invented the World Wide Web?**
→ **Tim Berners-Lee** (1989)

**Q8. What is the difference between a hub and a switch?**
→ A hub broadcasts to all devices; a switch sends data only to the intended recipient.

**Q9. Name the 7 layers of the OSI model.**
→ Physical, Data Link, Network, Transport, Session, Presentation, Application

**Q10. What does DNS stand for?**
→ **Domain Name System**

**Q11. What port does HTTP use?**
→ **Port 80** (HTTPS uses Port 443)

**Q12. What is the full form of TCP/IP?**
→ **Transmission Control Protocol / Internet Protocol**

**Q13. Give examples of WAN.**
→ **The Internet**, PSTN (telephone network)

**Q14. What is a firewall?**
→ A network security device that monitors and controls incoming and outgoing network traffic based on predetermined security rules.

---

*End of Unit 5*
