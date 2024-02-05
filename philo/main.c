#include "philo.h"

int	main(int ac, char **argv)
{
	pthread_mutex_t	mutex_p;
	t_info			*table;

	if (ac != 5 && ac != 6)
		return (error(1));
	table = (t_info *)malloc(sizeof(t_info));
	if (!table)
		return (error(0));
	table = check_content(argv, table);
	if (!table)
		return (0);
	table = init_mutx_philo(table);
	if (!table)
		return (0);
	if (pthread_mutex_init(&mutex_p, NULL))
		return (error(2), 0);
	table->basic_key = mutex_p;
	simulation_start(table);
	ft_free(table);
	return (0);
}
