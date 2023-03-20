#MAKEFLAGS = --silent
#BLACK			= 	\033[1;30m
GREEN			=	\033[3;32m
#BLUE			=	\033[1;34m
#RED			=	\033[1;31m
#YELLOW      	=	\033[1;33m
#MAGENTA		=	\033[1;35m
#CYAN			=	\033[1;36m
#WHITE			=	\033[1;37m
DEFAULT			=	\033[0m
#ONELINEUP		=	"\033[1A"
#ERASELINE		=	"\033[K"
#NORMAL			[0;
#BOLD			[1;
#DIM			[2;
#ITALIC			[3;
#UNDERLINED		[4;
#BLINK			[5;
#REVERSEBG		[7;
#HIDDEN			[8;
#STRIKETHROUGH	[9;
NAME	= fractol
SOURCESPATH = ./
SOURCESLIST = fractol.c fractal.c julia.c utils.c colour.c
SOURCES = $(addprefix $(SOURCESPATH), $(SOURCESLIST))
OBJECTS = $(SOURCES:.c=.o)

ifeq ($(shell uname), Darwin)	#MacOS
	SYSTEM		= @printf "\e[1;33mMacOS\n\e[m"
	MINILIBX	= libmlx
	MLXFLAGS 	= -lmlx -framework OpenGL -framework AppKit -L ./$(MINILIBX)
else 	#Linux
	SYSTEM		= @printf "\e[1;33mLinux\n\e[m"
	MINILIBX	= libmlx_Linux
	MLXFLAGS	= -lmlx -lXext -lX11 -L ./$(MINILIBX)
endif

INCLUDEPATH	= ./
LIBRARY		= $(foreach lib,$(LIBRARYLIST),$(LIBRARYPATH)$(lib)/)
LIBRARYDOTA	= $(foreach lib,$(LIBRARYLIST),$(LIBRARYPATH)$(lib)/$(lib).a)
LIBRARYPATH	= ./
LIBRARYLIST	= libft $(MINILIBX)

COMPILE	= gcc
FLAGS	= -Wall -Wextra -Werror -g -I $(INCLUDEPATH)
REMOVE	= rm -f

# In order to pass an argument to the compiler, use the -D flag and set a
# variable such as $(X) and when calling make, add X = 3, for instance.

# Compiles from open-source to binary, but doesn't link. Necessary to run flags.
.c.o:
	$(COMPILE) $(FLAGS) -c $< -o $(<:.c=.o)

# Calling its name acts as its own makefile. Will compile only if the object 
# dependencies are fulfilled. ar creates an archive (here, library) from the 
# files member (objects), replacing them as needed. ranlib simply indexes 
# every function in the library (equivalent to s in crs).
# '@' hides the clutter from the terminal.
# It searches for the libft library in its original location, avoiding relinks.
all:	$(NAME)

$(NAME):	$(OBJECTS)

$(LIBFT):
	make $(LIBFTA) -C $(LIBFTPATH)

$(NAME):	$(OBJECTS)
	$(foreach lib, $(LIBRARY), make -C $(lib) ;)
	$(COMPILE) $(FLAGS) $(OBJECTS) $(LIBRARYDOTA) -o $(NAME) $(MLXFLAGS) -lm
# The compiler doesn't pull in the math library by default, so it has to be
# called explicitly with -lm. This dates back to when not all CPUs had floating
# point arithmetic built in, so you needed software emulation or a coprocessor.
# From Mac OS X 10.8.4 on, you don't need the -lm flag.

clean:
	@$(REMOVE) $(OBJECTS) $(OBJECTSBONUS)
	@$(foreach lib, $(LIBRARY), make clean -C $(lib) ;)
	@echo "$(GREEN)Limpíssimo!$(DEFAULT)"

fclean:		clean
	@$(REMOVE) $(NAME) $(NAMEBONUS)
	@$(REMOVE) $(LIBRARYDOTA) 

re:		fclean all
	$(foreach lib, $(LIBRARY), make re -C $(lib) ;)

NAMEBONUS	=	fractol_bonus
PATHBONUS	=	./
LISTBONUS	=	fractol_bonus.c fractal_bonus.c julia_bonus.c \
				utils_bonus.c colour_bonus.c
SOURCESBONUS	=	$(addprefix $(PATHBONUS), $(LISTBONUS))
OBJECTSBONUS	=	$(SOURCESBONUS:.c=.o)

bonus:	$(NAMEBONUS)

$(NAMEBONUS):	$(OBJECTSBONUS)
	$(foreach lib, $(LIBRARY), make -C $(lib) ;)
	$(COMPILE) $(FLAGS) $(OBJECTSBONUS) $(LIBRARYDOTA) -o $(NAMEBONUS) $(MLXFLAGS) -lm -Ofast

run:	$(NAME)
	./$(NAME) mandelbrot

vrun:	$(NAME)
	valgrind --leak-check=full -s -v ./$(NAME) mandelbrot

rerun:	re run

# Ignores files that could eventually be named after any of these rules.
.PHONY:		all clean fclean re