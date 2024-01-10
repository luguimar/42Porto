/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:50 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/31 20:05:34 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB{
    public:
        HumanB( void );
        HumanB(std::string name);
        ~HumanB( void );
        void attack( void );
        void setWeapon(Weapon& tipo);
    private:
        std::string _name;
        Weapon*     _weapon;
};

#endif