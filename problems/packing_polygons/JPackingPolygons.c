
/**
 * @file PackingPolygons.c
 *
 * @author José Galaviz <jgc@fciencias.unam.mx>
 * @version 1.0
 * \date 31/Aug/2013 - 18:31
 *
 * Facultad de Ciencias,
 * Universidad Nacional Autónoma de México, México.
 *
 * @section LICENSE
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Programa para resolver el reto 10005 del volumen 100 de los volúmenes de
 * problemas de concurso de ACM: Packing Polygons.
 * http://uva.onlinejudge.org/external/100/10005.pdf
 *
 * 12280374 	10005 	Packing polygons 	Accepted 	ANSI C 	0.012
 * 2013-09-01 06:07:42
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * Estructura para manipular puntos 2D
 */
typedef struct {
   double            x;
   double            y;
} Punto;

/**
 * Estructura para manipular círculos
 */
typedef struct {
   Punto             centro;
   double            radio;
} Circulo;

/**
 * \brief Calcula la distancia entre dos puntos.
 *
 * Dados dos puntos en el plano euclidiano, calcula la distancia
 * convencional entre ellos.
 *
 * @param[in] a es uno de los puntos entre los que se calculará la
 * distancia.
 * @param[in] b es el otro punto.
 * @return Regresa un número real no negativo con la distancia euclidiana
 * entre los puntos dados.
 * \post el resultado es no negativo.
 */
double
distancia(Punto * a, Punto * b) {
   double            sqx = (a->x - b->x) * (a->x - b->x);
   double            sqy = (a->y - b->y) * (a->y - b->y);
   return sqrt(sqx + sqy);
}

/**
 * \brief Centro y radio de un círculo dados tres puntos de él.
 *
 * Calcula el centro y el radio del círculo determinado por tres puntos en
 * el plano.
 *
 * @param[in] a es el primer punto sobre el círculo.
 * @param[in] b es el segundo punto sobre el círculo.
 * @param[in] c es el tercer punto sobre el círculo.
 * @return una estructura Circulo con el sentro y el radio resultantes.
 * \pre Los puntos deben estar sobre el círculo.
 * \post el radio del círculo es no negativo
 */
Circulo          *
Circulo3Puntos(Punto * a, Punto * b, Punto * c) {
   Circulo          *cir = (Circulo *) calloc(1, sizeof(Circulo));
   double            bx = a->x;
   double            by = a->y;
   double            cx = b->x;
   double            cy = b->y;
   double            dx = c->x;
   double            dy = c->y;
   double            temp = cx * cx + cy * cy;
   double            bc = (bx * bx + by * by - temp) / 2.0;
   double            cd = (temp - dx * dx - dy * dy) / 2.0;
   double            det = (bx - cx) * (cy - dy) - (cx - dx) * (by - cy);
   if ((det < 1.0e-6) && ((det > -1.0e-6))) {
      cir->centro.x = cir->centro.y = 1.0;
      return cir;
   }
   det = 1 / det;
   cir->centro.x = (bc * (cy - dy) - cd * (by - cy)) * det;
   cir->centro.y = ((bx - cx) * cd - (cx - dx) * bc) * det;
   cx = cir->centro.x;
   cy = cir->centro.y;
   cir->radio = sqrt((cx - bx) * (cx - bx) + (cy - by) * (cy - by));
   return cir;
}

/**
 * \brief Calcula el círculo más pequeño en el que una colección de puntos
 * puede estar contenida.
 *
 * Dado un conjunto de puntos en el plano euclidiano, determina el radio
 * del círculo más pequeño posible que los contiene.
 * @param n es el número de puntos que se desea queden contenidos en el
 * círculo.
 * @param p es el conjunto de puntos.
 * @param m es el número de puntos que se desea tener en la frontera.
 * @param b es el conjunto de puntos en la frontera.
 */
Circulo          *
CirculoMinimo(int n, Punto * p, int m, Punto * b) {
   int               i;
   Circulo          *sec = (Circulo *) calloc(1, sizeof(Circulo));
   sec->centro.x = -1.0;
   sec->centro.y = -1.0;
   sec->radio = 0.0;

   if (m == 1) {
      sec->centro = b[0];
      sec->radio = 0;
   }
   else if (m == 2) {
      sec->centro.x = (b[0].x + b[1].x) / 2.0;
      sec->centro.y = (b[0].y + b[1].y) / 2.0;
      sec->radio = distancia(&b[0], &sec->centro);
   }
   else if (m == 3) {
      sec = Circulo3Puntos(&b[0], &b[1], &b[2]);
      return sec;
   }

   for (i = 0; i < n; i++) {
      if (distancia(&p[i], &sec->centro) > sec->radio) {
         b[m] = p[i];
         sec = CirculoMinimo(i, p, m + 1, b);
      }
   }
   return sec;
}

/**
 * \brief Captura del número de vértices.
 * @return Un entero no negativo con el número de vértices del polígono.
 */
int
numVertices() {
   int               nv;
   scanf("%d\n", &nv);
   return nv;
}

/**
 * \brief Captura las coordenadas de los vértices.
 * @param n es el nero de vértices a capturar.
 * @return Un apuntador al arreglo de vértices.
 */
Punto            *
leeVertices(int n) {
   int               i, xcoord, ycoord;
   Punto            *v = (Punto *) calloc(n, sizeof(Punto));

   for (i = 0; i < n; i++) {
      scanf("%d %d\n", &xcoord, &ycoord);
      v[i].x = (double) xcoord;
      v[i].y = (double) ycoord;
   }
   return v;
}

/**
 * \brief Programa principal
 * Recibe de la entrada estándar los datos.
 */
int
main() {
   int               nvert;
   Punto            *vertices;
   Punto            *noinclu;
   Circulo          *SEC;
   double            radio;

   while ((nvert = numVertices())) {
      vertices = leeVertices(nvert);
      scanf("%lf\n", &radio);
#ifdef DEBUG
      int               i;
      fprintf(stderr, "Número de vértices: %d\n", nvert);
      for (i = 0; i < nvert; i++) {
         fprintf(stderr, "%f %f\n", vertices[i].x, vertices[i].y);
      }
      fprintf(stderr, "%f\n", radio);
#endif
      noinclu = (Punto *) calloc(nvert, sizeof(Punto));
      SEC = CirculoMinimo(nvert, vertices, 0, noinclu);
#ifdef DEBUG
      fprintf(stderr, "Círculo mínimo. Centro: (%f, %f)\tRadio: %f\n",
              SEC->centro.x, SEC->centro.y, SEC->radio);
#endif
      if (radio < SEC->radio)
         printf("There is no way of packing that polygon.\n");
      else
         printf("The polygon can be packed in the circle.\n");
   }
   return 0;
}                               /* PackingPolygons.c ends here */
