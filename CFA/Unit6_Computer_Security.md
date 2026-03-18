# Unit 6: Computer Security
**BCA – Tribhuvan University | 8 Hours**

---

## 6.1 Introduction: Security Threats and Security Attacks

### What is Computer Security?
**Computer security** (also called cybersecurity or information security) is the practice of protecting computer systems, networks, data, and programs from unauthorized access, theft, damage, disruption, or misuse.

**Goals of Computer Security (CIA Triad):**

```
            Confidentiality
                  △
                 / \
                /   \
               /     \
  Integrity ─────────── Availability
```

1. **Confidentiality**: Ensuring that information is accessible only to those authorized to access it. (Prevents unauthorized disclosure.)
2. **Integrity**: Ensuring that data is accurate, complete, and not altered by unauthorized parties. (Prevents unauthorized modification.)
3. **Availability**: Ensuring that authorized users have access to information and systems when needed. (Prevents denial of service.)

### Security Threats
A **security threat** is any potential danger that could exploit a vulnerability to compromise the security of a system.

**Types of Security Threats:**

| Threat | Description |
|---|---|
| **Malware** | Malicious software (viruses, worms, trojans, ransomware) |
| **Phishing** | Fraudulent emails/websites that trick users into revealing credentials |
| **Denial of Service (DoS)** | Overwhelms a system to make it unavailable |
| **Man-in-the-Middle (MITM)** | Attacker intercepts communication between two parties |
| **SQL Injection** | Malicious SQL code inserted into input fields to manipulate databases |
| **Social Engineering** | Manipulating people into divulging confidential information |
| **Insider Threats** | Threats from employees or trusted individuals |
| **Zero-Day Exploit** | Attacking an unknown, unpatched vulnerability |
| **Password Attack** | Brute force, dictionary attack to crack passwords |
| **Eavesdropping** | Unauthorized interception of communications |

### Security Attacks

#### Active Attacks
The attacker actively modifies data or disrupts services.
1. **Modification**: Altering the content of a message.
2. **Masquerade**: Pretending to be another entity.
3. **Replay Attack**: Capturing and retransmitting valid data.
4. **Denial of Service (DoS)**: Flooding a server to make it unavailable.
5. **Distributed DoS (DDoS)**: DoS from multiple compromised systems.

#### Passive Attacks
The attacker observes/collects data without altering it.
1. **Eavesdropping/Sniffing**: Capturing network traffic.
2. **Traffic Analysis**: Analyzing communication patterns even if encrypted.

**Active vs Passive Attacks:**

| Feature | Active Attack | Passive Attack |
|---|---|---|
| Data modification | Yes | No |
| Detection | Easier to detect | Harder to detect |
| Goal | Disrupt, modify | Intercept, observe |
| Example | DoS, MITM, replay | Sniffing, eavesdropping |

### Vulnerability vs Threat vs Risk
- **Vulnerability**: A weakness in a system (e.g., unpatched software).
- **Threat**: A potential danger that exploits a vulnerability (e.g., hacker).
- **Risk**: The probability that a threat will exploit a vulnerability × potential impact.

---

## 6.2 Malicious Software and Types of Viruses

### Malware (Malicious Software)
**Malware** is any software designed to disrupt, damage, or gain unauthorized access to computer systems.

### Types of Malware

#### 1. Virus
- **Self-replicating program** that attaches to legitimate files.
- Needs a **host** to spread.
- Activated when the infected file is executed.
- **Types**: Boot sector virus, file infector, macro virus, polymorphic virus.
- **Example**: Melissa, I Love You, CIH (Chernobyl virus).

#### 2. Worm
- Self-replicating program that **spreads independently** across networks without needing a host file.
- Exploits network vulnerabilities.
- Consumes bandwidth and system resources.
- **Example**: Morris Worm (1988), Blaster, Sasser, WannaCry (partially).

#### 3. Trojan Horse
- **Disguises as legitimate software** but contains malicious code.
- Does not self-replicate.
- Creates backdoors for attackers, steals data.
- **Example**: Emotet, Zeus, RATs (Remote Access Trojans).

