#pragma once
#include "WorkTicket.h"
class ExtendedWorkTicket : public WorkTicket
{
public:

// When derived class's default constructor is called, the base class's default constructor is automatically called
ExtendedWorkTicket(): m_isOpen(true)
{
	
}


ExtendedWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen);

~ExtendedWorkTicket();

friend std::ostream& operator <<(std::ostream& out, const ExtendedWorkTicket& extendedWorkTicket);

bool SetIsOpen(bool isOpen);

bool CloseTicket( bool isOpen);

bool IsOpen() const;

bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen = true);

private:
	bool m_isOpen;
};

