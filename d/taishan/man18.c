// Room: /d/taishan/man18.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "慢十八盘");
	set("long", @LONG
泰山有三个十八盘之说。自开山至龙门为“慢十八”，再至升仙坊
为“不紧不慢又十八”，又至南天门为“紧十八”，共计一千六百三十
余阶。你现在正走在慢十八盘上，低头就看见石阶。看着旁边挑担上山
的挑夫，顿时自叹不如。
LONG );
	set("exits", ([
		"northup"   : __DIR__"longmen",
		"southdown" : __DIR__"kaishan",
	]));
	set("objects", ([
		__DIR__"npc/tiao-fu" : 2,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 720);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