#### 4. Ransomware
- **Encrypts victim's files** and demands payment (ransom) for decryption key.
- Usually demands cryptocurrency (Bitcoin).
- **Example**: WannaCry (2017), Petya, CryptoLocker, LockBit.
- **Prevention**: Regular backups, patching, not clicking suspicious links.

#### 5. Spyware
- **Secretly monitors user activity** and transmits data to attackers.
- Collects passwords, credit card numbers, browsing history.
- **Example**: CoolWebSearch, FinFisher.

#### 6. Adware
- Automatically displays **unwanted advertisements**.
- Less harmful but annoying.
- Often bundled with free software.
- **Example**: Fireball.

#### 7. Rootkit
- **Hides deeply in the OS** (root/administrator level).
- Gives attackers persistent administrative access.
- Very difficult to detect and remove.
- **Example**: Sony BMG rootkit, Necurs.

#### 8. Keylogger
- **Records keystrokes** typed by the user.
- Captures passwords, credit card numbers, private messages.
- Can be hardware (physical device) or software.

#### 9. Botnet
- Network of compromised computers ("zombies") controlled by an attacker ("bot herder").
- Used for DDoS attacks, spam campaigns, cryptocurrency mining.
- **Example**: Mirai botnet (attacked IoT devices).

#### 10. Logic Bomb
- Malicious code that **activates when specific conditions are met** (date, event).
- Lies dormant until triggered.
- **Example**: A disgruntled employee plants code that deletes files on termination date.

---

## 6.3 Security Mechanisms: Cryptography and Digital Signature

### Cryptography
**Cryptography** is the science of securing information by transforming it into an unreadable format that can only be deciphered by authorized parties.

**Key Terms:**
- **Plaintext**: Original readable message.
- **Ciphertext**: Encrypted, unreadable message.
- **Encryption**: Converting plaintext to ciphertext.
- **Decryption**: Converting ciphertext back to plaintext.
- **Key**: A value used in the encryption/decryption algorithm.
- **Cipher**: The encryption algorithm.

### Types of Cryptography

#### 1. Symmetric Key Cryptography (Secret Key)
- **Same key** is used for both encryption and decryption.
- Fast and efficient; suitable for large amounts of data.
- **Problem**: Secure key distribution (how to share the secret key).
- **Algorithms**: AES (Advanced Encryption Standard), DES, 3DES, Blowfish.

```
Sender:  Plaintext + Key → [Encrypt] → Ciphertext  → Transmit
Receiver: Ciphertext + Key → [Decrypt] → Plaintext
```

#### 2. Asymmetric Key Cryptography (Public Key)
- Uses **two different but mathematically related keys**:
  - **Public Key**: Shared openly with everyone.
  - **Private Key**: Kept secret by the owner.
- What one key encrypts, only the other can decrypt.
- **Algorithms**: RSA, ECC (Elliptic Curve Cryptography), Diffie-Hellman.
- Used in SSL/TLS (HTTPS), email encryption (PGP), digital signatures.

```
Sender:  Plaintext + Receiver's Public Key → [Encrypt] → Ciphertext
Receiver: Ciphertext + Receiver's Private Key → [Decrypt] → Plaintext
```

**Symmetric vs Asymmetric:**

| Feature | Symmetric | Asymmetric |
|---|---|---|
| Keys | Same key (1 key) | Two keys (public + private) |
| Speed | Fast | Slow |
| Key distribution | Challenging | Easier (public key is shared) |
| Use case | Bulk data encryption | Key exchange, digital signatures |
| Examples | AES, DES | RSA, ECC |

#### 3. Hash Functions (One-Way Encryption)
- Converts data into a **fixed-length hash value (digest)**.
- **One-way**: Cannot be reversed.
- Same input always produces same hash; different inputs produce different hashes.
- Used for password storage, data integrity verification.
- **Algorithms**: MD5 (128-bit), SHA-1 (160-bit), SHA-256, SHA-512.

