/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:57:15 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/31 18:57:19 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void free_array(char **array)
{
    int index = 0;
    if (array)
    {
        while (array[index])
        {
            free(array[index]);
            index++;
        }
        free(array);
    }
}
