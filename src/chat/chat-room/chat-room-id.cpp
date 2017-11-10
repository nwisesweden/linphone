/*
 * chat-room-id.cpp
 * Copyright (C) 2010-2017 Belledonne Communications SARL
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "object/clonable-object-p.h"

#include "chat-room-id.h"

// =============================================================================

using namespace std;

LINPHONE_BEGIN_NAMESPACE

class ChatRoomIdPrivate : public ClonableObjectPrivate {
public:
	SimpleAddress peerAddress;
	SimpleAddress localAddress;
};

// -----------------------------------------------------------------------------

ChatRoomId::ChatRoomId (
	const SimpleAddress &peerAddress,
	const SimpleAddress &localAddress
) : ClonableObject(*new ChatRoomIdPrivate) {
	L_D();
	d->peerAddress = peerAddress;
	d->localAddress = localAddress;
}

bool ChatRoomId::operator== (const ChatRoomId &chatRoomId) const {
	L_D();
	const ChatRoomIdPrivate *dChatRoomId = chatRoomId.getPrivate();
	return d->peerAddress == dChatRoomId->peerAddress && d->localAddress == dChatRoomId->localAddress;
}

bool ChatRoomId::operator!= (const ChatRoomId &chatRoomId) const {
	return !(*this == chatRoomId);
}

const SimpleAddress &ChatRoomId::getPeerAddress () const {
	L_D();
	return d->peerAddress;
}

const SimpleAddress &ChatRoomId::getLocalAddress () const {
	L_D();
	return d->localAddress;
}

LINPHONE_END_NAMESPACE
