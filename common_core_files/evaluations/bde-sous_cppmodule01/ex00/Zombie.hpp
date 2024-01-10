/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:52:59 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 19:28:06 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie{
    public:
        Zombie( std::string name );
        ~Zombie();
        void            announce( void );
    private:
        std::string     _name;
};

Zombie*     newZombie( std::string name );
void        randomChump( std::string name );

#endif