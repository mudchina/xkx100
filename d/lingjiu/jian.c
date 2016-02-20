// room: /d/lingjiu/jian.c
// modified by rocwood
#include <ansi.h>
inherit ROOM;
void init();
int do_zou(string);
int do_jump(string);
string check_tiesuo();
void create()
{
	set("short","百丈涧");
	set("long",@LONG
山道到此突然消失，在你面前是一条山涧(shanjian)，山涧之中云
雾缭绕，你根本无法看清对面。一条铁索(tiesuo)深入云中，旁边有一
块石碑(bei)。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"southdown" : __DIR__"yan",
	]));
	set("objects",([
		__DIR__"npc/yupopo" : 1,
	]));
	set("item_desc",([
		"shanjian" : "山涧之中云雾缭绕，你根本无法看清对面，也许可以运气跳(jump)过去。\n",
		"bei"      : "『灵鹫宫』重地，擅入者死！\n",
		"tiesuo"   : (: check_tiesuo :),
	]));
	set("coor/x", -51010);
	set("coor/y", 30010);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_zou", "zou");
	add_action("do_jump","jump");
}
int do_zou(string arg)
{
	object me=this_player(), room;
	if(!arg || arg!="tiesuo") return notify_fail("你要走什么？\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' 请巫师处理\n");
	if(objectp(present("yu popo", environment(me))))
	{
		if ((string)me->query("family/family_name")!="逍遥派"
		&& (string)me->query("family/family_name")!="灵鹫宫"
		)
			message_vision("余婆婆伸手拦住$N，说道：“老身奉主人之命守卫百丈涧，\n非灵鹫宫弟子请回！”\n",me);
		else
		{
			message_vision(HIW"$N轻轻跃起踩上铁索，潇洒地向对面走去。\n\n"NOR,me);
			me->move(room);
		}
	}
        else message_vision("$N看着断掉的铁索，不禁发愁，怎么过去呢？\n",me);
        return 1;
}
int do_jump(string arg)
{
	object me=this_player(), room, room1;
	int n = (int)this_player()->query_skill("dodge",1);
	if(!arg || arg!="shanjian") return notify_fail("你要往哪里跳？\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' 请巫师处理\n");
	if(!( room1 = find_object(__DIR__"shanjiao")) )
		room1 = load_object(__DIR__"shanjiao");
	if(!objectp(room1))
		return notify_fail("ERROR:not found 'shanjiao.c' 请巫师处理\n");
	if(objectp(present("yu popo", environment(me))))
		message_vision("犯什么傻，不是有铁索可以走过去吗？跳什么跳呀！\n", me);
	else
		if ((string)me->query("family/family_name")=="逍遥派")
		{
			message_vision( HIW"$N长发一甩，运起灵鹫宫独门轻功，轻轻跃起，潇洒地向对面飘去。\n\n"NOR,me);
			me->move(room);
		}
		else
		{
			message_vision( HIW"$N运起轻功，向对面跃去。\n"NOR,me);
			message_vision( HIW"不料距离山涧对面相当远，$N一口真气提不上来，眼看向山下掉下去。\n"NOR,me);
			if(n>100)
			{
				message_vision( HIY"$N急中生智，抓住对面垂下的那一截断铁索，借力向上跃去。\n"NOR,me);
				message_vision(HIY"$N暗暗叫到：好险！\n"NOR,me);
				me->move(room);
			}
			else
			{
				message_vision(HIR"$N手忙脚乱，发出刺耳的惨叫声！\n"NOR, me);
				message_vision(HIR"$N重重地跌到了山脚下……\n\n"NOR, me);
				me->move(room1);
				me->receive_damage("qi", 500);
				me->receive_wound("qi", 500);
			}
		}
	return 1;
}
string check_tiesuo()
{
	object me=this_player();
	if((objectp(present("yu popo", environment(me)))))
		return "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n";
	else return "看来铁索已经断了，怎么过去呢？\n";
}

