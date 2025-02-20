/*------------------------------------------------------------------*\
| Copyright (C) 2012 Ricardo Martins                                 |
+--------------------------------------------------------------------+
| This library is free software; you can redistribute it and/or      |
| modify it under the terms of the GNU Lesser General Public License |
| as published by the Free Software Foundation; either version 2.1   |
| of the License, or (at your option) any later version.             |
|                                                                    |
| This library is distributed in the hope that it will be useful,    |
| but WITHOUT ANY WARRANTY; without even the implied warranty of     |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  |
| Lesser General Public License for more details.                    |
|                                                                    |
| You should have received a copy of the GNU Lesser General Public   |
| License along with this library; if not, write to the Free         |
| Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        |
| Boston, MA 02110-1301 USA                                          |
\*------------------------------------------------------------------*/

#ifndef RPL_RPL_H_INCLUDED_
#define RPL_RPL_H_INCLUDED_

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/types.h>
#include <rpl/network/udp_socket.h>
#include <rpl/network/tcp_socket.h>
#include <rpl/string.h>

/**
 * @defgroup DLL Dynamic-link libraries
 */
#include <rpl/dll.h>

/**
 * @defgroup INIT Initialization
 */
#include <rpl/init.h>


/**
 * @defgroup ERROR Error Handling
 */
#include <rpl/error.h>

/**
 * @defgroup STREAMS Streams
 */
#include <rpl/streams/handle.h>

/**
 * @defgroup HARDWARE Hardware Access
 */
#include <rpl/hardware/uart.h>

/**
 * @defgroup CONCURRENCY Concurrency
 */
#include <rpl/concurrency/thread.h>

#include <rpl/time/clock.h>
#include <rpl/time/delay.h>

#endif
