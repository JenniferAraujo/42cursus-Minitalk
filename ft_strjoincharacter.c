/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincharacter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:18 by jede-ara          #+#    #+#             */
/*   Updated: 2023/01/19 16:39:19 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

unsigned char	*ft_strjoincharacter(unsigned char *str, unsigned char c)
{
	int				i;
	int				len;
	unsigned char	*swap;

	len = 0;
	i = 0;
	if (str)
		len = ft_strlen((char *)str);
	swap = malloc(sizeof(char) * (len + 2));
	if (str)
	{
		while (str[i] != '\0')
		{
			swap[i] = str[i];
			i++;
		}
	}
	swap[i] = c;
	swap[i + 1] = '\0';
	if (str)
		free(str);
	return (swap);
}
