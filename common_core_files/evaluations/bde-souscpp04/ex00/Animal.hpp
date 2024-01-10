/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:44:57 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 18:29:55 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
#define Animal_HPP

# include <iostream>

class Animal{
    public:
        Animal( void );
        Animal(std::string type);
        Animal(Animal const & value);
        virtual ~Animal( void );
        Animal&	        operator=( Animal const& rhs );
        std::string     getType( void ) const;
        virtual void            makeSound( void ) const;
    protected:
        std::string     type;

};

#endif