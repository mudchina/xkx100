// Room: /d/nanshaolin/dmyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"达摩院"NOR);
	set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不少白须
白眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。南北山墙是高
及屋顶的大书架，走近细看，它们是各门各派的武功秘笈，屋正中摆着
几张矮几诃和几个团，几位老僧正在入定中。北面有个小门通向后殿。
LONG );
	set("exits", ([
		"south" : __DIR__"huilang4",
		"north" : __DIR__"dmyuan2",
	]));
        set("objects",([
		CLASS_D("nanshaolin") + "/tianjing" : 1,
		__DIR__"npc/xiao-bei" : 1,
        ]));
	set("coor/x", 1790);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
        int skill;
	mapping myfam;
	myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "南少林派") && dir == "north" &&
		objectp(present("tianjing dashi", environment(me))))
		return notify_fail("天镜大师喝道：达摩院乃本寺重地，你非南少林弟子，不能入内。\n");
	skill = me->query_skill("yijinjing", 1);
	if (!wizardp(me) && skill < 80 &&
		objectp(present("tianjing dashi", environment(me))))
	{
		if (dir == "north")
		{
			return notify_fail("天镜大师摇头道：你功夫还不够，不能进入达摩院。\n");
		}
	}
        return ::valid_leave(me, dir);
}
