/* War.
      2013.
*/

#include <stdio.h>

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
        
        printf("%d %d %d\n", c, x, y);
      }
      return 0;
}