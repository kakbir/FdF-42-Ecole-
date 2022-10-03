/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilerp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 01:06:57 by pbondoer          #+#    #+#             */
/*   Updated: 2022/08/30 09:25:57 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_ilerp(double val, double first, double second) // 440 440 460
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}
