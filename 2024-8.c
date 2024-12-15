/* eight day ^>^ */
/* this one was *really* fun, I think my favourite so far
it wasn't that hard either?? I kinda did it in one go
without encountering any real problems */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define uchar unsigned char
#define ulong unsigned long



void load_file(char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("oof it didn't load %s\n", filename);
        return;
    }

    char c;
    while((c = getc(file)) != EOF)
        if(c != '\n') *buffer++ = c;
    buffer = '\0';
}

uint get_size(char *data) {
    uint size = 0;
    while(*data++ != '\0') size++;
    return (uint)sqrt((double)size);
}


void find_antinode(char type, uint size, char *map, bool *antinodes) {
    /* first, we look for all the antennae of this type */
    int i=0;
    int num_found = 0;
    int antennae[50]; /* this should be enough?? */
    for(int i=0; i<sizeof(antennae)/sizeof(*antennae); i++) antennae[i] = -1;
    while(map[i] != '\0') {
        if(map[i] == type)
            antennae[num_found++] = i;
        i++;
    }


    /* then, we calculate the antinodes */
    for(i=0; i<num_found; i++) {
        for(int j=i+1; j<num_found; j++) {
            int xi = antennae[i] % size;
            int yi = antennae[i] / size;
            int xj = antennae[j] % size;
            int yj = antennae[j] / size;

            int dx = xj - xi;
            int dy = yj - yi;

            if(xj + dx >= 0 && xj + dx < size
            && yj + dy >= 0 && yj + dy < size)
                antinodes[(xj + dx) + (yj + dy) * size] = true;

            if(xi - dx >= 0 && xi - dx < size
            && yi - dy >= 0 && yi - dy < size)
                antinodes[(xi - dx) + (yi - dy) * size] = true;


        }
    }


}



void find_all_antinodes(uint size, char *map, bool *antinodes) {
    for(char c='0'; c<='9'; c++) {
        find_antinode(c, size, map, antinodes);
    }
    for(char c='a'; c<='z'; c++) {
        find_antinode(c, size, map, antinodes);
    }
    for(char c='A'; c<='Z'; c++) {
        find_antinode(c, size, map, antinodes);
    }
}

void find_antinode_extended(char type, uint size, char *map, bool *antinodes) {
    /* first, we look for all the antennae of this type */
    int i=0;
    int num_found = 0;
    int antennae[50]; /* this should be enough?? */
    for(int i=0; i<sizeof(antennae)/sizeof(*antennae); i++) antennae[i] = -1;
    while(map[i] != '\0') {
        if(map[i] == type)
            antennae[num_found++] = i;
        i++;
    }


    /* then, we calculate the antinodes */
    for(i=0; i<num_found; i++) {
        for(int j=i+1; j<num_found; j++) {
            int xi = antennae[i] % size;
            int yi = antennae[i] / size;
            int xj = antennae[j] % size;
            int yj = antennae[j] / size;

            int dx = xj - xi;
            int dy = yj - yi;

            for(int k=0; xj + dx*k >= 0 && xj + dx*k < size
                      && yj + dy*k >= 0 && yj + dy*k < size; k++) {

                antinodes[(xj + dx*k) + (yj + dy*k) * size] = true;
            }

            for(int k=0; xi - dx*k >= 0 && xi - dx*k < size
                      && yi - dy*k >= 0 && yi - dy*k < size; k++) {

                antinodes[(xi - dx*k) + (yi - dy*k) * size] = true;
            }


        }
    }


}

void find_all_antinodes_extended(uint size, char *map, bool *antinodes) {
    for(char c='0'; c<='9'; c++) {
        find_antinode_extended(c, size, map, antinodes);
    }
    for(char c='a'; c<='z'; c++) {
        find_antinode_extended(c, size, map, antinodes);
    }
    for(char c='A'; c<='Z'; c++) {
        find_antinode_extended(c, size, map, antinodes);
    }
}




int count_shit(bool *antinodes, uint size) {
    uint counter=0;
    for(int i=0; i<size*size; i++) counter += antinodes[i];
    return counter;
}



int main() {
    char data[3000];
    bool antinodes[3000];
    for(int i=0; i<3000; i++) antinodes[i] = false;
    load_file("2024-8-input", data);

    uint size = get_size(data);
    find_all_antinodes(size, data, antinodes);

    uint answer_one = count_shit(antinodes, size);
    printf("answer I:  %u\n", answer_one);



    find_all_antinodes_extended(size, data, antinodes); 
    /* the places where it's already true are still 
    true so I can just use the same antinodes array */

    uint answer_two = count_shit(antinodes, size);
    printf("answer II: %u\n", answer_two);

    return 0;
}