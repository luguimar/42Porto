/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:32:27 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/01 18:03:12 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>

class Harl{
    public:
        Harl();
        ~Harl();
        void    complain( std::string level );
    private:
        void            debug( void );
        void            info( void );
        void            warning( void );
        void            error( void );
        void            (Harl::*_ptr[4])(void);
        std::string     _levels[4];
};

#endif