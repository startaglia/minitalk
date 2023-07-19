NAMEC = client
NAMES = server
LIBRARY = libftprintf.a
FT_PRINTF = ft_printf
SRCC_FILES = srcs/client.c
SRCS_FILES = srcs/server.c
OBJS = $(SRCS_FILES:.c=.o)
OBJC = $(SRCC_FILES:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all: $(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		make -C $(FT_PRINTF)
		$(CC) $(FLAGS) $(SRCC_FILES) $(INCLUDE) ft_printf/$(LIBRARY) -o $(NAMEC)
$(NAMES) : $(OBJS)
		make -C $(FT_PRINTF)
		$(CC) $(FLAGS) $(SRCS_FILES) $(INCLUDE) ft_printf/$(LIBRARY) -o $(NAMES)
clean:
		@make clean -C ft_printf
		$(RM) $(OBJC)
		$(RM) $(OBJS)
fclean:
		@make fclean -C ft_printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(LIBRARY)
re: fclean all

.PHONY:		all bonus clean fclean re

