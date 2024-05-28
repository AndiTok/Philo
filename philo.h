/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:22:47 by atok              #+#    #+#             */
/*   Updated: 2023/07/04 03:24:02 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	int				sleep;
	int				think;
	int				eaten;
	long long		last_eat;
	pthread_t		tid;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	long long		start;
	int				args;
	int				nop;
	int				t2d;
	int				t2e;
	int				t2s;
	int				noe;
	int				die;
	int				done;
	int				j;	//
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_mutex_t	barrier; //
}	t_info;

int			ft_atoi(const char *str);
int			checkparam(char **av);
void		initialize_var(t_info *info, int ac, char **av);
void		initialize_philo(t_info *info);
void		launch(t_info *info);
void		check(t_info *info);
void		condi(t_info *info, int i);
void		ft_msleep(long long input);
void		*routine(void *data);
void		ft_fork(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
long long	timestamp(t_info *info);
void		status(t_philo *philo, int ch);
void		ft_exit(t_info *info);
void		one(t_philo *philo);
#endif