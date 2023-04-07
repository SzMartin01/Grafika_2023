#include <stdio.h>

// Defini�ljuk a Cuboid strukt�r�t, amely tartalmazza a t�glatest 3 �l�nek a hossz�t.
typedef struct {
    float length;
    float width;
    float height;
} Cuboid;

// Defini�ljuk a set_size f�ggv�nyt, amellyel ellen�rz�tt m�don be lehet �ll�tani egyszerre a 3 �l hossz�t.
void set_size(Cuboid* cuboid, float length, float width, float height) {
    cuboid->length = length;
    cuboid->width = width;
    cuboid->height = height;
}

// Defini�ljuk a calc_volume f�ggv�nyt, amelyik kisz�m�tja a t�glatest t�rfogat�t.
float calc_volume(Cuboid cuboid) {
    return cuboid.length * cuboid.width * cuboid.height;
}

// Defini�ljuk a calc_surface f�ggv�nyt, amelyik kisz�m�tja a t�glatest felsz�n�t.
float calc_surface(Cuboid cuboid) {
    return 2 * (cuboid.length * cuboid.width + cuboid.length * cuboid.height + cuboid.width * cuboid.height);
}

// Defini�ljuk a check_square_side f�ggv�nyt, amelyik a t�glalapot megvizsg�lja, hogy van-e n�gyzet alak� lapja.
int check_square_side(Cuboid cuboid) {
    if (cuboid.length == cuboid.width || cuboid.length == cuboid.height || cuboid.width == cuboid.height) {
        return 1;
    }
    return 0;
}

// Tesztelj�k a f�ggv�nyeket.
int main() {
    Cuboid cuboid;
    set_size(&cuboid, 5, 3, 2);
    printf("T�rfogat: %.2f\n", calc_volume(cuboid));
    printf("Felsz�n: %.2f\n", calc_surface(cuboid));
    printf("N�gyzet alak� lap: %d\n", check_square_side(cuboid));
    return 0;
}
