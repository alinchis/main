/*
* This file is part of BRAT 
*
* BRAT is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* BRAT is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#if !defined(BRAT_TRACELOG_H)
#define BRAT_TRACELOG_H

#include "Trace.h"

class CTraceLog : public CTrace
{
public:
	CTraceLog( const std::string& szFilelog );
	virtual ~CTraceLog();

	//Methods
public:

protected:

	void OpenLogFile();

	virtual std::ostream* GetDumpContextReel();
	// Attributes
public:

protected:
	/*
	* Log file
	*/
	std::ofstream *m_pFileLog;
	/**
	* Log file name
	*/
	std::string  m_szFileLogName;
};

#endif // !defined(BRAT_TRACELOG_H)
