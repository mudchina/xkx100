// sgyhole1.c
// Last Modified by winder on Aug. 1 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
山洞内有块光溜溜的大石，不知道曾有多少华山派的前辈在此思过
面壁，以致这块大石竟被坐得滑溜。石壁(wall)左侧刻着「风清扬」三
个大字，是以利器所刻，笔划苍劲，深有半寸。这三字刻得劲力非凡，
想必其人武功一定十分了得。
LONG );
	set("objects", ([
		CLASS_D("huashan")+"/linghu" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"out" : __DIR__"siguoya",
	]));
	set("item_desc", ([
		"wall" : "一面很厚的石壁。\n"
	]) );
	set("coor/x", -860);
	set("coor/y", 150);
	set("coor/z", 130);
	setup();
}

void init()
{
	add_action("do_break", "break");
}
int do_break(string arg)
{
	int n;
	object weapon,me=this_player();
	mapping fam;

	if ((fam = me->query("family")) &&
		(fam["family_name"] != "华山派") ||
		!arg || arg!="wall" )
		return notify_fail("这是干嘛？\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你一掌打在石壁，满手都是鲜血。\n");

	message_vision(HIC"$N走到石壁前，拔出腰间所悬长剑，运劲向石壁刺了过去！\n"NOR,me);

	if (me->query("neili") < 200)
	{
		message_vision(HIC "结果只听一声闷哼，$N被石壁的反弹力震得眼前一黑....\n"NOR,me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIC"$N只听一声轰响，石壁被捅穿了，原来里面有一个大洞！\n"NOR,me);
	set("exits/enter",__DIR__"sgyhole");
	me->add("neili",-200);
	remove_call_out("close");
	call_out("close", 5, this_object());
	return 1;
}
void close_out()
{
	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
	message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", room);
	room->delete("exits/enter");
}
