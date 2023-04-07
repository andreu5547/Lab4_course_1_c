//
// Created by 1 on 25.03.2023.
//

#ifndef STRINGVECTORS_H
#define STRINGVECTORS_H

typedef struct CVector CVector;

CVector *init_cvector(int n);

void input_cvector(CVector *ve);

void add_symbol_cvector(CVector *ve, char symbol);

void free_CV(CVector* ve);

char *give_string(CVector *ve);

int find_pos_first_sym_ve1_in_ve2(CVector *ve1, CVector *ve2);

#endif //STRINGVECTORS_H
