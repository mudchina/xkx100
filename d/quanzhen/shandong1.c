// shandong.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
在这小山洞(dong)的深处，一股强大的水流自地上流出，形成一条
小河流向洞外。如果想再进一步深入的话，就得要跳入水中了。往外可
到小河边。往里就要潜水了。
LONG
	);
	set("item_desc", ([
		"dong" : "一个深邃、幽暗、恐怖的小山洞。\n",
	]));
	set("exits", ([
		"out"       : __DIR__"xiaohebian",
		"southdown" : "/d/gumu/anhe2",
	]));

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", -10);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "southdown" && me->query("family/family_name")!="古墓派")
	{
		return notify_fail("这么急的水，你想跳下去自杀呀？\n");
	}
	if (dir == "southdown" && me->query("family/family_name")=="古墓派")
	{
		message_vision(HIG "$N纵身一跃，跳入水潭之中。\n"NOR,me);
		write(HIC"许多游鱼从你边游过，你伸手一捞，却抓了空。突然你眼前一亮，一股暗流扑面而来，将你冲入一个所在。\n"NOR);
		return 1;
	}
	return ::valid_leave(me, dir);
}
