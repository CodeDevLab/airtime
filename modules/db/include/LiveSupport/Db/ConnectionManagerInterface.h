/*------------------------------------------------------------------------------

    Copyright (c) 2004 Media Development Loan Fund
 
    This file is part of the LiveSupport project.
    http://livesupport.campware.org/
    To report bugs, send an e-mail to bugs@campware.org
 
    LiveSupport is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
  
    LiveSupport is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with LiveSupport; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 
    Author   : $Author: maroy $
    Version  : $Revision: 1.1 $
    Location : $Source: /home/paul/cvs2svn-livesupport/newcvsrepo/livesupport/modules/db/include/LiveSupport/Db/ConnectionManagerInterface.h,v $

------------------------------------------------------------------------------*/
#ifndef LiveSupport_Db_ConnectionManagerInterface_h
#define LiveSupport_Db_ConnectionManagerInterface_h

#ifndef __cplusplus
#error This is a C++ include file
#endif


/* ============================================================ include files */

#ifdef HAVE_CONFIG_H
#include "configure.h"
#endif

#include <odbc++/connection.h>


#include "LiveSupport/Core/Ptr.h"

namespace LiveSupport {
namespace Db {

using namespace LiveSupport::Core;

/* ================================================================ constants */


/* =================================================================== macros */


/* =============================================================== data types */

/**
 *  The interface for handing out and managing database connections.
 *
 *  @author  $Author: maroy $
 *  @version $Revision: 1.1 $
 */
class ConnectionManagerInterface
{
    public:
        /**
         *  Get a database connection from the manager.
         *  After use, the connection must be returned by calling
         *  returnConnection().
         *
         *  @return a database connection to the database this manager
         *          serves.
         *  @see #returnConnection
         */
        virtual Ptr<odbc::Connection>::Ref
        getConnection(void)                     throw (std::runtime_error)
                                                                        = 0;

        /**
         *  Return a database connection previously aquired by a call to
         *  getConnection(), after it is not needed anymore.
         *
         *  @param connection the connection to return.
         *  @see #getConnection
         */
        virtual void
        returnConnection(Ptr<odbc::Connection>::Ref connection)
                                                throw (std::runtime_error)
                                                                        = 0;
};


/* ================================================= external data structures */


/* ====================================================== function prototypes */


} // namespace Db
} // namespace LiveSupport

#endif // LiveSupport_Db_ConnectionManagerInterface_h

