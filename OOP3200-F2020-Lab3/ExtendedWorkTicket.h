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

#pragma once

#ifndef __EXTENDEDWORKTICKET__
#define __EXTENDEDWORKTICKET__

#include "WorkTicket.h"
class ExtendedWorkTicket : public WorkTicket
{
public:

/// <summary>
/// Default Constructor for derived constructor
/// </summary>
ExtendedWorkTicket(): m_isOpen(true) { }

/// <summary>
/// Parameterized Constructor
/// </summary>
/// <param name="ticket_number"></param>
/// <param name="client_id"></param>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <param name="description"></param>
/// <param name="isOpen"></param>
ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen);

// Deconstructor
~ExtendedWorkTicket();

/// <summary>
/// Overloading the << operator
/// </summary>
/// <param name="out"></param>
/// <param name="extendedWorkTicket"></param>
/// <returns></returns>
friend std::ostream& operator <<(std::ostream& out, const ExtendedWorkTicket& extendedWorkTicket);

/// <summary>
/// Sets value of isOpen from private member variable to public variable
/// </summary>
/// <param name="isOpen"></param>
/// <returns></returns>
bool SetIsOpen(bool isOpen);

/// <summary>
/// Mutator that sets the value of isOpen to false or "closed"
/// </summary>
/// <returns></returns>
bool CloseTicket();

/// <summary>
/// Accessor to get value of IsOpen
/// </summary>
/// <returns></returns>
bool IsOpen() const;

/// <summary>
/// SetWorkTicket from the base class but overloaded with the isOpen parameter
/// </summary>
/// <param name="ticket_number"></param>
/// <param name="client_id"></param>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <param name="description"></param>
/// <param name="isOpen"></param>
/// <returns></returns>
bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen = true);

/// <summary>
/// Overriding the ShowWorkTicket to add a print statement to show if ticket is open or not
/// </summary>
void ShowWorkTicket() const override; 

// Private member variables
private:
	bool m_isOpen;
};

#endif
