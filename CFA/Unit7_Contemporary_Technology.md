# Unit 7: Contemporary Technology
**BCA – Tribhuvan University**

---

## 7.1 Introduction to AI and Its Applications

### What is Artificial Intelligence (AI)?
**Artificial Intelligence (AI)** is a branch of computer science that enables machines to simulate human intelligence — the ability to reason, learn, perceive, solve problems, understand language, and make decisions.

**Definition by John McCarthy (Father of AI):** "AI is the science and engineering of making intelligent machines, especially intelligent computer programs."

### Goals of AI
1. **Reasoning and Problem Solving**: Computers solve logical problems step by step.
2. **Knowledge Representation**: Storing and using knowledge about the world.
3. **Planning**: Setting and achieving goals.
4. **Learning**: Improving performance based on experience (Machine Learning).
5. **Natural Language Processing (NLP)**: Understanding and generating human language.
6. **Perception**: Image recognition, speech recognition.
7. **Motion and Manipulation**: Robotics.

### Types of AI

**Based on Capability:**

| Type | Description | Example |
|---|---|---|
| **Narrow AI (Weak AI)** | Designed for one specific task | Chess engine, face recognition, Siri |
| **General AI (AGI)** | Human-level intelligence across all domains | Hypothetical; not yet achieved |
| **Super AI** | Intelligence surpassing human capabilities | Hypothetical; future concept |

**Based on Functionality:**

| Type | Description |
|---|---|
| **Reactive Machines** | No memory; react to current input only | IBM Deep Blue (chess) |
| **Limited Memory** | Uses past data to make decisions | Self-driving cars, AI assistants |
| **Theory of Mind** | Understands emotions and human cognition | Research stage |
| **Self-Aware AI** | Has consciousness and self-awareness | Hypothetical |

### Branches of AI

**1. Machine Learning (ML):**
- AI systems that learn from data without being explicitly programmed.
- Algorithms find patterns and improve automatically.
- Types: Supervised Learning, Unsupervised Learning, Reinforcement Learning.

**2. Deep Learning (DL):**
- Subset of ML using multi-layered neural networks.
- Excellent for image recognition, speech, and NLP.
- Examples: ChatGPT, image generators, DeepMind AlphaGo.

**3. Natural Language Processing (NLP):**
- AI's ability to understand, interpret, and generate human language.
- Applications: Chatbots, translation, sentiment analysis, voice assistants.
- Examples: Google Translate, ChatGPT, Siri.

**4. Computer Vision:**
- AI ability to interpret and understand visual information (images, video).
- Applications: Medical imaging, self-driving cars, facial recognition.

**5. Robotics:**
- Machines that perform physical tasks intelligently.
- Industrial robots, surgical robots (da Vinci), Boston Dynamics robots.

**6. Expert Systems:**
- AI systems that emulate decision-making of human experts.
- Examples: Medical diagnosis systems, financial advisory systems.

### Applications of AI

| Domain | AI Application |
|---|---|
| **Healthcare** | Disease diagnosis (cancer detection), drug discovery, medical imaging analysis, robotic surgery |
| **Finance** | Fraud detection, algorithmic trading, credit scoring, chatbots |
| **Transportation** | Self-driving cars (Tesla), traffic management, route optimization |
| **Education** | Personalized learning, automated grading, intelligent tutoring systems |
| **E-Commerce** | Product recommendation (Amazon, Netflix), chatbots, demand forecasting |
| **Agriculture** | Crop disease detection, precision farming, yield prediction |
| **Manufacturing** | Predictive maintenance, quality control, supply chain optimization |
| **Natural Language** | ChatGPT, virtual assistants (Alexa, Siri, Cortana), language translation |
| **Security** | Intrusion detection, facial recognition surveillance, spam filtering |
| **Entertainment** | Game AI, content generation, music composition |

---

## 7.2 Machine Learning, Neural Networks (Basic Concepts)

### Machine Learning (ML)

**Machine Learning** is a subset of AI that enables systems to **automatically learn and improve from experience** without being explicitly programmed. It focuses on building systems that learn from data.

**Traditional Programming vs Machine Learning:**
```
Traditional: Data + Rules → Program → Output
ML:          Data + Output → ML Algorithm → Rules (Model)
```

### Types of Machine Learning

