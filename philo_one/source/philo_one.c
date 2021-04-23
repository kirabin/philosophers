#include "philo_one.h"

// NOTE:	POSIX thread in short - pthread
//			By the C language standart threads are not supported.

// NOTE:	All threads share data segment. Global and Static variables/

// LEARN:	PThread Functions
//			pthread_create(), creates thread.
//			pthread_join(), waits for thread or doesn't if it was terminated.
//			pthread_exit(thread)	terminates thread or all threads if NULL.

// LEARN:	What is mutex?


void	*function(void *arg)
{
	t_all			*all;
	t_philosopher	philosopher;

	all = (t_all *)arg;
	philosopher.id = all->philosopher.id;
	philosopher.thread_id = all->philosopher.thread_id;
	printf("%ld\tPhilosoppher %d is created\n", get_current_time(all), philosopher.id);
	eat_thread(all, philosopher);
	sleep_thread(all, philosopher);
	return (NULL);
}

void	start_threads(t_all *all)
{
	int		i;

	i = 0;
	printf("Before Thread\n");
	while (i < 3)
	{
		all->philosopher.id = i;
		pthread_create(&all->philosopher.thread_id, NULL, function, all);
		// pthread_join(all->philosopher.thread_id, NULL);
		i++;
	}
	pthread_join(all->philosopher.thread_id, NULL);
	printf("After Thread\n");
}

int	main(int argc, char **argv)
{
	t_all		*all;

	all = init_all(argc - 1, argv + 1);
	if (all)
	{
		start_threads(all);
	}
	free_all(all);
	return (0);
}
