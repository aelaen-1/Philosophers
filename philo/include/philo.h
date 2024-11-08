/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:57:15 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/08 12:57:16 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/types.h> 
# include <sys/time.h> // timeofday
# include <stdlib.h>
# include <string.h> // memset
# include <stdio.h>

typedef struct  args{ // juste struct ??
    int     nb_of_philos;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     nb_of_meals;
}   args;

int     init_input(int ac, char **av);
long long   ft_strtoll(char *s);


#endif
