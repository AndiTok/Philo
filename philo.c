/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:22:04 by atok              #+#    #+#             */
/*   Updated: 2023/06/29 14:28:26 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 5 || ac == 6)
	{
		if (checkparam(av) == 0)
			return (1);
		initialize_var(&info, ac, av);
		initialize_philo(&info);
		launch(&info);
		ft_exit(&info);
	}
	else if (ac < 5)
		printf("less than 5 param\n");
	else if (ac > 6)
		printf("more than 6 param\n");
	return (1);
}
