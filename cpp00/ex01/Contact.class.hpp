/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvalet <vvalet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:50:39 by vvalet            #+#    #+#             */
/*   Updated: 2023/10/25 15:44:20 by vvalet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "phonebook.hpp"
# include <string>

class Contact
{
	public:
	
		Contact(void);
		~Contact(void);

		std::string	getfirstname(void) const;
		std::string	getlastname(void) const;
		std::string	getnickname(void) const;
		std::string	getphonenumber(void) const;
		std::string	getdarkestsecret(void) const;
		int			getsaved(void) const;
		void		complete_infos(void);

	private:
	
		std::string first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		int			_saved;
};

#endif
