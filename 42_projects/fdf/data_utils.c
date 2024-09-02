/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:15 by seunghan          #+#    #+#             */
/*   Updated: 2024/04/03 18:03:00 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./get_next_line/get_next_line.h"

static void	x_check(char *str, t_map *map)
{
	int		word;
	size_t	i;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			if (str[i + 1] != '\n')
				word++;
		}
		i++;
	}
	if (str[0] != ' ' && str[0] != '\0')
		word++;
	if (word != map -> x_max && map -> y_max)
	{
		ft_putstr_fd("Wrong map data!\n", 2);
		exit(1);
	}
	else
		map -> x_max = word;
}

static void	mal_cordi(t_map *map)
{
	int		i;

	i = 0;
	map -> cord = (t_cord **)malloc((map -> y_max) * sizeof(t_cord *));
	if (!(map -> cord))
		exit(1);
	while (i < map -> y_max)
	{
		(map -> cord)[i] = (t_cord *)malloc((map -> x_max) * sizeof(t_cord));
		if (!(map -> cord)[i])
			exit(1);
		i++;
	}
}

static void	get_height_from_file(t_map *map, int y, char **numb_str)
{
	int		x;
	double	height;

	x = 0;
	while (numb_str[x])
	{
		if (!ft_strncmp(numb_str[x], "\n", 1))
		{
			free(numb_str[x]);
			break ;
		}
		height = ft_atoi(numb_str[x]);
		if (height > 2147483647 || height < -2147483648)
		{
			ft_putstr_fd("Wrong map data!\n", 2);
			exit(1);
		}	
		(map -> cord)[y][x]. ini_z = ft_atoi(numb_str[x]);
		(map -> cord)[y][x]. clean_z = ft_atoi(numb_str[x]);
		free(numb_str[x]);
		x++;
	}
}

static void	get_height(char **argv, t_map *map)
{
	int		map_fd;
	char	**numb_str;
	char	*str;
	int		y;

	y = 0;
	mal_cordi(map);
	map_fd = open(argv[1], O_RDONLY);
	str = get_next_line(map_fd);
	if (!str)
		exit(1);
	while (str)
	{
		numb_str = ft_split(str, ' ');
		get_height_from_file(map, y, numb_str);
		free(str);
		free(numb_str);
		str = get_next_line(map_fd);
		y++;
	}
	map -> x_mid = map -> x_max / 2;
	map -> y_mid = map -> y_max / 2;
}

t_map	*get_map(char **argv, void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	t_map	*map;
	int		map_fd;
	char	*str;

	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
	{
		ft_putstr_fd("Wrong file name!\n", 2);
		exit(1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(1);
	map_first_init(mlx_ptr, win_ptr, img_ptr, map);
	str = get_next_line(map_fd);
	while (str)
	{
		x_check(str, map);
		map -> y_max++;
		free(str);
		str = get_next_line(map_fd);
	}
	get_height(argv, map);
	get_map_cord(map);
	return (map);
}
