# C Socket Programming

A simple implementation of client-server communication using C sockets, supporting both TCP and UDP protocols.

## Features

- TCP socket implementation
  - Connection-oriented
  - Reliable data delivery
  - Stream-based communication
- UDP socket implementation
  - Connectionless
  - Faster, but unreliable
  - Message-based communication
- Basic client-server communication
- Simple message exchange
- Error handling

## Building

Compile all programs:
```bash
make all
```

Or compile specific versions:
```bash
make tcp_server tcp_client    # For TCP versions
make udp_server udp_client    # For UDP versions
```

## Usage

### TCP Version
1. Start the TCP server:
```bash
./tcp_server
```

2. In another terminal, start the TCP client:
```bash
./tcp_client
```

### UDP Version
1. Start the UDP server:
```bash
./udp_server
```

2. In another terminal, start the UDP client:
```bash
./udp_client
```

## Key Differences between TCP and UDP Implementations

1. TCP (Transmission Control Protocol):
   - Connection-oriented
   - Reliable data delivery
   - Order of messages guaranteed
   - Better for applications requiring data integrity

2. UDP (User Datagram Protocol):
   - Connectionless
   - No guarantee of delivery or order
   - Faster due to less overhead
   - Better for real-time applications
```

Key differences between TCP and UDP implementations:

1. Socket Type:
   - TCP uses `SOCK_STREAM`
   - UDP uses `SOCK_DGRAM`

2. Connection Handling:
   - TCP requires `connect()`, `accept()`, and maintains connection state
   - UDP is connectionless, using `sendto()` and `recvfrom()` for each message

3. Message Boundaries:
   - TCP is stream-based
   - UDP preserves message boundaries

4. Reliability:
   - TCP handles retransmission automatically
   - UDP has no built-in reliability mechanisms

