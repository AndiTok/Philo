/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:10:13 by atok              #+#    #+#             */
/*   Updated: 2023/06/23 17:10:13 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msleep(long long input)
{
	struct timeval	time1;
	struct timeval	time2;
	long long		base;
	long long		now;
	
	gettimeofday(&time1, NULL);
	base = time1.tv_sec * 1000 + time1.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&time2, NULL);
		now = time2.tv_sec * 1000 + time2.tv_usec / 1000;
		if (now >= input + base)
			break ;
		usleep(25);
	}
}
