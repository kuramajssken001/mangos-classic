#include "precompiled.h"
#include "Player.h"
#include "Spell.h"
#include "Language.h"
#include "../system/system.h"
#include "../../include/sc_gossip.h"
#include "../../../game/GossipDef.h"

uint32 Skill_Type = 0;   //技能类型
#define SETSKILL_MAXVAL           300          //商业技能最大值

bool JianCheTJ2(Player* player)
{
	if (player->getLevel() != 60)
	{
		ChatHandler(player->GetSession()).PSendSysMessage(LANG_JIAOBEN_16);
		player->CLOSE_GOSSIP_MENU();
		return false;
	}
	if (player->GetGroup())
	{
		ChatHandler(player->GetSession()).PSendSysMessage(LANG_JIAOBEN_17);
		player->CLOSE_GOSSIP_MENU();
		return false;
	}
	if (player->GetGuildId())
	{
		ChatHandler(player->GetSession()).PSendSysMessage(LANG_JIAOBEN_18);
		player->CLOSE_GOSSIP_MENU();
		return false;
	}

	return true;
}

bool GossipHello_test_item(Player *pPlayer, Item* _Item)
{
	if (!pPlayer)
		return true;

	if (pPlayer->isInCombat())
	{
		pPlayer->CLOSE_GOSSIP_MENU();
	}
	if (pPlayer->IsTaxiFlying() || pPlayer->IsMounted())
	{
		pPlayer->CLOSE_GOSSIP_MENU();
	}
	char *tmp = new char[100];
	sprintf(tmp, "|cFF0041FF当前帐户：[%d]积分|r　", pPlayer->Getjf());
	pPlayer->ADD_GOSSIP_ITEM(4, tmp, GOSSIP_SENDER_MAIN, 0);
	pPlayer->ADD_GOSSIP_ITEM(0, "帐号管理　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 600);
	pPlayer->ADD_GOSSIP_ITEM(0, "双倍经验　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
	pPlayer->ADD_GOSSIP_ITEM(0, "鸟点瞬飞　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
	pPlayer->ADD_GOSSIP_ITEM(0, "双天赋树　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
	pPlayer->ADD_GOSSIP_ITEM(0, "武器熟练　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 40);
	pPlayer->ADD_GOSSIP_ITEM(0, "秒升服务　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 50);
	pPlayer->ADD_GOSSIP_ITEM(0, "专业秒升　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 602);
	pPlayer->ADD_GOSSIP_ITEM(0, "增加专业　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 800);
	pPlayer->ADD_GOSSIP_ITEM(0, "坐骑服务　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 603);
	pPlayer->ADD_GOSSIP_ITEM(0, "物品购买　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 604);
	pPlayer->ADD_GOSSIP_ITEM(0, "宠物收养　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 770);
	pPlayer->ADD_GOSSIP_ITEM(0, "变身服务　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1100);
	pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000关闭菜单|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 999);
	pPlayer->SEND_GOSSIP_MENU(384, _Item->GetGUID());
	return true;
}

void SendDefaultMenu_Item(Player *pPlayer, Item *_Item, uint32 action)
{
	switch (action)
	{
	case GOSSIP_ACTION_INFO_DEF + 100:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "帐号管理　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 600);
		pPlayer->ADD_GOSSIP_ITEM(0, "双倍经验　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
		pPlayer->ADD_GOSSIP_ITEM(0, "鸟点瞬飞　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
		pPlayer->ADD_GOSSIP_ITEM(0, "双天赋树　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
		pPlayer->ADD_GOSSIP_ITEM(0, "武器熟练　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 40);
		pPlayer->ADD_GOSSIP_ITEM(0, "秒升服务　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 50);
		pPlayer->ADD_GOSSIP_ITEM(0, "专业秒升　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 602);
		pPlayer->ADD_GOSSIP_ITEM(0, "增加专业　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 798);
		pPlayer->ADD_GOSSIP_ITEM(0, "坐骑服务　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 603);
		pPlayer->ADD_GOSSIP_ITEM(0, "物品购买　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 604);
		pPlayer->ADD_GOSSIP_ITEM(0, "宠物收养　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 770);
		pPlayer->ADD_GOSSIP_ITEM(0, "变身服务　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000关闭菜单|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 999);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 10:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "确认开通双倍经验[5积分]　", 2, GOSSIP_ACTION_INFO_DEF + 700);
		pPlayer->ADD_GOSSIP_ITEM(0, "备注：使用后做任务变成双倍持续两个小时，多次购买时间叠加　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 20:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "确认开通鸟点瞬飞[10积分]　", 2, GOSSIP_ACTION_INFO_DEF + 701);
		pPlayer->ADD_GOSSIP_ITEM(0, "备注：开通后有效期为一个月鸟点飞行改为瞬间到达为您节省时间　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 30:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "确认开通双天赋树[30积分]　", 2, GOSSIP_ACTION_INFO_DEF + 703);
		pPlayer->ADD_GOSSIP_ITEM(0, "备注：开通后使用.tf 1和.tf 2来切换第一或第二天赋，每次洗点天赋点时请使用.bctf 1和.bctf 2来保存点好的天赋　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 40:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "确认开通武器熟练[10积分]　", 2, GOSSIP_ACTION_INFO_DEF + 706);
		pPlayer->ADD_GOSSIP_ITEM(0, "备注：开通后已学习到的武器技能达到上限，未学习的不会增加　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 50:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "确认开通秒升服务[199积分]　", 2, GOSSIP_ACTION_INFO_DEF + 709);
		pPlayer->ADD_GOSSIP_ITEM(0, "备注：开通后送T0套装和四个背包外加一张满级卡　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 600:  //角色管理
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "跨阵营转换种族服务[99积分]　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 900);
		pPlayer->ADD_GOSSIP_ITEM(0, "同阵营转换种族服务[50积分]　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 901);
		pPlayer->ADD_GOSSIP_ITEM(0, "改名字[50积分]　", 2, GOSSIP_ACTION_INFO_DEF + 704);
		pPlayer->ADD_GOSSIP_ITEM(0, "改性别[10积分]　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3300);
		pPlayer->ADD_GOSSIP_ITEM(0, "职业转换服务[199积分]　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 902);
		pPlayer->ADD_GOSSIP_ITEM(0, "变性服务[30积分]　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 903);
		//pPlayer->ADD_GOSSIP_ITEM(0, "改名服务[20积分]　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 704);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 900:  //跨阵营转换种族服务99积分
		if (pPlayer->getRace() == 1 || pPlayer->getRace() == 3 || pPlayer->getRace() == 4 || pPlayer->getRace() == 7 || pPlayer->getRace() == 11)
		{
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(121), 2, GOSSIP_ACTION_INFO_DEF + 2001);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(122), 2, GOSSIP_ACTION_INFO_DEF + 2002);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(123), 2, GOSSIP_ACTION_INFO_DEF + 2003);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(124), 2, GOSSIP_ACTION_INFO_DEF + 2004);
		}
		else
		{
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(125), 2, GOSSIP_ACTION_INFO_DEF + 2005);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(126), 2, GOSSIP_ACTION_INFO_DEF + 2006);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(127), 2, GOSSIP_ACTION_INFO_DEF + 2007);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(128), 2, GOSSIP_ACTION_INFO_DEF + 2008);
		}
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 901:  //同阵营转换种族服务50积分
		if (pPlayer->getRace() == 1 || pPlayer->getRace() == 3 || pPlayer->getRace() == 4 || pPlayer->getRace() == 7 || pPlayer->getRace() == 11)
		{
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(125), 2, GOSSIP_ACTION_INFO_DEF + 2005);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(126), 2, GOSSIP_ACTION_INFO_DEF + 2006);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(127), 2, GOSSIP_ACTION_INFO_DEF + 2007);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(128), 2, GOSSIP_ACTION_INFO_DEF + 2008);
		}
		else
		{
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(121), 2, GOSSIP_ACTION_INFO_DEF + 2001);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(122), 2, GOSSIP_ACTION_INFO_DEF + 2002);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(123), 2, GOSSIP_ACTION_INFO_DEF + 2003);
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(124), 2, GOSSIP_ACTION_INFO_DEF + 2004);
		}
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 902:  //角色职业转换服务100积分
		if (pPlayer->getClass() != CLASS_WARRIOR && pPlayer->getLevel() == 60)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(225), 2, GOSSIP_ACTION_INFO_DEF + 3001);
		if (pPlayer->getClass() != CLASS_PALADIN && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_HUMAN || pPlayer->getRace() == RACE_DWARF)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(226), 2, GOSSIP_ACTION_INFO_DEF + 3002);
		if (pPlayer->getClass() != CLASS_HUNTER && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_DWARF || pPlayer->getRace() == RACE_NIGHTELF || pPlayer->getRace() == RACE_ORC || pPlayer->getRace() == RACE_TAUREN || pPlayer->getRace() == RACE_TROLL)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(227), 2, GOSSIP_ACTION_INFO_DEF + 3003);
		if (pPlayer->getClass() != CLASS_ROGUE && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() != RACE_TAUREN)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(228), 2, GOSSIP_ACTION_INFO_DEF + 3004);
		if (pPlayer->getClass() != CLASS_PRIEST && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_HUMAN || pPlayer->getRace() == RACE_DWARF || pPlayer->getRace() == RACE_NIGHTELF || pPlayer->getRace() == RACE_UNDEAD || pPlayer->getRace() == RACE_TROLL)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(229), 2, GOSSIP_ACTION_INFO_DEF + 3005);
		if (pPlayer->getClass() != CLASS_SHAMAN && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_ORC || pPlayer->getRace() == RACE_TAUREN || pPlayer->getRace() == RACE_TROLL)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(230), 2, GOSSIP_ACTION_INFO_DEF + 3006);
		if (pPlayer->getClass() != CLASS_MAGE && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_HUMAN || pPlayer->getRace() == RACE_GNOME || pPlayer->getRace() == RACE_UNDEAD || pPlayer->getRace() == RACE_TROLL)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(231), 2, GOSSIP_ACTION_INFO_DEF + 3007);
		if (pPlayer->getClass() != CLASS_WARLOCK && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_HUMAN || pPlayer->getRace() == RACE_GNOME || pPlayer->getRace() == RACE_ORC || pPlayer->getRace() == RACE_UNDEAD)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(232), 2, GOSSIP_ACTION_INFO_DEF + 3008);
		if (pPlayer->getClass() != CLASS_DRUID && pPlayer->getLevel() == 60)
		if (pPlayer->getRace() == RACE_NIGHTELF || pPlayer->getRace() == RACE_TAUREN)
			pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(233), 2, GOSSIP_ACTION_INFO_DEF + 3009);
		pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(234), 2, GOSSIP_ACTION_INFO_DEF + 605);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 903: //变性服务30积分
		pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(117), 2, GOSSIP_ACTION_INFO_DEF + 221);
		pPlayer->ADD_GOSSIP_ITEM(0, pPlayer->GetZiZhiName(118), 2, GOSSIP_ACTION_INFO_DEF + 222);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 602:  //专业类服务开始
		pPlayer->PlayerTalkClass->ClearMenus();
		if (pPlayer->HasSkill(SKILL_ALCHEMY) && pPlayer->GetBaseSkillValue(SKILL_ALCHEMY) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]炼金等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 710);
		if (pPlayer->HasSkill(SKILL_BLACKSMITHING) && pPlayer->GetBaseSkillValue(SKILL_BLACKSMITHING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]锻造等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 711);
		if (pPlayer->HasSkill(SKILL_TAILORING) && pPlayer->GetBaseSkillValue(SKILL_TAILORING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]裁缝等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 712);
		if (pPlayer->HasSkill(SKILL_ENGINEERING) && pPlayer->GetBaseSkillValue(SKILL_ENGINEERING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]工程等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 713);
		if (pPlayer->HasSkill(SKILL_LEATHERWORKING) && pPlayer->GetBaseSkillValue(SKILL_LEATHERWORKING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]制皮等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 714);
		if (pPlayer->HasSkill(SKILL_ENCHANTING) && pPlayer->GetBaseSkillValue(SKILL_ENCHANTING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]附魔等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 715);
		if (pPlayer->HasSkill(SKILL_FISHING) && pPlayer->GetBaseSkillValue(SKILL_FISHING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[20积分]钓鱼等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 716);
		if (pPlayer->HasSkill(SKILL_COOKING) && pPlayer->GetBaseSkillValue(SKILL_COOKING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[20积分]烹饪等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 717);
		if (pPlayer->HasSkill(SKILL_MINING) && pPlayer->GetBaseSkillValue(SKILL_MINING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]采矿等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 718);
		if (pPlayer->HasSkill(SKILL_HERBALISM) && pPlayer->GetBaseSkillValue(SKILL_HERBALISM) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]草药等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 719);
		if (pPlayer->HasSkill(SKILL_SKINNING) && pPlayer->GetBaseSkillValue(SKILL_SKINNING) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]剥皮等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 720);
		if (pPlayer->HasSkill(SKILL_FIRST_AID) && pPlayer->GetBaseSkillValue(SKILL_FIRST_AID) < 300)
			pPlayer->ADD_GOSSIP_ITEM(0, "[20积分]急救等级加满　", 2, GOSSIP_ACTION_INFO_DEF + 721);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 798:
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "使用积分增加多专业　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 800);
		pPlayer->ADD_GOSSIP_ITEM(0, "使用金币增加多专业　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 799);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000关闭菜单|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 999);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 799:  //金币多专业类服务
		pPlayer->PlayerTalkClass->ClearMenus();
		if (!pPlayer->HasSkill(SKILL_TAILORING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[500金币]我要学习裁缝　", 2, GOSSIP_ACTION_INFO_DEF + 810);
		if (!pPlayer->HasSkill(SKILL_LEATHERWORKING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[500金币]我要学习制皮　", 2, GOSSIP_ACTION_INFO_DEF + 811);
		if (!pPlayer->HasSkill(SKILL_SKINNING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[500金币]我要学习剥皮　", 2, GOSSIP_ACTION_INFO_DEF + 812);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 800:  //积分多专业类服务
		pPlayer->PlayerTalkClass->ClearMenus();
		if (!pPlayer->HasSkill(SKILL_ALCHEMY))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习炼金　", 2, GOSSIP_ACTION_INFO_DEF + 801);
		if (!pPlayer->HasSkill(SKILL_BLACKSMITHING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习锻造　", 2, GOSSIP_ACTION_INFO_DEF + 802);
		if (!pPlayer->HasSkill(SKILL_TAILORING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习裁缝　", 2, GOSSIP_ACTION_INFO_DEF + 803);
		if (!pPlayer->HasSkill(SKILL_ENGINEERING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习工程　", 2, GOSSIP_ACTION_INFO_DEF + 804);
		if (!pPlayer->HasSkill(SKILL_LEATHERWORKING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习制皮　", 2, GOSSIP_ACTION_INFO_DEF + 805);
		if (!pPlayer->HasSkill(SKILL_ENCHANTING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习附魔　", 2, GOSSIP_ACTION_INFO_DEF + 806);
		if (!pPlayer->HasSkill(SKILL_MINING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习采矿　", 2, GOSSIP_ACTION_INFO_DEF + 807);
		if (!pPlayer->HasSkill(SKILL_HERBALISM))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习草药　", 2, GOSSIP_ACTION_INFO_DEF + 808);
		if (!pPlayer->HasSkill(SKILL_SKINNING))
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]我要学习剥皮　", 2, GOSSIP_ACTION_INFO_DEF + 809);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 603:  //坐骑类服务开始
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "[500积分]黑色其拉作战坦克[不需要骑术]　", 2, GOSSIP_ACTION_INFO_DEF + 730);
		pPlayer->ADD_GOSSIP_ITEM(0, "[100积分]死亡军马的缰绳　", 2, GOSSIP_ACTION_INFO_DEF + 731);
		pPlayer->ADD_GOSSIP_ITEM(0, "[150积分]冬泉霜刃豹　", 2, GOSSIP_ACTION_INFO_DEF + 732);
		pPlayer->ADD_GOSSIP_ITEM(0, "[200积分]迅捷祖利安猛虎　", 2, GOSSIP_ACTION_INFO_DEF + 733);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[30积分]鱼|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 734);
		pPlayer->ADD_GOSSIP_ITEM(0, "[150积分]拉扎什迅猛龙　", 2, GOSSIP_ACTION_INFO_DEF + 1204);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[30积分]迅捷黄色机械陆行鸟|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1205);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[30积分]迅捷白色机械陆行鸟|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1206);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[30积分]迅捷白色机械陆行鸟|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1207);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[30积分]迅捷棕狼号角|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1208);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[30积分]迅捷灰狼号角|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1209);
		pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]迅捷森林狼号角　", 2, GOSSIP_ACTION_INFO_DEF + 1210);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF下一页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1200);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 604:  //道具类服务开始
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "24格背包[30积分]　", 2, GOSSIP_ACTION_INFO_DEF + 740);
		pPlayer->ADD_GOSSIP_ITEM(0, "28格背包[50积分]　", 2, GOSSIP_ACTION_INFO_DEF + 741);
		pPlayer->ADD_GOSSIP_ITEM(0, "大面包[50积分]　", 2, GOSSIP_ACTION_INFO_DEF + 707);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[10积分]龙火护符|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 708);
		//pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[50积分]趣味变身|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1100);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 1100:  //趣味变身
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "[99积分]怀特迈恩　", 2, GOSSIP_ACTION_INFO_DEF + 1101);
		pPlayer->ADD_GOSSIP_ITEM(0, "[99积分]泰兰德　", 2, GOSSIP_ACTION_INFO_DEF + 1102);
		pPlayer->ADD_GOSSIP_ITEM(0, "[99积分]希尔瓦娜斯　", 2, GOSSIP_ACTION_INFO_DEF + 1103);
		pPlayer->ADD_GOSSIP_ITEM(0, "[99积分]月怒血啸者　", 2, GOSSIP_ACTION_INFO_DEF + 1104);
		//pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]海克拜瑞·斯莫特船长　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1105);
		//pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]藏宝海湾地精卫兵　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1106);
		pPlayer->ADD_GOSSIP_ITEM(0, "[99积分]吉安娜·普罗德摩尔　", 2, GOSSIP_ACTION_INFO_DEF + 1107);
		pPlayer->ADD_GOSSIP_ITEM(0, "[99积分]凯恩·血蹄　", 2, GOSSIP_ACTION_INFO_DEF + 1108);
		//pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]安蒂　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1109);
		//pPlayer->ADD_GOSSIP_ITEM(0, "[100积分]伯瓦尔·弗塔根公爵　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1110);
		//pPlayer->ADD_GOSSIP_ITEM(0, "[100积分]冬幕节狂欢者　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1111);
		//pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]恐惧魔王　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1112);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 770:  //小宠物收集
		pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]加尔　", 2, GOSSIP_ACTION_INFO_DEF + 771);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]迦顿男爵　", 2, GOSSIP_ACTION_INFO_DEF + 772);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]萨菲隆先驱者　", 2, GOSSIP_ACTION_INFO_DEF + 773);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]瑟莱德丝公主　", 2, GOSSIP_ACTION_INFO_DEF + 774);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]大检察官怀特迈恩　", 2, GOSSIP_ACTION_INFO_DEF + 775);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]血骨傀儡　", 2, GOSSIP_ACTION_INFO_DEF + 776);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]莱斯霜语　", 2, GOSSIP_ACTION_INFO_DEF + 777);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]奥比　", 2, GOSSIP_ACTION_INFO_DEF + 778);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]莫阿姆　", 2, GOSSIP_ACTION_INFO_DEF + 779);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]吞咽者布鲁　", 2, GOSSIP_ACTION_INFO_DEF + 780);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]无疤者奥斯里安　", 2, GOSSIP_ACTION_INFO_DEF + 781);
		pPlayer->ADD_GOSSIP_ITEM(0, "[10积分]狼王南杜斯　", 2, GOSSIP_ACTION_INFO_DEF + 782);
		pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
		pPlayer->PlayerTalkClass->SendGossipMenu(384, _Item->GetGUID());
		break;
	case GOSSIP_ACTION_INFO_DEF + 999:  //关闭菜单
		pPlayer->PlayerTalkClass->CloseGossip();
		break;
	}
};

