#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[50];
    Historico *historico;

} Aluno;

typedef struct historico {
    Disciplina *disciplinas;
} Historico;

typedef struct curso {

} Curso;

typedef struct disciplina {
    char nome[50];
    struct disciplina *next;
} Disciplina;

typedef struct turma {

} Turma;

