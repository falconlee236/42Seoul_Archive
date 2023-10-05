NAME=philo

all:
	$(MAKE) -C philo all
	touch mandatory
	rm -f bonus

bonus: 
	$(MAKE) -C philo_bonus all
	touch bonus
	rm -f mandatory

clean:
	$(MAKE) -C philo clean
	$(MAKE) -C philo_bonus clean
	rm -f mandatory
	rm -f bonus

fclean: clean
	$(MAKE) -C philo fclean
	$(MAKE) -C philo_bonus fclean

re: fclean all

.PHONY: all clean fclean re