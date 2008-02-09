/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

/*
 *	server/zone/objects/guild/Guild.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../player/Player.h"

#include "../../managers/guild/GuildManager.h"

#include "Guild.h"

#include "GuildImplementation.h"

/*
 *	GuildStub
 */

Guild::Guild() : ORBObjectStub(NULL) {
}

Guild::Guild(ORBObjectServant* obj) : ORBObjectStub(obj) {
}

Guild::Guild(Guild& ref) : ORBObjectStub(ref) {
}

Guild::~Guild() {
}

Guild* Guild::clone() {
	return new Guild(*this);
}


void Guild::sendGuildListTo(Player* player, bool doLock) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(player);
		invocation.addBooleanParameter(doLock);

		invocation.executeWithVoidReturn();
	} else
		((GuildImplementation*) _impl)->sendGuildListTo(player, doLock);
}

void Guild::updateGuildFor(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((GuildImplementation*) _impl)->updateGuildFor(player);
}

void Guild::deleteGuildFor(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((GuildImplementation*) _impl)->deleteGuildFor(player);
}

void Guild::setGuildManager(GuildManager* gmanager) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addObjectParameter(gmanager);

		invocation.executeWithVoidReturn();
	} else
		((GuildImplementation*) _impl)->setGuildManager(gmanager);
}

unsigned int Guild::getGuildID() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((GuildImplementation*) _impl)->getGuildID();
}

string& Guild::getGuildName() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);

		invocation.executeWithAsciiReturn(_return_getGuildName);
		return _return_getGuildName;
	} else
		return ((GuildImplementation*) _impl)->getGuildName();
}

string& Guild::getGuildTag() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);

		invocation.executeWithAsciiReturn(_return_getGuildTag);
		return _return_getGuildTag;
	} else
		return ((GuildImplementation*) _impl)->getGuildTag();
}

/*
 *	GuildAdapter
 */

GuildAdapter::GuildAdapter(GuildImplementation* obj) : ORBObjectAdapter((ORBObjectServant*) obj) {
}

Packet* GuildAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendGuildListTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		updateGuildFor((Player*) inv->getObjectParameter());
		break;
	case 8:
		deleteGuildFor((Player*) inv->getObjectParameter());
		break;
	case 9:
		setGuildManager((GuildManager*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertInt(getGuildID());
		break;
	case 11:
		resp->insertAscii(getGuildName());
		break;
	case 12:
		resp->insertAscii(getGuildTag());
		break;
	default:
		return NULL;
	}

	return resp;
}

void GuildAdapter::sendGuildListTo(Player* player, bool doLock) {
	return ((GuildImplementation*) impl)->sendGuildListTo(player, doLock);
}

void GuildAdapter::updateGuildFor(Player* player) {
	return ((GuildImplementation*) impl)->updateGuildFor(player);
}

void GuildAdapter::deleteGuildFor(Player* player) {
	return ((GuildImplementation*) impl)->deleteGuildFor(player);
}

void GuildAdapter::setGuildManager(GuildManager* gmanager) {
	return ((GuildImplementation*) impl)->setGuildManager(gmanager);
}

unsigned int GuildAdapter::getGuildID() {
	return ((GuildImplementation*) impl)->getGuildID();
}

string& GuildAdapter::getGuildName() {
	return ((GuildImplementation*) impl)->getGuildName();
}

string& GuildAdapter::getGuildTag() {
	return ((GuildImplementation*) impl)->getGuildTag();
}

/*
 *	GuildHelper
 */

GuildHelper::GuildHelper() {
	className = "Guild";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void GuildHelper::finalizeHelper() {
	GuildHelper::finalize();
}

ORBObject* GuildHelper::instantiateObject() {
	return new Guild();
}

ORBObjectAdapter* GuildHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new GuildAdapter((GuildImplementation*) obj);

	ORBObjectStub* stub = new Guild(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	GuildServant
 */

GuildServant::GuildServant() {
	_classHelper = GuildHelper::instance();
}

GuildServant::~GuildServant() {
}

void GuildServant::_setStub(ORBObjectStub* stub) {
	_this = (Guild*) stub;
}

ORBObjectStub* GuildServant::_getStub() {
	return _this;
}

