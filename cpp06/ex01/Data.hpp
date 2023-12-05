/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:16:48 by vvalet            #+#    #+#             */
/*   Updated: 2023/12/05 10:19:30 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

struct Data
{
	public:
		Data(void);
		Data(int x);
		Data(const Data &original);
		Data	&operator=(const Data &original);
		~Data(void);
		int		getI(void) const;
		void	setI(int x);

	private:
		int	i;
};

#endif
