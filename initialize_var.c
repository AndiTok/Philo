/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:01:33 by atok              #+#    #+#             */
/*   Updated: 2023/07/04 03:56:06 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_var(t_info *info, int ac, char **av)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	info->start = start.tv_sec * 1000 + start.tv_usec / 1000;
	info->args = ac;
	info->nop = ft_atoi(av[1]);
	info->t2d = ft_atoi(av[2]);
	info->t2e = ft_atoi(av[3]);
	info->t2s = ft_atoi(av[4]);
	info->noe = -1;
	info->die = 0;
	info->done = 0;
	info->j = 0;
	if (ac == 6)
		info->noe = ft_atoi(av[5]);
}
	//printf("time - %lld\n",info->start);