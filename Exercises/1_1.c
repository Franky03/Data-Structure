// implementar uma função que indique se um ponto (x, y) está localizado dentro de um retângulo de lados paralelos aos eixos x e y.
int insideRect(int x0, int y0, int x1, int y1, int x, int y) {
    if (x > x0 && x < x1 && y > y0 && y < y1) {
        return 1;
    }
    return 0;
}