# **Hospital Management System**

A simple console-based Hospital Management System written in C. The system allows the management of patient and doctor records, assigning doctors to patients, searching for patients by ID, and generating bills for consultations. The system also provides functionalities to add and display patient and doctor information.

## **Features**

- Add new patients to the system.
- Display the list of all registered patients.
- Search for a patient by their unique ID.
- Add new doctors to the system.
- Display the list of all registered doctors.
- Assign a doctor to a patient.
- Generate a prescribed bill with a fixed consultation fee for a patient.

## **Technologies Used**

- **C Programming Language** for system implementation.
- **Standard Libraries**: `stdio.h`, `string.h`, `stdlib.h`

## **Data Structures**

1. **Doctor**  
   A structure to store information about a doctor.

    ```c
    typedef struct {
        int id;                    // Doctor's unique identifier
        char name[50];             // Doctor's name
        char specialization[100];  // Doctor's specialization
        char degree[100];          // Doctor's degree (e.g., MD, PhD)
    } Doctor;
    ```

2. **Patient**  
   A structure to store information about a patient.

    ```c
    typedef struct {
        int id;                    // Patient's unique identifier
        char name[50];             // Patient's name
        int age;                   // Patient's age
        char address[100];         // Patient's address
        char contact[15];          // Patient's contact number
        char gender[1];            // Patient's gender (M/F)
        int doctor_id;             // ID of the assigned doctor
    } Patient;
    ```

## **Global Variables**

```c
#define MAX_PATIENT 200     // Maximum number of patients
#define MAX_DOCTOR 50       // Maximum number of doctors

Patient patient[MAX_PATIENT];  // Array to store patients
Doctor doctor[MAX_DOCTOR];    // Array to store doctors
int patient_count = 0;         // Counter for the number of patients
int doctor_count = 0;          // Counter for the number of doctors
```

- **MAX_PATIENT**: The maximum number of patients allowed in the system.
- **MAX_DOCTOR**: The maximum number of doctors allowed in the system.
- **patient_count**: Tracks the current number of patients in the system.
- **doctor_count**: Tracks the current number of doctors in the system.

## **Functions**

### **1. `add_patient()`**
Adds a new patient to the system. The user is prompted to enter the patient's details including ID, name, age, address, contact, gender, and the doctor ID to be assigned.

**Input**: Patient details (ID, Name, Age, Address, Contact, Gender, Doctor ID).  
**Output**: Confirmation message if the patient is added successfully or error message if the limit is reached.

### **2. `display_patient()`**
Displays the list of all registered patients in the system. If no patients exist, it will display an error message.

**Input**: None.  
**Output**: A list of all patients with their ID, Name, Age, Address, Contact, Gender, and Doctor ID.

### **3. `search_patient_by_id()`**
Searches for a patient by their ID and displays their details. If the patient is not found, an error message is displayed.

**Input**: Patient ID.  
**Output**: Patient details or a message indicating the patient was not found.

### **4. `add_doctor()`**
Adds a new doctor to the system. The user is prompted to enter the doctor's details including ID, name, specialization, and degree.

**Input**: Doctor details (ID, Name, Specialization, Degree).  
**Output**: Confirmation message if the doctor is added successfully or error message if the limit is reached.

### **5. `display_doctor()`**
Displays the list of all registered doctors in the system. If no doctors exist, an error message is displayed.

**Input**: None.  
**Output**: A list of all doctors with their ID, Name, Specialization, and Degree.

### **6. `assign_doctor_to_patient()`**
Assigns a doctor to a patient based on their unique IDs. If either the patient or the doctor is not found, an error message is displayed.

**Input**: Patient ID and Doctor ID.  
**Output**: Confirmation message if the doctor is successfully assigned to the patient or error message if either ID is not found.

### **7. `prescribed_bill()`**
Generates a prescribed bill for a patient, displaying a fixed consultation fee.

**Input**: Patient ID.  
**Output**: A bill with the consultation fee or an error message if the patient is not found.

## **How to Run**

1. Clone the repository:
    ```bash
    git clone https://github.com/Hydra-Ramesh/Hospital-Management-System-in-C.git
    ```

2. Navigate to the project directory:
    ```bash
    cd hospital-management-system
    ```

3. Compile the program using a C compiler (e.g., `gcc`):
    ```bash
    gcc hospital_management_system.c -o hospital_management_system
    ```

4. Run the program:
    ```bash
    ./hospital_management_system
    ```

5. Follow the on-screen instructions to interact with the system.

## **Sample Output**

### **Main Menu:**
```text
--- Hospital Management System ---
1. Add Patient
2. Display Patient
3. Search Patient by ID
4. Add Doctor
5. Display Doctor
6. Assign Doctor to Patient
7. Generate Prescribed Bill
8. Exit
Enter your choice:
```

### **Adding a Patient:**
```text
Enter Patient ID: 1
Enter Patient Name: John Doe
Enter Patient Age: 30
Enter Patient Address: 123 Main St
Enter Patient Contact: 555-1234
Enter Patient Gender (M/F): M
Enter Doctor ID for this Patient: 101
Patient added successfully.
```

### **Displaying Patients:**
```text
--- Patient Details ---
ID  Name        Age  Address       Contact   Gender  Doctor ID
1   John Doe    30   123 Main St   555-1234  M       101
```

### **Assigning a Doctor to a Patient:**
```text
Enter Patient ID: 1
Enter Doctor ID: 101
Doctor assigned successfully.
```

### **Generating a Prescribed Bill:**
```text
Enter Patient ID: 1
Bill for patient ID 1
Consultation Fee: 500
```

---

## **License**

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to customize the README with any specific details you'd like, such as your GitHub username or additional information about the system.