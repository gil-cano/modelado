/* Packing Polygons.
 	2013.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n_vertices;
	int i;
	int px, py;
	float radius;

	/* read number of vertices in the polygon.
	   input case with 0 vertices mark the end of the input. 
	 */
	while(scanf("%d", &n_vertices) != EOF && n_vertices > 0){
		/* read polygon */
		for (i = 0; i < n_vertices; i++){
			scanf("%d %d\n", &px, &py);
		}

		/* read radius */
		scanf("%f", &radius);

		printf("The polygon can be packed in the circle.\n");

		printf("There is no way of packing that polygon.\n");
	}

	return 0;
}