# Unit 4: Database Management System (DBMS)
**BCA – Tribhuvan University | 5 Hours**

---

## 4.1 Introduction to Data, Database, and DBMS

### Data
**Data** refers to raw, unprocessed facts and figures. Data alone has no meaning until it is processed.

- Examples: `20`, `Kathmandu`, `Ram`, `9841000000`
- Data can be: Numbers, Text, Images, Audio, Video.

### Information
**Information** is processed, organized, and meaningful data.
- Example: "Ram, 20 years old, lives in Kathmandu, phone: 9841000000"

### Database
A **database** is an organized collection of related data stored systematically so that it can be easily accessed, managed, and updated.

- Example: A student database containing name, roll number, marks, and address of all students.
- Databases are stored in **tables** (rows = records, columns = fields/attributes).

**Properties of a Database:**
1. Data is organized logically.
2. Eliminates data redundancy (duplication).
3. Ensures data consistency.
4. Allows multiple users to access data.
5. Ensures data security.

### DBMS (Database Management System)
A **DBMS** is software that enables users to create, define, manipulate, and manage databases.

- It acts as an interface between the database and the end users/applications.
- Examples: **MySQL, Oracle, MS SQL Server, PostgreSQL, MS Access, MongoDB**.

**Functions of DBMS:**
1. **Data Definition**: Creating tables, schemas, relationships.
2. **Data Manipulation**: INSERT, UPDATE, DELETE, SELECT operations.
3. **Data Security**: Access control, user authentication.
4. **Data Integrity**: Enforcing constraints (primary key, foreign key, not null).
5. **Backup and Recovery**: Protecting data from loss.
6. **Concurrency Control**: Allows multiple users to work simultaneously without conflict.
7. **Query Processing**: Executing SQL queries efficiently.

### Advantages of DBMS over File System

| DBMS | Traditional File System |
|---|---|
| Reduces data redundancy | Data duplication common |
| Ensures data consistency | Data inconsistency possible |
| Data sharing among multiple users | Limited sharing |
| Centralized data management | Decentralized, scattered files |
| Easy querying with SQL | Complex manual searching |
| Access control and security | Minimal security |
| Data independence | Tight coupling with application |

---

## 4.2 Database System Architecture

The **ANSI/SPARC architecture** (1975) defines the standard three-level architecture for a DBMS:

### Three-Level Architecture

```
       ┌─────────────────────────────────────┐
       │         External Level              │  ← User/Application View
       │  (View 1) (View 2) (View 3)        │
       └──────────────┬──────────────────────┘
                      │ (External/Conceptual Mapping)
       ┌──────────────▼──────────────────────┐
       │         Conceptual Level            │  ← Logical View (DBA)
       │    (Logical structure of entire DB) │
       └──────────────┬──────────────────────┘
                      │ (Conceptual/Internal Mapping)
       ┌──────────────▼──────────────────────┐
       │         Internal Level              │  ← Physical Storage
       │    (How data is physically stored)  │
       └─────────────────────────────────────┘
```

**1. External Level (View Level):**
- The highest level; what individual users see.
- Different users can have different views of the same data.
- Hides unnecessary data from users.
- Example: A student views only their own marks; an admin sees all student records.

**2. Conceptual Level (Logical Level):**
- Describes **what** data is stored in the entire database.
- Managed by the Database Administrator (DBA).
- Defines all tables, relationships, constraints, and rules.
- Hides physical storage details.

**3. Internal Level (Physical Level):**
- Describes **how** data is physically stored on disk.
- Deals with storage structures: indexes, file organization, data compression.
- Lowest level; managed by the DBMS itself.

### Data Independence
**Data independence** means changes at one level do not affect another level.
- **Logical Data Independence**: Changes to the conceptual schema don't affect external views.
- **Physical Data Independence**: Changes to the internal schema don't affect the conceptual schema.

