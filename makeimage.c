#include <fcntl.h>
#include <stdio.h>
#define SIZE 500

int main() {
    int imagefd = open("image.ppm", O_CREAT | O_EXCL | O_WRONLY, 0644);
    char buffer[20];
    int r, g, b, c1, c2;
    
    sprintf(buffer, "P3 %d %d 255", SIZE, SIZE);
    write(imagefd, buffer, sizeof(buffer));
    
    for( c1 = 0; c1 < SIZE + 1; c1++) {
        for (c2 = 0; c2 < SIZE + 1; c2++) {
            r = SIZE % (c2 + c1 + 1);
            g = SIZE - r;
            b = (r * g) % SIZE;
            sprintf(buffer, "%d %d %d\n", r, g, b);
            write(imagefd, buffer, sizeof(buffer));
        }
    }
    
    return 0;
}