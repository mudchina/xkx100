// Room: /d/wuyi/yingzuiyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "鹰嘴岩");
	set("long", @LONG
“雄鹰独立健无伦，锐喙昂头实逼真”。鹰嘴岩是一座浑然一体的
巨岩，光秃秃的岩顶，东端向前突出，尖曲如喙，宛如一只展翅欲飞、
搏击长空的雄鹰。相传，这是一只非礼仙女的魔鹰，天帝在降伏它的时
候，连它的下颚也被闪电削掉了。如今，曾经沸腾的鲜血也被无情的岁
月风化成一道道痛苦的裂痕，生命在这里停泊成苍老的归宿。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"path12",
		"north"     : __DIR__"path13",
		"southeast" : __DIR__"path14",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4920);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