### Database Languages
1. **DDL (Data Definition Language)**: Defines structure of database.
   - Commands: `CREATE`, `ALTER`, `DROP`, `TRUNCATE`
2. **DML (Data Manipulation Language)**: Manipulates data.
   - Commands: `SELECT`, `INSERT`, `UPDATE`, `DELETE`
3. **DCL (Data Control Language)**: Controls access.
   - Commands: `GRANT`, `REVOKE`
4. **TCL (Transaction Control Language)**: Manages transactions.
   - Commands: `COMMIT`, `ROLLBACK`, `SAVEPOINT`

---

## 4.3 Database Models and Database Applications

### Database Models
A **database model** describes the logical structure of a database — how data is organized, stored, and related.

#### 1. Hierarchical Model
- Organizes data in a **tree structure** (parent-child relationships).
- Each parent can have multiple children, but each child has only one parent.
- Example: Organization chart (Company → Department → Employee).
- **Disadvantage**: Rigid structure; difficult to handle many-to-many relationships.

```
        Company
           │
     ┌─────┴─────┐
   Sales        IT
     │           │
  Employee1  Employee2
```

#### 2. Network Model
- Extension of hierarchical model.
- Data is organized in a **graph structure** (records can have multiple parent and child records).
- Handles **many-to-many relationships**.
- Uses pointers to link records.
- **Disadvantage**: Complex structure; difficult to modify.

#### 3. Relational Model (Most Common)
- Data is organized in **tables (relations)** with rows (tuples) and columns (attributes).
- Proposed by **E.F. Codd** in 1970.
- Tables are linked using **keys** (primary key, foreign key).
- Uses **SQL** for querying.
- Examples: MySQL, Oracle, PostgreSQL, MS SQL Server.
- **Advantage**: Simple, flexible, widely used.

**Example Table:**

| StudentID | Name | Age | Course |
|---|---|---|---|
| 101 | Ram | 20 | BCA |
| 102 | Sita | 21 | BCA |

#### 4. Object-Oriented Model
- Data is stored as **objects** (like in OOP – Object-Oriented Programming).
- Objects have attributes and methods.
- Example: ObjectDB.
- **Advantage**: Suitable for complex data (multimedia, spatial data).

#### 5. Document Model (NoSQL)
- Data stored as **JSON/XML documents**.
- Flexible schema.
- Example: MongoDB.

### Database Applications
DBMS is used across many industries:

| Field | Application |
|---|---|
| **Banking** | Customer accounts, transactions, loan management |
| **Healthcare** | Patient records, medical history, prescriptions |
| **Education** | Student enrollment, exam results, library management |
| **E-Commerce** | Product catalog, order management, customer data |
| **Airlines** | Flight reservations, ticket booking, scheduling |
| **Government** | Citizen records, tax management, voter registration |
| **Telecommunications** | Call records, billing, subscriber management |
| **Manufacturing** | Inventory management, supply chain |

---

## 4.2 SQL and NoSQL Concepts

### SQL (Structured Query Language)

**SQL** is a standard language used to interact with **relational databases**. Developed by IBM in the 1970s.

**SQL Command Categories:**

**DDL (Data Definition Language):**
```sql
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
    Course VARCHAR(30)
);

ALTER TABLE Students ADD Email VARCHAR(100);

DROP TABLE Students;
```

**DML (Data Manipulation Language):**
```sql
-- Insert
INSERT INTO Students VALUES (101, 'Ram', 20, 'BCA');

-- Select
SELECT * FROM Students;
SELECT Name, Age FROM Students WHERE Course = 'BCA';

-- Update
UPDATE Students SET Age = 21 WHERE StudentID = 101;

-- Delete
DELETE FROM Students WHERE StudentID = 101;
```

**Key SQL Concepts:**
- **Primary Key**: Uniquely identifies each row in a table.
- **Foreign Key**: Links two tables together.
- **JOIN**: Combines rows from two or more tables.
- **Aggregate Functions**: COUNT(), SUM(), AVG(), MAX(), MIN()
- **GROUP BY**: Groups rows by a column.
- **ORDER BY**: Sorts results.

