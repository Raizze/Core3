/*
 * TemplateManager.cpp
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#include "TemplateManager.h"
#include "TemplateCRCMap.h"
#include "PortalLayoutMap.h"

#include "server/zone/templates/SharedObjectTemplate.h"
#include "server/zone/templates/intangible/SharedConstructionContractObjectTemplate.h"
#include "server/zone/templates/intangible/SharedManufactureSchematicObjectTemplate.h"
#include "server/zone/templates/intangible/SharedDraftSchematicObjectTemplate.h"
#include "server/zone/templates/intangible/DraftSchematicObjectTemplate.h"
#include "server/zone/templates/intangible/SharedMissionDataObjectTemplate.h"
#include "server/zone/templates/intangible/SharedMissionListEntryObjectTemplate.h"
#include "server/zone/templates/intangible/SharedMissionObjectTemplate.h"
#include "server/zone/templates/intangible/SharedPlayerObjectTemplate.h"
#include "server/zone/templates/intangible/SharedTokenObjectTemplate.h"
#include "server/zone/templates/intangible/SharedWaypointObjectTemplate.h"
#include "server/zone/templates/tangible/SharedBattlefieldMarkerObjectTemplate.h"
#include "server/zone/templates/tangible/SharedBuildingObjectTemplate.h"
#include "server/zone/templates/tangible/SharedCountingObjectTemplate.h"
#include "server/zone/templates/tangible/NonPlayerCreatureObjectTemplate.h"
#include "server/zone/templates/tangible/SharedCreatureObjectTemplate.h"
#include "server/zone/templates/tangible/SharedFactoryObjectTemplate.h"
#include "server/zone/templates/tangible/SharedInstallationObjectTemplate.h"
#include "server/zone/templates/tangible/SharedResourceContainerObjectTemplate.h"
#include "server/zone/templates/tangible/SharedShipObjectTemplate.h"
#include "server/zone/templates/tangible/SharedWeaponObjectTemplate.h"
#include "server/zone/templates/tangible/StimPackTemplate.h"
#include "server/zone/templates/tangible/ConsumableTemplate.h"
#include "server/zone/templates/tangible/InstrumentObjectTemplate.h"
#include "server/zone/templates/tangible/RangedStimPackTemplate.h"
#include "server/zone/templates/tangible/EnhancePackTemplate.h"
#include "server/zone/templates/tangible/CurePackTemplate.h"
#include "server/zone/templates/tangible/StatePackTemplate.h"
#include "server/zone/templates/tangible/DotPackTemplate.h"
#include "server/zone/templates/tangible/WoundPackTemplate.h"
#include "server/zone/templates/tangible/ArmorObjectTemplate.h"
#include "server/zone/templates/tangible/CharacterBuilderTerminalTemplate.h"
#include "server/zone/templates/tangible/LootkitObjectTemplate.h"
#include "server/zone/templates/tangible/GamblingTerminalTemplate.h"
#include "server/zone/templates/tangible/FireworkObjectTemplate.h"
#include "server/zone/templates/tangible/LairObjectTemplate.h"
#include "server/zone/templates/tangible/CampKitTemplate.h"
#include "server/zone/templates/universe/SharedGroupObjectTemplate.h"
#include "server/zone/templates/universe/SharedGuildObjectTemplate.h"
#include "server/zone/templates/universe/SharedJediManagerTemplate.h"
#include "server/zone/templates/SharedCellObjectTemplate.h"
#include "server/zone/templates/SharedIntangibleObjectTemplate.h"
#include "server/zone/templates/SharedStaticObjectTemplate.h"
#include "server/zone/templates/SharedTangibleObjectTemplate.h"
#include "server/zone/templates/SharedUniverseObjectTemplate.h"
#include "server/zone/templates/tangible/tool/SurveyToolTemplate.h"
#include "server/zone/templates/tangible/tool/CraftingToolTemplate.h"
#include "server/zone/templates/tangible/tool/CraftingStationTemplate.h"
#include "server/zone/templates/tangible/CloningBuildingObjectTemplate.h"
#include "server/zone/templates/resource_container/ResourceSpawnTemplate.h"
#include "server/zone/templates/tangible/DeedTemplate.h"
#include "server/zone/templates/tangible/VehicleDeedTemplate.h"
#include "server/zone/templates/tangible/MissionTerminalTemplate.h"

#include "server/zone/templates/installation/FactoryObjectTemplate.h"

#include "server/zone/objects/tangible/wearables/ArmorObject.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/objects/creature/CreatureState.h"

#include "server/zone/templates/appearance/PortalLayout.h"
#include "server/zone/templates/appearance/FloorMesh.h"
#include "server/zone/templates/appearance/MeshAppearanceTemplate.h"

Lua* TemplateManager::luaTemplatesInstance = NULL;

TemplateManager::TemplateManager() {
	setLogging(false);
	setGlobalLogging(true);
	setLoggingName("TemplateManager");

	registerTemplateObjects();

	luaTemplatesInstance = new Lua();
	luaTemplatesInstance->init();

	templateCRCMap = new TemplateCRCMap();
	clientTemplateCRCMap = new ClientTemplateCRCMap();

	portalLayoutMap = new PortalLayoutMap();
	floorMeshMap = new FloorMeshMap();
	meshAppearanceMap = new MeshAppearanceMap();

	registerFunctions();
	registerGlobals();
}

TemplateManager::~TemplateManager() {
	delete templateCRCMap;
	templateCRCMap = NULL;

	delete clientTemplateCRCMap;
	clientTemplateCRCMap = NULL;

	delete luaTemplatesInstance;
	luaTemplatesInstance = NULL;

	delete portalLayoutMap;
	portalLayoutMap = NULL;

	delete floorMeshMap;
	floorMeshMap = NULL;
}

void TemplateManager::loadLuaTemplates() {
	info("loading object templates...", true);

	try {
		luaTemplatesInstance->runFile("scripts/object/main.lua");
	} catch (Exception& e) {
		error(e.getMessage());
		e.printStackTrace();
	} catch (...) {
		error("unreported exception caught while loading templates");
	}

	info("done loading object templates", true);
	info(String::valueOf(portalLayoutMap->size()) + " portal layouts loaded", true);
	info(String::valueOf(floorMeshMap->size()) + " floor meshes loaded", true);
}

void TemplateManager::addTemplate(uint32 key, const String& fullName, LuaObject* templateData) {
	uint32 templateType = templateData->getIntField("templateType");

	SharedObjectTemplate* templateObject = templateFactory.createObject(templateType);

	if (templateObject == NULL) {
		error("error creating template from lua with templateType 0x" + String::hexvalueOf((int)templateType));

		return;
	}

	//info("loading " + fullName);

	templateObject->setFullTemplateString(fullName);
	templateObject->readObject(templateData);

	//info("loaded " + fullName);

	if (templateCRCMap->put(key, templateObject) != NULL) {
		error("duplicate template for " + fullName);
	}
}

void TemplateManager::registerTemplateObjects() {
	templateFactory.registerObject<SharedObjectTemplate>(SharedObjectTemplate::SHOT);
	templateFactory.registerObject<SharedConstructionContractObjectTemplate>(SharedObjectTemplate::SCNC);
	templateFactory.registerObject<SharedDraftSchematicObjectTemplate>(SharedObjectTemplate::SDSC);
	templateFactory.registerObject<SharedManufactureSchematicObjectTemplate>(SharedObjectTemplate::SMSC);
	templateFactory.registerObject<SharedMissionDataObjectTemplate>(SharedObjectTemplate::SMSD);
	templateFactory.registerObject<SharedMissionListEntryObjectTemplate>(SharedObjectTemplate::SMLE);
	templateFactory.registerObject<SharedMissionObjectTemplate>(SharedObjectTemplate::SMSO);
	templateFactory.registerObject<SharedPlayerObjectTemplate>(SharedObjectTemplate::SPLY);
	templateFactory.registerObject<SharedTokenObjectTemplate>(SharedObjectTemplate::STOK);
	templateFactory.registerObject<SharedWaypointObjectTemplate>(SharedObjectTemplate::SWAY);
	templateFactory.registerObject<SharedBattlefieldMarkerObjectTemplate>(SharedObjectTemplate::SBMK);
	templateFactory.registerObject<SharedBuildingObjectTemplate>(SharedObjectTemplate::SBOT);
	templateFactory.registerObject<SharedCountingObjectTemplate>(SharedObjectTemplate::SCOU);
	templateFactory.registerObject<SharedCreatureObjectTemplate>(SharedObjectTemplate::SCOT);
	templateFactory.registerObject<SharedFactoryObjectTemplate>(SharedObjectTemplate::SFOT);
	templateFactory.registerObject<SharedInstallationObjectTemplate>(SharedObjectTemplate::SIOT);
	templateFactory.registerObject<SharedResourceContainerObjectTemplate>(SharedObjectTemplate::RCCT);
	templateFactory.registerObject<SharedShipObjectTemplate>(SharedObjectTemplate::SSHP);
	templateFactory.registerObject<SharedWeaponObjectTemplate>(SharedObjectTemplate::SWOT);
	templateFactory.registerObject<SharedGroupObjectTemplate>(SharedObjectTemplate::SGRP);
	templateFactory.registerObject<SharedGuildObjectTemplate>(SharedObjectTemplate::SGLD);
	templateFactory.registerObject<SharedJediManagerTemplate>(SharedObjectTemplate::SJED);
	templateFactory.registerObject<SharedCellObjectTemplate>(SharedObjectTemplate::CCLT);
	templateFactory.registerObject<SharedIntangibleObjectTemplate>(SharedObjectTemplate::SITN);
	templateFactory.registerObject<SharedStaticObjectTemplate>(SharedObjectTemplate::STAT);
	templateFactory.registerObject<SharedTangibleObjectTemplate>(SharedObjectTemplate::STOT);
	templateFactory.registerObject<SharedUniverseObjectTemplate>(SharedObjectTemplate::SUNI);
	templateFactory.registerObject<CharacterBuilderTerminalTemplate>(SharedObjectTemplate::CHARACTERBUILDERTERMINAL);
	templateFactory.registerObject<LootkitObjectTemplate>(SharedObjectTemplate::LOOTKIT);
	templateFactory.registerObject<GamblingTerminalTemplate>(SharedObjectTemplate::GAMBLINGTERMINAL);
	templateFactory.registerObject<FireworkObjectTemplate>(SharedObjectTemplate::FIREWORK);
	templateFactory.registerObject<SurveyToolTemplate>(SharedObjectTemplate::SURVEYTOOL);
	templateFactory.registerObject<CraftingToolTemplate>(SharedObjectTemplate::CRAFTINGTOOL);
	templateFactory.registerObject<CraftingStationTemplate>(SharedObjectTemplate::CRAFTINGSTATION);
	templateFactory.registerObject<ResourceSpawnTemplate>(SharedObjectTemplate::RESOURCESPAWN);
	templateFactory.registerObject<ArmorObjectTemplate>(SharedObjectTemplate::ARMOROBJECT);
	templateFactory.registerObject<DeedTemplate>(SharedObjectTemplate::DEED);
	templateFactory.registerObject<VehicleDeedTemplate>(SharedObjectTemplate::VEHICLEDEED);
	templateFactory.registerObject<MissionTerminalTemplate>(SharedObjectTemplate::MISSIONTERMINAL);
	templateFactory.registerObject<CloningBuildingObjectTemplate>(SharedObjectTemplate::CLONINGBUILDING);
	templateFactory.registerObject<DraftSchematicObjectTemplate>(SharedObjectTemplate::DRAFTSCHEMATIC);
	templateFactory.registerObject<NonPlayerCreatureObjectTemplate>(SharedObjectTemplate::NPCCREATURE);
	templateFactory.registerObject<LairObjectTemplate>(SharedObjectTemplate::LAIRTEMPLATE);
	templateFactory.registerObject<FactoryObjectTemplate>(SharedObjectTemplate::FACTORY);
	templateFactory.registerObject<StimPackTemplate>(SharedObjectTemplate::STIMPACK);
	templateFactory.registerObject<RangedStimPackTemplate>(SharedObjectTemplate::RANGEDSTIMPACK);
	templateFactory.registerObject<EnhancePackTemplate>(SharedObjectTemplate::ENHANCEPACK);
	templateFactory.registerObject<CurePackTemplate>(SharedObjectTemplate::CUREPACK);
	templateFactory.registerObject<DotPackTemplate>(SharedObjectTemplate::DOTPACK);
	templateFactory.registerObject<WoundPackTemplate>(SharedObjectTemplate::WOUNDPACK);
	templateFactory.registerObject<StatePackTemplate>(SharedObjectTemplate::STATEPACK);
	templateFactory.registerObject<ConsumableTemplate>(SharedObjectTemplate::CONSUMABLE);
	templateFactory.registerObject<InstrumentObjectTemplate>(SharedObjectTemplate::INSTRUMENT);
	templateFactory.registerObject<CampKitTemplate>(SharedObjectTemplate::CAMPKIT);

}


void TemplateManager::registerFunctions() {
	//lua generic
	lua_register(luaTemplatesInstance->getLuaState(), "includeFile", includeFile);
	lua_register(luaTemplatesInstance->getLuaState(), "crcString", crcString);
	lua_register(luaTemplatesInstance->getLuaState(), "addTemplateCRC", addTemplateCRC);
	lua_register(luaTemplatesInstance->getLuaState(), "addClientTemplate", addClientTemplate);
}

void TemplateManager::registerGlobals() {
	//ItemMasks
	luaTemplatesInstance->setGlobalShort("MALE", WearableObject::MALE);
	luaTemplatesInstance->setGlobalShort("FEMALE", WearableObject::FEMALE);

	luaTemplatesInstance->setGlobalShort("HUMAN", WearableObject::HUMAN);
	luaTemplatesInstance->setGlobalShort("TRANDOSHAN", WearableObject::TRANDOSHAN);
	luaTemplatesInstance->setGlobalShort("TWILEK", WearableObject::TWILEK);
	luaTemplatesInstance->setGlobalShort("BOTHAN", WearableObject::BOTHAN);
	luaTemplatesInstance->setGlobalShort("ZABRAK", WearableObject::ZABRAK);
	luaTemplatesInstance->setGlobalShort("RODIAN", WearableObject::RODIAN);
	luaTemplatesInstance->setGlobalShort("MONCALAMARI", WearableObject::MONCALAMARI);
	luaTemplatesInstance->setGlobalShort("WOOKIEE", WearableObject::WOOKIEE);
	luaTemplatesInstance->setGlobalShort("SULLUSTAN", WearableObject::SULLUSTAN);
	luaTemplatesInstance->setGlobalShort("ITHORIAN", WearableObject::ITHORIAN);

	luaTemplatesInstance->setGlobalLong("DISEASED", CreatureState::DISEASED);
	luaTemplatesInstance->setGlobalLong("ONFIRE", CreatureState::ONFIRE);
	luaTemplatesInstance->setGlobalLong("POISONED", CreatureState::POISONED);
	luaTemplatesInstance->setGlobalLong("BLINDED", CreatureState::BLINDED);
	luaTemplatesInstance->setGlobalLong("STUNNED", CreatureState::STUNNED);
	luaTemplatesInstance->setGlobalLong("DIZZY", CreatureState::DIZZY);
	luaTemplatesInstance->setGlobalLong("INTIMIDATED", CreatureState::INTIMIDATED);

	luaTemplatesInstance->setGlobalShort("NEUTRAL", WearableObject::NEUTRAL);
	luaTemplatesInstance->setGlobalShort("IMPERIAL", WearableObject::IMPERIAL);
	luaTemplatesInstance->setGlobalShort("REBEL", WearableObject::REBEL);
	luaTemplatesInstance->setGlobalShort("COVERT", WearableObject::COVERT);

	luaTemplatesInstance->setGlobalShort("ALL", WearableObject::ALL);
	luaTemplatesInstance->setGlobalShort("ALLSEXES",  WearableObject::ALLSEXES);
	luaTemplatesInstance->setGlobalShort("ALLFACTIONS", WearableObject::ALLFACTIONS);
	luaTemplatesInstance->setGlobalShort("HUMANOIDS", WearableObject::HUMANOIDS);
	luaTemplatesInstance->setGlobalShort("HUMANOID_FOOTWEAR", WearableObject::HUMANOID_FOOTWEAR);
	luaTemplatesInstance->setGlobalShort("HUMANOID_MALES", WearableObject::HUMANOID_MALES);
	luaTemplatesInstance->setGlobalShort("HUMANOID_FEMALES", WearableObject::HUMANOID_FEMALES);
	luaTemplatesInstance->setGlobalShort("HUMANOID_IMPERIALS", WearableObject::HUMANOID_IMPERIALS);
	luaTemplatesInstance->setGlobalShort("HUMANOID_REBELS", WearableObject::HUMANOID_REBELS);
	luaTemplatesInstance->setGlobalShort("WOOKIEES", WearableObject::WOOKIEES);
	luaTemplatesInstance->setGlobalShort("ITHORIANS", WearableObject::ITHORIANS);
	luaTemplatesInstance->setGlobalShort("TWILEKS", WearableObject::TWILEKS);

	luaTemplatesInstance->setGlobalInt("KINETIC", WeaponObject::KINETIC);
	luaTemplatesInstance->setGlobalInt("ENERGY", WeaponObject::ENERGY);
	luaTemplatesInstance->setGlobalInt("ELECTRICITY", WeaponObject::ELECTRICITY);
	luaTemplatesInstance->setGlobalInt("STUN", WeaponObject::STUN);
	luaTemplatesInstance->setGlobalInt("BLAST", WeaponObject::BLAST);
	luaTemplatesInstance->setGlobalInt("HEAT", WeaponObject::HEAT);
	luaTemplatesInstance->setGlobalInt("COLD", WeaponObject::COLD);
	luaTemplatesInstance->setGlobalInt("ACID", WeaponObject::ACID);
	luaTemplatesInstance->setGlobalInt("LIGHTSABER", WeaponObject::LIGHTSABER);
	luaTemplatesInstance->setGlobalInt("FORCE", WeaponObject::FORCE);

	luaTemplatesInstance->setGlobalInt("NONE", WeaponObject::NONE);
	luaTemplatesInstance->setGlobalInt("LIGHT", WeaponObject::LIGHT);
	luaTemplatesInstance->setGlobalInt("MEDIUM", WeaponObject::MEDIUM);
	luaTemplatesInstance->setGlobalInt("HEAVY", WeaponObject::HEAVY);

	luaTemplatesInstance->setGlobalInt("MELEEATTACK", WeaponObject::MELEEATTACK);
	luaTemplatesInstance->setGlobalInt("RANGEDATTACK", WeaponObject::RANGEDATTACK);
	luaTemplatesInstance->setGlobalInt("FORCEATTACK", WeaponObject::FORCEATTACK);
	luaTemplatesInstance->setGlobalInt("TRAPATTACK", WeaponObject::TRAPATTACK);
	luaTemplatesInstance->setGlobalInt("GRENADEATTACK", WeaponObject::GRENADEATTACK);
	luaTemplatesInstance->setGlobalInt("HEAVYACIDBEAMATTACK", WeaponObject::HEAVYACIDBEAMATTACK);
	luaTemplatesInstance->setGlobalInt("HEAVYLIGHTNINGBEAMATTACK", WeaponObject::HEAVYLIGHTNINGBEAMATTACK);
	luaTemplatesInstance->setGlobalInt("HEAVYPARTICLEBEAMATTACK", WeaponObject::HEAVYPARTICLEBEAMATTACK);
	luaTemplatesInstance->setGlobalInt("HEAVYROCKETLAUNCHERATTACK", WeaponObject::HEAVYROCKETLAUNCHERATTACK);
	luaTemplatesInstance->setGlobalInt("HEAVYLAUNCHERATTACK", WeaponObject::HEAVYLAUNCHERATTACK);

	luaTemplatesInstance->setGlobalInt("SHOT", SharedObjectTemplate::SHOT);
	luaTemplatesInstance->setGlobalInt("STOT", SharedObjectTemplate::STOT);
	luaTemplatesInstance->setGlobalInt("SBMK", SharedObjectTemplate::SBMK);
	luaTemplatesInstance->setGlobalInt("SBOT", SharedObjectTemplate::SBOT);
	luaTemplatesInstance->setGlobalInt("STAT", SharedObjectTemplate::STAT);
	luaTemplatesInstance->setGlobalInt("SIOT", SharedObjectTemplate::SIOT);
	luaTemplatesInstance->setGlobalInt("CCLT", SharedObjectTemplate::CCLT);
	luaTemplatesInstance->setGlobalInt("SCOU", SharedObjectTemplate::SCOU);
	luaTemplatesInstance->setGlobalInt("SDSC", SharedObjectTemplate::SDSC);
	luaTemplatesInstance->setGlobalInt("SFOT", SharedObjectTemplate::SFOT);
	luaTemplatesInstance->setGlobalInt("SGRP", SharedObjectTemplate::SGRP);
	luaTemplatesInstance->setGlobalInt("SITN", SharedObjectTemplate::SITN);
	luaTemplatesInstance->setGlobalInt("SGLD", SharedObjectTemplate::SGLD);
	luaTemplatesInstance->setGlobalInt("SJED", SharedObjectTemplate::SJED);
	luaTemplatesInstance->setGlobalInt("SMSC", SharedObjectTemplate::SMSC);
	luaTemplatesInstance->setGlobalInt("SMSO", SharedObjectTemplate::SMSO);
	luaTemplatesInstance->setGlobalInt("SMSD", SharedObjectTemplate::SMSD);
	luaTemplatesInstance->setGlobalInt("SMLE", SharedObjectTemplate::SMLE);
	luaTemplatesInstance->setGlobalInt("SPLY", SharedObjectTemplate::SPLY);
	luaTemplatesInstance->setGlobalInt("RCCT", SharedObjectTemplate::RCCT);
	luaTemplatesInstance->setGlobalInt("SSHP", SharedObjectTemplate::SSHP);
	luaTemplatesInstance->setGlobalInt("SUNI", SharedObjectTemplate::SUNI);
	luaTemplatesInstance->setGlobalInt("SWAY", SharedObjectTemplate::SWAY);
	luaTemplatesInstance->setGlobalInt("STOK", SharedObjectTemplate::STOK);
	luaTemplatesInstance->setGlobalInt("SWOT", SharedObjectTemplate::SWOT);
	luaTemplatesInstance->setGlobalInt("SCNC", SharedObjectTemplate::SCNC);
	luaTemplatesInstance->setGlobalInt("SCOT", SharedObjectTemplate::SCOT);
	luaTemplatesInstance->setGlobalInt("CHARACTERBUILDERTERMINAL", SharedObjectTemplate::CHARACTERBUILDERTERMINAL);
	luaTemplatesInstance->setGlobalInt("LOOTKIT", SharedObjectTemplate::LOOTKIT);
	luaTemplatesInstance->setGlobalInt("GAMBLINGTERMINAL", SharedObjectTemplate::GAMBLINGTERMINAL);
	luaTemplatesInstance->setGlobalInt("FIREWORK", SharedObjectTemplate::FIREWORK);
	luaTemplatesInstance->setGlobalInt("SURVEYTOOL", SharedObjectTemplate::SURVEYTOOL);
	luaTemplatesInstance->setGlobalInt("CRAFTINGTOOL", SharedObjectTemplate::CRAFTINGTOOL);
	luaTemplatesInstance->setGlobalInt("CRAFTINGSTATION", SharedObjectTemplate::CRAFTINGSTATION);
	luaTemplatesInstance->setGlobalInt("RESOURCESPAWN", SharedObjectTemplate::RESOURCESPAWN);
	luaTemplatesInstance->setGlobalInt("ARMOROBJECT", SharedObjectTemplate::ARMOROBJECT);
	luaTemplatesInstance->setGlobalInt("DEED", SharedObjectTemplate::DEED);
	luaTemplatesInstance->setGlobalInt("VEHICLEDEED", SharedObjectTemplate::VEHICLEDEED);
	luaTemplatesInstance->setGlobalInt("MISSIONTERMINAL", SharedObjectTemplate::MISSIONTERMINAL);
	luaTemplatesInstance->setGlobalInt("CLONINGBUILDING", SharedObjectTemplate::CLONINGBUILDING);
	luaTemplatesInstance->setGlobalInt("DRAFTSCHEMATIC", SharedObjectTemplate::DRAFTSCHEMATIC);
	luaTemplatesInstance->setGlobalInt("NPCCREATURE", SharedObjectTemplate::NPCCREATURE);
	luaTemplatesInstance->setGlobalInt("LAIRTEMPLATE", SharedObjectTemplate::LAIRTEMPLATE);
	luaTemplatesInstance->setGlobalInt("FACTORY", SharedObjectTemplate::FACTORY);
	luaTemplatesInstance->setGlobalInt("STIMPACK", SharedObjectTemplate::STIMPACK);
	luaTemplatesInstance->setGlobalInt("RANGEDSTIMPACK", SharedObjectTemplate::RANGEDSTIMPACK);
	luaTemplatesInstance->setGlobalInt("ENHANCEPACK", SharedObjectTemplate::ENHANCEPACK);
	luaTemplatesInstance->setGlobalInt("CUREPACK", SharedObjectTemplate::CUREPACK);
	luaTemplatesInstance->setGlobalInt("DOTPACK", SharedObjectTemplate::DOTPACK);
	luaTemplatesInstance->setGlobalInt("WOUNDPACK", SharedObjectTemplate::WOUNDPACK);
	luaTemplatesInstance->setGlobalInt("STATEPACK", SharedObjectTemplate::STATEPACK);
	luaTemplatesInstance->setGlobalInt("CONSUMABLE", SharedObjectTemplate::CONSUMABLE);
	luaTemplatesInstance->setGlobalInt("INSTRUMENT", SharedObjectTemplate::INSTRUMENT);
	luaTemplatesInstance->setGlobalInt("CAMPKIT", SharedObjectTemplate::CAMPKIT);
}

String TemplateManager::getTemplateFile(uint32 key) {
	SharedObjectTemplate* templateData = templateCRCMap->get(key);

	if (templateData == NULL) {
		String ascii = clientTemplateCRCMap->get(key);

		if (ascii.isEmpty())
			throw Exception("TemplateManager::getTemplateFile exception unknown template key 0x" + String::hexvalueOf((int)key));
		else
			return ascii;
	}

	return templateData->getFullTemplateString();
}

IffStream* TemplateManager::openIffFile(const String& fileName) {
	String correctedFileName = "scripts/" + fileName;

	IffStream* iffStream = NULL;

	try {
		iffStream = new IffStream(correctedFileName);
	} catch (...) {
		iffStream = NULL;

		info("could not open " + correctedFileName);

		return NULL;
	}

	if (iffStream != NULL) {
		try {
			if (!iffStream->parseChunks()) {
				delete iffStream;
				return NULL;
			}
		} catch (...) {
			delete iffStream;
			return NULL;
		}
	}

	return iffStream;
}

FloorMesh* TemplateManager::getFloorMesh(const String& fileName) {
	FloorMesh* floorMesh = floorMeshMap->get(fileName);

	if (floorMesh == NULL) {
		// read file

		IffStream* iffStream = openIffFile(fileName);

		if (iffStream != NULL) {
			try {
				floorMesh = new FloorMesh();

				floorMesh->readObject(iffStream);

				info("parsed " + fileName);
			} catch (...) {
				info("could not parse " + fileName);
				delete floorMesh;
				floorMesh = NULL;
			}

			delete iffStream;
			iffStream = NULL;

			floorMeshMap->put(fileName, floorMesh);
		}
	}

	return floorMesh;
	//return NULL;
}

MeshAppearanceTemplate* TemplateManager::getMeshAppearanceTemplate(const String& fileName) {
	MeshAppearanceTemplate* meshAppearance = meshAppearanceMap->get(fileName);

	if (meshAppearance == NULL) {
		IffStream* iffStream = openIffFile(fileName);

		if (iffStream != NULL) {
			try {
				meshAppearance = new MeshAppearanceTemplate();

				meshAppearance->readObject(iffStream);

				info("parsed " + fileName);
			} catch (...) {
				info("could not parse " + fileName);
				delete meshAppearance;
				meshAppearance = NULL;
			}

			delete iffStream;
			iffStream = NULL;

			meshAppearanceMap->put(fileName, meshAppearance);
		}
	}

	return meshAppearance;
}

PortalLayout* TemplateManager::getPortalLayout(const String& fileName) {
	PortalLayout* portalLayout = portalLayoutMap->get(fileName);

	if (portalLayout == NULL) {
		IffStream* iffStream = openIffFile(fileName);

		if (iffStream != NULL) {
			try {
				portalLayout = new PortalLayout();

				portalLayout->readObject(iffStream);

				info("parsed " + fileName);
			} catch (...) {
				info("could not parse " + fileName);
				delete portalLayout;
				portalLayout = NULL;
			}

			delete iffStream;
			iffStream = NULL;

			portalLayoutMap->put(fileName, portalLayout);
		}
	}

	return portalLayout;
	//return NULL;
}

SharedObjectTemplate* TemplateManager::getTemplate(uint32 key) {
	return templateCRCMap->get(key);
}

bool TemplateManager::existsTemplate(uint32 key) {
	return templateCRCMap->containsKey(key);
}

int TemplateManager::includeFile(lua_State* L) {
	String filename = Lua::getStringParameter(L);

	Lua::runFile("scripts/object/" + filename, L);

	return 0;
}

int TemplateManager::crcString(lua_State* L) {
	String ascii = Lua::getStringParameter(L);

	uint32 crc = ascii.hashCode();

	lua_pushnumber(L, crc);

	return 1;
}

int TemplateManager::addTemplateCRC(lua_State* L) {
	String ascii =  lua_tostring(L, -2);

	LuaObject obj(L);

	uint32 crc = (uint32) ascii.hashCode();

	TemplateManager::instance()->addTemplate(crc, ascii, &obj);

	//System::out << ascii << endl;

	return 0;
}

int TemplateManager::addClientTemplate(lua_State* L) {
	String ascii = lua_tostring(L, -2);

	uint32 crc = (uint32) ascii.hashCode();

	TemplateManager::instance()->clientTemplateCRCMap->put(crc, ascii);

	return 0;
}
