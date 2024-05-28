/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:53:57 by atok              #+#    #+#             */
/*   Updated: 2023/06/24 16:53:57 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->id]);
	status(philo, 'f');
	pthread_mutex_lock(&philo->info->fork[(philo->id + 1) % philo->info->nop]);
	status(philo, 'f');
}

void	ft_eat(t_philo *philo)
{
	status(philo, 'e');
	ft_msleep(philo->info->t2e);
	pthread_mutex_lock(&philo->info->lock);
	philo->eaten += 1;
	philo->last_eat = timestamp(philo->info);
	pthread_mutex_unlock(&philo->info->lock);
	pthread_mutex_unlock(&philo->info->fork[philo->id]);
	pthread_mutex_unlock(&philo->info->fork[(philo->id + 1)
		% philo->info->nop]);
}

void	ft_sleep(t_philo *philo)
{
	status(philo, 's');
	ft_msleep(philo->info->t2s);
	status(philo, 't');
}
