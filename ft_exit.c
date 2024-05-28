/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:37:35 by atok              #+#    #+#             */
/*   Updated: 2023/06/29 13:55:51 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nop)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	free(info->fork);
	free(info->philo);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->lock);
}
