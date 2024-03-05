#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    // TODO
    thread_arg_t *p = (thread_arg_t*) p_arg;
    if (p->id == 0){ // thread 1
        for (unsigned int i = 0; i < p->m->nrows/2; i++)  {
            for (unsigned int j = 0; j < p->n->ncols; j++) {
                TElement sum = (TElement)0;
                for (unsigned int k = 0; k < p->m->ncols; k++)
                    sum += p->m->data[i][k] * p->n->data[k][j];
                p->t->data[i][j] = sum;
            }
        }
    }
    else{ // thread 2
        for (unsigned int i = p->m->nrows/2; i < p->m->nrows; i++)  {
            for (unsigned int j = 0; j < p->n->ncols; j++) {
                TElement sum = (TElement)0;
                for (unsigned int k = 0; k < p->m->ncols; k++)
                    sum += p->m->data[i][k] * p->n->data[k][j];
                p->t->data[i][j] = sum;
            }
        }
    }
    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    thread_arg_t arg[2];
    arg[0].id = 0;
    arg[0].n = n;
    arg[0].m = m;
    arg[0].t = t;

    arg[1].id = 1;
    arg[1].n = n;
    arg[1].m = m;
    arg[1].t = t;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_main, &arg[0]);
    pthread_create(&t2, NULL, thread_main, &arg[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return t;
}
