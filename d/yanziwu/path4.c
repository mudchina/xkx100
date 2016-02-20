// Room: /d/yanziwu/path4.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "茶花小径");
	set("long", @LONG
你走在蔓陀山庄中的绿泥小径上。小径两侧摆满拉一盆盆茶花，结
了许许多多的五色茶花，时有蜂飞蝶舞戏弄花间。往北望前面有个精美
的小楼。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"garden",
		"south"  : __DIR__"path3",
	]));
	set("coor/x", 1230);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}