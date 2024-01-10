/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:44:57 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 21:37:16 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat( void );
        WrongCat(std::string type);
        WrongCat(WrongCat const & value);
        ~WrongCat( void );
        WrongCat&	    operator=( WrongCat const& rhs );
        void            makeSound( void ) const; 
    protected:
        std::string _sound;
};

#endif