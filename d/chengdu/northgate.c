// Room: /d/chengdu/northchengmen.c
// Date: Feb.14 1998 by Java

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "北城门");
	set("long", @LONG
这是成都北城门，城门正上方刻着“北门”两个楷书大字，城墙上
贴着几张官府告示(gaoshi)。一条笔直的青石板大道向北延伸。北边望
去，一片绿油油的田野夹着随风摇曳的高树，长竹。城门边两行官兵仔
细盘查进出人等。
LONG
	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south"  : __DIR__"beijie",
		"north"  : __DIR__"fuheqiaon",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n成都提督\n吴天德\n";
}

