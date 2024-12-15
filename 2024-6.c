/* and the sixth day :3 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#define uchar unsigned char

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

void get_pos(char *data, uint size, uint *x, uint *y) {
    int i=0;
    while(data[i] != '^') i++;
    *x = i%size;
    *y = i/size;
}

void move(char *data, uint size, uint x, uint y) {
    uchar dir = 0;
    /*
    as for dir:
      0
      |
    3-+-1
      |
      2
    */
    // size++; /* uhh because of the fucking \n at the end of every line I guess */

    // /* such an ugly way to do it :3 */

    while(1) {
        data[x + y*size] = 'x';
        uint goal_x, goal_y;
        goal_x = x + (dir == 1) - (dir == 3);
        goal_y = y + (dir == 2) - (dir == 0);

        if(goal_x <  0     || 
          goal_x  >= size || 
          goal_y  <  0     || 
          goal_y  >= size ) 
            return; /* reached edge of the map */


        if(data[goal_x + goal_y*size] == '#') {
            dir = (dir+1) % 4;
        } else {
            x = goal_x;
            y = goal_y;
        }
    }

}

uint count_shit_one(char *data) {
    uint count=0;
    while(*data != '\0') {
        if(*data == 'x') 
            count++;
        data++;
    }
    return count;
}


bool loops(char *data, uint size, uint x, uint y) {
    uchar dir = 0;
    /*
    as for dir:
      0
      |
    3-+-1
      |
      2
    */
    // size++; /* uhh because of the fucking \n at the end of every line I guess */

    // /* such an ugly way to do it :3 */

    for(int time=0; time<size*size; time++) { /* wow this is a truely fucking awful way to check it */
        uint goal_x, goal_y;
        goal_x = x + (dir == 1) - (dir == 3);
        goal_y = y + (dir == 2) - (dir == 0);

        if(goal_x <  0     || 
          goal_x  >= size || 
          goal_y  <  0     || 
          goal_y  >= size ) 
            return false; /* reached edge of the map */


        if(data[goal_x + goal_y*size] == '#') {
            dir = (dir+1) % 4;
        } else {
            x = goal_x;
            y = goal_y;
        }
    }


    return true;

}


int count_shit_two(char *data, uint size, uint x, uint y) {
    int counter=0;
    for(int i=0; i<size*size; i++) {
        if(data[i] == '#') continue; /* if it's already an obstacle, we know it doesn't loop */

        data[i] = '#';
        counter += loops(data, size, x, y);
        data[i] = '.';
    }
    return counter;
}




int main() {
    char data[100000];
    load_file("2024-6-input", data);

    uint size = get_size(data);
    uint x, y;
    get_pos(data, size, &x, &y);

    uint answer_two = count_shit_two(data, size, x, y);


    move(data, size, x, y);
    for(int i=0; i<size; i++) {
        printf("%.*s\n", size, data+i*size);
    }

    uint answer_one = count_shit_one(data);
    printf("part I: %d\n", answer_one);

    printf("part II: %d\n", answer_two);



    return 0;
}