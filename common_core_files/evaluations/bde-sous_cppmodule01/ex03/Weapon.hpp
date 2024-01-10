/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:08:50 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/31 19:49:52 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>

class Weapon{
    public:
        Weapon();
        ~Weapon();
        Weapon(std::string name);
        std::string const& getType() const;
        void setType(std::string value);
    private:
        std::string     _type;
};

# include "HumanA.hpp"
# include "HumanB.hpp"

#endif