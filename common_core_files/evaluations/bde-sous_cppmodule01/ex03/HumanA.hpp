/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:26:54 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/31 20:06:48 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA{
    public:
        HumanA(std::string name, Weapon& type );
        HumanA(Weapon& type);
        ~HumanA( void );
        void attack( void );
    private:
        std::string _name;
        Weapon*     _weapon;
};

#endif