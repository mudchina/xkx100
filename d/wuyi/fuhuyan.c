// Room: /d/wuyi/fuhuyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "伏虎岩");
	set("long", @LONG
伏虎岩又名撞冠石，是五曲和六曲的分界石。其形如虎蹲踞，石壁
上有明代兵部侍郎陈省书勒“伏虎”二字。相传古时此处群虎为恶，民
不聊生。观音大士化成人身，收降群虎，并以杨柳瓶镇住最后一只雌虎。
如今，在二曲仙榜岩上，瓶虎栩栩如在。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"yunwo",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