#### 1. Supervised Learning
- Algorithm learns from **labeled training data** (input-output pairs).
- Learns a mapping function from input to output.
- **Goal**: Predict output for new, unseen input.
- **Tasks**: Classification (discrete output), Regression (continuous output).
- **Examples**: 
  - Email spam detection (spam/not spam)
  - Image classification (cat/dog)
  - House price prediction
- **Algorithms**: Linear Regression, Decision Trees, SVM, Random Forest, Neural Networks.

#### 2. Unsupervised Learning
- Algorithm learns from **unlabeled data** (no predefined output).
- Finds hidden patterns or structures in data.
- **Tasks**: Clustering, Dimensionality Reduction, Association.
- **Examples**:
  - Customer segmentation (grouping customers by behavior)
  - Anomaly detection
  - Topic modeling
- **Algorithms**: K-Means Clustering, Principal Component Analysis (PCA), DBSCAN.

#### 3. Reinforcement Learning (RL)
- Agent **learns by interacting with an environment** and receiving rewards/punishments.
- Trial and error learning — maximize cumulative reward.
- **Examples**:
  - Game playing (DeepMind AlphaGo, OpenAI Five)
  - Robotics
  - Self-driving cars
  - Trading algorithms
- **Key concepts**: Agent, Environment, State, Action, Reward, Policy.

#### 4. Semi-Supervised Learning
- Combines small amounts of labeled data with large amounts of unlabeled data.
- Practical when labeling data is expensive.

### ML Workflow (Pipeline)
```
Problem Definition → Data Collection → Data Preprocessing → 
Feature Engineering → Model Selection → Model Training → 
Model Evaluation → Hyperparameter Tuning → Deployment
```

**Key ML Terms:**
- **Training Data**: Data used to teach the model.
- **Test Data**: New data used to evaluate model performance.
- **Overfitting**: Model learns training data too well; fails on new data.
- **Underfitting**: Model is too simple to capture patterns.
- **Cross-Validation**: Technique to assess model generalization.

### Neural Networks

**Artificial Neural Network (ANN)** is a computational model inspired by the structure and function of the **human brain**. It consists of interconnected artificial neurons (nodes).

**Biological vs Artificial Neuron:**

| Biological Neuron | Artificial Neuron |
|---|---|
| Cell body (soma) | Node (neuron) |
| Dendrites (receive signals) | Input values (x1, x2, x3) |
| Synapses (connection strength) | Weights (w1, w2, w3) |
| Axon (sends signals) | Output |
| Activation (firing) | Activation function |

### Structure of a Neural Network

```
       Input Layer    Hidden Layer    Output Layer
           │               │               │
         x1 ──┐         ○───┐
               ├──────► ○   ├──────────► ŷ (Prediction)
         x2 ──┤         ○───┤
               └──────► ○   │
         x3 ──────────► ○───┘
         
Input Neurons → Weighted Connections → Hidden Neurons → Output Neuron
```

**Layers:**
1. **Input Layer**: Receives raw input features (one neuron per feature).
2. **Hidden Layers**: Intermediate layers that learn complex patterns. More hidden layers = **Deep Learning**.
3. **Output Layer**: Produces the final prediction.

**How a Neuron Works:**
1. Receives inputs (x1, x2, ..., xn).
2. Multiplies each input by its weight (w1, w2, ..., wn).
3. Sums the weighted inputs: `z = w1x1 + w2x2 + ... + b` (b = bias)
4. Applies an **activation function** to determine if/how much to fire.

**Activation Functions:**
- **Sigmoid**: Output between 0 and 1; used in binary classification.
- **ReLU (Rectified Linear Unit)**: `max(0, x)`; most common in hidden layers.
- **Tanh**: Output between -1 and 1.
- **Softmax**: Output probabilities for multi-class classification.

### Deep Learning
**Deep Learning** = Neural Networks with **many hidden layers**.

- Learns hierarchical representations of data.
- Excellent for unstructured data: images, text, audio.
- Requires large datasets and powerful GPUs.

**Types of Deep Learning Architectures:**

| Architecture | Use Case |
|---|---|
| **CNN** (Convolutional Neural Network) | Image recognition, video analysis |
| **RNN** (Recurrent Neural Network) | Sequential data: time series, NLP |
| **LSTM** (Long Short-Term Memory) | Long sequences: speech, translation |
| **GAN** (Generative Adversarial Network) | Image generation, deepfakes |
| **Transformer** | NLP: ChatGPT, BERT, translation |

