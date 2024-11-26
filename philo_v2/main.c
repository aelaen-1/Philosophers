/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:56:56 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/26 22:16:10 by aelaen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	struct Philosopher	philos[200];
	struct Fork			forks[200];
	struct Diner		diner;

	if (error_input(ac, av))
		return (0);
	if (!init_input(ac, av, &diner))
		return (0);
	if (!init_philos_and_forks(philos, forks, &diner))
		return (0);
	if (!pthread_create_join(philos, forks, &diner))
		return (0);
	clean_mutex(forks, &diner);
	return (0);
}
