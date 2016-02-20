// /d/xingxiu/house.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "巴依家院");
	set("long", @LONG
这是一个巴依家的庭院。门口大树的树荫投到院子里，让人觉得很
凉快。院子东面是巴依的客厅，西边就是伊犁镇大街。
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"yili",
	    "east" : __DIR__"house1",
	]));
	set("objects", ([
		__DIR__"npc/kid": 1,
		__DIR__"npc/bayi": 1
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");

	set("coor/x", -38900);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) &&
		objectp(present("bayi", environment(me))) && 
		dir == "east")
		return notify_fail("巴依说：我把阿凡提关在我的客厅里了，谁也不许进去。\n");
	return ::valid_leave(me, dir);
}
