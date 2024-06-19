/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:50:32 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:03:11 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		check_format(va_list ap, const char format);
int		ft_pf_char(int c);
int		ft_pf_str(char *str);
int		add_null(uintptr_t add);
int		add_len(unsigned long long add);
int		ft_pf_address(uintptr_t add);
int		ft_pf_dec(int num);
int		ft_pf_int(int num);
int		ft_pf_per(void);
int		ft_pf_unsigned_dec(unsigned int num);
char	*ft_unsigned_itoa(unsigned int num);
int		uhex_len(unsigned int hex);
int		ft_pf_upp_hex(unsigned int hex);
int		hex_len(unsigned int hex);
int		ft_pf_low_hex(unsigned int hex);

#endif