---

## 7.3 Blockchain Technology and Bitcoin

### Blockchain Technology
**Blockchain** is a **distributed, decentralized, immutable ledger** that records transactions across multiple computers in a secure and transparent manner.

**Key Concepts:**

**Block:**
Each block contains:
- Data (transaction records)
- **Hash**: A unique fingerprint of the current block.
- **Previous Hash**: Hash of the previous block (creates the chain).
- Timestamp, Nonce.

**Chain:**
Blocks are linked in a chronological chain using their hashes. If any block is altered, its hash changes, breaking all subsequent links → **tamper-evident**.

```
┌─────────────────┐  ┌─────────────────┐  ┌─────────────────┐
│   Block 1       │  │   Block 2       │  │   Block 3       │
│ Data: Genesis   │  │ Data: Tx A→B   │  │ Data: Tx B→C   │
│ Hash: 000abc    │  │ Hash: 000def    │  │ Hash: 000ghi    │
│ Prev: 000000    │  │ Prev: 000abc ◄──┤  │ Prev: 000def ◄──┤
└─────────────────┘  └─────────────────┘  └─────────────────┘
```

### Properties of Blockchain

| Property | Description |
|---|---|
| **Decentralized** | No central authority; distributed across many nodes |
| **Immutable** | Once recorded, data cannot be altered |
| **Transparent** | All participants can view the ledger (public blockchain) |
| **Secure** | Cryptographic hashing protects data integrity |
| **Consensus-Based** | Requires agreement from the network to add a block |

### Consensus Mechanisms
Methods for network nodes to agree on valid transactions:
- **Proof of Work (PoW)**: Miners solve complex mathematical puzzles (Bitcoin). Energy-intensive.
- **Proof of Stake (PoS)**: Validators chosen based on their stake (Ethereum 2.0). More energy-efficient.
- **Delegated Proof of Stake (DPoS)**: Token holders vote for delegates.

### Types of Blockchain

| Type | Access | Examples |
|---|---|---|
| **Public Blockchain** | Open to everyone | Bitcoin, Ethereum |
| **Private Blockchain** | Restricted to invited participants | Hyperledger Fabric |
| **Consortium Blockchain** | Controlled by a group of organizations | R3 Corda (banking) |

### Bitcoin
**Bitcoin (BTC)** is the first and most well-known **cryptocurrency**, created by the pseudonymous **Satoshi Nakamoto** in 2009.

**Key Features:**
- Decentralized digital currency (no central bank or government).
- Transactions recorded on the Bitcoin blockchain.
- Maximum supply: **21 million BTC**.
- Transactions verified by **miners** using Proof of Work.
- Transactions are **pseudonymous** (wallet addresses, not names).

**How Bitcoin Transaction Works:**
1. Alice wants to send 1 BTC to Bob.
2. Alice signs the transaction with her **private key**.
3. Transaction broadcast to the network.
4. **Miners** validate the transaction (Proof of Work).
5. Transaction confirmed and added to the blockchain.
6. Bob receives 1 BTC.

**Bitcoin Mining:**
- Process of validating transactions and adding them to the blockchain.
- Miners solve cryptographic puzzles (SHA-256 hash).
- First to solve gets a **block reward** (Bitcoin + transaction fees).
- Difficulty adjusts every 2016 blocks (~2 weeks).

### Smart Contracts
Self-executing contracts with terms written directly in code. Run on blockchain (Ethereum). Automatically execute when conditions are met, without intermediaries.

**Example**: Insurance payout automatically triggered when flight is delayed (verified by data oracle).

### Applications of Blockchain
- **Finance**: Cryptocurrencies, cross-border payments, DeFi (Decentralized Finance).
- **Supply Chain**: Tracking goods from origin to consumer (IBM Food Trust).
- **Healthcare**: Secure patient record sharing.
- **Voting**: Tamper-proof electronic voting.
- **NFTs (Non-Fungible Tokens)**: Digital ownership of art, music.
- **Identity Management**: Self-sovereign identity.

---

## 7.4 IoT, Cloud Computing, and Their Use

### Internet of Things (IoT)

**IoT** is the network of physical devices ("things") embedded with sensors, software, and connectivity that enables them to collect, exchange, and act on data over the internet.

