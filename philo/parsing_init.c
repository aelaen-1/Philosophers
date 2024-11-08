/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:57:17 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/08 13:57:29 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void     error_msg(void)
{
    printf("Invalid input. Args must be strictly positive");
    // printf("Invalid input : nb_of_philos time_to_die time_to_eat
        //     time_to_sleep nb_of_meal");
}

static void    fill_input(char *s, char **av, args input)
{
    if (s == av[1])
        input.nb_of_philos = ft_strtoll(av[1]);
    else if (s == av[2])
        input.time_to_die = ft_strtoll(av[2]);
    else if (s == av[3])
        input.time_to_eat = ft_strtoll(av[3]);
    else if (s == av[4])
        input.time_to_sleep = ft_strtoll(av[4]);
    else if (s == av[5])
        input.nb_of_meals = ft_strtoll(av[5]);
}

int     init_input(int ac, char **av)
{
    int     i;
    args input;

    input.nb_of_philos = 0;
    input.time_to_die = 0;
    input.time_to_eat = 0;
    input.time_to_sleep = 0;
    input.nb_of_meals = 0;
    i = 1;
    if (ac != 6)
    {
        write(1, "5 arguments needed\n", 19);
        return (1);
    }
    while(av[i])
    {
        if (ft_strtoll(av[i]) > 0)
            fill_input(av[i], av, input);
        else
        {
            error_msg();
            return (1);
        }
        i++;
    }
    return (0);
}
