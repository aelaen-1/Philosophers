#include "include/philo.h"

            // END BECAUSE EVERYONE ATE ENOUGH
int everyone_ate(struct Philosopher *philos)
{
    int     i;
    int     all_ate;

    i = 0;
    all_ate = 0;
    if (philos->diner_infos->nb_of_meals == NO_MEAL_LIMIT)
        return (0);
    while (i < philos->diner_infos->nb_of_philos)
    {
        pthread_mutex_lock(&philos->diner_infos->eating_change_mutex);
        if (philos[i].meal_counter == philos->diner_infos->nb_of_meals)
            all_ate++;
        pthread_mutex_unlock(&philos->diner_infos->eating_change_mutex);
        i++;
    }
    if (all_ate == philos->diner_infos->nb_of_philos)
    {
        pthread_mutex_lock(&philos->diner_infos->sb_is_dead_mutex);
        philos->diner_infos->sb_is_dead = 1;
        pthread_mutex_unlock(&philos->diner_infos->sb_is_dead_mutex);
        return (1);
    }
    return (0);
}
            // END BECAUSE SOMEONE DIED 
int is_dead(struct Philosopher *philo)
{
    pthread_mutex_lock(&philo->diner_infos->eating_change_mutex);
    if ((time_now_ms(philo->diner_infos->program_start) - philo->last_eaten >= philo->diner_infos->time_to_die) && (philo->state != EATING))
        return(pthread_mutex_unlock(&philo->diner_infos->eating_change_mutex), 1);
    return (pthread_mutex_unlock(&philo->diner_infos->eating_change_mutex), 0);
}

int check_if_dead(struct Philosopher *philos)
{
    int     i;

    i = 0;
    while(i < philos->diner_infos->nb_of_philos)
    {
        if (is_dead(&philos[i]))
        {
            write_log(&philos[i], RED "died" reset);
            pthread_mutex_lock(&philos->diner_infos->sb_is_dead_mutex);
            philos->diner_infos->sb_is_dead = 1;
            pthread_mutex_unlock(&philos->diner_infos->sb_is_dead_mutex);
            return (1);
        }
        i++;
    }
    return (0);
}

            // LISTENER TO SB_IS_DEAD VARIABLE
int		sb_is_dead_listener(struct Philosopher *philo)
{
	pthread_mutex_lock(&philo->diner_infos->sb_is_dead_mutex);
	if (philo->diner_infos->sb_is_dead == 1)
		return (pthread_mutex_unlock(&philo->diner_infos->sb_is_dead_mutex), 1);
	pthread_mutex_unlock(&philo->diner_infos->sb_is_dead_mutex);
	return (0);
}
