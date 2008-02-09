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
 *	server/zone/objects/tangible/weapons/RangedWeapon.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../../creature/CreatureObject.h"

#include "Weapon.h"

#include "RangedWeapon.h"

#include "RangedWeaponImplementation.h"

/*
 *	RangedWeaponStub
 */

RangedWeapon::RangedWeapon() : Weapon(NULL) {
}

RangedWeapon::RangedWeapon(ORBObjectServant* obj) : Weapon(obj) {
}

RangedWeapon::RangedWeapon(RangedWeapon& ref) : Weapon(ref) {
}

RangedWeapon::~RangedWeapon() {
}

RangedWeapon* RangedWeapon::clone() {
	return new RangedWeapon(*this);
}


int RangedWeapon::getRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((RangedWeaponImplementation*) _impl)->getRange();
}

void RangedWeapon::setRange(int rng) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addSignedIntParameter(rng);

		invocation.executeWithVoidReturn();
	} else
		((RangedWeaponImplementation*) _impl)->setRange(rng);
}

/*
 *	RangedWeaponAdapter
 */

RangedWeaponAdapter::RangedWeaponAdapter(RangedWeaponImplementation* obj) : WeaponAdapter(obj) {
}

Packet* RangedWeaponAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getRange());
		break;
	case 7:
		setRange(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

int RangedWeaponAdapter::getRange() {
	return ((RangedWeaponImplementation*) impl)->getRange();
}

void RangedWeaponAdapter::setRange(int rng) {
	return ((RangedWeaponImplementation*) impl)->setRange(rng);
}

/*
 *	RangedWeaponHelper
 */

RangedWeaponHelper::RangedWeaponHelper() {
	className = "RangedWeapon";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void RangedWeaponHelper::finalizeHelper() {
	RangedWeaponHelper::finalize();
}

ORBObject* RangedWeaponHelper::instantiateObject() {
	return new RangedWeapon();
}

ORBObjectAdapter* RangedWeaponHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new RangedWeaponAdapter((RangedWeaponImplementation*) obj);

	ORBObjectStub* stub = new RangedWeapon(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	RangedWeaponServant
 */

RangedWeaponServant::RangedWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, bool eqp, int tp, int cat) : WeaponImplementation(objid, tempcrc, n, tempn, eqp, tp, cat) {
	_classHelper = RangedWeaponHelper::instance();
}

RangedWeaponServant::RangedWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, bool eqp, int tp, int cat) : WeaponImplementation(creature, temp, n, tempn, eqp, tp, cat) {
	_classHelper = RangedWeaponHelper::instance();
}

RangedWeaponServant::~RangedWeaponServant() {
}

void RangedWeaponServant::_setStub(ORBObjectStub* stub) {
	_this = (RangedWeapon*) stub;
	WeaponServant::_setStub(stub);
}

ORBObjectStub* RangedWeaponServant::_getStub() {
	return _this;
}