**IoT Architecture:**
```
Physical Devices → Connectivity (Wi-Fi, Bluetooth, 5G) → 
Gateway/Edge → Cloud Platform → Applications/Users
```

**Key Components of IoT:**
1. **Sensors/Actuators**: Collect data from the physical world (temperature, motion, GPS).
2. **Connectivity**: Wi-Fi, Bluetooth, Zigbee, LoRaWAN, 5G, NB-IoT.
3. **IoT Gateway/Edge**: Processes data locally before sending to cloud.
4. **Cloud Platform**: Stores and analyzes large amounts of IoT data.
5. **Applications**: User interfaces (mobile apps, dashboards).

**Applications of IoT:**

| Domain | IoT Application |
|---|---|
| **Smart Home** | Smart thermostats (Nest), smart lights, voice assistants (Alexa), security cameras |
| **Healthcare** | Wearable health monitors (Fitbit, Apple Watch), remote patient monitoring |
| **Agriculture** | Precision farming, soil moisture sensors, automated irrigation |
| **Smart Cities** | Intelligent traffic lights, smart parking, waste management |
| **Industry (IIoT)** | Predictive maintenance of machines, factory automation |
| **Transportation** | Connected vehicles, fleet management, GPS tracking |
| **Retail** | Smart shelves, inventory management, contactless payment |

**Challenges of IoT:**
- Security vulnerabilities (many devices have weak security).
- Privacy concerns (constant data collection).
- Interoperability (different standards and protocols).
- Scalability and data management.

### Cloud Computing

**Cloud computing** is the delivery of computing services (servers, storage, databases, networking, software, analytics, intelligence) over the internet ("the cloud") to offer faster innovation, flexible resources, and economies of scale.

**Key Characteristics (NIST):**
1. **On-demand self-service**: Provision resources without human interaction.
2. **Broad network access**: Accessible from anywhere via internet.
3. **Resource pooling**: Resources shared among multiple users (multi-tenancy).
4. **Rapid elasticity**: Scale up or down quickly.
5. **Measured service**: Pay only for what you use.

### Cloud Service Models

#### 1. IaaS (Infrastructure as a Service)
- Provides virtualized computing infrastructure (servers, storage, networking).
- Most flexibility; user manages OS, middleware, applications.
- **Examples**: Amazon EC2, Microsoft Azure VMs, Google Compute Engine.
- **Users**: IT administrators, developers needing full control.

#### 2. PaaS (Platform as a Service)
- Provides a platform (OS, runtime, development tools, databases) for developing, testing, and deploying applications.
- User focuses on application; provider manages infrastructure.
- **Examples**: Google App Engine, Heroku, Microsoft Azure App Service.
- **Users**: Developers.

#### 3. SaaS (Software as a Service)
- Delivers software applications over the internet; no installation needed.
- Provider manages everything.
- **Examples**: Gmail, Office 365, Salesforce, Zoom, Netflix.
- **Users**: End users.

```
                You manage:
IaaS → Applications, Data, Runtime, OS
PaaS → Applications, Data
SaaS → Nothing (just use the software)
```

### Cloud Deployment Models

| Model | Description | Example |
|---|---|---|
| **Public Cloud** | Services offered over the public internet; shared infrastructure | AWS, Azure, Google Cloud |
| **Private Cloud** | Cloud infrastructure operated solely for one organization | On-premise data center |
| **Hybrid Cloud** | Mix of public and private cloud | Most enterprises use hybrid |
| **Community Cloud** | Shared among organizations with common concerns | Government cloud |

### Benefits and Challenges of Cloud Computing

**Benefits:**
1. **Cost savings**: No upfront hardware investment; pay-as-you-go.
2. **Scalability**: Instantly scale resources up or down.
3. **Accessibility**: Access data/apps from anywhere.
4. **Reliability**: High availability with redundancy.
5. **Automatic updates**: Provider handles maintenance and patching.
6. **Disaster recovery**: Built-in backup and recovery.

**Challenges:**
1. **Security and Privacy**: Data stored off-site; third-party access concerns.
2. **Downtime**: Dependent on internet connectivity.
3. **Vendor lock-in**: Difficult to switch providers.
4. **Compliance**: Data sovereignty and regulatory issues.

---

## 7.5 Virtual and Augmented Reality

### Virtual Reality (VR)

**Virtual Reality** is a technology that creates a **fully immersive, computer-generated 3D environment** that users can interact with using specialized hardware, making them feel as if they are physically present in that virtual world.

