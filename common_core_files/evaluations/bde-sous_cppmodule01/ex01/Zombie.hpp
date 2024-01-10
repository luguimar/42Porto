/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:52:59 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 21:14:02 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie{
    public:
        Zombie( std::string name );
        ~Zombie();
        Zombie(void);
        void            announce( void );
        void            setName(std::string name);
    private:
        std::string     _name;
};

Zombie*     zombieHorde(int i, std::string name);

#endif