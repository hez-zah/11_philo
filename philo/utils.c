#include"philo.h"

static	int	ft_atoi_aid(char *str, int *i, int *nb)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			return (-1);
		*nb = *nb * 10 + str[*i] - '0';
		(*i)++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		sing;
	int		i;
	int		nb;

	nb = 0;
	sing = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = sing * -1;
		i++;
	}
	if (!str[i])
		return (-1);
	if ((ft_atoi_aid(str, &i, &nb) == -1))
		return (-1);
	if ((nb * sing) < 1 || (nb * sing) > 2147483647)
		return (-1);
	return (nb * sing);
}

t_info	*check_content(char **argv, t_info *tmp)
{
	tmp->time_die = ft_atoi(argv[2]);
	tmp->time_eat = ft_atoi(argv[3]);
	tmp->time_sleep = ft_atoi(argv[4]);
	tmp->number_eat = -1;
	if (tmp->num_philo == -1 || tmp->time_die == -1
		|| tmp->time_eat == -1 || tmp->time_sleep == -1)
		return (error(1), (NULL));
	if (argv[5])
	{
		tmp->number_eat = ft_atoi(argv[5]);
		if (tmp->number_eat == -1)
			return (error(1), (NULL));
	}
	tmp->num_philo = ft_atoi(argv[1]);
	if (tmp->num_philo == -1)
		return (error(1), (NULL));
	return (tmp);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*new_fin;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new_fin = *alst;
	while (new_fin)
	{
		if (!new_fin->next)
			break ;
		new_fin = new_fin->next;
	}
	new_fin->next = new;
}

t_philo	*ft_lstnew(int nb, int nb_next)
{
	t_philo	*n_node;

	n_node = (t_philo *)malloc(sizeof(t_philo));
	if (!n_node)
		return (NULL);
	n_node->numbre = nb;
	n_node->numbre_next = nb_next;
	n_node->next = NULL;
	return (n_node);
}
