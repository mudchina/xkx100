// expell.c
inherit F_CLEAN_UP;

#include <skill.h>



void create() { seteuid(getuid()); }

	string *base_skill = ({
		"array",     	"axe",     	"blade",
		"claw",      	"club",    	"cuff", 
		"dagger",    	"dodge",   	"force",   
		"finger",    	"gambling" 	"hammer", 
		"hand",      	"hook",		  "leg",
	  "literate", 	"parry",     	"spear",   	
		"staff",	    "stick",     	"strike",  	
		"sword", 	    "throwing",  	"unarmed", 	
		"whip"
	});
int main(object me, string arg)
{
	object ob;
	string skill_name;
	int skill_level;
	mapping ob_skills,smap,pmap;
	mapping myfam;
	int i;
	
	myfam =(mapping)me->query("family");
	
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("你要将谁逐出师门？\n");

	if( !ob->is_character() || !myfam)
		return notify_fail("你逐不动他。\n");

	if( !userp(ob) )
		return notify_fail("你只能开除玩家所扮演的人物。\n");
	
	if(
	ob->query("combat_exp")>10000
	&&(myfam["title"]!= "开山祖师")
	&&(myfam["title"]!= "掌门")
	&&(myfam["title"]!= "总舵主")
	&&(me->query("id")!= "feng qingyang")
	&&(myfam["title"]!= "帮主")
	)
		return notify_fail("对方经验太高，恐怕要找你掌门师尊为你做主了！\n");

		if( ob->is_apprentice_of(me) )
		{
			message_vision("\n$N对着$n说道：从今天起，你我师徒恩断情绝，你走吧！\n\n", me, ob);
			tell_object(ob, "\n你被师父开革出师门了！\n\n");
		}
		else if( me->query("family/privs")==-1 &&
		(string)me->query("family/family_name") ==
		(string)ob->query("family/family_name") )
	{
		message_vision("\n$N对着$n说道：从今天起，你再也不是我" + me->query("family/family_name") + "的弟子了，你走吧！\n\n", me, ob);
		tell_object(ob, "\n你被" + me->query("family/title") + "开革出师门了！\n\n");
	}  else
			return notify_fail("这个人不是你的弟子。\n");

	ob->add("detach/"+ob->query("family/family_name"),1);
	ob->delete("family");
//	ob->delete("title");
	ob->set("title","普通百姓");
	ob->set("score", 0);
	ob->add("expell", 1);
	ob_skills = ob->query_skills();
	smap = (mapping)ob->query_skill_map();
        pmap = (mapping)ob->query_skill_prepare();
/*
	if( mapp(skills) )
	{
		skname = keys(skills);
		for(i=0; i<sizeof(skname); i++)
			skills[skname[i]] /= 2;
	}
*/
		for (i = 0; i < sizeof(ob_skills); )
		{
			skill_name = keys(ob_skills)[i];
			skill_level = ob_skills[skill_name];
			if (member_array(skill_name, base_skill) != -1)
			{
				skill_level = skill_level / 2;
				if (skill_level == 0)
					map_delete(ob_skills, skill_name);
				else
				{
					ob_skills[skill_name] = skill_level;
					i ++;
				}
			}
			else
			{
				map_delete(ob_skills, skill_name);
			}
			
		}
                for (i = sizeof(smap)-1; i >= 0; i --)
                        ob->map_skill(keys(smap)[i]);
                for (i = sizeof(pmap)-1; i >= 0; i -- )
                        ob->prepare_skill(keys(pmap)[i]);
                ob->reset_action();
		ob->set("jiali",0);
		ob->delete("perform");
		ob->delete("can_perform");
		if (!ob->is_busy()) ob->start_busy(5);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : expell|kaichu <某人>
 
    这个指令可以让你开除不成才的弟子，被开除的弟子所有基本技能都会
降到原来的一半，武功全废，综合评价一项也会变成零，这对于一个人物而
言是一个「比死还严重」的打击，请你在开除一名弟子之前务必审慎考虑。
 
HELP
	);
	return 1;
}
