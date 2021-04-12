#include "cub3d.h"

int ft_jump_space(char **str)
{
	while (*str && ft_strchr(" \t\v\f\r", **str))
		*str += 1;
	return 0;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	init_struct_specs(t_red *info)
{
	info->save = 0;
	info->width = 0;
	info->height = 0;
	info->no_t = 0;
	info->so_t = 0;
	info->ea_t = 0;
	info->we_t = 0;
	info->sp_t = 0;
	info->f_c = 0;
	info->c_c = 0;
}

void	debug_struct_specs(t_red info)
{
	printf("	--	DEBUGGING PROCESS	--\n");
	printf("width:			%d\nheight:			%d\n", info.width, info.height);
	printf("north textrure path:	%s\n", info.no_t);
	printf("south textrure path:	%s\n", info.so_t);
	printf("east textrure path:	%s\n", info.ea_t);
	printf("west textrure path:	%s\n", info.we_t);
	printf("sprite textrure path:	%s\n", info.sp_t);
	printf("floor color: 		%d\n", info.f_c);
	printf("ceiling color:		%d\n", info.c_c);
	printf("save opt:		%d\n", info.save);
	printf("\n		map debug\n");
	print_mat(info.map);
}

int 	map_moment(t_red *info)
{
	if (info->width && info->height && info->no_t && info->so_t &&
		info->ea_t && info->we_t && info->sp_t && info->f_c && info->c_c)
		return (1);
	return (0);
}

int		ft_strrstr(char *haystack, char *needle)
{
	int hlen;
	int nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	while (nlen > 0)
	{
		if(needle[--nlen] != haystack[--hlen])
			return (0);
	}
	return (1);
}

int ret_err(int err_code)
{
	if (err_code == 0)
		return (0);
	else if (err_code == 1)
		printf("Error: wrong argument's number\n");
	else if (err_code == 2)
		printf("Error: invalid file name\n");
	else
		printf("Error: something goes wrong\n");
	return (-1);
}