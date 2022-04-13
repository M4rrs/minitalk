/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:43:58 by nnorazma          #+#    #+#             */
/*   Updated: 2022/04/12 10:43:59 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		start;

	start = 0;
	if (!s1 || !set)
		return (0);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, start, (len - start) + 1));
}

/*First while: strchr will match each character in S1 to set, if it returns
the string aka true, start index moves to next char. Continues till return 0
loop ends, move to next one.*/
/*Second while: strchr does the same thing but we start from the back, but 
len-- hence removing char from set, till its no longer there- strchr 
returns 0. Loop ends.*/
/*Return: Returns the substring aka result of trimmed string. Len - start
because len only removes what is at the end, so we wanna get rid of that,
and we start with 'start' bcs we wanna get rid of what is at the beginning.
+1 because in the second while loop it len-- before the break. So we need
to recover that.*/
