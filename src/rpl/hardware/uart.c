/*--------------------------------------------------------------------+
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
 ---------------------------------------------------------------------*/

// ISO C99 headers.
#include <stdlib.h>

// RPL headers.
#include <rpl/config.h>
#include <rpl/platform.h>
#include <rpl/hardware/uart.h>

// POSIX headers.
#if defined(RPL_OS_UNIX)
#  include <unistd.h>
#  include <termios.h>
#endif

struct rpl_uart
{
#if defined(RPL_OS_UNIX)
  int handle;
  struct termios options;

#elif defined(RPL_OS_WINDOWS)
  HANDLE handle;
  DCB options;
#endif
};

rpl_uart_t
rpl_uart_new(void)
{
  rpl_uart_t rpl_uart = calloc(1, sizeof(struct rpl_uart));
  return rpl_uart;
}

void
rpl_uart_free(rpl_uart_t* rpl_uart)
{
  if (rpl_uart == NULL)
    return;

  if (*rpl_uart != NULL)
  {
    free(*rpl_uart);
    *rpl_uart = NULL;
  }
}

void
rpl_uart_open(rpl_uart_t rpl_uart, const char* dev)
{
#if defined(RPL_OS_UNIX)
  rpl_uart->options.c_iflag &= ~(BRKINT | ICRNL | INLCR | PARMRK
                                 | IXOFF | IXON | PARMRK | ISTRIP
                                 | INPCK);

  rpl_uart->options.c_oflag &= ~(OPOST | ONLCR | OCRNL | ONOCR
                                 | ONLRET | OFILL | NLDLY | CRDLY
                                 | TABDLY | BSDLY | VTDLY | FFDLY);

  rpl_uart->options.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL
                                 | ICANON | IEXTEN | ISIG | NOFLSH
                                 | TOSTOP);
#endif
}

void
rpl_uart_close(rpl_uart_t rpl_uart)
{
  rpl_uart_flush(rpl_uart);

#if defined(RPL_OS_UNIX)
  close(rpl_uart->handle);
#endif
}

void
rpl_uart_set_frame_type(rpl_uart_t rpl_uart, rpl_uart_frame_t type)
{
#if defined(RPL_OS_UNIX)
  switch (type)
  {
    case RPL_UART_FRAME_8N1:
      rpl_uart->options.c_cflag &= ~(PARENB | PARODD | CSTOPB | CSIZE);
      rpl_uart->options.c_cflag |= CS8;
      rpl_uart->options.c_iflag |= IGNPAR;
      rpl_uart->options.c_iflag &= ~(PARMRK);
      break;

    case RPL_UART_FRAME_7E1:
      rpl_uart->options.c_cflag &= ~(PARODD | CSTOPB | CSIZE);
      rpl_uart->options.c_cflag |= (PARENB | CS7);
      break;

    case RPL_UART_FRAME_7O1:
      rpl_uart->options.c_cflag &= ~(CSTOPB | CSIZE);
      rpl_uart->options.c_cflag |= (PARENB | PARODD | CS7);
      break;
  }
#endif
}

void
rpl_uart_set_baud_rate(rpl_uart_t rpl_uart, unsigned baud)
{
#if defined(RPL_OS_UNIX)
  speed_t speed = B4800;

  switch (baud)
  {
    case 4800:
      speed = B4800;
      break;

    case 9600:
      speed = B9600;
      break;

    case 19200:
      speed = B19200;
      break;

    case 38400:
      speed = B38400;
      break;

    case 57600:
      speed = B57600;
      break;

    case 115200:
      speed = B115200;
      break;

    case 230400:
      speed = B230400;
      break;

    case 460800:
      speed = B460800;
      break;

    case 500000:
      speed = B500000;
      break;

    case 576000:
      speed = B576000;
      break;

    case 921600:
      speed = B921600;

    default:
      break;
  }
#endif
}
