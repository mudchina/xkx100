// Room: /d/xingxiu/wanxiangdong.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "万象洞");
	set("long", @LONG
这是一个深邃的洞穴，洞内钟乳石绚丽多姿，美妙神奇。有犀牛望
月、五岳朝天、卧龙坪、炼丹井、仙人灶、上天梯、独木桥等，景象万
千，耐人寻味。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"east" : __DIR__"shashan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20330);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

