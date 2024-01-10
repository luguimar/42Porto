/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:44:57 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 18:29:55 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
    public:
        WrongAnimal( void );
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const & value);
        ~WrongAnimal( void );
        WrongAnimal&	        operator=( WrongAnimal const& rhs );
        std::string     getType( void ) const;
        void            makeSound( void ) const;
    protected:
        std::string     type;

};

#endif