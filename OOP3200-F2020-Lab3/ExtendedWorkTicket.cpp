#include "ExtendedWorkTicket.h"

// To call the parameterized constructor of the base class, we have to mention it by name explicitly
ExtendedWorkTicket::ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
	:WorkTicket(ticket_number, client_id, day, month, year, description), m_isOpen(isOpen)
{
	SetIsOpen(isOpen);
}

std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& extendedWorkTicket)
{
	//out << (extendedWorkTicket)ShowWorkTicket;
	return out;
}

ExtendedWorkTicket::~ExtendedWorkTicket()
= default;

bool ExtendedWorkTicket::SetIsOpen(bool isOpen)
{
	return m_isOpen = isOpen;
}

bool ExtendedWorkTicket::CloseTicket(bool isOpen)
{
	m_isOpen = false;
	return m_isOpen;
}

bool ExtendedWorkTicket::IsOpen() const
{
	return m_isOpen;
}

bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
{
	// TO DO
	return true;
}





