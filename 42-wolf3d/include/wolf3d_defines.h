/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:59:52 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 17:54:54 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

/*
** letters
*/
# define KEY_T         17
# define KEY_R         15
# define KEY_W         13
# define KEY_D          0
# define KEY_S          1
# define KEY_A          2
/*
** directions
*/
# define KEY_LEFT     123
# define KEY_DOWN     125
# define KEY_RIGHT    124
# define KEY_UP       126
/*
** actions
*/
# define KEY_ENTER     36
# define KEY_ESC       53
/*
** nums
*/
# define KEY_1         18
# define KEY_2         19
# define KEY_3         20

/*
** UI_NUMBER
*/
# define UI_LOAD        1
# define UI_MENU        2
# define UI_GAME        3
# define UI_EDITOR      4

/*
** SOME SIZE
*/
# define SCRX        1280
# define SCRY         720
# define TEXHEIGHT     64
# define TEXWIDTH      64
# define NBTEX         26

/*
** SOME COLORS
*/
# define WHITE       0x00FFFFFF
# define BLACK       0x00000000
# define GREEN       0x0000FF21
# define RED         0x00FF0000
# define BLUE        0x0000FFFF
# define ORANGE      0x00FF6A00
# define GROUND      0x00475A5A
# define SKY         0x0067DDE7
# define NORTH       0x0010B17C
# define EST         0x00A7D306
# define SUD         0x00DB510B
# define OUEST       0x00B01F99

/*
** DRAW MODE
*/
# define M_SUBJECT       0
# define M_TEXTURE       1

/*
** WEAPONS MODE
*/
# define SAFE            0
# define SHOOT           1

# define HAND            0
# define GUN             1
# define RIFLE           2
# define SHOOTGUN        3

/*
** USAGE CODE
*/
# define MALLOC_FAILED   1
# define INIT_FAILED     2
# define OPEN_FAILED     3
# define OPEN_DIR_FAILED 4
# define END_PROGRAM     9

#endif
