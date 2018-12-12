# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/10 06:36:58 by gmadec       #+#   ##    ##    #+#        #
#    Updated: 2018/02/23 12:06:03 by gmadec      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

#******************************************************************************#
#                                    LIBFT                                     #
#******************************************************************************#
NAME_LIBFT = libft.a
PATH_SRC_LIBFT = ./Libft/
PATH_OBJ_LIBFT = ./Libft/
PATH_INC_LIBFT = ./Libft/
FILES_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			  ft_strncpy.c ft_strlcat.c ft_strcat.c ft_strncat.c ft_strchr.c \
			  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
			  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
			  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
			  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
			  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
			  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			  ft_itoa_base.c ft_isupper.c ft_islower.c ft_strcapitalize.c \
			  ft_swap.c ft_tablen.c ft_tabsupstr.c ft_ltoa.c ft_nbrlen.c \
			  ft_putsp.c ft_tabdup.c ft_free_tab.c
OBJ_LIBFT = $(addprefix $(PATH_OBJ_LIBFT), $(FILES_LIBFT:.c=.o))
	SRC_LIBFT = $(addprefix $(PATH_SRC_LIBFT), $(FILES_LIBFT))
	INC_LIBFT = $(addprefix $(PATH_INC_LIBFT), libft.h)

#******************************************************************************#
#                                   FT_LS                                      #
#******************************************************************************#

NAME = ft_ls
PATH_SRC_FT_LS = ./
PATH_OBJ_FT_LS = ./
PATH_INC_FT_LS = ./includes/
FILES_FT_LS = ft_in_dir.c ft_manage_list.c ft_filling_list.c main.c \
			  ft_manage_right.c ft_print.c ft_manage_file.c ft_free_list.c \
			  ft_sort_params.c ft_print_file.c ft_sort.c
OBJ_FT_LS = $(addprefix $(PATH_OBJ_FT_LS), $(FILES_FT_LS:.c=.o))
	SRC_FT_LS = $(addprefix $(PATH_SRC_FT_LS), $(FILES_FT_LS))
	INC_FT_LS = $(addprefix $(PATH_INC_FT_LS), ft_ls.h)

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#

all: $(NAME)

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

