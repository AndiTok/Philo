/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:51:30 by atok              #+#    #+#             */
/*   Updated: 2023/07/04 03:56:03 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(t_info *info)
{
	struct timeval	current;
	long long		dif;

	gettimeofday(&current, NULL);
	dif = current.tv_sec * 1000 + current.tv_usec / 1000 - info->start;
	return (dif);
}
