/*
 *	server/zone/objects/installation/garage/GarageInstallation.cpp generated by engine3 IDL compiler 0.60
 */

#include "GarageInstallation.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	GarageInstallationStub
 */

enum {RPC_CREATECHILDOBJECTS__ = 6,RPC_DESTROYOBJECTFROMDATABASE__BOOL_};

GarageInstallation::GarageInstallation() : InstallationObject(DummyConstructorParameter::instance()) {
	GarageInstallationImplementation* _implementation = new GarageInstallationImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

GarageInstallation::GarageInstallation(DummyConstructorParameter* param) : InstallationObject(param) {
}

GarageInstallation::~GarageInstallation() {
}


void GarageInstallation::createChildObjects() {
	GarageInstallationImplementation* _implementation = (GarageInstallationImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATECHILDOBJECTS__);

		method.executeWithVoidReturn();
	} else
		_implementation->createChildObjects();
}

void GarageInstallation::destroyObjectFromDatabase(bool destroyContainedObjects) {
	GarageInstallationImplementation* _implementation = (GarageInstallationImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DESTROYOBJECTFROMDATABASE__BOOL_);
		method.addBooleanParameter(destroyContainedObjects);

		method.executeWithVoidReturn();
	} else
		_implementation->destroyObjectFromDatabase(destroyContainedObjects);
}

DistributedObjectServant* GarageInstallation::_getImplementation() {

	_updated = true;
	return _impl;
}

void GarageInstallation::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	GarageInstallationImplementation
 */

GarageInstallationImplementation::GarageInstallationImplementation(DummyConstructorParameter* param) : InstallationObjectImplementation(param) {
	_initializeImplementation();
}


GarageInstallationImplementation::~GarageInstallationImplementation() {
}


void GarageInstallationImplementation::finalize() {
}

void GarageInstallationImplementation::_initializeImplementation() {
	_setClassHelper(GarageInstallationHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void GarageInstallationImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GarageInstallation*) stub;
	InstallationObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GarageInstallationImplementation::_getStub() {
	return _this;
}

GarageInstallationImplementation::operator const GarageInstallation*() {
	return _this;
}

void GarageInstallationImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void GarageInstallationImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void GarageInstallationImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void GarageInstallationImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void GarageInstallationImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void GarageInstallationImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void GarageInstallationImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void GarageInstallationImplementation::_serializationHelperMethod() {
	InstallationObjectImplementation::_serializationHelperMethod();

	_setClassName("GarageInstallation");

}

void GarageInstallationImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(GarageInstallationImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool GarageInstallationImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (InstallationObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "garageArea") {
		TypeInfo<ManagedReference<ActiveArea* > >::parseFromBinaryStream(&garageArea, stream);
		return true;
	}


	return false;
}

void GarageInstallationImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = GarageInstallationImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int GarageInstallationImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "garageArea";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ActiveArea* > >::toBinaryStream(&garageArea, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + InstallationObjectImplementation::writeObjectMembers(stream);
}

GarageInstallationImplementation::GarageInstallationImplementation() {
	_initializeImplementation();
	// server/zone/objects/installation/garage/GarageInstallation.idl():  		setLoggingName("ShuttleInstallation");
	setLoggingName("ShuttleInstallation");
}

/*
 *	GarageInstallationAdapter
 */

GarageInstallationAdapter::GarageInstallationAdapter(GarageInstallationImplementation* obj) : InstallationObjectAdapter(obj) {
}

Packet* GarageInstallationAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_CREATECHILDOBJECTS__:
		createChildObjects();
		break;
	case RPC_DESTROYOBJECTFROMDATABASE__BOOL_:
		destroyObjectFromDatabase(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void GarageInstallationAdapter::createChildObjects() {
	((GarageInstallationImplementation*) impl)->createChildObjects();
}

void GarageInstallationAdapter::destroyObjectFromDatabase(bool destroyContainedObjects) {
	((GarageInstallationImplementation*) impl)->destroyObjectFromDatabase(destroyContainedObjects);
}

/*
 *	GarageInstallationHelper
 */

GarageInstallationHelper* GarageInstallationHelper::staticInitializer = GarageInstallationHelper::instance();

GarageInstallationHelper::GarageInstallationHelper() {
	className = "GarageInstallation";

	Core::getObjectBroker()->registerClass(className, this);
}

void GarageInstallationHelper::finalizeHelper() {
	GarageInstallationHelper::finalize();
}

DistributedObject* GarageInstallationHelper::instantiateObject() {
	return new GarageInstallation(DummyConstructorParameter::instance());
}

DistributedObjectServant* GarageInstallationHelper::instantiateServant() {
	return new GarageInstallationImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GarageInstallationHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GarageInstallationAdapter((GarageInstallationImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

