// Room: /d/qilian/yumenguan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "玉门关");
	set("long", @LONG
这是大西北的最外一道关隘，不过现在早已废弃不用了。过了玉门
关，就是西域，那里的居民多为碧眼的胡人，“劝君更饮一杯酒，西出
阳关无故人”，再往西去汉人就不多了。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"danshan",
		"east"   : __DIR__"halahu",
	]));
	set("coor/x", -20000);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}