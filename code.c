#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for patient
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    char contact[20];

    struct Patient *next;
};

// Head pointer
struct Patient *head = NULL;

// Function to add patient
void addPatient() {
    struct Patient *newPatient;
    struct Patient *temp;

    newPatient = (struct Patient*)malloc(sizeof(struct Patient));

    if (newPatient == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &newPatient->id);

    temp = head;
    while (temp != NULL) {
        if (temp->id == newPatient->id) {
            printf("Patient ID already exists!\n");
            free(newPatient);
            return;
        }
        temp = temp->next;
    }

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", newPatient->name);

    printf("Enter Age: ");
    scanf("%d", &newPatient->age);

    printf("Enter Disease: ");
    scanf(" %49[^\n]", newPatient->disease);

    printf("Enter Contact Number: ");
    scanf("%19s", newPatient->contact);

    newPatient->next = NULL;

    if (head == NULL) {
        head = newPatient;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    printf("\nPatient Added Successfully!\n");
}

// Function to display patients
void displayPatients() {
    struct Patient *temp = head;

    if (head == NULL) {
        printf("\nNo Patient Records Found!\n");
        return;
    }

    printf("\n------ Patient Records ------\n");

    while (temp != NULL) {
        printf("\nPatient ID: %d", temp->id);
        printf("\nName: %s", temp->name);
        printf("\nAge: %d", temp->age);
        printf("\nDisease: %s", temp->disease);
        printf("\nContact: %s\n", temp->contact);

        temp = temp->next;
    }
}

// Function to search patient
void searchPatient() {
    int id;
    struct Patient *temp = head;

    printf("\nEnter Patient ID to Search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nPatient Found!\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Disease: %s\n", temp->disease);
            printf("Contact: %s\n", temp->contact);
            return;
        }
        temp = temp->next;
    }

    printf("\nPatient Not Found!\n");
}

// Function to update patient
void updatePatient() {
    int id;
    struct Patient *temp = head;

    printf("\nEnter Patient ID to Update: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", temp->name);

            printf("Enter New Age: ");
            scanf("%d", &temp->age);

            printf("Enter New Disease: ");
            scanf(" %49[^\n]", temp->disease);

            printf("Enter New Contact: ");
            scanf("%19s", temp->contact);

            printf("\nPatient Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nPatient Not Found!\n");
}

// Function to delete patient
void deletePatient() {
    int id;
    struct Patient *temp = head;
    struct Patient *prev = NULL;

    printf("\nEnter Patient ID to Delete: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {

            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nPatient Deleted Successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nPatient Not Found!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n\n================================");
        printf("\n HOSPITAL PATIENT MANAGEMENT");
        printf("\n================================");
        printf("\n1. Add Patient");
        printf("\n2. Display Patients");
        printf("\n3. Search Patient");
        printf("\n4. Update Patient");
        printf("\n5. Delete Patient");
        printf("\n6. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                printf("\nThank You! Exiting Program.\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 6);

    // Free remaining memory
    while (head != NULL) {
        struct Patient *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