### NoSQL (Not Only SQL)

**NoSQL** databases are non-relational databases designed for **large-scale, distributed, unstructured data**.

**Why NoSQL?**
- Web applications needed to handle massive amounts of unstructured data.
- Relational databases couldn't scale horizontally easily.
- Need for flexible schemas (no fixed table structure).

**Types of NoSQL Databases:**

| Type | Description | Example |
|---|---|---|
| **Document Store** | Data stored as JSON/XML documents | MongoDB, CouchDB |
| **Key-Value Store** | Simple key-value pairs | Redis, DynamoDB |
| **Column Family** | Data stored in columns rather than rows | Apache Cassandra, HBase |
| **Graph Database** | Data stored as nodes and edges | Neo4j, ArangoDB |

**SQL vs NoSQL:**

| Feature | SQL (Relational) | NoSQL |
|---|---|---|
| Schema | Fixed (predefined tables) | Flexible (dynamic schema) |
| Scalability | Vertical (scale up) | Horizontal (scale out) |
| Data type | Structured | Unstructured/semi-structured |
| Query language | SQL | Varies (MongoDB queries, Cypher) |
| ACID compliance | Full ACID support | Often eventual consistency |
| Use case | Banking, ERP, traditional apps | Big data, social media, real-time apps |
| Examples | MySQL, PostgreSQL, Oracle | MongoDB, Redis, Cassandra |

---

## 4.4 Introduction to Data Warehousing

### What is a Data Warehouse?
A **data warehouse** is a large, centralized repository of integrated data collected from multiple sources, optimized for **analytical processing and business intelligence (BI)** rather than transaction processing.