```
"Hello" → [SHA-256] → 185f8db32921bd46d35...
```

### Digital Signature
A **digital signature** is an electronic signature that provides:
1. **Authentication**: Verifies the identity of the sender.
2. **Integrity**: Confirms the message was not altered.
3. **Non-repudiation**: The sender cannot deny sending the message.

**How Digital Signature Works:**

```
SIGNING (Sender's side):
Document → [Hash Function] → Hash Value
Hash Value + Sender's Private Key → [Encrypt] → Digital Signature
Transmit: Document + Digital Signature

VERIFICATION (Receiver's side):
Digital Signature + Sender's Public Key → [Decrypt] → Hash Value 1
Received Document → [Hash Function] → Hash Value 2
If Hash Value 1 == Hash Value 2 → Signature is VALID ✓
```

**Digital Certificate:**
A **digital certificate** (issued by a Certificate Authority – CA) binds a public key to an identity. Used in HTTPS to verify website authenticity.

**Certificate Authority (CA):** A trusted organization that issues digital certificates (VeriSign, DigiCert, Let's Encrypt).

---

## 6.4 Firewall, User Authentication, Intrusion Detection System

### Firewall
A **firewall** is a network security device (hardware or software) that monitors and controls incoming and outgoing network traffic based on **predetermined security rules**.

**How Firewall Works:**
- Acts as a barrier between a trusted internal network and untrusted external networks (internet).
- Examines packets and allows/blocks them based on rules.

**Types of Firewalls:**

**1. Packet Filtering Firewall:**
- Examines packets at the network layer.
- Checks source/destination IP, port, and protocol.
- Fast but limited; cannot inspect packet content.
- Stateless.

**2. Stateful Inspection Firewall:**
- Tracks the **state** of active connections.
- Allows response packets for established outgoing connections.
- More secure than packet filtering.

**3. Application Layer Firewall (Proxy Firewall):**
- Inspects traffic at the application layer.
- Understands HTTP, FTP, DNS protocols.
- Can detect application-layer attacks (SQL injection, XSS).
- Slower but most thorough.

**4. Next-Generation Firewall (NGFW):**
- Combines packet filtering + stateful inspection + deep packet inspection + IPS.
- Can identify applications (not just ports).
- Examples: Palo Alto, Cisco Firepower.

**Firewall Rules:**
- Allow/Deny based on: Source IP, Destination IP, Port number, Protocol (TCP/UDP), Direction (Inbound/Outbound).

### User Authentication
**Authentication** is the process of verifying the identity of a user before granting access.

**Authentication Factors:**

| Factor | Type | Example |
|---|---|---|
| **Something you know** | Knowledge factor | Password, PIN, security question |
| **Something you have** | Possession factor | Smart card, OTP (one-time password), security token |
| **Something you are** | Inherence factor (Biometrics) | Fingerprint, iris scan, face recognition |

**Multi-Factor Authentication (MFA):**
Combines two or more authentication factors for higher security.
- Example: Password + OTP sent to phone = 2FA (Two-Factor Authentication).
- Used in banking, email, and sensitive systems.

**Password Security Best Practices:**
- Use long passwords (12+ characters).
- Mix uppercase, lowercase, numbers, and symbols.
- Use different passwords for different accounts.
- Use a **password manager**.
- Enable 2FA.
- Avoid dictionary words and personal information.

**Biometric Authentication:**
Uses unique physical characteristics:
- Fingerprint scanning
- Iris/retinal recognition
- Facial recognition
- Voice recognition
- Signature dynamics

### Intrusion Detection System (IDS)
An **IDS** is a system that monitors network traffic or system activities for malicious activity or policy violations and generates alerts.

**Types of IDS:**

**1. NIDS (Network-Based IDS):**
- Monitors network traffic for suspicious patterns.
- Deployed at network boundaries.
- Example: Snort, Suricata.

**2. HIDS (Host-Based IDS):**
- Monitors activities on a single host/system.
- Checks system logs, file changes, running processes.
- Example: OSSEC, Tripwire.

**IDS Detection Methods:**

**1. Signature-Based Detection:**
- Compares traffic/activity against a database of known attack signatures.
- Effective against known attacks; cannot detect new attacks.
- Similar to antivirus signature detection.

**2. Anomaly-Based Detection:**
- Establishes a baseline of normal behavior.
- Flags deviations from normal as suspicious.
- Can detect unknown/new attacks.
- Higher false positive rate.

**IDS vs IPS (Intrusion Prevention System):**
- **IDS**: Detects and **alerts** (passive).
- **IPS**: Detects and **blocks** the attack in real-time (active).

---

## 6.5 Security Awareness and Security Policy

### Security Awareness
**Security awareness** is the knowledge and attitude that members of an organization possess regarding the protection of the organization's physical and information assets.

**Why Security Awareness is Important:**
- Human error is the leading cause of security breaches.
- Phishing attacks succeed because users are unaware.
- Educated users are the first line of defense.

**Security Awareness Training Topics:**
1. Identifying phishing emails and social engineering attacks.
2. Creating and managing strong passwords.
3. Safe browsing and downloading habits.
4. Physical security (clean desk policy, lock screens).
5. Incident reporting procedures.
6. Data classification and handling.
7. Use of public Wi-Fi risks and VPN usage.
8. Software updates and patch management.

### Security Policy
A **security policy** is a formal document that defines the rules, guidelines, and practices that govern how an organization manages and protects its information assets.

**Types of Security Policies:**

**1. Acceptable Use Policy (AUP):**
- Defines how employees are allowed to use company IT resources.
- Covers: internet usage, email, social media, personal devices.
- Prohibits: downloading illegal content, sharing passwords, unauthorized software.

**2. Password Policy:**
- Minimum length and complexity requirements.
- Password expiration and history.
- Account lockout after failed attempts.

**3. Data Classification Policy:**
- Classifies data by sensitivity: Public, Internal, Confidential, Top Secret.
- Defines how each category must be handled and protected.

**4. Incident Response Policy:**
- Defines procedures for responding to security incidents.
- Steps: Preparation → Identification → Containment → Eradication → Recovery → Lessons Learned.

**5. Access Control Policy:**
- Defines who can access what resources.
- Implements principle of **least privilege** (users have minimum access needed for their job).

**6. Backup and Recovery Policy:**
- Frequency of backups (daily, weekly).
- Backup storage location (on-site, off-site, cloud).
- Recovery time objectives (RTO) and recovery point objectives (RPO).

### Principles of Information Security

**1. Principle of Least Privilege:**
Users and systems should have the minimum level of access necessary to perform their functions.

**2. Defense in Depth:**
Multiple layers of security controls (network firewall + antivirus + access control + encryption).

**3. Separation of Duties:**
No single person should have complete control over an important process.

**4. Need to Know:**
Users should only have access to information they need for their job.

**5. Fail Securely:**
When a system fails, it should fail to a secure state (e.g., firewall blocking all traffic if it crashes).

---

## TU Exam Format Questions – Unit 6

---

### 📝 Long Answer Questions (10 Marks)

**Q1. What is cryptography? Explain symmetric and asymmetric encryption with diagrams.**

**Answer:**

**Cryptography** is the science of securing information through encoding (encryption) so that only authorized parties can decode (decrypt) and read it. The word comes from Greek: *kryptos* (hidden) + *graphein* (writing).

**Key Terms:**
- **Plaintext**: The original readable message (e.g., "Transfer $1000").
- **Ciphertext**: The encrypted, unreadable version (e.g., "Xk7#mZ9!@").
- **Encryption**: The process of converting plaintext to ciphertext using a key and algorithm.
- **Decryption**: The reverse process of converting ciphertext back to plaintext.
- **Key**: A secret value used in the encryption algorithm.

---

**Symmetric Key Cryptography:**

In symmetric cryptography, the **same secret key** is used for both encryption and decryption. Both sender and receiver must possess the same key.

```
         Secret Key (K)
              │
Sender:  Plaintext ──[Encrypt]──► Ciphertext ──► Network ──► Ciphertext
                                                                   │
Receiver:                                          Secret Key (K)─┤
                                              Ciphertext ──[Decrypt]──► Plaintext
```

**Process:**
1. Both sender and receiver agree on a shared secret key.
2. Sender encrypts plaintext using the key → Ciphertext.
3. Ciphertext transmitted over network.
4. Receiver decrypts ciphertext using the same key → Plaintext.

**Advantages:** Very fast; suitable for encrypting large amounts of data.
**Disadvantages:** Key distribution problem — how to securely share the key? If key is intercepted, all communications are compromised.

**Common Algorithms:**
- **DES** (Data Encryption Standard): 56-bit key; now considered insecure.
- **3DES**: Applies DES three times; more secure but slow.
- **AES** (Advanced Encryption Standard): 128/192/256-bit keys; current gold standard.

---

**Asymmetric Key Cryptography (Public Key Cryptography):**

Uses **two mathematically related keys**:
- **Public Key**: Freely shared with everyone.
- **Private Key**: Kept secret by the owner.

What the public key encrypts, only the corresponding private key can decrypt, and vice versa.

```
FOR CONFIDENTIALITY:
Sender:  Plaintext + Receiver's PUBLIC KEY ──[Encrypt]──► Ciphertext
Receiver: Ciphertext + Receiver's PRIVATE KEY ──[Decrypt]──► Plaintext

FOR DIGITAL SIGNATURE:
Sender:  Hash(Message) + Sender's PRIVATE KEY ──[Sign]──► Signature
Receiver: Signature + Sender's PUBLIC KEY ──[Verify]──► Hash (compare)
```

**Process for Secure Communication:**
1. Receiver generates a public/private key pair.
2. Receiver publishes the public key.
3. Sender encrypts message using receiver's public key.
4. Only receiver's private key can decrypt it.

**Advantages:** Solves key distribution problem; enables digital signatures.
**Disadvantages:** Much slower than symmetric encryption.

**Common Algorithms:** RSA (Rivest-Shamir-Adleman), ECC (Elliptic Curve Cryptography), Diffie-Hellman.

**Hybrid Approach (Used in SSL/TLS):**
In practice, asymmetric encryption is used to securely exchange a symmetric session key. Then the faster symmetric encryption is used for the actual data.

---

**Q2. Explain different types of malware. What security measures can be taken to protect against them?**

**Answer:**

**Malware (Malicious Software)** refers to any software intentionally designed to cause damage to a computer, server, client, or network.

**Types of Malware:**

**1. Virus:** A self-replicating program that attaches to legitimate files. Activated when the host file runs. Can corrupt files, consume resources, or display messages. Example: CIH (Chernobyl virus) that overwrote BIOS chips.

**2. Worm:** Self-replicating program that spreads across networks without needing a host. Can paralyze entire networks. Example: WannaCry (2017) infected 230,000+ computers using a Windows vulnerability.

**3. Trojan Horse:** Appears as legitimate software. Does not self-replicate. Creates backdoors, steals data, or gives remote control to attackers. Example: Emotet banking trojan.

**4. Ransomware:** Encrypts victim's files and demands payment. Extremely damaging to businesses. Example: WannaCry demanded Bitcoin payments to decrypt files.

**5. Spyware:** Silently monitors user activities and transmits sensitive data (passwords, financial info) to attackers without user knowledge.

**6. Rootkit:** Hides at the deepest OS level, giving persistent admin access to attackers. Extremely hard to detect and remove.

**7. Keylogger:** Records keystrokes to capture passwords and sensitive information.

**8. Adware:** Displays unwanted advertisements; less harmful but privacy concern.

**Security Measures:**

**Technical Measures:**
1. **Antivirus/Anti-malware Software**: Install and update regularly; perform scheduled scans.
2. **Firewall**: Block unauthorized network traffic.
3. **Regular OS/Software Updates**: Patch known vulnerabilities.
4. **Email Security**: Spam filters, never open unknown attachments.
5. **Network Monitoring**: IDS/IPS to detect suspicious activity.
6. **Data Backup**: Regular, tested backups (especially against ransomware).
7. **Encryption**: Protect data even if stolen.
8. **Application Whitelisting**: Only allow approved software to run.

**Behavioral Measures:**
1. **User Awareness Training**: Educate users about phishing, social engineering.
2. **Strong Password Policy**: Complex passwords, MFA.
3. **Principle of Least Privilege**: Users have minimum necessary access.
4. **USB/Removable Media Policy**: Restrict or scan before use.
5. **Safe Browsing**: Avoid suspicious websites and downloads.

---

### 📝 Short Answer Questions (5 Marks)

**Q3. What is a firewall? Explain the types of firewalls.**

**Answer:** Refer to Section 6.4 for detailed answer. Key types: Packet filtering, Stateful inspection, Application layer (proxy), Next-generation firewall. Include how each works and pros/cons.

---

**Q4. Explain digital signature and its role in computer security.**

**Answer:** Refer to Section 6.3 Digital Signature for complete explanation. Include: signing process (private key + hash), verification process (public key), properties (authentication, integrity, non-repudiation), and use cases (email, software distribution, financial transactions).

---

**Q5. What is an Intrusion Detection System (IDS)? Explain its types.**

**Answer:** Refer to Section 6.4 IDS section. Include: NIDS vs HIDS, signature-based vs anomaly-based detection, and difference between IDS and IPS.

---

**Q6. What is user authentication? Explain multi-factor authentication.**

**Answer:**

**Authentication** verifies that a user is who they claim to be before granting access. It is the second step in access control after identification (claiming identity).

**Authentication factors:**
- **Knowledge**: Password, PIN, passphrase, security questions.
- **Possession**: Smart card, OTP token, mobile phone for SMS codes.
- **Inherence (Biometrics)**: Fingerprint, iris scan, face, voice.

**Multi-Factor Authentication (MFA):**
MFA requires users to provide two or more different types of authentication factors. This significantly increases security because an attacker must compromise multiple authentication methods.

**Example of 2FA (Two-Factor Authentication):**
- Online banking: Password (knowledge) + OTP sent to phone (possession).
- Google Account: Password + Google Authenticator app code.

**Benefits of MFA:**
1. Even if password is stolen, attacker cannot log in without the second factor.
2. Reduces risk from phishing, brute force, and credential stuffing attacks.
3. Required by many compliance standards (PCI DSS, HIPAA).

**Types of OTP (One-Time Password):**
- **TOTP** (Time-Based OTP): Changes every 30 seconds (Google Authenticator).
- **HOTP** (HMAC-Based OTP): Counter-based.
- **SMS OTP**: Sent via text message (less secure).

---

### 📝 Very Short / Objective Questions (1–2 Marks)

**Q7. What does CIA stand for in computer security?**
→ **Confidentiality, Integrity, Availability**

**Q8. What is ransomware?**
→ Malware that encrypts a victim's files and demands payment to restore access.

**Q9. What is phishing?**
→ A social engineering attack using fake emails or websites to trick users into revealing sensitive information.

**Q10. Difference between IDS and IPS.**
→ IDS detects and alerts (passive); IPS detects and blocks in real-time (active).

**Q11. What is a digital certificate?**
→ An electronic document issued by a Certificate Authority (CA) that verifies the ownership of a public key.

**Q12. Full form of RSA.**
→ **Rivest-Shamir-Adleman** (a public-key cryptography algorithm)

**Q13. What is non-repudiation?**
→ A security property that ensures a sender cannot deny having sent a message; enforced by digital signatures.

**Q14. What is a DoS attack?**
→ **Denial of Service** – An attack that floods a server with traffic to make it unavailable to legitimate users.

**Q15. What is the principle of least privilege?**
→ Users and systems should have the minimum access rights necessary to perform their functions.

---

*End of Unit 6*
