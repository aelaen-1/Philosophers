/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:57:15 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/23 12:44:21 by aelaen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/types.h> 
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "colors.h"
# define NO_MEAL_LIMIT -65
# define USE_USLEEP 0

typedef long long TimeMs;

enum State{
    EATING,
    SLEEPING,
    THINKING,
    VOID  
};

struct Diner{
        int     nb_of_philos;
        int     time_to_die;
        int     time_to_eat;
        int     time_to_sleep;
        int     nb_of_meals;
        TimeMs  program_start;
        int     sb_is_dead;
        pthread_mutex_t log_mutex;
	pthread_mutex_t	eating_change_mutex;
        pthread_mutex_t sb_is_dead_mutex;
};

struct  Philosopher{
    pthread_t thread;
    struct Diner *diner_infos;
    int     index;
    int     id;
    int     meal_counter;
    int     last_eaten;
    enum State      state;
    struct Fork   *left_fork;
    struct Fork   *right_fork;
};

struct  Fork{
    int     index;
    pthread_mutex_t mutex;
};


//              INIT : 
        /*   input_check.c  */
int     error_input(int ac, char **av);
        /*   set_the_table.c  */
int     init_input(int ac, char **av, struct Diner *diner);
int     init_philos_and_forks(struct Philosopher *philos, struct Fork *forks, struct Diner *diner);
int     pthread_create_join(struct Philosopher *philos, struct Fork *forks, struct Diner *diner);
void    clean_mutex(struct Fork *forks, struct Diner *diner);

//              PHILOS' LIVES EXECUTION
            /*      philo_life.c        */
void    *start_living(void *p);
void	philo_think(struct Philosopher  *philo);
void	philo_sleep(struct Philosopher  *philo);
void	philo_eat(struct Philosopher  *philo);

//              MONITORING
        /*    check_if_end.c    */
int     check_if_dead(struct Philosopher *philos);
int     everyone_ate(struct Philosopher *philos);
void    *tracker_routine(void *p);

//              UTILS
        /*     utils.c     */
long long   ft_strtoll(char *s);
int     min(int a, int b);
void    clean_mutex(struct Fork *forks, struct Diner *diner);
void    write_log(struct Philosopher *p, char *s);


//              TIME FUNCTIONS
        /*         time.c         */
void    ft_sleep_ms(TimeMs duration);
TimeMs  time_now_ms(TimeMs start_time);
TimeMs  get_remaining_lifetime(struct Philosopher *p);

// solve helgrind pbs

int     dead_or_all_eaten(struct Philosopher *philo);

#endif
