// Room: /d/yanziwu/path3.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "绿泥小径");
	set("long", @LONG
你走在蔓陀山庄中的绿泥小径上。小径两侧摆满拉一盆盆茶花，结
了许许多多的五色茶花，时有蜂飞蝶舞戏弄花间。你不敢多留，急步前
行。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"path4",
		"west"   : __DIR__"bridge",
	]));
	set("coor/x", 1230);
	set("coor/y", -1290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}