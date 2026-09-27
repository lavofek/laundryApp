//
// Created by ofek lavi on 27/09/2026.
//
#ifndef LAUNDRYAPP_FAMILY_H
#define LAUNDRYAPP_FAMILY_H

#include<stdbool.h>

struct FamilyMember {
    char name[30];
    bool laundryReady;
};

void viewFamily(struct FamilyMember family[], int size);
int markLaundryReady(struct FamilyMember family[], int size);
int collectLaundry(struct FamilyMember family[], int size);




#endif //LAUNDRYAPP_FAMILY_H