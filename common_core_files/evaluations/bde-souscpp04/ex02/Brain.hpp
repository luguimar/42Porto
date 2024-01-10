/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:12:52 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 22:49:09 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>

class Brain{
    public:
        Brain( void );
        //Brain(std::string type);
        Brain(Brain const & value);
        ~Brain( void );
        Brain&	        operator=( Brain const& rhs );
    protected:
        std::string     ideas[100];
};

#endif