/*
 *      Copyright (C) 2000 Nikos Mavroyanopoulos
 *
 * This file is part of GNUTLS.
 *
 * GNUTLS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GNUTLS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

int _gnutls_send_handshake(int cd, GNUTLS_STATE state, void* i_data, uint32 i_datasize, HandshakeType type);
int gnutls_send_hello_request(int cd, GNUTLS_STATE state);
int _gnutls_recv_hello_request(int cd, GNUTLS_STATE state, void* data, uint32 data_size);
int _gnutls_send_hello(int cd, GNUTLS_STATE state);
int _gnutls_recv_hello(int cd, GNUTLS_STATE state, char* data, int datalen);
int gnutls_handshake(int cd, GNUTLS_STATE state);
int _gnutls_recv_handshake( int cd, GNUTLS_STATE state, uint8**, int*, HandshakeType);
int _gnutls_generate_session_id( char* session_id, uint8* len);
int _gnutls_recv_certificate(int cd, GNUTLS_STATE state, char *data, int datalen);
int gnutls_handshake_begin(int cd, GNUTLS_STATE state);
int gnutls_handshake_finish(int cd, GNUTLS_STATE state);
