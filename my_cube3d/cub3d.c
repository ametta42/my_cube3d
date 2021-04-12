#include "cub3d.h"

int	fill_info(t_red *info, char *path)
{
	char	*line = 0;
	int		fd = 0;

	fd = open(path, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		take_resolution(line, info);
		parsing_path(line, info);
		take_color(line, info);
		free(line);
		if (map_moment(info))
			break;
	}
	while(get_next_line(fd, &line))
	{
		if(ft_strlen(line))
			add_string_to_mat(&info->map, line);
		free(line);
	}
	add_string_to_mat(&info->map, line);
	free(line);
	return (check_info(info));
}

int		main(int ac, char **av)				// <-- Everithing start here
{
	t_red	info;
	if (ac >= 2 && ac <= 3)
	{
		init_struct_specs(&info);
		if (ac > 2 && ft_strrstr(av[2], "--save"))
			info.save = 1;
		if (ft_strrstr(av[1], ".cub"))
			return (ret_err(fill_info(&info, av[1])));
		else
			return (ret_err(2));
		debug_struct_specs(info);
		return 0;
	}
	else
		return (ret_err(1));
	/*
	t_game	all;
	t_key	keys;
	all.player.posX = 22, all.player.posY = 12;		// posizione di creazione del giocatore all;interno della mappa 
	all.player.dirX = -1, all.player.dirY = 0;		// direzione della visale del giocatore
	all.player.planeX = 0, all.player.planeY = 0.66;	// angolo di visuale

	all.mlx.ptr = mlx_init();
    all.mlx.win = mlx_new_window(all.mlx.ptr, screenWidth, screenHeight, "ametta's Cube3d");  //creazione della finestra

	mlx_hook(all.mlx.win, 2, 1L<<0, key_pressed, &keys);
	mlx_hook(all.mlx.win, 3, 1L<<1, key_release, &keys);

	mlx_hook(all.mlx.win, 17, 1L<<5, red_cross, &all.mlx);
	mlx_loop_hook(all.mlx.ptr, ft_render, &all.mlx);
    mlx_loop(all.mlx.ptr);
	*/
}