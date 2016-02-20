// Room: /d/nanshaolin/fangjuku.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "防具库");
	set("long", @LONG
这是一间很大的房间，靠墙整齐地放着一个个大柜子，不少柜子门
敞开着，露出里面的各种防具，品种之多，是你生平仅见。一位灰衣僧
人正埋头整理一堆破损的护具。连你进来也没有注意。
LONG );
	set("exits", ([
		"north" : __DIR__"lshuyuan",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangtu" : 1,
	]));
	set("coor/x", 1790);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


