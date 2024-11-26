#include "include/philo.h"

void	philo_think(struct Philosopher *philo)
{
	philo->state = THINKING;
	write_log(philo, "is thinking");
	ft_sleep_ms(get_remaining_lifetime(philo) / 2);
}

void	philo_sleep(struct Philosopher *philo)
{
	philo->state = SLEEPING;
	write_log(philo, "is sleeping");
	ft_sleep_ms(philo->diner_infos->time_to_sleep);
}

void	philo_eat(struct Philosopher *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	write_log(philo, "has taken a fork");
	if (philo->diner_infos->nb_of_philos == 1)
	{
		ft_sleep_ms(philo->diner_infos->time_to_die);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		return ;
	}
	pthread_mutex_lock(&philo->right_fork->mutex);
	write_log(philo, "has taken a fork");
	philo->state = EATING;
	write_log(philo, "is eating");
	pthread_mutex_lock(&philo->diner_infos->eating_change_mutex);
	philo->last_eaten = time_now_ms(philo->diner_infos->program_start);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->diner_infos->eating_change_mutex);
	ft_sleep_ms(philo->diner_infos->time_to_eat);
	philo->state = VOID;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
}
