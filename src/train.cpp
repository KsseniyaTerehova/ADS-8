// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
  Cage* CageW = new Cage;
  CageW->light = light;
  CageW->n = nullptr;
  CageW->p = nullptr;
  if (first == nullptr) {
    first = CageW;
  } else {
    if (first->n == nullptr) {
      first->n = CageW;
      first->p = CageW;
      CageW->p = first;
      CageW->n = first;
    } else {
      Cage* cg = first;
      while (cg->n != first) {
        cg = cg->n;
      }
      cg->n = CageW;
      CageW->p = cg;
      CageW->n = first;
      first->p  = CageW;
    }
  }
  countOp = 0;
}
int Train::getLength() {
    Cage* CageWa = first;
    if (CageWa->light == false) {
        CageWa->light = true;
    }
    int rezult = 0;
    int countCageW = 0;
    while (true) {
        CageWa = CageWa->n;
        countOp += 1;
        countCageW += 1;
        while (CageWa->light == false) {
            CageWa = CageWa->n;
            countOp += 1;
            countCageW += 1;
        }
        CageWa->light = false;
        rezult = countCageW;
        while (countCageW != 0) {
            countOp += 1;
            countCageW -= 1;
            CageWa = CageWa->p;
        }
        if (CageWa->light == false) {
            return rezult;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
