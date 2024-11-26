#include "include/philo.h"

            // PHILOSOPHERS ROUTINE

void    *start_living(void *p)
{
    struct Philosopher *myself = (struct Philosopher *)p;

    if ((myself->id % 2) == 0)
    	ft_sleep_ms(myself->diner_infos->time_to_eat);
    while (!dead_or_all_eaten(myself))
    {
        philo_eat(myself);
        philo_sleep(myself);
        philo_think(myself);
    }
    return (0);
}

            // END TRACKER ROUTINE
void    *tracker_routine(void *p)
{
    struct Philosopher *philo;

    philo = (struct Philosopher *)p;
    while(1)
    {
        if (check_if_dead(philo) || everyone_ate(philo))
            break;
    }
    return (0);
}