**Key Hardware:**
- **VR Headset (HMD – Head-Mounted Display)**: Oculus Quest, PlayStation VR, HTC Vive, Google Cardboard.
- **Motion Controllers**: Track hand movements.
- **Haptic Gloves/Suits**: Provide touch feedback.
- **Treadmills**: Simulate walking.

**How VR Works:**
1. Computer renders two slightly different images (one per eye) to create depth perception (stereoscopic 3D).
2. Head tracking sensors update the view as the user moves.
3. Creates a sense of **presence** — feeling of being "in" the virtual world.

**Applications of VR:**

| Domain | Application |
|---|---|
| **Gaming** | Immersive game worlds (Beat Saber, Half-Life: Alyx) |
| **Education/Training** | Medical training, pilot/military simulation, virtual classrooms |
| **Healthcare** | Pain management, phobia therapy (exposure therapy), surgical simulation |
| **Architecture/Design** | Virtual walkthroughs of buildings before construction |
| **Real Estate** | Virtual property tours |
| **Entertainment** | Virtual concerts, movies, social VR (Facebook Horizon) |
| **Retail** | Virtual try-on (clothes, furniture) |

---

### Augmented Reality (AR)

**Augmented Reality** is a technology that **overlays digital information (images, sounds, text) on the real world** through a device (smartphone, tablet, AR glasses), enhancing the real-world experience.

**Unlike VR**: AR doesn't replace reality — it **enhances** it.

**Key Hardware:**
- **Smartphone/Tablet**: Most accessible AR platform.
- **AR Glasses/Smart Glasses**: Microsoft HoloLens, Google Glass, Apple Vision Pro.

**How AR Works:**
1. Camera captures the real world.
2. Computer vision identifies surfaces, objects, and markers.
3. Digital content (3D models, text, overlays) is rendered on top of the camera feed.
4. Display shows combined real + digital world.

**Applications of AR:**

| Domain | Application |
|---|---|
| **Gaming** | Pokémon GO (overlays Pokémon on real streets) |
| **Retail** | IKEA Place app (see furniture in your room), virtual makeup try-on |
| **Navigation** | AR navigation overlays directions on live camera view |
| **Healthcare** | Surgeons viewing patient data overlaid on patient during surgery |
| **Education** | Interactive AR textbooks, anatomy models |
| **Manufacturing** | AR instructions overlaid on machinery during repair |
| **Military** | Fighter pilot HUD (Heads-Up Display), AR training |
| **Social Media** | Snapchat/Instagram filters |

### VR vs AR

| Feature | VR (Virtual Reality) | AR (Augmented Reality) |
|---|---|---|
| Environment | Fully virtual (replaces real world) | Real world + digital overlay |
| Immersion | Fully immersive | Partial (enhances real world) |
| Hardware | Headset required | Smartphone or glasses |
| Real world awareness | None | Full awareness |
| Examples | Oculus Quest, PlayStation VR | Pokémon GO, HoloLens, IKEA app |
| Cost | Higher | Lower (smartphone) |
| Use cases | Gaming, training simulation | Navigation, retail, education |

### Mixed Reality (MR)
**Mixed Reality** blends physical and digital worlds where physical and virtual objects coexist and interact in real time. More advanced than AR.

Example: Microsoft HoloLens — holographic images appear "placed" in the real world and respond to the environment.

### Extended Reality (XR)
An umbrella term encompassing VR + AR + MR — all technologies that alter reality.

---

## TU Exam Format Questions – Unit 7

---

### 📝 Long Answer Questions (10 Marks)

**Q1. What is Artificial Intelligence? Explain its branches and applications in detail.**

**Answer:**

**Definition:** Artificial Intelligence (AI) is the simulation of human intelligence processes by machines, especially computer systems. The term was coined by **John McCarthy** in 1956. AI encompasses the ability to reason, learn, understand language, recognize patterns, and make decisions.

**Branches of AI:** (Refer to Section 7.1 for complete detail on ML, Deep Learning, NLP, Computer Vision, Robotics, Expert Systems.)

**Applications:** (Detail across Healthcare, Finance, Transportation, Education, E-Commerce, Agriculture, Security, Entertainment — refer to table in Section 7.1.)

---

**Q2. Explain blockchain technology. How does Bitcoin use blockchain?**

