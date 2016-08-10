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
	item_id = 90003,
	max_lvl = 60
};

bool Item_Level(Player* player, Item* item, const SpellCastTargets &)
{
	if (player->GetMap()->IsBattleGround())
	{
		player->GetSession()->SendNotification("你现在还不能使用这个物品　");
		return false;
	}
	if (player->getLevel() == max_lvl)
	{
		player->GetSession()->SendNotification("等级已达上限　");
		return false;
	}
	int32 addlevel = 1;
	int32 oldlevel = player->getLevel();
	int32 newlevel = oldlevel + addlevel;
	player->GiveLevel(newlevel);
	player->InitTalentForLevel();
	player->SetUInt32Value(PLAYER_XP, 0);
	player->DestroyItemCount(item_id, 1, true);
	player->GetSession()->SendNotification("升级成功　");
	player->CastSpell(player, 27741, true);
	return true;
};


void AddSC_Item_Level()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "item_level";
	pNewScript->pItemUse = Item_Level;
	pNewScript->RegisterSelf();
}