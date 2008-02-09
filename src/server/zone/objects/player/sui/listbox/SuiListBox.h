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
 *	server/zone/objects/player/sui/listbox/SuiListBox.h generated by Engine3 IDL compiler 0.51
 */

#ifndef SUILISTBOX_H_
#define SUILISTBOX_H_

#include "engine/orb/ObjectRequestBroker.h"

class SuiBox;

class Player;

#include "engine/service/proto/BaseMessage.h"

#include "../SuiBox.h"

class SuiListBox : public SuiBox {
public:
	SuiListBox();
	SuiListBox(ORBObjectServant* obj);
	SuiListBox(SuiListBox& ref);

	SuiListBox* clone();

	virtual ~SuiListBox();

	void addMenuItem(const string& item, unsigned long long objectID);

	int getMenuSize();

	unsigned long long getMenuObjectID(int idx);

	BaseMessage* generateMessage();

protected:
};

class SuiListBoxImplementation;

class SuiListBoxAdapter : public SuiBoxAdapter {
public:
	SuiListBoxAdapter(SuiListBoxImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, ORBMethodInvocation* inv);

	void addMenuItem(const string& item, unsigned long long objectID);

	int getMenuSize();

	unsigned long long getMenuObjectID(int idx);

	BaseMessage* generateMessage();

protected:
	string _param0_addMenuItem__string_long_;
};

class SuiListBoxHelper : public ORBClassHelper, public Singleton<SuiListBoxHelper> {
public:
	SuiListBoxHelper();

	void finalizeHelper();

	ORBObject* instantiateObject();

	ORBObjectAdapter* createAdapter(ORBObjectServant* obj);

	friend class SingletonWrapper<SuiListBoxHelper>;
};

#include "../SuiBoxImplementation.h"

class SuiListBoxServant : public SuiBoxImplementation {
public:
	SuiListBox* _this;

public:
	SuiListBoxServant(Player* play, unsigned int typeID, unsigned int boxtype);
	virtual ~SuiListBoxServant();

	void _setStub(ORBObjectStub* stub);
	ORBObjectStub* _getStub();

};

#endif /*SUILISTBOX_H_*/