**Answer:** (Refer to Section 7.3 for full detailed answer covering: blockchain structure, blocks and chain linkage, properties, consensus mechanisms, Bitcoin creation and transactions, mining, and applications.)

---

**Q3. What is cloud computing? Explain the cloud service models (IaaS, PaaS, SaaS) with examples.**

**Answer:** (Refer to Section 7.4 Cloud Computing. Cover: definition, 5 key characteristics, IaaS/PaaS/SaaS with diagrams, deployment models, benefits and challenges.)

---

### 📝 Short Answer Questions (5 Marks)

**Q4. What is Machine Learning? Explain supervised, unsupervised, and reinforcement learning.**

**Answer:** Refer to Section 7.2 for complete explanation of all three types with examples.

---

**Q5. What is IoT? Explain its components and applications.**

**Answer:** Refer to Section 7.4 IoT section. Cover: definition, 5 components (sensors, connectivity, gateway, cloud, applications), and at least 5 application domains.

---

**Q6. Differentiate between Virtual Reality (VR) and Augmented Reality (AR).**

**Answer:** Refer to the VR vs AR comparison table and individual sections in 7.5. Cover: definition of each, how they work, hardware, examples, and key differences.

---

**Q7. Explain Neural Networks. What is Deep Learning?**

**Answer:** Refer to Section 7.2 Neural Networks section. Cover: biological vs artificial neuron, structure (input/hidden/output layers), how a neuron works (weighted sum + activation function), and Deep Learning as multi-layer neural networks. Include CNN, RNN examples.

---

### 📝 Very Short / Objective Questions (1–2 Marks)

**Q8. What does AI stand for? Who coined the term?**
→ **Artificial Intelligence** — coined by **John McCarthy** in 1956.

**Q9. Who created Bitcoin?**
→ **Satoshi Nakamoto** (pseudonym), 2009.

**Q10. What is the maximum supply of Bitcoin?**
→ **21 million BTC**.

**Q11. Name three types of cloud service models.**
→ **IaaS, PaaS, SaaS**

**Q12. What is Augmented Reality?**
→ Technology that overlays digital information on the real world using devices like smartphones or AR glasses.

**Q13. Full form of IoT.**
→ **Internet of Things**

**Q14. What is a smart contract?**
→ A self-executing program stored on a blockchain that automatically executes when predetermined conditions are met.

**Q15. Name two examples of VR headsets.**
→ **Oculus Quest** and **HTC Vive**

**Q16. What is Proof of Work in blockchain?**
→ A consensus mechanism where miners solve complex mathematical puzzles to validate transactions and add blocks to the blockchain. Used by Bitcoin.

**Q17. Name three types of Machine Learning.**
→ **Supervised Learning, Unsupervised Learning, Reinforcement Learning**

**Q18. What is NLP?**
→ **Natural Language Processing** — a branch of AI dealing with the interaction between computers and human language (understanding and generation).

**Q19. Give an example of SaaS.**
→ **Gmail, Microsoft Office 365, Zoom, Netflix**

**Q20. What is the difference between VR and AR?**
→ VR completely replaces the real world with a virtual one; AR overlays digital content on the real world.

---

*End of Unit 7*

---

## Quick Revision: All 7 Units Summary

| Unit | Topic | Hours |
|---|---|---|
| Unit 1 | Introduction to Computer: definition, anatomy, types, history & generations, applications | 5 hrs |
| Unit 2 | Computer Hardware: organization, components, CPU (ALU/CU/RA), memory hierarchy, motherboard, BIOS/SMPS/CMOS/microprocessor | 10 hrs |
| Unit 3 | Computer Software: types, OS (functions & types), utility, virus & antivirus, programming languages & translators | 10 hrs |
| Unit 4 | Database Management: DBMS, DB architecture, DB models, SQL & NoSQL, data warehousing, data mining, Big Data | 5 hrs |
| Unit 5 | Networks & Internet: types of networks, LAN topologies, transmission media, data communication, OSI model, protocols, WWW, URL, DNS | 5 hrs |
| Unit 6 | Computer Security: threats & attacks, malware, cryptography, digital signature, firewall, authentication, IDS, security policy | 8 hrs |
| Unit 7 | Contemporary Technology: AI, ML, neural networks, blockchain, Bitcoin, IoT, cloud computing, VR, AR | — |
