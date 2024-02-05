#include "philo.h"

int	error(int indx)
{
	if (indx == 0)
		printf(RED"error ---> malloc\n");
	else if (indx == 1)
		printf(RED"error ---> arguments\n");
	else if (indx == 2)
		printf(RED"error ---> mutex\n");
	else if (indx == 3)
		printf(RED"error ---> thread\n");
	return (0);
}

long	get_day(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_action(char *action, t_philo *lst, char *color)
{
	pthread_mutex_lock(&lst->cont->basic_key);
	printf("%s%-10ld %-3d %-30s\n", color, get_day() - lst->t0, lst->numbre + 1, action);
	pthread_mutex_unlock(&lst->cont->basic_key);
}

void	exec_action(long add)
{
	long	fin;

	fin = get_day() + add;
	while (get_day() < fin)
		usleep(50);
}

void	ft_free(t_info *tmp)
{
	t_philo	*lst;
	int		i;

	i = 0;
	while (++i < tmp->num_philo)
		pthread_mutex_destroy(&tmp->frk[i]);
	pthread_mutex_destroy(&tmp->basic_key);
	lst = *tmp->stack;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	free(tmp->stack);
	free(tmp->frk);
	free(tmp);
}
