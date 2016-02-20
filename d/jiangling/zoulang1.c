//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
这是一条长长的走廊。走廊西边是万府大厅。东边的尽头是个小客堂。
LONG);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/qifang" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"dating",
		"east"  : __DIR__"ketang",
	]));
  
	set("coor/x", -1488);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!objectp(present("hu cheng", me)) &&
		dir == "east" &&
		objectp(present("qi fang", environment(me))))
		return notify_fail("戚芳拦住你说：我夫君中毒卧床，请勿打扰。\n");

        return ::valid_leave(me, dir);
}