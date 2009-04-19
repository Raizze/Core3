/*
 *	server/zone/managers/resource/ResourceSpawn.h generated by engine3 IDL compiler 0.55
 */

#ifndef RESOURCESPAWN_H_
#define RESOURCESPAWN_H_

#include "engine/orb/DistributedObjectBroker.h"

class ResourceSpawn;

class SpawnLocation;

class SceneObject;

#include "../../objects/scene/SceneObject.h"

class ResourceSpawn : public SceneObject {
public:
	ResourceSpawn(String& inType);

	void addSpawnLocation(SpawnLocation* location);

	SpawnLocation* removeSpawnLocation(unsigned int oid);

	SpawnLocation* getSpawnLocation(int i);

	int getSpawnLocationSize();

	void setName(const String& inString);

	void setClass1(const String& inString);

	void setClass2(const String& inString);

	void setClass3(const String& inString);

	void setClass4(const String& inString);

	void setClass5(const String& inString);

	void setClass6(const String& inString);

	void setClass7(const String& inString);

	void setAtt1(const String& inString);

	void setAtt2(const String& inString);

	void setAtt3(const String& inString);

	void setAtt4(const String& inString);

	void setAtt5(const String& inString);

	void setAtt6(const String& inString);

	void setAtt7(const String& inString);

	void setAtt8(const String& inString);

	void setAtt9(const String& inString);

	void setAtt10(const String& inString);

	void setAtt11(const String& inString);

	void setAtt1Stat(int inInt);

	void setAtt2Stat(int inInt);

	void setAtt3Stat(int inInt);

	void setAtt4Stat(int inInt);

	void setAtt5Stat(int inInt);

	void setAtt6Stat(int inInt);

	void setAtt7Stat(int inInt);

	void setAtt8Stat(int inInt);

	void setAtt9Stat(int inInt);

	void setAtt10Stat(int inInt);

	void setAtt11Stat(int inInt);

	void setMaxType(int inInt);

	void setMinType(int inInt);

	void setMaxPool(int inInt);

	void setMinPool(int inInt);

	void setContainerName(const String& inString);

	String& getName();

	String& getType();

	String& getClass1();

	String& getClass2();

	String& getClass3();

	String& getClass4();

	String& getClass5();

	String& getClass6();

	String& getClass7();

	String& getAtt1();

	String& getAtt2();

	String& getAtt3();

	String& getAtt4();

	String& getAtt5();

	String& getAtt6();

	String& getAtt7();

	String& getAtt8();

	String& getAtt9();

	String& getAtt10();

	String& getAtt11();

	int getAtt1Stat();

	int getAtt2Stat();

	int getAtt3Stat();

	int getAtt4Stat();

	int getAtt5Stat();

	int getAtt6Stat();

	int getAtt7Stat();

	int getAtt8Stat();

	int getAtt9Stat();

	int getAtt10Stat();

	int getAtt11Stat();

	int getMaxType();

	int getMinType();

	int getMaxPool();

	int getMinPool();

	String& getContainerName();

	void toString();

protected:
	ResourceSpawn(DummyConstructorParameter* param);

	virtual ~ResourceSpawn();

	String _return_getAtt1;
	String _return_getAtt10;
	String _return_getAtt11;
	String _return_getAtt2;
	String _return_getAtt3;
	String _return_getAtt4;
	String _return_getAtt5;
	String _return_getAtt6;
	String _return_getAtt7;
	String _return_getAtt8;
	String _return_getAtt9;
	String _return_getClass1;
	String _return_getClass2;
	String _return_getClass3;
	String _return_getClass4;
	String _return_getClass5;
	String _return_getClass6;
	String _return_getClass7;
	String _return_getContainerName;
	String _return_getName;
	String _return_getType;

	friend class ResourceSpawnHelper;
};

class ResourceSpawnImplementation;

