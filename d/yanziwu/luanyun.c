// Room: /d/yanziwu/luanyun.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "乱云亭");
	set("long", @LONG
乱云亭建在蔓陀山峰顶上。在这里俯瞰五湖风光，但见舟船如织，
蔓陀山庄镶嵌在万顷波涛中，恰若水晶盆中一枚青螺。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown"   : __DIR__"path24",
	]));
	set("coor/x", 1210);
	set("coor/y", -1240);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}