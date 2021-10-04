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

/// <summary>
/// Parameterized Constructor for derived class
/// NOTE: To call the parameterized constructor of the base class, we have to mention it by name explicitly
/// </summary>
/// <param name="ticket_number"></param>
/// <param name="client_id"></param>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <param name="description"></param>
/// <param name="isOpen"></param>
ExtendedWorkTicket::ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
	:WorkTicket(ticket_number, client_id, day, month, year, description), m_isOpen(isOpen)
{
	SetTicketNumber(ticket_number);
	SetClientId(client_id);
	SetDate(day, month, year);
	SetDescription(description);
	SetIsOpen(isOpen);
}

/// <summary>
/// Deconstructor
/// </summary>
ExtendedWorkTicket::~ExtendedWorkTicket()
= default;

/// <summary>
/// Mutator to set the value of isOpen. Also used in initialization for parameterized constructor
/// </summary>
/// <param name="isOpen"></param>
/// <returns></returns>
bool ExtendedWorkTicket::SetIsOpen(bool isOpen)
{
	return m_isOpen = isOpen;
}

/// <summary>
/// Mutator to close a work ticket 
/// </summary>
/// <returns></returns>
bool ExtendedWorkTicket::CloseTicket()
{
	m_isOpen = false;
	SetIsOpen(m_isOpen);
	return m_isOpen;
}

/// <summary>
/// Accessor to get the value isOpen
/// </summary>
/// <returns></returns>
bool ExtendedWorkTicket::IsOpen() const
{
	return m_isOpen;
}

/// <summary>
///	Overloading the << operator to include the status of a WorkTicket 
/// </summary>
/// <param name="out"></param>
/// <param name="extendedWorkTicket"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& extendedWorkTicket)
{
	// Logic to show if a ticket is open or closed - instead of showing 1 or 0. 
	if (extendedWorkTicket.IsOpen() == true)
	{
		out << WorkTicket(extendedWorkTicket) << "Ticket:        Open";
	}
	else
	{
		out << WorkTicket(extendedWorkTicket) << "Ticket:        Closed";
	}

	// This code will show true/false instead of 1/0
	//out << WorkTicket(extendedWorkTicket) << "Ticket:        " << std::boolalpha << extendedWorkTicket.IsOpen();

	return out;
}

/// <summary>
/// Overloaded SetWorkTicket to include isOpen
/// </summary>
/// <param name="ticket_number"></param>
/// <param name="client_id"></param>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <param name="description"></param>
/// <param name="isOpen"></param>
/// <returns></returns>
bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
{
	bool isValid = false;

	// Call the base class version of SetWorkTicket
	WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description);

	// If the base class version returns true then set the isOpen status
	// if base class version returns false then don't set anything
	if (WorkTicket::SetWorkTicket(ticket_number, client_id, day, month, year, description) == true)
	{
		isValid = true;
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


