/*
*	Author: Gaelen Rhoads
*	Student ID: 100804776
*
*	Author: Nimsith Fernandopulle
*	Student ID: 100806868
*
*	Date: October 3, 2021
*	Project: Lab 3 - Inheritance
*	File Name: ExtendedWorkTicket.cpp
*
*/

#include "ExtendedWorkTicket.h"

// To call the parameterized constructor of the base class, we have to mention it by name explicitly
ExtendedWorkTicket::ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
	:WorkTicket(ticket_number, client_id, day, month, year, description), m_isOpen(isOpen)
{
	SetTicketNumber(ticket_number);
	SetClientId(client_id);
	SetDate(day, month, year);
	SetDescription(description);
	SetIsOpen(isOpen);
}

std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& extendedWorkTicket)
{
	out << WorkTicket(extendedWorkTicket);
	return out;
}

ExtendedWorkTicket::~ExtendedWorkTicket()
= default;

bool ExtendedWorkTicket::SetIsOpen(bool isOpen)
{
	return m_isOpen = isOpen;
}

bool ExtendedWorkTicket::CloseTicket()
{
	m_isOpen = false;
	SetIsOpen(m_isOpen);
	return m_isOpen;
}

bool ExtendedWorkTicket::IsOpen() const
{
	return m_isOpen;
}

bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
{
	bool isValid = false;

	if (isValid == true)
	{
		SetIsOpen(isOpen);
	}
	
	return isValid;
}

/// <summary>
/// Call base class version of ShowWorkTicket, then add the ticket status based on the value of IsOpen
/// </summary>
void ExtendedWorkTicket::ShowWorkTicket() const
{
	WorkTicket::ShowWorkTicket();

	// Space added here to match original spacing in super class version
	if (IsOpen() == true)
	{
		cout << "Ticket:        OPEN" << std::endl;
	}
	else
	{
		cout << "Ticket:        CLOSED" << std::endl;
	}
}


