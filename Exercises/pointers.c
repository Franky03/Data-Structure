#include <stdio.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct circle {
    point p;
    int radius;
} circle;


void imprimePorCirculo(circle *c, point *p){
    printf("Circulo: %d %d %d\n", c->radius, c->p.x, c->p.y);
    printf("Ponto: %d %d\n", p->x, p->y);
}

int main(void){
    circle c;
    point p;

    p.x = 10;
    p.y = 20;

    c.p = p;
    c.radius = 10;


    imprimePorCirculo(&c, &c.p);

}