# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:55:21 by anurtiag          #+#    #+#              #
#    Updated: 2023/12/15 07:21:54 by anurtiag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

NAME_BONUS	=	fractol_bonus

LIBMLX		=	./lib/mlx

LIBFT		=	./lib/Libft

PRINTF		=	./lib/ft_printf

LIBS		=	$(LIBFT)/libft.a $(LIBMLX)/libmlx.a $(PRINTF)/libftprintf.a -framework OpenGL -framework AppKit

HEADERS		=	-I $(LIBFT) -I $(LIBMLX) -I $(PRINTF)

SRCS		= fractol.c hooks.c fractals.c hooks_utils.c colors.c utils.c

SRCS_BONUS	= fractol_bonus.c hooks_bonus.c fractals_bonus.c hooks_utils_bonus.c colors_bonus.c utils_bonus.c

OBJ			=	$(SRCS:.c=.o)

OBJ_BONUS	=	$(SRCS_BONUS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf



all:		$(NAME)

$(NAME):	libft libmlx printf $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

bonus:			libft printf libmlx $(OBJ_BONUS)
				@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

libmlx:
			@$(MAKE) -C $(LIBMLX)

libft:
			@$(MAKE) -C $(LIBFT)
printf:
			@$(MAKE) -C  $(PRINTF)

clean:
			@$(RM) $(OBJ) $(OBJDIR)
			@$(RM) $(OBJ_BONUS)
			@$(MAKE) -C $(LIBFT) clean
			@$(MAKE) -C $(LIBMLX) clean

fclean: clean
			@$(MAKE) -C $(LIBFT) fclean
			@$(MAKE) -C $(LIBMLX) fclean
			@$(MAKE) -C $(PRINTF) fclean
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re libft libmlx printf