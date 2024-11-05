#include "philosophers.h"

int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr,
void *(*start_routine)(void *arg), void *restrict arg);
// pthread_create(pthread_t *thread, phtread_attr_t *attr, void *start_routine(void *arg, void *arg))
// attr : change les attributs (priorités) par défaut du thread  NULL
// start_routine : fonction par laquelle le thread commence son exécution
// arg : argument de la fonction start_routine 
// return 0 for sucess, else error code
// le thread nouvellement créé possède désormais un id

// int pthread_join(pthread_t thread, void **retval);
// retval : return value de start_routine, on peut spécifier NULL si pas besoin

// void    *f1(void *i)
// {  
//     printf("\033[94m Philosophe numéro %d\n\033[0m", (int)i);
//     pthread_exit(NULL);
// }

void    *f1(void *i)
{  
    printf(BBLU "Philosophe numéro " UMAG"%d\n" reset, (int)i);
    pthread_exit(NULL);
}

int main()
{
    pthread_t   philos[3]; //bus error avec *t1, *t2

    int     i;

    i = 0;
    printf("'I am the main thread.\nHere are my bitches:'\n");
    while (i < 3)
    {
        pthread_create(&philos[i], NULL, f1, (void *)i);
        pthread_join(philos[i], NULL);
        i++;
    }
    return (0);
}