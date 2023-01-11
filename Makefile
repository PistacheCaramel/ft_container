NAME = ft_containers

SRCS = test_rev_it.cpp

CC = c++

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD

INCLUDES = -Iincludes
all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $@

clean :
	rm -rf $(DEPS)
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean make

-include $(DEPS)

.PHONY : all flcean clean re
