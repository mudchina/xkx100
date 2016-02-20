// Room: /d/nanshaolin/zdyuan.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"证道院"NOR);
	set("long", @LONG
穿过西侧廊，前面出现一片宽阔的院落。院门的匾额上写着“证道
院”三个大字，这里乃是僧人们日常念经诵佛，参禅打坐的地方。院中
种满了翠竹，显得极是幽静。从周围的禅房中不断传出阵阵的梵唱和木
鱼敲击的声音。
LONG );
	set("exits", ([
		"west" : __DIR__"chanfang-1",
		"east" : __DIR__"celang-2",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dapi" : 1,
		__DIR__"npc/xiao-ku" : 1
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "南少林派") && dir == "west" &&
		objectp(present("dapi dashi", environment(me))))
		return notify_fail("大疲大师喝道：证道院乃本寺弟子禅修之处，你非本寺弟子，不能入内。\n");
	return ::valid_leave(me, dir);
}


