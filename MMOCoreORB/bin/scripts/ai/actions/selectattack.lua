SelectAttack = Ai:new {}

function SelectAttack:checkConditions(pAgent)
	if (pAgent ~= nil) then
		local creature = LuaCreatureObject(pAgent)
		
		if (creature:isDead()) then
			local agent = LuaAiAgent(pAgent)
			agent:removeDefenders()
			agent:setFollowObject(nil)
			return false
		end
		
		if (creature:getQueueSize() > 3) then
			return false
		end
		
		return true
	end
	return false
end

function SelectAttack:doAction(pAgent)
	if (pAgent ~= nil) then
		local agent = LuaAiAgent(pAgent)
		local creature = LuaCreatureObject(pAgent)
		
		agent:selectSpecialAttack(-1)
		if (not agent:validateStateAttack() or math.random(5) == 1) then
			agent:selectDefaultAttack()
		end
		
		agent:enqueueAttack()
		
		return BEHAVIOR_SUCCESS
	end
	return BEHAVIOR_FAILURE
end

addAiBehavior("SelectAttack")