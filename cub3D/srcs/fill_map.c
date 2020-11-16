/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 19:40:31 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/09 21:05:28 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_y_map(t_map_data *m_d, char *map)
{
	int i;

	i = m_d->index;
	m_d->map_y++;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			m_d->map_y++;
		i++;
	}
}

static	void	get_x_map(t_map_data *m_d, char *map)
{
	int i;
	int j;

	j = 0;
	i = m_d->index;
	m_d->map_x = (int *)malloc(sizeof(int) * m_d->map_y);
	if (!m_d->map_x)
		on_error(9);
	while (j < m_d->map_y)
	{
		m_d->map_x[j] = 0;
		while (map[i] != '\n' && map[i] != '\0')
		{
			if ((map[i] >= '0' && map[i] <= '2') || map[i] == 'N' \
			|| map[i] == 'S' || map[i] == 'W' || map[i] == 'E' || map[i] == ' ')
				m_d->map_x[j]++;
			i++;
		}
		i++;
		j++;
	}
}

static	void	fill_line(t_map_data *m_d, char *map, int j, int i)
{
	while (i < m_d->map_x[j])
	{
		if (map[m_d->index] >= '0' && map[m_d->index] <= '2')
		{
			m_d->map[j][i] = (int)map[m_d->index] - 48;
			i++;
		}
		else if ((map[m_d->index] == 'N' || map[m_d->index] == 'E' || \
		map[m_d->index] == 'W' || map[m_d->index] == 'S') && m_d->sp_or == '0')
		{
			m_d->spawn_loc_x = i;
			m_d->spawn_loc_y = j;
			m_d->sp_or = map[m_d->index];
			m_d->map[j][i] = 0;
			i++;
		}
		else if (map[m_d->index] == ' ')
		{
			m_d->map[j][i] = 9;
			i++;
		}
		else if (map[m_d->index] != ' ')
			on_error(1);
		m_d->index++;
	}
}

static	void	fill_map(t_map_data *m_d, char *map)
{
	int	j;

	j = 0;
	while (j < m_d->map_y)
	{
		if (map[m_d->index] == '\n')
		{
			if (map[m_d->index + 1] == '\n' || map[m_d->index + 1] == '\0')
				on_error(1);
			m_d->index++;
		}
		fill_line(m_d, map, j, 0);
		j++;
	}
}

void			get_map(t_map_data *m_d, char *map)
{
	int	i;

	i = m_d->index;
	while (map[m_d->index] != '\n')
		m_d->index--;
	m_d->index++;
	get_y_map(m_d, map);
	get_x_map(m_d, map);
	i = 0;
	m_d->map = (int **)malloc(sizeof(int*) * m_d->map_y);
	if (!m_d->map)
		on_error(9);
	while (i < m_d->map_y)
	{
		m_d->map[i] = (int *)malloc(sizeof(int) * m_d->map_x[i]);
		if (!m_d->map[i])
			on_error(9);
		i++;
	}
	fill_map(m_d, map);
	check_map(m_d);
	ft_putstr("Extracted Map \xE2\x9C\x94\n");
}
