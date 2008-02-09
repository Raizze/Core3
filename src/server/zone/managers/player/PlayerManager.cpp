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
 *	server/zone/managers/player/PlayerManager.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../guild/GuildManager.h"

#include "../../objects/player/Player.h"

#include "../../objects/tangible/TangibleObject.h"

#include "PlayerMap.h"

#include "PlayerManager.h"

#include "PlayerManagerImplementation.h"

/*
 *	PlayerManagerStub
 */

PlayerManager::PlayerManager() : ORBObjectStub(NULL) {
}

PlayerManager::PlayerManager(ORBObjectServant* obj) : ORBObjectStub(obj) {
}

PlayerManager::PlayerManager(PlayerManager& ref) : ORBObjectStub(ref) {
}

PlayerManager::~PlayerManager() {
}

PlayerManager* PlayerManager::clone() {
	return new PlayerManager(*this);
}


bool PlayerManager::create(Player* player, unsigned int sessionkey) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(player);
		invocation.addUnsignedIntParameter(sessionkey);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->create(player, sessionkey);
}

bool PlayerManager::validateName(string& name) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addAsciiParameter(name);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->validateName(name);
}

Player* PlayerManager::load(unsigned long long charid) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addUnsignedLongParameter(charid);

		return (Player*) invocation.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->load(charid);
}

void PlayerManager::unload(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->unload(player);
}

void PlayerManager::handleAbortTradeMessage(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->handleAbortTradeMessage(player);
}

void PlayerManager::handleAddItemMessage(Player* player, unsigned long long itemID) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);
		invocation.addObjectParameter(player);
		invocation.addUnsignedLongParameter(itemID);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->handleAddItemMessage(player, itemID);
}

void PlayerManager::handleGiveMoneyMessage(Player* player, unsigned int value) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);
		invocation.addObjectParameter(player);
		invocation.addUnsignedIntParameter(value);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->handleGiveMoneyMessage(player, value);
}

void PlayerManager::handleAcceptTransactionMessage(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->handleAcceptTransactionMessage(player);
}

void PlayerManager::handleUnAcceptTransactionMessage(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 14);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->handleUnAcceptTransactionMessage(player);
}

void PlayerManager::handleVerifyTradeMessage(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 15);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->handleVerifyTradeMessage(player);
}

void PlayerManager::moveItem(Player* sender, Player* receiver, TangibleObject* item) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 16);
		invocation.addObjectParameter(sender);
		invocation.addObjectParameter(receiver);
		invocation.addObjectParameter(item);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->moveItem(sender, receiver, item);
}

void PlayerManager::doBankTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 17);
		invocation.addObjectParameter(sender);
		invocation.addObjectParameter(receiver);
		invocation.addSignedIntParameter(tipAmount);
		invocation.addBooleanParameter(updateTipTo);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->doBankTip(sender, receiver, tipAmount, updateTipTo);
}

void PlayerManager::doCashTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 18);
		invocation.addObjectParameter(sender);
		invocation.addObjectParameter(receiver);
		invocation.addSignedIntParameter(tipAmount);
		invocation.addBooleanParameter(updateTipTo);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->doCashTip(sender, receiver, tipAmount, updateTipTo);
}

void PlayerManager::modifyOfflineBank(Player* sender, string& receiverName, int creditAmount) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 19);
		invocation.addObjectParameter(sender);
		invocation.addAsciiParameter(receiverName);
		invocation.addSignedIntParameter(creditAmount);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->modifyOfflineBank(sender, receiverName, creditAmount);
}

void PlayerManager::setGuildManager(GuildManager* gmanager) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 20);
		invocation.addObjectParameter(gmanager);

		invocation.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->setGuildManager(gmanager);
}

Player* PlayerManager::getPlayer(string& name) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 21);
		invocation.addAsciiParameter(name);

		return (Player*) invocation.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->getPlayer(name);
}

GuildManager* PlayerManager::getGuildManager() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 22);

		return (GuildManager*) invocation.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->getGuildManager();
}

PlayerMap* PlayerManager::getPlayerMap() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 23);

		return (PlayerMap*) invocation.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->getPlayerMap();
}

/*
 *	PlayerManagerAdapter
 */

PlayerManagerAdapter::PlayerManagerAdapter(PlayerManagerImplementation* obj) : ORBObjectAdapter((ORBObjectServant*) obj) {
}

