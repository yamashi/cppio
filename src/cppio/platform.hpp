#pragma once

#ifdef _WIN32
#define CPPIO_PLATFORM_WIN 1
#define CPPIO_PLATFORM_POSIX 0
#else
#define CPPIO_PLATFORM_WIN 0
#define CPPIO_PLATFORM_POSIX 1
#endif

#include <cppio/error_code.hpp>

#include <outcome.hpp>

namespace outcome = OUTCOME_V2_NAMESPACE;


#if CPPIO_PLATFORM_WIN
#include <WinSock2.h>
#include <mswsock.h>
#include <ws2ipdef.h>
#include <ws2tcpip.h>

#include <cppio/impl/win32/defines.hpp>
namespace cppio
{
    using win32::handle_t;
    using win32::socket_t;

    using win32::socket_invalid_handle;
    using win32::socket_error;
}
#endif

#if CPPIO_PLATFORM_POSIX
#include <unistd.h> 
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include <cppio/impl/posix/defines.hpp>

namespace cppio
{
    using posix::handle_t;
    using posix::socket_t;
    using posix::closesocket;

    using posix::socket_invalid_handle;
    using posix::socket_error;
}
#endif
   