# This is a minimal set of ANSI/VT100 color codes
END=\x1b[0m
BOLD=\x1b[1m
UNDER=\x1b[4m
REV=\x1b[7m
#
# Colors
GREY=\x1b[30m
RED=\x1b[31m
GREEN=\x1b[32m
YELLOW=\x1b[33m
BLUE=\x1b[34m
PURPLE=\x1b[35m
CYAN=\x1b[36m
WHITE=\x1b[37m
#
# Inverted, i.e. colored backgrounds
BGREY=\x1b[40m
BRED=\x1b[41m
BGREEN=\x1b[42m
BYELLOW=\x1b[43m
BBLUE=\x1b[44m
BPURPLE=\x1b[45m
BCYAN=\x1b[46m
BWHITE=\x1b[47m

#******************************************************************************#
#                                 ASCII_ART                                     #
#******************************************************************************#

ASCII_ART=\n\
		 $(GREY)                              $(END)$(GREEN)00000000000000000$(END)\n\
		 $(GREY)                         $(END)$(GREEN)100001        1000000011$(END)\n\
		 $(GREY)                       $(END)$(GREEN)1                1100000001$(END)\n\
		 $(GREY)                      $(END)$(GREEN)1                       00001$(END)\n\
		 $(GREY)                    $(END)$(GREEN)11                        111000$(END)\n\
		 $(GREY)                   $(END)$(GREEN)11 1                         10001$(END)\n\
		 $(GREY)                   $(END)$(GREEN)0  11                       100000$(END)\n\
		 $(GREY)                  $(END)$(GREEN)11  1                       10000000$(END)\n\
		 $(GREY)                  $(END)$(GREEN)10   1             10000111000000000$(END)\n\
		 $(GREY)                  $(END)$(GREEN)001  11            000000000000000001$(END)\n\
		 $(GREY)                  $(END)$(GREEN)000   11           000000000000000001$(END)\n\
		 $(GREY)                  $(END)$(GREEN)000001 11111001    000111111000000000$(END)\n\
		 $(GREY)   $(END)$(GREEN)1101111        000001 000000111 00000000000  0000000$(END)\n\
		 $(GREY)   $(END)$(GREEN)1001  11       00000 1000000  1 00000000001  0000001         1111$(END)\n\
		 $(GREY)  $(END)$(GREEN)100001  11      00000  1000010   0110000000   000001        11  101$(END)\n\
		 $(GREY)  $(END)$(GREEN)000000   11     10001   00001   10  000001111000          11  100001$(END)\n\
		 $(GREY)  $(END)$(GREEN)00000001   11    101            00  00000000000011       00  1000001$(END)\n\
		 $(GREY)  $(END)$(GREEN)10000001    111   11  111     000  00000000000001      01  10000001$(END)\n\
		 $(GREY)      $(END)$(GREEN)11100001   111   101      1000  1000000000001     11   1000001$(END)\n\
		 $(GREY)           $(END)$(GREEN)100001  101  0001     000 100000011100    1111  1000011$(END)\n\
		 $(GREY)           $(END)$(GREEN)100001  101  0001     000 100000011100    1111  1000011$(END)\n\
		 $(GREY)               $(END)$(GREEN)1100000000 101      100000001 1001 01  1001$(END)\n\
		 $(GREY)                  $(END)$(GREEN)0000000 10 1101010 01011110000 1110001$(END)\n\
		 $(GREY)                    $(END)$(GREEN)10000  11110 011100011100001 00000$(END)\n\
		 $(GREY)                      $(END)$(GREEN)100    1000110101000000001 001$(END)\n\
		 $(GREY)                        $(END)$(GREEN)11         100000000000111$(END)\n\
		 $(GREY)                         $(END)$(GREEN)10011     1000000000001$(END)\n\
		 $(GREY)                          $(END)$(GREEN)0000    0000000000000$(END)\n\
		 $(GREY)                           $(END)$(GREEN)00001  10000000001$(END)\n\
		 $(GREY)                            $(END)$(GREEN)11000000000000001$(END)\n\
		 $(GREY)                          $(END)$(GREEN)11      00000000000011$(END)\n\
		 $(GREY)                        $(END)$(GREEN)11      1001  00001  11001$(END)\n\
		 $(GREY)                    $(END)$(GREEN)111      11011      10001   1001$(END)\n\
		 $(GREY)             $(END)$(GREEN)1101111       1001            10001  110011$(END)\n\
		 $(GREY)           $(END)$(GREEN)101           1001                10001   1100000011$(END)\n\
		 $(GREY)          $(END)$(GREEN)100  11      100                      0001         100$(END)\n\
		 $(GREY)          $(END)$(GREEN)10000001   100                          1001         10$(END)\n\
		 $(GREY)           $(END)$(GREEN)10011101 100                             10    1000001$(END)\n\
		 $(GREY)             $(END)$(GREEN)101 000001                              11  1000010$(END)\n\
		 $(GREY)              $(END)$(GREEN)10100001                                11100001$(END)\n

#******************************************************************************#
#                              Compilation FT_LS                               #
#******************************************************************************#

$(NAME): $(NAME_LIBFT) $(OBJ_FT_LS)
	@clear
	@$(CC) $(CC_FLAGS) $(OBJ_FT_LS) -L ./ -l ft -o $(NAME)
	@printf "$(RED)               $(REV)$(BOLD)$(UNDER)[-----COMPILATION DU PROGRAMME TERMINEE-----]$(END)\n"
	@printf "$(ASCII_ART)"

$(PATH_OBJ_FT_LS)%.o: $(PATH_SRC_FT_LS)%.c $(INC_FT_LS)
	@clear
	@printf "Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m\r"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC_FT_LS)

#******************************************************************************#
#                             Compilation LIBFT                                #
#******************************************************************************#

$(NAME_LIBFT): $(OBJ_LIBFT)
	@ar rcs $(NAME_LIBFT) $(OBJ_LIBFT)

$(PATH_OBJ_LIBFT)%.o: $(PATH_SRC_LIBFT)%.c $(INC_LIBFT)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC_LIBFT)

#******************************************************************************#
#                                   OTHER                                      #
#******************************************************************************#

clean:
	@printf "SUPPRESION DES .O"
	@rm -f $(OBJ_LIBFT) $(OBJ_FT_LS) */.DS_STORE

fclean: clean
	@printf ", $(NAME_LIBFT) et $(NAME)\n"
	@rm -f ./Libft/$(NAME_LIBFT) $(NAME_LIBFT) $(NAME) 

re: fclean all

exe: all
	@time ./ft_ls -lR /

exec: exe fclean
