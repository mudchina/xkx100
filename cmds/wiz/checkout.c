//
// checkout.c
//
// Created :  96-08-15  09:20PM   Falcon
//
inherit F_CLEAN_UP;

#include <ansi.h>



mapping valid_types = ([
        "array":        "阵法",
        "axe":          "斧法",
        "blade":        "刀法",
        "claw":         "爪法",
        "club" :        "棍法",
        "cuff":         "拳法",
        "dagger":       "短兵",
        "dodge":        "轻功",
        "finger":       "指法",
        "force":        "内功",
        "hammer":       "锤法",
        "hand":         "手法",
        "hook":         "钩法",
        "leg":          "腿法",
        "magic":        "法术",
        "parry":        "招架",
        "spear":        "枪法",
        "staff":        "杖法",
        "stick":        "棒法",
        "strike":       "掌法",
        "sword":        "剑法",
        "throwing":     "暗器",
        "unarmed":      "拳脚",
        "whip":         "鞭法",
]);

int main(object me, string arg)
{
	object player;
        mapping map,pmap;
        string *types, *skill, ski, map_to;
        int i, modify;

        if ( arg )
	{
         	player = present( arg, environment( me ) );
		if ( !player )
			player = find_player( arg );
		if ( !player )
			player = find_living( arg );
		if ( !player )
			return notify_fail( "你想查看谁的状态? \n" );	
		map = player->query_skill_map();
		pmap = player->query_skill_prepare();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("他现在没有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是他目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" : 
to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
		if (!pmap || sizeof(pmap) ==0 )
			return notify_fail("他现在没有互备任何特殊技能。\n");
		for (i=0; i<sizeof(skill); i++) {
			if( !player->query_skill(skill[i]) 
			|| !pmap[skill[i]] ) continue;
			printf(	valid_types[skill[i]] + " (" + skill[i] + ")" 
				+ "   " + to_chinese(pmap[skill[i]]) + "\n");
        	}
        	return 1;
        }
	else
	{
        	return notify_fail( "你想看谁的状态啊? \n" );
	}
}
