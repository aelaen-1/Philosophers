/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:37:05 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/26 22:49:53 by aelaen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

long long	ft_strtoll(char *s)
{
	long long	res;
	int			sign;
	int			i;

	if (!s)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * sign);
}

static int    ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
} 

void    write_log(struct Philosopher *p, char *s)
{
    if (!pthread_mutex_lock(&p->diner_infos->log_mutex))
	{
		if (!sb_is_dead_listener(p))
        {
            if (ft_strcmp(s, "died"))
                printf(BHRED"%lld %d %s\n"reset, time_now_ms(p->diner_infos->program_start),
				    p->id, s);
            else if (ft_strcmp(s, "has taken a fork")) 
                printf(BHWHT"%lld %d %s\n"reset, time_now_ms(p->diner_infos->program_start),
				    p->id, s);
            else if (ft_strcmp(s, "is eating"))
                printf(BHYEL"%lld %d %s\n"reset, time_now_ms(p->diner_infos->program_start),
				    p->id, s);
            else if (ft_strcmp(s,"is thinking"))
                printf(BHGRN"%lld %d %s\n"reset, time_now_ms(p->diner_infos->program_start),
				    p->id, s);
            else if (ft_strcmp(s, "is sleeping"))
                printf(BHBLU"%lld %d %s\n"reset, time_now_ms(p->diner_infos->program_start),
				    p->id, s);
        }
		pthread_mutex_unlock(&p->diner_infos->log_mutex);
	}
}
void	clean_mutex(struct Fork *forks, struct Diner *diner)
{
	int	i;

	i = 0;
	while (i < diner->nb_of_philos)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&diner->eating_change_mutex);
	pthread_mutex_destroy(&diner->log_mutex);
	pthread_mutex_destroy(&diner->sb_is_dead_mutex);
}