Packet* PlayerManagerAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(create((Player*) inv->getObjectParameter(), inv->getUnsignedIntParameter()));
		break;
	case 7:
		resp->insertBoolean(validateName(inv->getAsciiParameter(_param0_validateName__string_)));
		break;
	case 8:
		resp->insertLong(load(inv->getUnsignedLongParameter())->_getORBObjectID());
		break;
	case 9:
		unload((Player*) inv->getObjectParameter());
		break;
	case 10:
		handleAbortTradeMessage((Player*) inv->getObjectParameter());
		break;
	case 11:
		handleAddItemMessage((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	case 12:
		handleGiveMoneyMessage((Player*) inv->getObjectParameter(), inv->getUnsignedIntParameter());
		break;
	case 13:
		handleAcceptTransactionMessage((Player*) inv->getObjectParameter());
		break;
	case 14:
		handleUnAcceptTransactionMessage((Player*) inv->getObjectParameter());
		break;
	case 15:
		handleVerifyTradeMessage((Player*) inv->getObjectParameter());
		break;
	case 16:
		moveItem((Player*) inv->getObjectParameter(), (Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter());
		break;
	case 17:
		doBankTip((Player*) inv->getObjectParameter(), (Player*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 18:
		doCashTip((Player*) inv->getObjectParameter(), (Player*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 19:
		modifyOfflineBank((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_modifyOfflineBank__Player_string_int_), inv->getSignedIntParameter());
		break;
	case 20:
		setGuildManager((GuildManager*) inv->getObjectParameter());
		break;
	case 21:
		resp->insertLong(getPlayer(inv->getAsciiParameter(_param0_getPlayer__string_))->_getORBObjectID());
		break;
	case 22:
		resp->insertLong(getGuildManager()->_getORBObjectID());
		break;
	case 23:
		resp->insertLong(getPlayerMap()->_getORBObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool PlayerManagerAdapter::create(Player* player, unsigned int sessionkey) {
	return ((PlayerManagerImplementation*) impl)->create(player, sessionkey);
}

bool PlayerManagerAdapter::validateName(string& name) {
	return ((PlayerManagerImplementation*) impl)->validateName(name);
}

Player* PlayerManagerAdapter::load(unsigned long long charid) {
	return ((PlayerManagerImplementation*) impl)->load(charid);
}

void PlayerManagerAdapter::unload(Player* player) {
	return ((PlayerManagerImplementation*) impl)->unload(player);
}

void PlayerManagerAdapter::handleAbortTradeMessage(Player* player) {
	return ((PlayerManagerImplementation*) impl)->handleAbortTradeMessage(player);
}

void PlayerManagerAdapter::handleAddItemMessage(Player* player, unsigned long long itemID) {
	return ((PlayerManagerImplementation*) impl)->handleAddItemMessage(player, itemID);
}

void PlayerManagerAdapter::handleGiveMoneyMessage(Player* player, unsigned int value) {
	return ((PlayerManagerImplementation*) impl)->handleGiveMoneyMessage(player, value);
}

void PlayerManagerAdapter::handleAcceptTransactionMessage(Player* player) {
	return ((PlayerManagerImplementation*) impl)->handleAcceptTransactionMessage(player);
}

void PlayerManagerAdapter::handleUnAcceptTransactionMessage(Player* player) {
	return ((PlayerManagerImplementation*) impl)->handleUnAcceptTransactionMessage(player);
}

void PlayerManagerAdapter::handleVerifyTradeMessage(Player* player) {
	return ((PlayerManagerImplementation*) impl)->handleVerifyTradeMessage(player);
}

void PlayerManagerAdapter::moveItem(Player* sender, Player* receiver, TangibleObject* item) {
	return ((PlayerManagerImplementation*) impl)->moveItem(sender, receiver, item);
}

void PlayerManagerAdapter::doBankTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo) {
	return ((PlayerManagerImplementation*) impl)->doBankTip(sender, receiver, tipAmount, updateTipTo);
}

void PlayerManagerAdapter::doCashTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo) {
	return ((PlayerManagerImplementation*) impl)->doCashTip(sender, receiver, tipAmount, updateTipTo);
}

void PlayerManagerAdapter::modifyOfflineBank(Player* sender, string& receiverName, int creditAmount) {
	return ((PlayerManagerImplementation*) impl)->modifyOfflineBank(sender, receiverName, creditAmount);
}

void PlayerManagerAdapter::setGuildManager(GuildManager* gmanager) {
	return ((PlayerManagerImplementation*) impl)->setGuildManager(gmanager);
}

Player* PlayerManagerAdapter::getPlayer(string& name) {
	return ((PlayerManagerImplementation*) impl)->getPlayer(name);
}

GuildManager* PlayerManagerAdapter::getGuildManager() {
	return ((PlayerManagerImplementation*) impl)->getGuildManager();
}

PlayerMap* PlayerManagerAdapter::getPlayerMap() {
	return ((PlayerManagerImplementation*) impl)->getPlayerMap();
}

/*
 *	PlayerManagerHelper
 */

PlayerManagerHelper::PlayerManagerHelper() {
	className = "PlayerManager";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void PlayerManagerHelper::finalizeHelper() {
	PlayerManagerHelper::finalize();
}

ORBObject* PlayerManagerHelper::instantiateObject() {
	return new PlayerManager();
}

ORBObjectAdapter* PlayerManagerHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new PlayerManagerAdapter((PlayerManagerImplementation*) obj);

	ORBObjectStub* stub = new PlayerManager(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	PlayerManagerServant
 */

PlayerManagerServant::PlayerManagerServant() {
	_classHelper = PlayerManagerHelper::instance();
}

PlayerManagerServant::~PlayerManagerServant() {
}

void PlayerManagerServant::_setStub(ORBObjectStub* stub) {
	_this = (PlayerManager*) stub;
}

ORBObjectStub* PlayerManagerServant::_getStub() {
	return _this;
}

