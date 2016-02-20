// tufeiwo2.c 林中小路
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
你走在一条僻静的林中小路上，两旁是阴森森的树林。只见左右前
后，到处都是铺天盖地的松树林。几十丈高的大松树簇在一块，密实的
枝叶象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。据说这里经常有
土匪出没，不可久留。
LONG );
	set("outdoors", "sanbuguan");
	set("no_sleep_room",1);
	set("exits", ([
		"east" : __DIR__"tufeiwo3",
		"north" : __DIR__"tufeiwo1",
	]));

	set("objects", ([
		__DIR__"npc/tufei1" : 3,
		__DIR__"npc/baibian" : 1,
	]));
	set("coor/x", -2000);
	set("coor/y", -820);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
