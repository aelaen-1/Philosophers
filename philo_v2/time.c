#include "include/philo.h"

TimeMs  time_now_ms(TimeMs start_time)
{
    struct timeval  tv;
    long long   time_in_ms;

    gettimeofday(&tv, NULL);
    time_in_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time_in_ms - start_time);
}

void    ft_sleep_ms(TimeMs duration)
{
    #if USE_USLEEP 
    usleep(duration * 1000);
    #else
    TimeMs start = time_now_ms(0);
    while(time_now_ms(0) - start < duration)
        usleep(500);
    #endif
}

TimeMs  get_remaining_lifetime(struct Philosopher *p)
{
    TimeMs  time_since_last_meal;

    time_since_last_meal = time_now_ms(p->diner_infos->program_start) - p->last_eaten;
    return (p->diner_infos->time_to_die - time_since_last_meal);
}