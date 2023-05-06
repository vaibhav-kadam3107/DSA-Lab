#include <stdio.h>
#include <stdlib.h>

#define MAX_DOCTORS 10
#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
} Patient;

typedef struct {
    int id;
    char name[50];
    int num_patients;
    Patient patients[MAX_PATIENTS];
} Doctor;

int num_doctors = 0;
Doctor doctors[MAX_DOCTORS];

void add_doctor() {
    if (num_doctors < MAX_DOCTORS) {
        Doctor doctor;
        printf("Enter doctor's ID: ");
        scanf("%d", &doctor.id);
        printf("Enter doctor's name: ");
        scanf("%s", doctor.name);
        doctor.num_patients = 0;
        doctors[num_doctors] = doctor;
        num_doctors++;
        printf("Doctor added successfully.\n");
    } else {
        printf("Maximum number of doctors reached.\n");
    }
}

void add_patient() {
    if (num_doctors == 0) {
        printf("No doctors available.\n");
    } else {
        Patient patient;
        printf("Enter patient's ID: ");
        scanf("%d", &patient.id);
        printf("Enter patient's name: ");
        scanf("%s", patient.name);
        int assigned_doctor = 0;
        for (int i = 1; i < num_doctors; i++) {
            if (doctors[i].num_patients < doctors[assigned_doctor].num_patients) {
                assigned_doctor = i;
            }
        }
        if (doctors[assigned_doctor].num_patients < MAX_PATIENTS) {
            doctors[assigned_doctor].patients[doctors[assigned_doctor].num_patients] = patient;
            doctors[assigned_doctor].num_patients++;
            printf("Patient added successfully and assigned to Doctor %d (%s).\n",
                   doctors[assigned_doctor].id, doctors[assigned_doctor].name);
        } else {
            printf("Maximum number of patients for this doctor reached.\n");
        }
    }
}

void display_patients() {
    if (num_doctors == 0) {
        printf("No doctors available.\n");
    } else {
        for (int i = 0; i < num_doctors; i++) {
            printf("Doctor %d (%s): %d patients\n", doctors[i].id, doctors[i].name, doctors[i].num_patients);
            for (int j = 0; j < doctors[i].num_patients; j++) {
                printf("- Patient %d (%s)\n", doctors[i].patients[j].id, doctors[i].patients[j].name);
            }
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nMedical Clinic Management System\n");
        printf("1. Add a doctor\n");
        printf("2. Add a patient\n");
        printf("3. Display patients\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_doctor();
                break;
            case 2:
                add_patient();
                break;
            case 3:
                display_patients();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
