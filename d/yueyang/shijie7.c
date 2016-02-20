// Room: /d/yueyang/shijie7.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "城门石阶");
	set("long", @LONG
这是岳阳城门外的石阶，下边就是洞庭湖的码头。石阶由于来往渔
民甚多，不但潮湿，而且沾染了浓重的鱼腥味。石阶上坐着一些乞丐，
手里拿着竹杖或破碗，似在乞讨。有时也见一些身着百纳衣却衣冠鲜亮
的人，匆忙掩鼻而过。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south"    : __DIR__"dianjiangtai",
		"eastup"   : __DIR__"ximen",
		"westdown" : __DIR__"matou1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 3,
	]));
	set("coor/x", -1440);
	set("coor/y", -2270);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
