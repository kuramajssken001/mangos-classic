/*
_______        _         ______
|__   __|      | |       |  ____|
| | __ _ ___| |_ _   _| |__   _ __ ___  _   _
| |/ _` / __| __| | | |  __| | '_ ` _ \| | | |
| | (_| \__ \ |_| |_| | |____| | | | | | |_| |
|_|\__,_|___/\__|\__, |______|_| |_| |_|\__,_|
__/ |
|___/

Script Made By Sinistah
Special Thanks To LilleCarl For The Code Snippet

Legend
------
item_id = the item id of the item ur using.
max_lvl = the max lvl the script will allow players to use the item.
lvl = how many levels the item will grant upon used
*/
#include "Player.h"
#include "DBCStructure.h"
#include "precompiled.h"

enum
{
	item_id = 90004
};
bool Item_Talent(Player* player, Item* item, const SpellCastTargets &)
{
	if (player->GetMap()->IsBattleGround() || player->isInCombat())
	{
		player->GetSession()->SendNotification("你现在还不能使用这个物品　");
		return false;
	}
	player->resetTalents(true);
	//player->DestroyItemCount(item_id, 1, true);
	player->GetSession()->SendNotification("天赋点重置成功　");
	player->CastSpell(player, 27741, true);
	return true;
};


void AddSC_Item_Talent()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "item_talent";
	pNewScript->pItemUse = Item_Talent;
	pNewScript->RegisterSelf();
}