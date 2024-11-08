/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:56:56 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/08 12:56:58 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

//number_of_philosophers time_to_die time_to_eat time_to_sleep [nb of times each philo must eat]


// doesnt work
static void *action(void *i)
{
    int     n;

    n = *((int *)i);
    printf ("Je suis le philosophe %d\n", n);
}

int main (int ac, char **av)
{
    int     err;
    pthread_t   philo[3];
    int     i;
    
    i = 0;
    err = init_input(ac, av);
    if (err)
        return (0);
    while (i < 3)
    {
        pthread_create(&philo[i], NULL, action, (void *)i);
        pthread_join(philo[i], NULL);
        i++;
    }
    return (0);
}