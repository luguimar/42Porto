/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:08:30 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/16 13:53:02 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.h"


int main() {
	Data* data = new Data;


	data->string_data = std::string("String data");
	data->int_data = 42;
	data->float_data = 21.0f;
	data->double_data = 10.5;

	Data* sd = Serializer::deserialize(Serializer::serialize(data));

	std::cout << sd->string_data << std::endl;
	std::cout << sd->int_data << std::endl;
	std::cout << sd->float_data << std::endl;
	std::cout << sd->double_data << std::endl;

	delete data;
	return 0;
}



// 42.42f
// 00010101010101
// static_cast 000101010 * (0x44sd) 
// reinterpret_cast 