/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:44:57 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 18:29:55 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat( void );
        Cat(std::string type);
        Cat(Cat const & value);
        ~Cat( void );
        Cat&	    operator=( Cat const& rhs );
        void            makeSound( void ) const; 
    protected:
        std::string _sound;
    private:
        Brain*      _brain;
};

#endif