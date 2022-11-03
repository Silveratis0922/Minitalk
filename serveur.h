/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:11:30 by tchantro          #+#    #+#             */
/*   Updated: 2022/11/03 13:54:12 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H
// Tous les includes de la Libft.
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <strings.h>
# include <bsd/string.h>
# include <ctype.h>
# include <stdarg.h>
# include "libft.h"
// Les includes et defines supplementaire pour le projet.
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

int	main(int argc, char **argv);
#endif