**Key Characteristics (W.H. Inmon's definition):**
1. **Subject-Oriented**: Organized around major subjects (sales, finance, customers).
2. **Integrated**: Data from multiple sources is unified and consistent.
3. **Time-Variant**: Stores historical data (can track changes over time).
4. **Non-Volatile**: Data is not updated/deleted; it is only loaded and queried.

### Database vs Data Warehouse

| Feature | Database (OLTP) | Data Warehouse (OLAP) |
|---|---|---|
| Purpose | Daily transactions | Analysis and reporting |
| Data type | Current data | Historical data |
| Operations | INSERT, UPDATE, DELETE | Mostly SELECT (read-heavy) |
| Schema | Normalized (3NF) | Denormalized (Star/Snowflake) |
| Query type | Simple, fast | Complex, analytical |
| Users | Clerks, operational staff | Analysts, managers, executives |
| Size | GB range | TB to PB range |
| Examples | MySQL for orders | Amazon Redshift, Teradata |

### ETL Process
Data enters a data warehouse through the **ETL** process:
- **E – Extract**: Data is extracted from multiple source systems (databases, files, APIs).
- **T – Transform**: Data is cleaned, reformatted, and standardized.
- **L – Load**: Transformed data is loaded into the data warehouse.

### OLAP (Online Analytical Processing)
OLAP tools allow users to analyze data from multiple dimensions:
- **Slice and Dice**: Select specific dimensions.
- **Drill Down/Up**: Move between levels of data granularity.
- **Pivot**: Rotate data axes.

---

## 4.5 Data Mining and Concept of Big Data

### Data Mining
**Data mining** is the process of discovering patterns, correlations, anomalies, and insights from large datasets using statistical, mathematical, and machine learning techniques.

**Data Mining Tasks:**
1. **Classification**: Categorize data into predefined classes. (Email → Spam/Not Spam)
2. **Clustering**: Group similar data points without predefined classes. (Customer segmentation)
3. **Association Rule Mining**: Find relationships between variables. (Market basket analysis: "People who buy diapers also buy beer")
4. **Regression**: Predict continuous values. (House price prediction)
5. **Anomaly Detection**: Identify unusual patterns. (Fraud detection)

**KDD Process (Knowledge Discovery in Databases):**
```
Data → [Selection] → Target Data → [Preprocessing] → Clean Data 
    → [Transformation] → Transformed Data → [Data Mining] 
    → Patterns → [Interpretation/Evaluation] → Knowledge
```

**Applications of Data Mining:**
- Banking: Fraud detection, credit risk analysis
- Retail: Market basket analysis, customer churn prediction
- Healthcare: Disease prediction, drug discovery
- Telecom: Customer behavior analysis
- Web: Search engines, recommendation systems (Netflix, Amazon)

### Big Data

**Big Data** refers to extremely large datasets that cannot be processed effectively using traditional database management systems.

**The 5 V's of Big Data:**

| V | Description | Example |
|---|---|---|
| **Volume** | Massive scale of data | Facebook generates 500TB/day |
| **Velocity** | Speed of data generation | Real-time Twitter feeds |
| **Variety** | Different types of data | Text, images, video, sensor data |
| **Veracity** | Quality and trustworthiness | Removing noise and inaccuracies |
| **Value** | Business value from data | Insights that drive decisions |

**Big Data Technologies:**
- **Hadoop**: Open-source framework for distributed storage and processing (HDFS + MapReduce).
- **Apache Spark**: Fast, in-memory big data processing.
- **NoSQL Databases**: MongoDB, Cassandra for storing big data.
- **Cloud Platforms**: AWS, Google Cloud, Azure for big data storage and analysis.

**Big Data Applications:**
- Social media analytics
- Smart cities and IoT
- Healthcare analytics (genomics)
- Financial fraud detection
- Predictive maintenance in manufacturing

---

## TU Exam Format Questions – Unit 4

---

### 📝 Long Answer Questions (10 Marks)

**Q1. What is DBMS? Explain the three-level architecture of a database system with a diagram.**

**Answer:**

**DBMS Definition:** A Database Management System is software that enables the creation, definition, manipulation, and management of databases. It serves as an interface between the database and its end users, ensuring that data is consistently organized and accessible.

**Three-Level Architecture (ANSI/SPARC):**

The three-level architecture separates the database into three levels of abstraction to achieve data independence.

```
    ┌────────────────────────────────────────┐
    │           EXTERNAL LEVEL               │
    │  User A View │ User B View │ User C View│
    │  (My Marks)  │ (All Marks) │ (Attendance│
    └──────────────────────┬─────────────────┘
                           │ External/Conceptual Mapping
    ┌──────────────────────▼─────────────────┐
    │           CONCEPTUAL LEVEL             │
    │    Full logical structure of DB        │
    │   (Tables, relationships, constraints) │
    └──────────────────────┬─────────────────┘
                           │ Conceptual/Internal Mapping
    ┌──────────────────────▼─────────────────┐
    │           INTERNAL LEVEL               │
    │    Physical storage on disk            │
    │   (File organization, indexes, blocks) │
    └────────────────────────────────────────┘
```

**1. External Level:**
- The highest level of abstraction.
- Represents the user's view of the database.
- Different users have different views based on their needs and permissions.
- A student sees only their own records; an administrator sees all records.
- Implemented through **Views** in SQL.

**2. Conceptual Level:**
- Middle level; the logical view of the entire database.
- Managed by the Database Administrator (DBA).
- Describes all entities, attributes, relationships, and constraints.
- Hides the details of physical storage from users.
- Schema defined using DDL (Data Definition Language).

**3. Internal Level:**
- The lowest level; describes how data is physically stored.
- Deals with storage structures: B-trees, hash tables, file organization.
- Managed by the DBMS engine.
- Hides physical implementation from the conceptual level.

**Data Independence:**
- **Logical data independence**: Change in conceptual schema doesn't affect user views.
- **Physical data independence**: Change in internal schema doesn't affect conceptual schema.

**Advantages of this architecture:**
1. Different users can have different views of the same data.
2. Changes to physical storage don't affect applications.
3. Improved security (users see only what they're authorized to see).
4. Simplified database design and maintenance.

---

**Q2. What is data mining? Explain its tasks and applications. Also explain Big Data with its characteristics.**

**Answer:**

**Data Mining:**

Data mining is the process of discovering hidden patterns, correlations, trends, and knowledge from large datasets using techniques from statistics, machine learning, and artificial intelligence.

**Data Mining Tasks:**

**1. Classification:**
Assigns data items to predefined categories based on patterns in the training data.
- Algorithm learns from labeled data.
- Example: Email classification (spam/not spam), medical diagnosis (disease/no disease).
- Algorithms: Decision Trees, Naive Bayes, Neural Networks.

**2. Clustering:**
Groups data points into clusters based on similarity, without predefined labels.
- Unlike classification, there are no predefined categories.
- Example: Customer segmentation (group customers by buying behavior).
- Algorithms: K-means, Hierarchical Clustering, DBSCAN.

**3. Association Rule Mining:**
Discovers interesting relationships between variables in large databases.
- Example: Market basket analysis: "Customers who buy bread also buy butter with 80% probability."
- Algorithm: Apriori algorithm.
- Used in supermarket layouts, recommendation engines.

**4. Regression:**
Predicts a continuous numerical value.
- Example: Predicting house prices, stock market forecasting.
- Algorithms: Linear Regression, Decision Tree Regression.

**5. Anomaly Detection:**
Identifies unusual patterns that do not conform to expected behavior.
- Example: Credit card fraud detection, network intrusion detection.

**Applications of Data Mining:**
- **Banking**: Fraud detection, credit scoring, customer churn prediction.
- **Retail**: Product recommendation, inventory optimization.
- **Healthcare**: Disease outbreak prediction, drug discovery.
- **Telecom**: Network fault prediction, customer behavior analysis.
- **Web**: Search engine optimization, click-stream analysis.

---

**Big Data:**

Big Data refers to datasets that are so large, fast-moving, or diverse that traditional data management systems cannot process them efficiently.

**The 5 V's of Big Data:**

**1. Volume:** Refers to the sheer size of data generated. Social media platforms, IoT sensors, and transaction systems generate petabytes of data daily. Example: Google processes 8.5 billion searches per day.

**2. Velocity:** The speed at which data is generated and must be processed. Financial markets require real-time processing of trade data. Example: Twitter generates 500 million tweets per day.

**3. Variety:** Data comes in many different formats: structured (databases), semi-structured (JSON, XML), and unstructured (images, videos, emails).

**4. Veracity:** The uncertainty and quality of data. Raw data may contain noise, errors, and inconsistencies that must be cleaned before analysis.

**5. Value:** The business value derived from analyzing big data. Insights gained from big data drive competitive advantage and decision-making.

**Big Data Technologies:**
- **Hadoop (HDFS + MapReduce)**: Open-source framework for distributed storage and parallel processing of large datasets.
- **Apache Spark**: In-memory data processing framework; 100x faster than MapReduce.
- **NoSQL Databases**: MongoDB, Cassandra, HBase for storing unstructured big data.
- **Cloud Platforms**: AWS S3 and Redshift, Google BigQuery, Azure HDInsight.

---

### 📝 Short Answer Questions (5 Marks)

**Q3. What is SQL? Explain DDL and DML commands with examples.**

**Answer:**

**SQL (Structured Query Language)** is a standard language for interacting with relational databases. It was developed by IBM in the 1970s and is now an ANSI/ISO standard.

**DDL (Data Definition Language):** Defines the structure of the database.

```sql
-- CREATE: Create a new table
CREATE TABLE Student (
    RollNo INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Age INT,
    Course VARCHAR(30)
);

-- ALTER: Modify existing table
ALTER TABLE Student ADD Email VARCHAR(100);

-- DROP: Delete a table permanently
DROP TABLE Student;

-- TRUNCATE: Remove all records but keep structure
TRUNCATE TABLE Student;
```

**DML (Data Manipulation Language):** Manipulates data within tables.

```sql
-- INSERT: Add new record
INSERT INTO Student VALUES (101, 'Ram Sharma', 20, 'BCA');

-- SELECT: Retrieve data
SELECT * FROM Student;
SELECT Name, Age FROM Student WHERE Course = 'BCA' ORDER BY Name;

-- UPDATE: Modify existing data
UPDATE Student SET Age = 21 WHERE RollNo = 101;

-- DELETE: Remove records
DELETE FROM Student WHERE RollNo = 101;
```

---

**Q4. Differentiate between SQL and NoSQL databases.**

| Feature | SQL (Relational) | NoSQL |
|---|---|---|
| Data model | Tables with rows and columns | Documents, key-value, graph, column |
| Schema | Fixed, predefined | Flexible, dynamic |
| Query language | Standardized SQL | No standard; varies by database |
| Scalability | Vertical scaling | Horizontal scaling |
| ACID | Fully ACID compliant | Often sacrifices ACID for performance |
| Data structure | Structured only | Structured, semi-structured, unstructured |
| Joins | Supports complex joins | Typically no joins |
| Use case | ERP, banking, traditional web apps | Real-time web, big data, IoT |
| Examples | MySQL, PostgreSQL, Oracle, MS SQL | MongoDB, Redis, Cassandra, Neo4j |
| Best for | Complex queries, data integrity | High speed, large-scale, flexible data |

---

**Q5. What is a data warehouse? How does it differ from a traditional database?**

**Answer:**

**Data Warehouse:** A data warehouse is a centralized repository that integrates data from multiple operational sources, designed specifically for reporting, analysis, and business intelligence. It stores large volumes of historical data.

Key features:
- **Subject-oriented**: Organized around business subjects (sales, customers).
- **Integrated**: Unified data from multiple sources.
- **Time-variant**: Stores historical data for trend analysis.
- **Non-volatile**: Data is only loaded, not updated or deleted.

**Traditional Database vs Data Warehouse:**

| Feature | Traditional Database (OLTP) | Data Warehouse (OLAP) |
|---|---|---|
| Full form | Online Transaction Processing | Online Analytical Processing |
| Purpose | Record day-to-day transactions | Analyze historical data |
| Operations | INSERT, UPDATE, DELETE | Mostly SELECT |
| Data | Current operational data | Historical, aggregated data |
| Query type | Simple, fast, predefined | Complex, ad-hoc analytical |
| Schema | Normalized (reduces redundancy) | Denormalized (star/snowflake schema) |
| Users | Front-line operational staff | Business analysts, executives |
| Response time | Milliseconds | Seconds to minutes |
| Size | Gigabytes | Terabytes to petabytes |

---

### 📝 Very Short / Objective Questions (1–2 Marks)

**Q6. Who proposed the Relational Database Model?**
→ **E.F. Codd** (1970)

**Q7. What does ETL stand for?**
→ **Extract, Transform, Load**

**Q8. Give two examples of NoSQL databases.**
→ **MongoDB** and **Apache Cassandra**

**Q9. What is the primary key?**
→ A column (or set of columns) that uniquely identifies each row in a table.

**Q10. Full form of DBMS.**
→ **Database Management System**

**Q11. What is data mining?**
→ The process of discovering patterns and knowledge from large datasets.

**Q12. Name two DBMS software.**
→ **MySQL** and **Oracle**

**Q13. What does DDL stand for?**
→ **Data Definition Language**

**Q14. What command is used to retrieve data in SQL?**
→ `SELECT`

**Q15. Name the 5 V's of Big Data.**
→ **Volume, Velocity, Variety, Veracity, Value**

---

*End of Unit 4*
