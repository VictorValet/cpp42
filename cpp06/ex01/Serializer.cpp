#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(const Serializer &original)
{
	static_cast<void>(original);
	return ;
}

Serializer	&Serializer::operator=(const Serializer &original)
{
	static_cast<void>(original);
	return (*this);
}

Serializer::~Serializer(void)
{
	return ;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
