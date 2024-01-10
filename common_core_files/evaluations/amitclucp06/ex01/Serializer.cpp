/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:08:35 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/09 09:08:38 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer() {
}

Serializer::Serializer(const Serializer& other) {
	(void) other;
}

Serializer& Serializer::operator=(const Serializer& rhs) {
	(void) rhs;
	return *this;
}

Serializer::~Serializer() {
}


uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}


