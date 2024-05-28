/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:16:45 by atok              #+#    #+#             */
/*   Updated: 2023/07/05 21:38:27 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = data;
	if ((philo->id + 1) % 2 == 0)
		usleep(25);
	if (philo->info->nop == 1)
	{
		one(philo);
		return (NULL);
	}
/* 	// Increment the ready thread count and wait for others to reach the synchronization point
	pthread_mutex_lock(&philo->info->barrier);
	philo->info->j++;
	pthread_mutex_unlock(&philo->info->barrier);
	while (philo->info->j < philo->info->nop) 
	{
		usleep(1);
	} */
	while (1)
	{
		ft_fork(philo);
		ft_eat(philo);
		pthread_mutex_lock(&philo->info->lock);
		if (philo->eaten == philo->info->noe || philo->info->die == 1)
		{	
			pthread_mutex_unlock(&philo->info->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->info->lock);
		ft_sleep(philo);
		usleep(25);
	}
	return (NULL);
}

void	condi(t_info *info, int i)
{
	i = 0;
	while (i < info->nop)
	{
		pthread_mutex_lock(&info->lock);
		if (timestamp(info) - info->philo[i].last_eat >= info->t2d)
		{
			pthread_mutex_lock(&info->print);
			info->die = 1;
			pthread_mutex_unlock(&info->print);
			printf("%lld ", timestamp(info->philo->info));
			printf("%d died\n", info->philo->id + 1);
			pthread_mutex_unlock(&info->lock);
			break ;
		}
		if (info->philo[i].eaten == info->noe)
		{
			info->done = 1;
			pthread_mutex_unlock(&info->lock);
			break ;
		}
		i++;
		pthread_mutex_unlock(&info->lock);
	}
	return ;
}

void	check(t_info *info)
{
	int	i;

	i = 0;
	while (info->nop != 1)
	{
		if (info->die == 1 || info->done == 1)
			break ;
		condi(info, i);
		usleep(25);
	}
	return ;
}

void	launch(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nop)
	{
		usleep(25);
		pthread_create(&info->philo[i].tid, NULL, routine, &info->philo[i]);
		i++;
	}
	check(info);
	i = 0;
	while (i < info->nop)
	{
		pthread_join(info->philo[i].tid, NULL);
		i++;
	}
	return ;
}
	//printf("parent thread has ended\n");
