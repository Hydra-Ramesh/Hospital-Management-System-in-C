#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Define the Doctor
typedef struct{
    int id;
    char name[50];
    char specilization[100];
    char degree[100];
}Doctor;

//Define the Patient
typedef struct{
    int id;
    char name[50];
    int age;
    char address[100];
    char contact[15];
    char gender[1];
    int doctor_id; //Assinged to doctor
}Patient;

//Global variables
#define MAX_PATIENT 200
#define MAX_DOCTOR 50

Patient patient[MAX_PATIENT];
Doctor doctor[MAX_DOCTOR];
int patient_count = 0;
int doctor_count = 0;

//Function Prototypes
void add_patient();//Done
void display_patient();//DOne
void search_patient_by_id();//DOne
void add_doctor();//Done
void display_doctor();//Done
void assign_doctor_to_patient();//Done
void prescribed_bill();//Done



void add_patient(){
    if(patient_count >= MAX_PATIENT){
        printf("Maximum number of patients reached.\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &patient[patient_count].id);

    printf("Enter Patient Name: ");
    scanf("%s", patient[patient_count].name);

    printf("Enter Patient Age: ");
    scanf("%d", &patient[patient_count].age);

    printf("Enter Patient Address: ");
    scanf("%s", patient[patient_count].address);

    printf("Enter Patient Contact: ");
    scanf("%s", patient[patient_count].contact);

    printf("Enter Patient Gender (M/F): ");
    scanf(" %c", &patient[patient_count].gender);

    printf("Enter Doctor ID for this Patient: ");
    scanf("%d", &patient[patient_count].doctor_id);

    patient_count++; //post increment
    printf("Patient added successfully.\n");
}

void display_patient(){
    if(patient_count == 0){
        printf("No patients found.\n");
        return;
    }

    printf("--- Patient Details ---\n");
    printf("ID\tName\tAge\tAddress\tContact\tGender\tDoctor ID\n");
    for(int i=0; i<patient_count; i++){
        printf("%d\t%s\t%d\t%s\t%s\t%c\t%d\n", patient[i].id, patient[i].name, patient[i].age, patient[i].address, patient[i].contact, patient[i].gender, patient[i].doctor_id);
    }
}

void search_patient_by_id(){
    int id;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<patient_count; i++){
        if(patient[i].id == id){
            printf("--- Patient Details ---\n");
            printf("ID\tName\tAge\tAddress\tContact\tGender\tDoctor ID\n");
            printf("%d\t%s\t%d\t%s\t%s\t%c\t%d\n", patient[i].id, patient[i].name, patient[i].age, patient[i].address, patient[i].contact, patient[i].gender, patient[i].doctor_id);
            return;
        }
    }

    printf("Patient not found.\n");
}

void add_doctor(){
    if(doctor_count >= MAX_DOCTOR){
        printf("Maximum number of doctors reached.\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &doctor[doctor_count].id);

    printf("Enter Doctor Name: ");
    scanf("%s", doctor[doctor_count].name);

    printf("Enter Doctor Specialization: ");
    scanf("%s", doctor[doctor_count].specilization);

    printf("Enter Doctor Degree: ");
    scanf("%s", doctor[doctor_count].degree);

    doctor_count++; //post increment
    printf("Doctor added successfully.\n");
}

void display_doctor(){
    if(doctor_count == 0){
        printf("No doctors found.\n");
        return;
    }

    printf("--- Doctor Details ---\n");
    printf("ID\tName\tSpecilization\tDegree\n");
    for(int i=0; i<doctor_count; i++){
        printf("%d\t%s\t%s\t%s\n", doctor[i].id, doctor[i].name, doctor[i].specilization, doctor[i].degree);
    }
}

void assign_doctor_to_patient(){
    int patient_id, doctor_id;
    printf("Enter Patient ID: ");
    scanf("%d", &patient_id);

    printf("Enter Doctor ID: ");
    scanf("%d", &doctor_id);

    // for(int i=0; i<patient_count; i++){
    //     if(patient[i].id == patient_id){
    //         patient[i].doctor_id = doctor_id;
    //         printf("Doctor assigned successfully.\n");
    //         return;
    //     }
    // }
    int patient_found = 0;
    int doctor_found= 0;
    for(int i=0; i<patient_count; i++){
        if(patient[i].id == patient_id){
            patient_found=1;
            for(int j=0; j<doctor_count;j++){
                if(doctor[j].id == doctor_id){
                    doctor_found = 1;
                    patient[i].doctor_id = doctor_id;
                    printf("Doctor assigned successfully.\n");
                    return;
                }
            }
        }
    }
    if(!patient_found){
        printf("Patient not found.\n");
    }
    if(!doctor_found){
        printf("Doctor not found.\n");
    }
}

void prescribed_bill(){
    int patient_id;
    printf("Enter Patient ID: ");
    scanf("%d", &patient_id);
    if(patient_count == 0){
        printf("No patients found.\n");
        return;
    }
    for(int i=0; i<patient_count; i++){
        if(patient[i].id == patient_id){
            int consult_fee = 500;
            printf("\nBill for patient ID %d\n", patient[i].id);
            printf("Consultation Fee: %d\n", consult_fee);
            return;
        }
    }
}
int main(){
    int choice;
    while(1){
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. Display Patient\n");
        printf("3. Search Patient by ID\n");
        printf("4. Add Doctor\n");
        printf("5. Display Doctor\n");
        printf("6. Assign Doctor to Patient\n");
        printf("7. Generate Prescribed Bill\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_patient();
                break;
            case 2:
                display_patient();
                break;
            case 3:
                search_patient_by_id();
                break;
            case 4:
                add_doctor();
                break;
            case 5:
                display_doctor();
                break;
            case 6:
                assign_doctor_to_patient();
                break;
            case 7:
                prescribed_bill();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}