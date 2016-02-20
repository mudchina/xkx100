// /cmds/std/ask.c

// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by Zeratul Jan 5 2001
// Modified by Constant Jan 12 2001
inherit F_CLEAN_UP;

#include <ansi.h>
object i_have(object env,string name); // env中取包含 name的物品
string filter_color(string arg);



string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n疑惑地看着$N，摇了摇头。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");

//	if( !objectp(ob = present(dest, environment(me))) )
	if( !objectp(ob = i_have(environment(me),dest)) )
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") )
	{
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) || ob->query_temp("noliving") )
	{
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n", me, ob);
		return 1;
	}
	if (topic == "本门叛徒" && ob->party_quest_betrayer(me))
		return 1;

	if (topic == "别派奸细" && ob->party_quest_thief(me))
		return 1;

	if ((topic == "quest" || topic == "江湖仇杀" ) && ob->party_quest_kill(me))
		return 1;

	if ( topic == "取消本门叛徒任务" && ob->cancle_quest_betrayer(me) )
		return 1;

	if (topic == "取消别派奸细任务" && ob->cancle_quest_thief(me))
		return 1;
		
	if (topic == "cancel" && ob->cancle_quest_kill(me))
		return 1;
		
	if (topic == "本门秘籍" && ob->party_quest_book(me))
		return 1;

	// 增加向掌门要求叛师的功能。
	// Added by Constant Jan 12 2001
	if ( (topic == "叛师" || topic == "开除") && ob->betray(me, 0))
		return 1;
		
	//增加掌门弟子向掌门要牌上侠客岛
	if (topic == "侠客岛" && ob->xkd(me))
		return 1;
		
		
	if (msg = ob->query("inquiry/" + topic)) {
		if (stringp(msg)) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
	{
			if (ob->accept_ask(me,topic))
			 return 1;
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
  }
	return 1;
}
object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
}
string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

    这个指令在解谜时很重要，通常必须藉由此一指令才能获得进一步的信息。
有ｎａｍｅ、ｈｅｒｅ、ｒｕｍｏｒｓ等预设的关键词。（切记：根据场景或
者金庸书中有关情节而向ＮＰＣ询问相应的问题是破解许多ＱＵＥＳＴ的关键。
而对于ｎａｍｅ，ｈｅｒｅ，ｒｕｍｏｒｓ这几个预设值，ＮＰＣ都会乐于回
答的。）

HELP
   );
   return 1;
}

