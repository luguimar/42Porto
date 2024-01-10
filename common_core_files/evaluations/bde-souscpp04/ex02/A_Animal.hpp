/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:44:57 by bde-sous          #+#    #+#             */
/*   Updated: 2023/12/08 21:48:10 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_Animal_HPP
#define A_Animal_HPP

# include <iostream>

class A_Animal{
    public:
        A_Animal(A_Animal const & value);
        virtual ~A_Animal( void );
        A_Animal&	        operator=( A_Animal const& rhs );
        std::string         getType( void ) const;
        virtual void            makeSound( void ) const = 0;
    protected:
        A_Animal( void );
        A_Animal(std::string type);
        std::string     type;

};

#endif