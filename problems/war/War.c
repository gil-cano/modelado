/* War.
      2013.
*/

#include <stdio.h>

typedef struct tree_node{
    /* data */
    int item;
    struct tree_node *parent;
} node;

node *tree = NULL;

int main(int argc, char const *argv[])
{
    /* the number of people */
    int n;

    /* the code of operation
       1 - setFriends
       2 - setEnemies
       3 - areFiends
       4 - areEnemies  
    */
    int c;

    /* integers in the range [0, n), 
       identifying two (different) people
    */
    int x, y;

    scanf("%d", &n);

    while(scanf("%d %d %d\n", &c, &x, &y) != EOF) {
        if (!c && !x && !y) {
            return 0;
        }

        switch(c){
            case 1:
                printf("%d %d %d\n", c, x, y);
            case 2:
                printf("%d %d %d\n", c, x, y);
            case 3:
                printf("%d %d %d\n", c, x, y);
            case 4:
                printf("%d %d %d\n", c, x, y);
        }
      }
      return 0;
}