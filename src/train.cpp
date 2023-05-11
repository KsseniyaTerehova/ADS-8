// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
  Cage* CageW = new Cage;
  CageW->light = light;
  CageW->next = nullptr;
  CageW->prev = nullptr;
  if (first == nullptr) {
    first = CageW;
  } else {
    if (first->next == nullptr) {
      first->next = CageW;
      first->prev = CageW;
      CageW->prev = first;
      CageW->next = first;
    } else {
      Cage* cg = first;
      while (cg->next != first) {
        cg = cg->next;
      }
      cg->next = CageW;
      CageW->prev = cg;
      CageW->next = first;
      first->prev  = CageW;
    }
  }
  countOp = 0;
}
int Train::getLength() {
    Cage* CageWg = first;
    if (CageWg->light == false) {
        CageWg->light = true;
    }
    int rezult = 0;
    int countCageW = 0;
    while (true) {
        CageWg = CageWg->next;
        countOp += 1;
        countCageW += 1;
        while (CageWg->light == false) {
            CageWg = CageWg->next;
            countOp += 1;
            countCageW += 1;
        }
        CageWg->light = false;
        rezult = countCageW;
        while (countCageW != 0) {
            countOp += 1;
            countCageW -= 1;
            CageWg = CageWg->prev;
        }
        if (CageWg->light == false) {
            return rezult;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
