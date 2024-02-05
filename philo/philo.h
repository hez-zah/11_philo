#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>


// limit
# define INT_MAX 2147483647

// bool
# define TRUE 1
# define FALSE 0

//colors
# define RED "\033[0;31m"
# define PURPLE "\e[0;38;5;199m"
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

//Error messages
# define  NUM_ARGS "ERROR: The number of argments must be 4 or 5"
# define ARG1 "ERROR: There is a mistake in formt of argments"


//Routines messages
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

typedef struct s_info{
	int						num_philo;
	long					time_die;
	long					time_eat;
	long					time_sleep;
	int						number_eat;
	struct s_philo			**stack;
	pthread_mutex_t			*frk;
	pthread_mutex_t			basic_key;
}t_info;

typedef struct s_philo{
	pthread_mutex_t			left;
	pthread_mutex_t			right;
	pthread_t				philo;
	int						nbr_eat;
	int						numbre;
	int						numbre_next;
	long					t0;
	long					last_eat;
	struct s_info			*cont;
	struct s_philo			*next;
}t_philo;

//init_philo
t_info	*init_mutx_philo(t_info *cont);
//main
int		main(int ac, char **argv);
//philo_util
void	ft_free(t_info *cont);
void	exec_action(long ms);
void	print_action(char *action, t_philo *lst, char *color);
long	get_day(void);
int		error(int index);
long	get_day(void);
//routine
void	*routine(void *ptr);
int		simulation_start(t_info *cont);
int		all_eat(t_philo **stack);
//utils
t_info	*check_content(char **argv, t_info *cont);
int		ft_atoi(char	*str);
t_philo	*ft_lstnew(int nb, int nb_mext);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
#endif
