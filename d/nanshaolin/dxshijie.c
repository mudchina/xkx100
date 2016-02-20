// Room: /d/nanshaolin/dxshijie.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "台阶");
	set("long", @LONG
大雄宝殿前的石阶，三道平行的青石阶展向前方。北面是一条石板
路，隐隐飘来阵阵清烟。香客们大都在此屏息默祷，然后一步一拜到大
雄宝殿去。
LONG );
	set("exits", ([
		"northup" : __DIR__ "pingtai",
		"south"   : __DIR__ "miaofadian",
	]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/first" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

