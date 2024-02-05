#include "philo.h"

int	all_eat(t_philo **stack)
{
	t_philo	*lst;

	lst = *stack;
	while (lst)
	{
		if (lst->nbr_eat != 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	check_nbr_eat(t_philo *lst)
{
	if (lst->nbr_eat > 0)
		lst->nbr_eat--;
}

void	*checker(void *var)
{
	t_info	*info;
	t_philo	*lst;

	info = var;
	while (1)
	{
		if (all_eat(info->stack) == 1)
			return (NULL);
		lst = *info->stack;
		while (lst)
		{
			if ((get_day() - lst->last_eat) >= lst->cont->time_die)
			{
				print_action(DIED, lst, RED);
				pthread_mutex_lock(&lst->cont->basic_key);
				return (NULL);
			}
			lst = lst->next;
		}
	}
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*tmp;

	tmp = ptr;
	if (tmp->numbre % 2)
		exec_action(40);
	print_action(THINK, tmp, G_BLUE);
	while (1)
	{
		pthread_mutex_lock(&tmp->cont->frk[tmp->numbre]);
		print_action(FORK, tmp, PURPLE);
		pthread_mutex_lock(&tmp->cont->frk[tmp->numbre_next]);
		print_action(FORK, tmp, PURPLE);
		tmp->last_eat = get_day();
		print_action(EAT, tmp, GREEN);
		exec_action(tmp->cont->time_eat);
		pthread_mutex_unlock(&tmp->cont->frk[tmp->numbre]);
		pthread_mutex_unlock(&tmp->cont->frk[tmp->numbre_next]);
		check_nbr_eat(tmp);
		if (tmp->nbr_eat == 0)
			break ;
		print_action(SLEEP, tmp, BLUE);
		exec_action(tmp->cont->time_sleep);
		print_action(THINK, tmp, G_BLUE);
	}
	return (NULL);
}

int	simulation_start(t_info *cont)
{
	pthread_t	trd;
	t_philo		*lst;

	lst = *cont->stack;
	while (lst)
	{
		lst->cont = cont;
		lst->t0 = get_day();
		lst->last_eat = get_day();
		if (pthread_create(&lst->philo, NULL, routine, lst))
			return ((error(3)), (0));
		lst = lst->next;
	}
	if (pthread_create(&trd, NULL, checker, cont))
		return ((error(3)), (0));
	if (pthread_join(trd, NULL))
		return ((error(3)), (0));
	return (0);
}
