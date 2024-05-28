/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:03:29 by atok              #+#    #+#             */
/*   Updated: 2023/07/05 23:06:48 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_philo(t_info *info)
{	
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->nop);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nop);
	while (i < info->nop)
	{
		info->philo[i].id = i;
		info->philo[i].eat = 0;
		info->philo[i].sleep = 0;
		info->philo[i].think = 0;
		info->philo[i].eaten = 0;
		info->philo[i].last_eat = 0;
		info->philo[i].info = info;
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->lock, NULL);
	//pthread_mutex_init(&info->barrier, NULL);
}
