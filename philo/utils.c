/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:37:05 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/08 13:37:09 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"


long long   ft_strtoll(char *s)
{
    if (!s)
        return (0);
    long long     res;
    int     sign;
    int     i;

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