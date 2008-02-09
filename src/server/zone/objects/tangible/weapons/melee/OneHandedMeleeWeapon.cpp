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
 *	server/zone/objects/tangible/weapons/melee/OneHandedMeleeWeapon.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../../../creature/CreatureObject.h"

#include "../MeleeWeapon.h"

#include "OneHandedMeleeWeapon.h"

#include "OneHandedMeleeWeaponImplementation.h"

/*
 *	OneHandedMeleeWeaponStub
 */

OneHandedMeleeWeapon::OneHandedMeleeWeapon() : MeleeWeapon(NULL) {
}

OneHandedMeleeWeapon::OneHandedMeleeWeapon(ORBObjectServant* obj) : MeleeWeapon(obj) {
}

OneHandedMeleeWeapon::OneHandedMeleeWeapon(OneHandedMeleeWeapon& ref) : MeleeWeapon(ref) {
}

OneHandedMeleeWeapon::~OneHandedMeleeWeapon() {
}

OneHandedMeleeWeapon* OneHandedMeleeWeapon::clone() {
	return new OneHandedMeleeWeapon(*this);
}


/*
 *	OneHandedMeleeWeaponAdapter
 */

OneHandedMeleeWeaponAdapter::OneHandedMeleeWeaponAdapter(OneHandedMeleeWeaponImplementation* obj) : MeleeWeaponAdapter(obj) {
}

Packet* OneHandedMeleeWeaponAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	OneHandedMeleeWeaponHelper
 */

OneHandedMeleeWeaponHelper::OneHandedMeleeWeaponHelper() {
	className = "OneHandedMeleeWeapon";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void OneHandedMeleeWeaponHelper::finalizeHelper() {
	OneHandedMeleeWeaponHelper::finalize();
}

ORBObject* OneHandedMeleeWeaponHelper::instantiateObject() {
	return new OneHandedMeleeWeapon();
}

ORBObjectAdapter* OneHandedMeleeWeaponHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new OneHandedMeleeWeaponAdapter((OneHandedMeleeWeaponImplementation*) obj);

	ORBObjectStub* stub = new OneHandedMeleeWeapon(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	OneHandedMeleeWeaponServant
 */

OneHandedMeleeWeaponServant::OneHandedMeleeWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, int tp, bool eqp) : MeleeWeaponImplementation(objid, tempcrc, n, tempn, tp, eqp) {
	_classHelper = OneHandedMeleeWeaponHelper::instance();
}

OneHandedMeleeWeaponServant::OneHandedMeleeWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, int tp, bool eqp) : MeleeWeaponImplementation(creature, temp, n, tempn, tp, eqp) {
	_classHelper = OneHandedMeleeWeaponHelper::instance();
}

OneHandedMeleeWeaponServant::~OneHandedMeleeWeaponServant() {
}

void OneHandedMeleeWeaponServant::_setStub(ORBObjectStub* stub) {
	_this = (OneHandedMeleeWeapon*) stub;
	MeleeWeaponServant::_setStub(stub);
}

ORBObjectStub* OneHandedMeleeWeaponServant::_getStub() {
	return _this;
}

