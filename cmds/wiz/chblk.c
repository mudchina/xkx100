// chblk.c
inherit F_CLEAN_UP;

#include <globals.h>


string *blocks_name = ({
	"all",
	"rumor",
	"chat",
	"xkx",
	"sing",
	"party",
	"family",
});
mapping ch_str = ([
	"all"	:	"所有",
	"rumor"	:	"谣言",
	"chat"	:	"聊天",
	"xkx"	:	"侠客行",
	"sing"	:	"歌唱",
	"party"	:	"帮会",
	"family":	"门派",
]);

int main(object me, string arg)
{
	object ob;
	int i;
	string who, ch_name, str;
	
	if (!arg)
	{
		tell_object(me,"目前所有公共频道的情况如下：\n");
		for (i = 1;i < sizeof(blocks_name);i ++)
		{
			str = "  ";
			str += ch_str[blocks_name[i]];
			str += "频道：  ";
			if (CHANNEL_D->query_block("all")) str += "关闭";
			else str += CHANNEL_D->query_block(blocks_name[i])?"关闭":"打开";
			str += "\n";
			tell_object(me,str);
		}	
		return 1;
	}

	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	}
	//关闭所有玩家的频道
	ob = LOGIN_D->find_body(who);
	if (ch_name == "")
	{
		if ( !ob && (member_array(who, blocks_name) == -1))
			return notify_fail("你无法关闭此频道或此人不在线！\n");
		else if ( !LOGIN_D->find_body(who)) {
			CHANNEL_D->set_block(who, 1);
			CHANNEL_D->do_channel(me, "sys", ch_str[who] + "频道关闭了。\n");
			return 1;
		}		
	}
	if (!ob) return notify_fail("此人不在线！\n");
	if (wizardp(ob)) return notify_fail("不能关闭巫师的频道。\n");

	//如果不带频道名，则返回该玩家所有频道情况
	if (ch_name == "" || ch_name == " ") 
	{	
		for (i = 1;i <sizeof(blocks_name);i ++) 
			if ( ob->query("chblk_on") ||
				ob->query("chblk_" + blocks_name[i]) )
				tell_object(me, (string)ob->query("name") + "的" + ch_str[blocks_name[i]] + "频道是关闭的。\n");
		if (!(ob->query("chblk_on") ||
			ob->query("chblk_rumor") ||
			ob->query("chblk_chat") ||
			ob->query("chblk_xkx") ||
			ob->query("chblk_sing") ||
			ob->query("chblk_family") ||
			ob->query("chblk_party"))) 
		{
			tell_object(me,(string)ob->query("name")+"没有被关闭的频道。\n");
		} 
	}
	else
		if ( member_array(ch_name, blocks_name) != -1)
		{
			if (ch_name == "all")
			{
				if ( ob->query("chblk_on"))
					tell_object(me, (string)ob->query("name") + "的所有频道已经是关闭的。\n");
				else
				{
					ob->set("chblk_on",1);
					tell_object(me, (string)ob->query("name") + "的所有频道被关闭了。\n");
				}	
			}
			else
				if ( ob->query("chblk_" + ch_name) )
				{
					 tell_object(me, (string)ob->query("name")+"的" + ch_str[ch_name] + "频道已经是关闭的。\n");
				}
				else
				{
					ob->set("chblk_" + ch_name, 1);
					tell_object(me, (string)ob->query("name")+"的" + ch_str[ch_name] + "频道被关闭了。\n");
				}
		}
		else 
		{
			return notify_fail("<Syntax>: chblk <player id> <channel name>\n");
		}
		
	return 1;
}

int help(object me)
{
write(@HELP
    指令格式 : chblk <某人> <频道名>

    此命令将关闭某人的某个频道。

    如果不加任何参数，将显示目前所有频道的情况。
    <频道名>：可以是rumor、chat、xkx、sing、party、family或all。
    如果不提供频道名，则显示某人当前的频道状态。 

并且：
chblk rumor  将关闭所有玩家的谣言频道。
chblk chat   将关闭所有玩家的聊天频道。
chblk xkx    将关闭所有玩家的侠客行频道。
chblk sing   将关闭所有玩家歌唱频道。
chblk party  将关闭所有玩家的帮会频道。
chblk family 将关闭所有玩家的门派频道。
chblk all    将关闭所有玩家的所有频道。

HELP
    );
    return 1;
}

