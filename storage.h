//
// Created by ofek lavi on 27/09/2026.
//
#ifndef LAUNDRYAPP_STORAGE_H
#define LAUNDRYAPP_STORAGE_H

#include "family.h"

int saveFamily(struct FamilyMember family[], int size, const char *location);
int loadFamily(struct FamilyMember family[], int size, const char *location);

#endif //LAUNDRYAPP_STORAGE_H