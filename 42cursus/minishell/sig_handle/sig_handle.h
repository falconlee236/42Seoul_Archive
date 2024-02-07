/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:21:17 by yonyoo            #+#    #+#             */
/*   Updated: 2024/01/29 13:31:08 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_HANDLE_H
# define SIG_HANDLE_H
# include "../pm_shell.h"

void	init_sig_handler(void);
void	heredoc_handler(int sig);

#endif
