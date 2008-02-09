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
 *	server/zone/managers/item/ItemManager.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../../objects/tangible/TangibleObject.h"

#include "../../objects/tangible/weapons/Weapon.h"

#include "../../objects/tangible/wearables/Armor.h"

#include "../../objects/player/Player.h"

#include "ItemManager.h"

#include "ItemManagerImplementation.h"

/*
 *	ItemManagerStub
 */

ItemManager::ItemManager() : ORBObjectStub(NULL) {
}

ItemManager::ItemManager(ORBObjectServant* obj) : ORBObjectStub(obj) {
}

ItemManager::ItemManager(ItemManager& ref) : ORBObjectStub(ref) {
}

ItemManager::~ItemManager() {
}

ItemManager* ItemManager::clone() {
	return new ItemManager(*this);
}


void ItemManager::loadStaticWorldObjects() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadStaticWorldObjects();
}

TangibleObject* ItemManager::getPlayerItem(Player* player, long long objectid) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(player);
		invocation.addSignedLongParameter(objectid);

		return (TangibleObject*) invocation.executeWithObjectReturn();
	} else
		return ((ItemManagerImplementation*) _impl)->getPlayerItem(player, objectid);
}

void ItemManager::loadPlayerItems(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadPlayerItems(player);
}

void ItemManager::loadDefaultPlayerItems(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadDefaultPlayerItems(player);
}

void ItemManager::unloadPlayerItems(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->unloadPlayerItems(player);
}

void ItemManager::createPlayerItem(Player* player, TangibleObject* item) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);
		invocation.addObjectParameter(player);
		invocation.addObjectParameter(item);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->createPlayerItem(player, item);
}

void ItemManager::savePlayerItem(Player* player, TangibleObject* item) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);
		invocation.addObjectParameter(player);
		invocation.addObjectParameter(item);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->savePlayerItem(player, item);
}

void ItemManager::deletePlayerItem(Player* player, TangibleObject* item) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);
		invocation.addObjectParameter(player);
		invocation.addObjectParameter(item);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->deletePlayerItem(player, item);
}

void ItemManager::showDbStats(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 14);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->showDbStats(player);
}

void ItemManager::showDbDeleted(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 15);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->showDbDeleted(player);
}

void ItemManager::purgeDbDeleted(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 16);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->purgeDbDeleted(player);
}

unsigned long long ItemManager::getNextStaticObjectID() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 17);

		return invocation.executeWithUnsignedLongReturn();
	} else
		return ((ItemManagerImplementation*) _impl)->getNextStaticObjectID();
}

/*
 *	ItemManagerAdapter
 */

ItemManagerAdapter::ItemManagerAdapter(ItemManagerImplementation* obj) : ORBObjectAdapter((ORBObjectServant*) obj) {
}

Packet* ItemManagerAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		loadStaticWorldObjects();
		break;
	case 7:
		resp->insertLong(getPlayerItem((Player*) inv->getObjectParameter(), inv->getSignedLongParameter())->_getORBObjectID());
		break;
	case 8:
		loadPlayerItems((Player*) inv->getObjectParameter());
		break;
	case 9:
		loadDefaultPlayerItems((Player*) inv->getObjectParameter());
		break;
	case 10:
		unloadPlayerItems((Player*) inv->getObjectParameter());
		break;
	case 11:
		createPlayerItem((Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter());
		break;
	case 12:
		savePlayerItem((Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter());
		break;
	case 13:
		deletePlayerItem((Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter());
		break;
	case 14:
		showDbStats((Player*) inv->getObjectParameter());
		break;
	case 15:
		showDbDeleted((Player*) inv->getObjectParameter());
		break;
	case 16:
		purgeDbDeleted((Player*) inv->getObjectParameter());
		break;
	case 17:
		resp->insertLong(getNextStaticObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ItemManagerAdapter::loadStaticWorldObjects() {
	return ((ItemManagerImplementation*) impl)->loadStaticWorldObjects();
}

TangibleObject* ItemManagerAdapter::getPlayerItem(Player* player, long long objectid) {
	return ((ItemManagerImplementation*) impl)->getPlayerItem(player, objectid);
}

void ItemManagerAdapter::loadPlayerItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->loadPlayerItems(player);
}

void ItemManagerAdapter::loadDefaultPlayerItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->loadDefaultPlayerItems(player);
}

void ItemManagerAdapter::unloadPlayerItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->unloadPlayerItems(player);
}

void ItemManagerAdapter::createPlayerItem(Player* player, TangibleObject* item) {
	return ((ItemManagerImplementation*) impl)->createPlayerItem(player, item);
}

void ItemManagerAdapter::savePlayerItem(Player* player, TangibleObject* item) {
	return ((ItemManagerImplementation*) impl)->savePlayerItem(player, item);
}

void ItemManagerAdapter::deletePlayerItem(Player* player, TangibleObject* item) {
	return ((ItemManagerImplementation*) impl)->deletePlayerItem(player, item);
}

void ItemManagerAdapter::showDbStats(Player* player) {
	return ((ItemManagerImplementation*) impl)->showDbStats(player);
}

void ItemManagerAdapter::showDbDeleted(Player* player) {
	return ((ItemManagerImplementation*) impl)->showDbDeleted(player);
}

void ItemManagerAdapter::purgeDbDeleted(Player* player) {
	return ((ItemManagerImplementation*) impl)->purgeDbDeleted(player);
}

unsigned long long ItemManagerAdapter::getNextStaticObjectID() {
	return ((ItemManagerImplementation*) impl)->getNextStaticObjectID();
}

/*
 *	ItemManagerHelper
 */

ItemManagerHelper::ItemManagerHelper() {
	className = "ItemManager";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void ItemManagerHelper::finalizeHelper() {
	ItemManagerHelper::finalize();
}

ORBObject* ItemManagerHelper::instantiateObject() {
	return new ItemManager();
}

ORBObjectAdapter* ItemManagerHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new ItemManagerAdapter((ItemManagerImplementation*) obj);

	ORBObjectStub* stub = new ItemManager(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	ItemManagerServant
 */

ItemManagerServant::ItemManagerServant() {
	_classHelper = ItemManagerHelper::instance();
}

ItemManagerServant::~ItemManagerServant() {
}

void ItemManagerServant::_setStub(ORBObjectStub* stub) {
	_this = (ItemManager*) stub;
}

ORBObjectStub* ItemManagerServant::_getStub() {
	return _this;
}