bool GossipSelect_test_item(Player *pPlayer, Item *_Item, uint32 sender, uint32 action)
{
	switch (sender)
	{
		// 主选单
	case 1:
		pPlayer->PlayerTalkClass->GetGossipMenu().ClearMenu();
		SendDefaultMenu_Item(pPlayer, _Item, action);
		break;
		// 动作执行
	case 2:
		switch (action)
		{
		case GOSSIP_ACTION_INFO_DEF + 2001:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_PALADIN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_PRIEST:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_MAGE:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_DRUID:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 99)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_ORC);
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)99);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2002:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_PALADIN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_HUNTER:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_SHAMAN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_DRUID:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 99)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_UNDEAD);
						   pPlayer->DeletePlayerRaceSpell();
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)99);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2003:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_PALADIN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_PRIEST:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_MAGE:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_ROGUE:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_WARLOCK:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 99)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_TAUREN);
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)99);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2004:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_PALADIN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_DRUID:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_WARLOCK:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 99)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_TROLL);
						   pPlayer->DeletePlayerRaceSpell();
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)99);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2005:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_SHAMAN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_HUNTER:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_DRUID:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 50)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_HUMAN);
						   pPlayer->DeletePlayerRaceSpell();
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)50);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2006:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_SHAMAN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_MAGE:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_WARLOCK:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_DRUID:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 50)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_DWARF);
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)50);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2007:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_SHAMAN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_PALADIN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_MAGE:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_WARLOCK:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 50)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_NIGHTELF);
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)50);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 2008:
			if (!JianCheTJ2(pPlayer))
				return false;

			switch (pPlayer->getClass())
			{
			case CLASS_SHAMAN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_PALADIN:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_HUNTER:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_PRIEST:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			case CLASS_DRUID:
				ChatHandler(pPlayer->GetSession()).PSendSysMessage(LANG_JIAOBEN_15);
				pPlayer->CLOSE_GOSSIP_MENU();
				break;
			default:
			{
					   if (pPlayer->Getjf() >= 50)
					   {
						   pPlayer->SaveToDB();
						   uint32 slot = pPlayer->GetBankBagSlotCount();
						   pPlayer->DeletePlayerRaceSkill(pPlayer);
						   pPlayer->SetRace(RACE_GNOME);
						   pPlayer->DeletePlayerRaceSpell();
						   pPlayer->SetUInt32Value(PLAYER_BYTES, pPlayer->GetPlayerRacePlayerBytes());
						   pPlayer->SetUInt32Value(PLAYER_BYTES_2, pPlayer->GetPlayerRacePlayerBytes2());
						   pPlayer->SetBankBagSlotCount(slot);
						   pPlayer->GetSession()->KickPlayer();
						   pPlayer->Modifyjifen(-(int32)50);
						   pPlayer->CLOSE_GOSSIP_MENU();
					   }
					   else
					   {
						   pPlayer->GetSession()->SendNotification("你的积分不足　");
						   pPlayer->PlayerTalkClass->CloseGossip();
					   }
			}break;
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 704:	//[50积分]改名字
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);    //修改名字
				pPlayer->GetSession()->SendNotification("重新登录后修改角色名字　");
				pPlayer->PlayerTalkClass->CloseGossip();
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买改名服务!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3300:	//变性
			if (pPlayer->Getjf() >= 30)
			{
				if (pPlayer->getGender() == 0)
				{
					pPlayer->SetGender(1);
					pPlayer->Modifyjifen(-(int32)30);
					pPlayer->GetSession()->KickPlayer();
					pPlayer->CLOSE_GOSSIP_MENU();
				}
				else
				{
					pPlayer->SetGender(0);
					pPlayer->Modifyjifen(-(int32)30);
					pPlayer->GetSession()->KickPlayer();
					pPlayer->CLOSE_GOSSIP_MENU();
				}
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法改变性别!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3001:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_WARRIOR);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3002:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_PALADIN);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3003:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_HUNTER);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3004:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_ROGUE);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3005:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_PRIEST);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3006:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_SHAMAN);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3007:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_MAGE);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3008:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_WARLOCK);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 3009:
			if (pPlayer->Getjf() >= 199)
			{
				pPlayer->SaveToDB();
				pPlayer->resetTalents(true);
				pPlayer->DeletePlayerAllSpell();
				pPlayer->SetClass(CLASS_DRUID);
				SD2Database.PExecute("DELETE FROM character_spell_Talentsa WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsb WHERE guid = '%u'", pPlayer->GetGUIDLow());
				SD2Database.PExecute("DELETE FROM character_spell_Talentsc WHERE guid = '%u'", pPlayer->GetGUIDLow());
				pPlayer->Modifyjifen(-(int32)199);
				pPlayer->GetSession()->KickPlayer();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 700:	//[5积分]双倍经验药水
			if (pPlayer->Getjf() >= 5)
			{
				pPlayer->AddItem(30049, 1);
				pPlayer->Modifyjifen(-(int32)5);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 701:	//[10积分]鸟点瞬飞
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->Setshunfei();
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->Modifyjifen(-(int32)10);
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买瞬飞!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 703:	//[30积分]双天赋
			if (pPlayer->Getjf() >= 30)
			{
				pPlayer->SetTowTf();
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->Modifyjifen(-(int32)30);
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买双天赋!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 706:	//[10积分]熟练度提升
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->UpdateSkillsToMaxSkillsForLevel();
				pPlayer->PlayerTalkClass->CloseGossip();
				pPlayer->GetSession()->SendNotification("熟练度MAX　");
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 709:	//秒级判断
			if (pPlayer->getClass() == CLASS_WARRIOR)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100047, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_PALADIN)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100048, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_HUNTER)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100049, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_ROGUE)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100050, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_PRIEST)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100051, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_SHAMAN)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100052, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_MAGE)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100053, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_WARLOCK)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100054, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			else if (pPlayer->getClass() == CLASS_DRUID)
			{
				if (pPlayer->Getjf() >= 199)
				{
					pPlayer->AddItem(100055, 1);
					pPlayer->Modifyjifen(-(int32)199);
					pPlayer->PlayerTalkClass->CloseGossip();
				}
				else
				{
					pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
					pPlayer->PlayerTalkClass->CloseGossip();
				}
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 710:	//炼金171
			if (pPlayer->Getjf() >= 80)
			{
				pPlayer->Modifyjifen(-(int32)80);
				Skill_Type = SKILL_ALCHEMY;
				pPlayer->learnSpell(2259, false);
				pPlayer->learnSpell(3101, false);
				pPlayer->learnSpell(3464, false);
				pPlayer->learnSpell(11611, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 711:	//锻造164
			if (pPlayer->Getjf() >= 80)
			{
				pPlayer->Modifyjifen(-(int32)80);
				Skill_Type = SKILL_BLACKSMITHING;
				pPlayer->learnSpell(2018, false);
				pPlayer->learnSpell(3100, false);
				pPlayer->learnSpell(3538, false);
				pPlayer->learnSpell(9785, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 712:	//裁缝197
			if (pPlayer->Getjf() >= 80)
			{
				pPlayer->Modifyjifen(-(int32)80);
				Skill_Type = SKILL_TAILORING;
				pPlayer->learnSpell(3908, false);
				pPlayer->learnSpell(3909, false);
				pPlayer->learnSpell(3910, false);
				pPlayer->learnSpell(12180, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 713:	//工程学202
			if (pPlayer->Getjf() >= 80)
			{
				pPlayer->Modifyjifen(-(int32)80);
				Skill_Type = SKILL_ENGINEERING;
				pPlayer->learnSpell(4036, false);
				pPlayer->learnSpell(4037, false);
				pPlayer->learnSpell(4038, false);
				pPlayer->learnSpell(12656, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 714:	//制皮165
			if (pPlayer->Getjf() >= 80)
			{
				pPlayer->Modifyjifen(-(int32)80);
				Skill_Type = SKILL_LEATHERWORKING;
				pPlayer->learnSpell(2108, false);
				pPlayer->learnSpell(3104, false);
				pPlayer->learnSpell(3811, false);
				pPlayer->learnSpell(10662, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 715:	//附魔333
			if (pPlayer->Getjf() >= 80)
			{
				pPlayer->Modifyjifen(-(int32)80);
				Skill_Type = SKILL_ENCHANTING;
				pPlayer->learnSpell(7411, false);
				pPlayer->learnSpell(7412, false);
				pPlayer->learnSpell(7413, false);
				pPlayer->learnSpell(13920, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 716:	//钓鱼
			if (pPlayer->Getjf() >= 20)
			{
				pPlayer->Modifyjifen(-(int32)20);
				Skill_Type = SKILL_FISHING;
				pPlayer->learnSpell(7620, false);
				pPlayer->learnSpell(7731, false);
				pPlayer->learnSpell(7732, false);
				pPlayer->learnSpell(18248, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 717:	//烹饪
			if (pPlayer->Getjf() >= 20)
			{
				pPlayer->Modifyjifen(-(int32)20);
				Skill_Type = SKILL_COOKING;
				pPlayer->learnSpell(2250, false);
				pPlayer->learnSpell(3102, false);
				pPlayer->learnSpell(3413, false);
				pPlayer->learnSpell(18260, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 718:	//采矿
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_MINING;
				pPlayer->learnSpell(2575, false);
				pPlayer->learnSpell(2576, false);
				pPlayer->learnSpell(3564, false);
				pPlayer->learnSpell(10248, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 719:	//草药
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_HERBALISM;
				pPlayer->learnSpell(2366, false);
				pPlayer->learnSpell(2368, false);
				pPlayer->learnSpell(3570, false);
				pPlayer->learnSpell(11990, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 720:	//剥皮
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_SKINNING;
				pPlayer->learnSpell(8613, false);
				pPlayer->learnSpell(8617, false);
				pPlayer->learnSpell(8618, false);
				pPlayer->learnSpell(10768, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 721:	//急救
			if (pPlayer->Getjf() >= 20)
			{
				pPlayer->Modifyjifen(-(int32)20);
				Skill_Type = SKILL_FIRST_AID;
				pPlayer->learnSpell(3273, false);
				pPlayer->learnSpell(3274, false);
				pPlayer->learnSpell(7924, false);
				pPlayer->learnSpell(10846, false);
				pPlayer->SetSkill(Skill_Type, SETSKILL_MAXVAL, SETSKILL_MAXVAL);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法秒升!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 801:	//炼金171
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_ALCHEMY;
				pPlayer->learnSpell(2259, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 802:	//锻造164
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_BLACKSMITHING;
				pPlayer->learnSpell(2018, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 803:	//裁缝197
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_TAILORING;
				pPlayer->learnSpell(3908, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 804:	//工程学202
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_ENGINEERING;
				pPlayer->learnSpell(4036, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 805:	//制皮165
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_LEATHERWORKING;
				pPlayer->learnSpell(2108, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 806:	//附魔333
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_ENCHANTING;
				pPlayer->learnSpell(7411, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 807:	//采矿
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_MINING;
				pPlayer->learnSpell(2575, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 808:	//草药
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_HERBALISM;
				pPlayer->learnSpell(2366, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 809:	//剥皮
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->Modifyjifen(-(int32)50);
				Skill_Type = SKILL_SKINNING;
				pPlayer->learnSpell(8613, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 810:	//裁缝197
			if (pPlayer->GetMoney() >= 5000000)
			{
				pPlayer->ModifyMoney(-(int32)5000000);
				Skill_Type = SKILL_TAILORING;
				pPlayer->learnSpell(3908, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的金币不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 811:	//制皮165
			if (pPlayer->GetMoney() >= 5000000)
			{
				pPlayer->ModifyMoney(-(int32)5000000);
				Skill_Type = SKILL_LEATHERWORKING;
				pPlayer->learnSpell(2108, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 812:	//剥皮
			if (pPlayer->GetMoney() >= 5000000)
			{
				pPlayer->ModifyMoney(-(int32)5000000);
				Skill_Type = SKILL_SKINNING;
				pPlayer->learnSpell(8613, false);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,学习新专业!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 730:	//[500积分]黑色其拉作战坦克
			if (pPlayer->HasItemCount(30089, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 500)
			{
				pPlayer->AddItem(30089, 1);
				pPlayer->Modifyjifen(-(int32)500);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 731:	//[100积分]死亡军马的缰绳
			if (pPlayer->HasItemCount(13335, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 100)
			{
				pPlayer->AddItem(13335, 1);
				pPlayer->Modifyjifen(-(int32)100);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 732:	//[100积分]冬泉霜刃豹
			if (pPlayer->HasItemCount(13086, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 150)
			{
				pPlayer->AddItem(13086, 1);
				pPlayer->Modifyjifen(-(int32)150);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 733:	//[200积分]迅捷祖利安猛虎
			if (pPlayer->HasItemCount(19902, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 200)
			{
				pPlayer->AddItem(19902, 1);
				pPlayer->Modifyjifen(-(int32)200);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1204:	//[150积分]拉扎什迅猛龙
			if (pPlayer->HasItemCount(19872, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 150)
			{
				pPlayer->AddItem(19872, 1);
				pPlayer->Modifyjifen(-(int32)150);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1210:	//[50积分]迅捷森林狼号角
			if (pPlayer->HasItemCount(18797, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->AddItem(18797, 1);
				pPlayer->Modifyjifen(-(int32)50);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 740:	//[30积分]24格背包
			if (pPlayer->Getjf() >= 30)
			{
				pPlayer->AddItem(30144, 1);
				pPlayer->Modifyjifen(-(int32)30);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 741:	//[30积分]28格背包
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->AddItem(31005, 1);
				pPlayer->Modifyjifen(-(int32)50);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 707:	//[50积分]大面包
			if (pPlayer->HasItemCount(90013, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 50)
			{
				pPlayer->AddItem(90013, 1);
				pPlayer->Modifyjifen(-(int32)50);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 771:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30110, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30110, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 772:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30111, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30111, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 773:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30112, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30112, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 774:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30113, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30113, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 775:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30114, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30114, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 776:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30115, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30115, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 777:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30116, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30116, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 778:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30117, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30117, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 779:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30118, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30118, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 780:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30119, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30119, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 781:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30120, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30120, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 782:	//[10积分]宠物购买
			if (pPlayer->HasItemCount(30121, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 10)
			{
				pPlayer->AddItem(30121, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1101:	//[100积分]怀特迈恩
			if (pPlayer->HasItemCount(30095, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 99)
			{
				pPlayer->AddItem(30095, 1);
				pPlayer->Modifyjifen(-(int32)99);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1102:	//[100积分]泰兰德
			if (pPlayer->HasItemCount(30143, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 99)
			{
				pPlayer->AddItem(30143, 1);
				pPlayer->Modifyjifen(-(int32)99);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1103:	//[100积分]希尔瓦娜斯
			if (pPlayer->HasItemCount(30142, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 99)
			{
				pPlayer->AddItem(30142, 1);
				pPlayer->Modifyjifen(-(int32)99);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1104:	//[100积分]月怒血啸者
			if (pPlayer->HasItemCount(30146, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 99)
			{
				pPlayer->AddItem(30146, 1);
				pPlayer->Modifyjifen(-(int32)99);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1107:	//[100积分]吉安娜·普罗德摩尔
			if (pPlayer->HasItemCount(30151, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 99)
			{
				pPlayer->AddItem(30151, 1);
				pPlayer->Modifyjifen(-(int32)99);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		case GOSSIP_ACTION_INFO_DEF + 1108:	//[100积分]凯恩·血蹄
			if (pPlayer->HasItemCount(30152, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjf() >= 100)
			{
				pPlayer->AddItem(30152, 1);
				pPlayer->Modifyjifen(-(int32)100);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
	}
	return true;
}

bool GossipSelect_Item2(Player *player, Item *_Item, uint32 sender, uint32 action)
{
	return GossipSelect_test_item(player, _Item, sender, action);
}

bool Gossip_test_USE(Player *player, Item* _Item, SpellCastTargets const& targets)
{
	return GossipHello_test_item(player, _Item);
}

void AddSC_test_item()
{
	Script *newscript;
	newscript = new Script;
	newscript->Name = "test_item";
	//newscript->pGossipHello_Item = &GossipHello_npc_tele;
	newscript->pItemUse = Gossip_test_USE;
	newscript->pGossipItemSelect = GossipSelect_Item2;
	newscript->RegisterSelf();
}