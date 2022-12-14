SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/utils/utils00.c \
		$(SRCS_DIR)/parse.c \
		$(SRCS_DIR)/philo.c \
		$(SRCS_DIR)/time.c \
		$(SRCS_DIR)/threads.c \
		$(SRCS_DIR)/death.c \
		$(SRCS_DIR)/sleep.c \
		$(SRCS_DIR)/eat.c \


SRCS_DIR = srcs

OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR = objs

FLAGS = -Werror -Wall -Wextra -pthread -g -fsanitize=thread
CC = cc
RM = rm -rf
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			mkdir -p $(@D)
			$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean all