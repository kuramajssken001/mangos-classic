/**
* ScriptData
* SDName:      npc_custom_box
* SD%Complete: 100
* SDComment:自定义功能
* EndScriptData
**/


#include "precompiled.h"
#include "Spell.h"
/*####################
## npc_tool
######################*/
uint32 Skill_Type = 0;   //技能类型
#define SETSKILL_MAXVAL           300          //商业技能最大值

bool GossipHello_npc_tool(Player* pPlayer, Creature* pCreature)
{
	char *tmp = new char[100];
	sprintf(tmp, "|cFF0041FF我的帐户积分：[%d]点|r 　", pPlayer->Getjifen());
	pPlayer->ADD_GOSSIP_ITEM(4, tmp, GOSSIP_SENDER_MAIN, 0);
	//pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF积分查询|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 600);
	pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF便利类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 601);
	pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF专业类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 602);
	pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF坐骑类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 603);
	pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF道具类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 604);
	pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000关闭菜单|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 605);
	pPlayer->PlayerTalkClass->SendGossipMenu(384, pCreature->GetGUID());
	return true;
}

bool GossipSelect_npc_tool(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
	if (!pPlayer)
		return true;

	switch (uiAction)
	{
		case GOSSIP_ACTION_INFO_DEF + 100:
		{
			char *tmp = new char[100];
			sprintf(tmp, "|cFF0041FF我的帐户积分：[%d]点|r 　", pPlayer->Getjifen());
			pPlayer->ADD_GOSSIP_ITEM(4, tmp, GOSSIP_SENDER_MAIN, 0);
			//pPlayer->ADD_GOSSIP_ITEM(4, "|cFF0041FF积分查询|r　 ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 600);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF便利类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 601);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF专业类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 602);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF坐骑类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 603);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF道具类服务|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 604);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000关闭菜单|r　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 605);
			pPlayer->PlayerTalkClass->SendGossipMenu(384, pCreature->GetGUID());
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 605:  //关闭菜单
		{
			pPlayer->PlayerTalkClass->CloseGossip();
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 601:  //便利类服务开始
		{
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[1积分]经验券　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 700);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[7积分]鸟点瞬飞　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 701);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[10积分]200金币　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 702);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[10积分]天赋券　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 703);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[10积分]改名字　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 704);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[10积分]世界频道　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 705);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
			pPlayer->PlayerTalkClass->SendGossipMenu(384, pCreature->GetGUID());
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 602:  //专业类服务开始
		{
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]炼金等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 710);
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]锻造等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 711);
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]裁缝等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 712);
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]工程等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 713);
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]制皮等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 714);
			pPlayer->ADD_GOSSIP_ITEM(0, "[80积分]附魔等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 715);
			pPlayer->ADD_GOSSIP_ITEM(0, "[20积分]钓鱼等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 716);
			pPlayer->ADD_GOSSIP_ITEM(0, "[20积分]烹饪等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 717);
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]采矿等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 718);
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]草药等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 719);
			pPlayer->ADD_GOSSIP_ITEM(0, "[50积分]制皮等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 720);
			pPlayer->ADD_GOSSIP_ITEM(0, "[20积分]急救等级加满　", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 721);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
			pPlayer->PlayerTalkClass->SendGossipMenu(384, pCreature->GetGUID());
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 603:  //坐骑类服务开始
		{
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[200积分]迅捷祖利安猛虎　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 730);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[100积分]死亡军马的缰绳　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 731);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[100积分]冬泉霜刃豹　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 732);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
			pPlayer->PlayerTalkClass->SendGossipMenu(384, pCreature->GetGUID());
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 604:  //道具类服务开始
		{
			pPlayer->PlayerTalkClass->ClearMenus();
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFF0041FF[25积分]28格背包　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 740);
			pPlayer->ADD_GOSSIP_ITEM(0, "|cFFFF0000返回主页　|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
			pPlayer->PlayerTalkClass->SendGossipMenu(384, pCreature->GetGUID());
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 700:	//[1积分]经验券
		{
			if (pPlayer->Getjifen() >= 1)
			{
				pPlayer->AddItem(90003, 1);
				pPlayer->Modifyjifen(-(int32)1);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 701:	//[7积分]鸟点瞬飞
		{
			if (pPlayer->HasItemCount(90002, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjifen() >= 7)
			{
				pPlayer->AddItem(90002, 1);
				pPlayer->Modifyjifen(-(int32)7);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 702:	//[10积分]200金币
		{
			if (pPlayer->Getjifen() >= 10)
			{
				pPlayer->ModifyMoney(2000000);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 703:	//[10积分]天赋券
		{
			if (pPlayer->HasItemCount(90004, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjifen() >= 10)
			{
				pPlayer->AddItem(90004, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 704:	//[10积分]改名字
		{
			if (pPlayer->Getjifen() >= 10)
			{
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);    //修改名字
				pPlayer->GetSession()->SendNotification("重新登录后修改角色名字　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 705:	//[10积分]世界频道
		{
			if (pPlayer->HasItemCount(90001, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjifen() >= 10)
			{
				pPlayer->AddItem(90001, 1);
				pPlayer->Modifyjifen(-(int32)10);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
				pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}
		case GOSSIP_ACTION_INFO_DEF + 730:	//[200积分]迅捷祖利安猛虎
		{
			if (pPlayer->HasItemCount(19902, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjifen() >= 200)
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
		}
		case GOSSIP_ACTION_INFO_DEF + 731:	//[100积分]死亡军马的缰绳
		{
			if (pPlayer->HasItemCount(13335, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjifen() >= 100)
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
		}
		case GOSSIP_ACTION_INFO_DEF + 732:	//[100积分]冬泉霜刃豹
		{
			if (pPlayer->HasItemCount(13086, 1))
			{
				pPlayer->GetSession()->SendNotification("无法重复购买!　");
				pPlayer->PlayerTalkClass->CloseGossip();
				break;
			}
			if (pPlayer->Getjifen() >= 100)
			{
				pPlayer->AddItem(13086, 1);
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
		case GOSSIP_ACTION_INFO_DEF + 740:	//[25积分]28格背包
		{
			if (pPlayer->Getjifen() >= 25)
			{
				pPlayer->AddItem(90005, 1);
				pPlayer->Modifyjifen(-(int32)25);
				pPlayer->PlayerTalkClass->CloseGossip();
			}
			else
			{
			pPlayer->GetSession()->SendNotification("你的积分不足,无法购买物品!　");
			pPlayer->PlayerTalkClass->CloseGossip();
			}
			break;
		}		
		case GOSSIP_ACTION_INFO_DEF + 710:	//炼金171
		{
			if (pPlayer->Getjifen() >= 80)
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
		}
		case GOSSIP_ACTION_INFO_DEF + 711:	//锻造164
		{
			if (pPlayer->Getjifen() >= 80)
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
		}		
		case GOSSIP_ACTION_INFO_DEF + 712:	//裁缝197
		{
			if (pPlayer->Getjifen() >= 80)
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
		}	
		case GOSSIP_ACTION_INFO_DEF + 713:	//工程学202
		{
			if (pPlayer->Getjifen() >= 80)
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
		}
		case GOSSIP_ACTION_INFO_DEF + 714:	//制皮165
		{
			if (pPlayer->Getjifen() >= 80)
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
		}
		case GOSSIP_ACTION_INFO_DEF + 715:	//附魔333
		{
			if (pPlayer->Getjifen() >= 80)
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
		}	
		case GOSSIP_ACTION_INFO_DEF + 716:	//钓鱼
		{
			if (pPlayer->Getjifen() >= 20)
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
		}		
		case GOSSIP_ACTION_INFO_DEF + 717:	//烹饪
		{
			if (pPlayer->Getjifen() >= 20)
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
		}
		
		case GOSSIP_ACTION_INFO_DEF + 718:	//采矿
		{
			if (pPlayer->Getjifen() >= 50)
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
		}
		
		case GOSSIP_ACTION_INFO_DEF + 719:	//草药
		{
			if (pPlayer->Getjifen() >= 50)
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
		}		
		case GOSSIP_ACTION_INFO_DEF + 720:	//剥皮
		{
			if (pPlayer->Getjifen() >= 50)
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
		}	
		case GOSSIP_ACTION_INFO_DEF + 721:	//急救
		{
			if (pPlayer->Getjifen() >= 20)
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
		}
	}
	return true;
};
void AddSC_npc_custom_box()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "npc_tool";
	pNewScript->pGossipHello = &GossipHello_npc_tool;
	pNewScript->pGossipSelect = &GossipSelect_npc_tool;
	pNewScript->RegisterSelf();

}
