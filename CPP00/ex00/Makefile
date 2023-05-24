
NAME	= megaphone

CC		= g++

CFLAGS	= -std=c++98 -Wall -Wextra -Werror

OBJ_DIR = objs/

MEGAPHONE_DIR = 

SRCS	= megaphone.o \


MEGAPHONE_PREFIXE = $(addprefix  $(OBJ_DIR),$(SRCS))

all		: mkdir_obj compile $(NAME) done


$(OBJ_DIR)%.o : $(MEGAPHONE_DIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS)

mkdir_obj :
		@mkdir -p objs

.SILENT :

clean	:
		  @rm -f $(OBJS)

fclean	: clean
		  @rm -f $(NAME)
		  @rm -rf objs

re		: fclean all

.PHONY	: clean fclean all re

#.SILENT:

BLUE	= \033[1;34m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
DEFAULT = \033[0m

compile	:
		  echo "\n$(YELLOW)[X]Compiling $(BLUE)MEGAPHONE$(DEFAULT)\n"
done	:
		  echo "$(GREEN) $(GREEN)████████████ 100%$(DEFAULT)\n"