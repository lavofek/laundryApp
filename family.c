//
// Created by ofek lavi on 27/09/2026.
//

#include <stdio.h>
#include <string.h>
#include "family.h"


void viewFamily(struct FamilyMember family[], int size) {
    wipeInputStream();
    for (int i = 0; i < size; i++) {
        if (family[i].laundryReady) {
            printf("%d. %s - Laundry ready\n", i + 1, family[i].name);
        } else {
            printf("%d. %s - Laundry not ready\n", i + 1, family[i].name);
        }
    }
}
//TODO - add what happens when there are no family members
int markLaundryReady(struct FamilyMember family[], int size) {
    wipeInputStream();
    for (int i = 0; i < size; i++) printf("%d. %s\n", i + 1, family[i].name);
    printf("Select family member:\n");
    int selection;
    scanf(" %d", &selection);
    if (selection < 1 || selection > size) {
        printf("Invalid option\n");
        return -1;
    }
    selection -= 1;
    family[selection].laundryReady = true;
    printf("\n%s's laundry is now ready!\n", family[selection].name);
    return selection;
}
int collectLaundry(struct FamilyMember family[], int size) {
    wipeInputStream();
    for (int i = 0; i < size; i++) printf("%d. %s\n", i + 1, family[i].name);
    printf("Select family member:\n");
    int selection;
    scanf(" %d", &selection);
    if (selection < 1 || selection > size) {
        printf("Invalid option\n");
        return -1;
    }
    selection -= 1;
    family[selection].laundryReady = false;
    printf("\n%s has collected his/her laundry\n", family[selection].name);
    return selection;
}
int addFamilyMember(struct FamilyMember family[], int *size, int nameSize) {
    wipeInputStream();
    char tempName[nameSize];
    printf("New member name: ");
    if (getString(tempName, nameSize) == 0) {
        strcpy(family[*size].name, tempName);
        *size += 1;
        return 0;
    }
    printf("Error creating a new family member.\n");
    return 1;
}
int removeFamilyMember(struct FamilyMember family[], int *size, int nameSize) {
    wipeInputStream();
    printf("Which member do you want to remove?\nPlease enter a number:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d. %s\n", i + 1, family[i].name);
    }
    int selection = -1;
    scanf(" %d",&selection);
    if (selection < 1 || selection > *size) {
        printf("Error with family member selection.\n");
        return 1;
    }
    selection--;
    printf("%d. %s has been selected, are you sure you want to delete them?",
        selection + 1, family[selection].name);
    printf("Please enter Y/N: ");
    char sure = 'N';
    scanf(" %c", &sure);
    char tempName[nameSize];
    strcpy(tempName, family[selection].name);
    if (sure == 'Y' || sure == 'y') {
        deleteFamilyMember(family, *size, selection);
        (*size)--;
        printf("Family member %s has been deleted!\n", tempName);
        return 0;
    }
    if (sure == 'N' || sure == 'n') {
        printf("No family member has been deleted\n");
        return 0;
    }
    printf("Input not valid\nNo family member has been deleted\n");
    return 1;
}
int deleteFamilyMember(struct FamilyMember family[], int size, int sel) {
    for (int i = sel; i < size; i++) {
        if (i == size-1) {
            strcpy(family[i].name," ");
            family[i].laundryReady = 0;
            return 0;
        }
        strcpy(family[i].name,family[i+1].name);
        family[i].laundryReady = family[i+1].laundryReady;
    }
    return 0;
}
int getString(char name[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == size-1 && name[i] != '\0') {
            printf("Error with name input.\n");
            wipeInputStream();
            return 1;
        }
        scanf("%c", &name[i]);
        if (name[i] == '\n') {
            name[i] = '\0';
            wipeInputStream();
            return 0;
        }
    }
    printf("Error with name input.\n");
    wipeInputStream();
    return 1;
}
void wipeInputStream() {
    while (getchar() != '\n');
}
