#include <stdio.h>

// Definiáljuk a Cuboid struktúrát, amely tartalmazza a téglatest 3 élének a hosszát.
typedef struct {
    float length;
    float width;
    float height;
} Cuboid;

// Definiáljuk a set_size függvényt, amellyel ellenõrzött módon be lehet állítani egyszerre a 3 él hosszát.
void set_size(Cuboid* cuboid, float length, float width, float height) {
    cuboid->length = length;
    cuboid->width = width;
    cuboid->height = height;
}

// Definiáljuk a calc_volume függvényt, amelyik kiszámítja a téglatest térfogatát.
float calc_volume(Cuboid cuboid) {
    return cuboid.length * cuboid.width * cuboid.height;
}

// Definiáljuk a calc_surface függvényt, amelyik kiszámítja a téglatest felszínét.
float calc_surface(Cuboid cuboid) {
    return 2 * (cuboid.length * cuboid.width + cuboid.length * cuboid.height + cuboid.width * cuboid.height);
}

// Definiáljuk a check_square_side függvényt, amelyik a téglalapot megvizsgálja, hogy van-e négyzet alakú lapja.
int check_square_side(Cuboid cuboid) {
    if (cuboid.length == cuboid.width || cuboid.length == cuboid.height || cuboid.width == cuboid.height) {
        return 1;
    }
    return 0;
}

// Teszteljük a függvényeket.
int main() {
    Cuboid cuboid;
    set_size(&cuboid, 5, 3, 2);
    printf("Térfogat: %.2f\n", calc_volume(cuboid));
    printf("Felszín: %.2f\n", calc_surface(cuboid));
    printf("Négyzet alakú lap: %d\n", check_square_side(cuboid));
    return 0;
}
