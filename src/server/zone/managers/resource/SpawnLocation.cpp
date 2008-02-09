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
 *	server/zone/managers/resource/SpawnLocation.cpp generated by Engine3 IDL compiler 0.51
 */

#include "SpawnLocation.h"

#include "SpawnLocationImplementation.h"

/*
 *	SpawnLocationStub
 */

SpawnLocation::SpawnLocation() : ORBObjectStub(NULL) {
}

SpawnLocation::SpawnLocation(ORBObjectServant* obj) : ORBObjectStub(obj) {
}

SpawnLocation::SpawnLocation(SpawnLocation& ref) : ORBObjectStub(ref) {
}

SpawnLocation::~SpawnLocation() {
}

SpawnLocation* SpawnLocation::clone() {
	return new SpawnLocation(*this);
}


unsigned long long SpawnLocation::getID() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);

		return invocation.executeWithUnsignedLongReturn();
	} else
		return ((SpawnLocationImplementation*) _impl)->getID();
}

int SpawnLocation::getPlanet() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((SpawnLocationImplementation*) _impl)->getPlanet();
}

float SpawnLocation::getX() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);

		return invocation.executeWithFloatReturn();
	} else
		return ((SpawnLocationImplementation*) _impl)->getX();
}

float SpawnLocation::getY() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);

		return invocation.executeWithFloatReturn();
	} else
		return ((SpawnLocationImplementation*) _impl)->getY();
}

float SpawnLocation::getRadius() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);

		return invocation.executeWithFloatReturn();
	} else
		return ((SpawnLocationImplementation*) _impl)->getRadius();
}

float SpawnLocation::getMax() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);

		return invocation.executeWithFloatReturn();
	} else
		return ((SpawnLocationImplementation*) _impl)->getMax();
}

string& SpawnLocation::getPool() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);

		invocation.executeWithAsciiReturn(_return_getPool);
		return _return_getPool;
	} else
		return ((SpawnLocationImplementation*) _impl)->getPool();
}

/*
 *	SpawnLocationAdapter
 */

SpawnLocationAdapter::SpawnLocationAdapter(SpawnLocationImplementation* obj) : ORBObjectAdapter((ORBObjectServant*) obj) {
}

Packet* SpawnLocationAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(getID());
		break;
	case 7:
		resp->insertSignedInt(getPlanet());
		break;
	case 8:
		resp->insertFloat(getX());
		break;
	case 9:
		resp->insertFloat(getY());
		break;
	case 10:
		resp->insertFloat(getRadius());
		break;
	case 11:
		resp->insertFloat(getMax());
		break;
	case 12:
		resp->insertAscii(getPool());
		break;
	default:
		return NULL;
	}

	return resp;
}

unsigned long long SpawnLocationAdapter::getID() {
	return ((SpawnLocationImplementation*) impl)->getID();
}

int SpawnLocationAdapter::getPlanet() {
	return ((SpawnLocationImplementation*) impl)->getPlanet();
}

float SpawnLocationAdapter::getX() {
	return ((SpawnLocationImplementation*) impl)->getX();
}

float SpawnLocationAdapter::getY() {
	return ((SpawnLocationImplementation*) impl)->getY();
}

float SpawnLocationAdapter::getRadius() {
	return ((SpawnLocationImplementation*) impl)->getRadius();
}

float SpawnLocationAdapter::getMax() {
	return ((SpawnLocationImplementation*) impl)->getMax();
}

string& SpawnLocationAdapter::getPool() {
	return ((SpawnLocationImplementation*) impl)->getPool();
}

/*
 *	SpawnLocationHelper
 */

SpawnLocationHelper::SpawnLocationHelper() {
	className = "SpawnLocation";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void SpawnLocationHelper::finalizeHelper() {
	SpawnLocationHelper::finalize();
}

ORBObject* SpawnLocationHelper::instantiateObject() {
	return new SpawnLocation();
}

ORBObjectAdapter* SpawnLocationHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new SpawnLocationAdapter((SpawnLocationImplementation*) obj);

	ORBObjectStub* stub = new SpawnLocation(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	SpawnLocationServant
 */

SpawnLocationServant::SpawnLocationServant() {
	_classHelper = SpawnLocationHelper::instance();
}

SpawnLocationServant::~SpawnLocationServant() {
}

void SpawnLocationServant::_setStub(ORBObjectStub* stub) {
	_this = (SpawnLocation*) stub;
}

ORBObjectStub* SpawnLocationServant::_getStub() {
	return _this;
}

