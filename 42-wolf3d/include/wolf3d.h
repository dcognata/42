/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:17:01 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 15:17:26 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "./wolf3d_includes.h"

void	launch(t_env *e);
void	display_menu(t_env *e);
int		select_x_arrow(t_env *e);
void	reload_load_screen(t_env *e, int state);
void	parse(t_env *e);
void	load_assets(t_env *e);
void	load_assets_editor(t_env *e);
void	load_assets_menu(t_env *e);
void	load_assets_load(t_env *e);
void	load_level(t_env *e);
void	load_textures(t_env *e);
void	load_tex_s(t_env *e);
void	load_tex_items(t_env *e);
void	set_texture(t_env *e, int x, char *str);
void	load_assets_minia(t_env *e);
void	load_assets_reticles(t_env *e);
void	load_assets_weapons(t_env *e);
void	initialisation(t_env *e);
void	put_pixel_to_img(t_env *e, int x, int y, int color);
void	select_color(t_env *e);
void	draw_base_walls(int x, t_env *e);
void	draw_texture_walls(int x, t_env *e);
void	draw_floor(int x, t_env *e);
void	draw_sky(int x, t_env *e);
void	load_textures(t_env *e);
void	wolf_reload(t_env *e);
void	editor_reload(t_env *e);
void	leave_program(t_env *e);
void	state_launch(int argc, char **argv, t_env *e);
void	select_weapon(t_env *e);
void	display_gun(t_env *e);
void	display_shootgun(t_env *e);
void	display_rifle(t_env *e);
void	usage(int error);
void	start_wolf(t_env *e);
void	start_editor(t_env *e);
void	editor_key_hook(int keycode, t_env *e);
void	menu_key_hook(int keycode, t_env *e);
void	game_key_hook(int keycode, t_env *e);
void	open_file(t_env *e);
void	destroy_weapons(t_env *e);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		motion_hook(int x, int y, t_env *e);
int		key_press(int keycode, t_env *e);
void	editor_mouse_hook(int button, int x, int y, t_env *e);

#endif