class ResourceSpawnAdapter : public SceneObjectAdapter {
public:
	ResourceSpawnAdapter(ResourceSpawnImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void addSpawnLocation(SpawnLocation* location);

	SpawnLocation* removeSpawnLocation(unsigned int oid);

	SpawnLocation* getSpawnLocation(int i);

	int getSpawnLocationSize();

	void setName(const String& inString);

	void setClass1(const String& inString);

	void setClass2(const String& inString);

	void setClass3(const String& inString);

	void setClass4(const String& inString);

	void setClass5(const String& inString);

	void setClass6(const String& inString);

	void setClass7(const String& inString);

	void setAtt1(const String& inString);

	void setAtt2(const String& inString);

	void setAtt3(const String& inString);

	void setAtt4(const String& inString);

	void setAtt5(const String& inString);

	void setAtt6(const String& inString);

	void setAtt7(const String& inString);

	void setAtt8(const String& inString);

	void setAtt9(const String& inString);

	void setAtt10(const String& inString);

	void setAtt11(const String& inString);

	void setAtt1Stat(int inInt);

	void setAtt2Stat(int inInt);

	void setAtt3Stat(int inInt);

	void setAtt4Stat(int inInt);

	void setAtt5Stat(int inInt);

	void setAtt6Stat(int inInt);

	void setAtt7Stat(int inInt);

	void setAtt8Stat(int inInt);

	void setAtt9Stat(int inInt);

	void setAtt10Stat(int inInt);

	void setAtt11Stat(int inInt);

	void setMaxType(int inInt);

	void setMinType(int inInt);

	void setMaxPool(int inInt);

	void setMinPool(int inInt);

	void setContainerName(const String& inString);

	String& getName();

	String& getType();

	String& getClass1();

	String& getClass2();

	String& getClass3();

	String& getClass4();

	String& getClass5();

	String& getClass6();

	String& getClass7();

	String& getAtt1();

	String& getAtt2();

	String& getAtt3();

	String& getAtt4();

	String& getAtt5();

	String& getAtt6();

	String& getAtt7();

	String& getAtt8();

	String& getAtt9();

	String& getAtt10();

	String& getAtt11();

	int getAtt1Stat();

	int getAtt2Stat();

	int getAtt3Stat();

	int getAtt4Stat();

	int getAtt5Stat();

	int getAtt6Stat();

	int getAtt7Stat();

	int getAtt8Stat();

	int getAtt9Stat();

	int getAtt10Stat();

	int getAtt11Stat();

	int getMaxType();

	int getMinType();

	int getMaxPool();

	int getMinPool();

	String& getContainerName();

	void toString();

protected:
	String _param0_setName__String_;
	String _param0_setClass1__String_;
	String _param0_setClass2__String_;
	String _param0_setClass3__String_;
	String _param0_setClass4__String_;
	String _param0_setClass5__String_;
	String _param0_setClass6__String_;
	String _param0_setClass7__String_;
	String _param0_setAtt1__String_;
	String _param0_setAtt2__String_;
	String _param0_setAtt3__String_;
	String _param0_setAtt4__String_;
	String _param0_setAtt5__String_;
	String _param0_setAtt6__String_;
	String _param0_setAtt7__String_;
	String _param0_setAtt8__String_;
	String _param0_setAtt9__String_;
	String _param0_setAtt10__String_;
	String _param0_setAtt11__String_;
	String _param0_setContainerName__String_;
};

class ResourceSpawnHelper : public DistributedObjectClassHelper, public Singleton<ResourceSpawnHelper> {
	static ResourceSpawnHelper* staticInitializer;

public:
	ResourceSpawnHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<ResourceSpawnHelper>;
};

#include "../../objects/scene/SceneObjectImplementation.h"

class ResourceSpawnServant : public SceneObjectImplementation {
public:
	ResourceSpawn* _this;

public:
	ResourceSpawnServant();
	virtual ~ResourceSpawnServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*RESOURCESPAWN_H_*/
