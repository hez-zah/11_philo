#include "philo.h"

t_info	*init_mutx_philo(t_info *cont)
{
	t_philo	*lst;
	int		i;

	cont->stack = (t_philo **)malloc(sizeof(t_philo *));
	cont->frk = malloc(sizeof(pthread_mutex_t) * cont->num_philo);
	if (!cont->frk || !cont->stack)
		return (error(0), NULL);
	*cont->stack = NULL;
	i = -1;
	while (++i < cont->num_philo)
		if (pthread_mutex_init(&cont->frk[i], NULL))
			return ((error(2)), (NULL));
	i = -1;
	while (++i < cont->num_philo)
	{
		if (i == cont->num_philo - 1)
			lst = ft_lstnew(i, 0);
		else
			lst = ft_lstnew(i, i + 1);
		if (!lst)
			return (error(0), ft_free(cont), NULL);
		lst->nbr_eat = cont->number_eat;
		ft_lstadd_back(cont->stack, lst);
	}
	return (cont);
}
