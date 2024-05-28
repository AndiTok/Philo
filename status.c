/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:08:51 by atok              #+#    #+#             */
/*   Updated: 2023/06/26 17:08:51 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status(t_philo *philo, int ch)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->die != 1)
	{
		printf("%lld ", timestamp(philo->info));
		if (ch == 'o')
			printf("%d has taken own fork\n", philo->id + 1);
		else if (ch == 'n')
			printf("%d has taken next fork\n", philo->id + 1);
		else if (ch == 'f')
			printf("%d has taken a fork\n", philo->id + 1);
		else if (ch == 'e')
			printf("%d is eating\n", philo->id + 1);
		else if (ch == 's')
			printf("%d is sleeping\n", philo->id + 1);
		else if (ch == 't')
			printf("%d is thinking\n", philo->id + 1);
	}
	pthread_mutex_unlock(&philo->info->print);
}

void	one(t_philo *philo)
{
	printf("%lld ", timestamp(philo->info));
	printf("%d has taken a fork\n", philo->id + 1);
	ft_msleep(philo->info->t2d);
	printf("%lld ", timestamp(philo->info));
	printf("%d died\n", philo->id + 1);
}
